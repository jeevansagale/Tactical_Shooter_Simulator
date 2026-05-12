#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define NOGDI
#define NOUSER
#include <winsock2.h>
#include <ws2tcpip.h>
#include <enet/enet.h>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "winmm.lib")

#include "ENet.h"
#include "MainGame.h"
#include <cmath>
#include <limits>

NetworkManager netManager;

static const int DEAD_PEER_HIDE_TICKS = 120;

static NetVec3 NormalizeNetVec3(const NetVec3& v) {
    float lenSq = v.x * v.x + v.y * v.y + v.z * v.z;
    if (lenSq <= 0.000001f) return { 0.0f, 0.0f, 0.0f };

    float invLen = 1.0f / std::sqrt(lenSq);
    return { v.x * invLen, v.y * invLen, v.z * invLen };
}

static int ResolveAuthoritativeHealth(int currentHealth, int reportedHealth) {
    if (currentHealth <= 0 && reportedHealth > currentHealth) {
        return reportedHealth;
    }

    return currentHealth;
}

static bool RayHitsNetBox(
    const NetVec3& orig, const NetVec3& dir,
    const NetVec3& bmin, const NetVec3& bmax,
    float& tHit)
{
    const float EPS = 1e-8f;

    float tmin = 0.0f;
    float tmax = std::numeric_limits<float>::max();

    const float os[3] = { orig.x, orig.y, orig.z };
    const float ds[3] = { dir.x,  dir.y,  dir.z };
    const float mins[3] = { bmin.x, bmin.y, bmin.z };
    const float maxs[3] = { bmax.x, bmax.y, bmax.z };

    for (int i = 0; i < 3; i++) {
        if (std::fabs(ds[i]) < EPS) {
            if (os[i] < mins[i] || os[i] > maxs[i]) return false;
        }
        else {
            float invD = 1.0f / ds[i];
            float t1 = (mins[i] - os[i]) * invD;
            float t2 = (maxs[i] - os[i]) * invD;
            if (t1 > t2) { float tmp = t1; t1 = t2; t2 = tmp; }
            tmin = t1 > tmin ? t1 : tmin;
            tmax = t2 < tmax ? t2 : tmax;
            if (tmin > tmax) return false;
        }
    }

    if (tmax < 0.0f) return false;

    tHit = tmin >= 0.0f ? tmin : tmax;
    return true;
}

static bool RayBlockedByBoxes(const NetVec3& origin, const NetVec3& direction,
    float maxT, const std::vector<BoundingBox>& boxes) {
    for (const BoundingBox& box : boxes) {
        NetVec3 bmin = { box.min.x, box.min.y, box.min.z };
        NetVec3 bmax = { box.max.x, box.max.y, box.max.z };

        float t = 0.0f;
        if (RayHitsNetBox(origin, direction, bmin, bmax, t) &&
            t > 0.01f && t < maxT) {
            return true;
        }
    }

    return false;
}

static bool RayBlockedByWorld(const NetVec3& origin, const NetVec3& direction, float maxT) {
    return RayBlockedByBoxes(origin, direction, maxT, MW.HitBox) ||
        RayBlockedByBoxes(origin, direction, maxT, MB.HitBox);
}

NetworkManager::NetworkManager()
    : host(nullptr), serverPeer(nullptr),
    isServer(false), connected(false),
    localPeerID(0), wasHit(false), hitDamage(0) {
}

NetworkManager::~NetworkManager() { Deinitialize(); }

bool NetworkManager::Initialize() {
    if (enet_initialize() != 0) {
        std::cerr << "An error occurred while initializing ENet.\n";
        return false;
    }
    return true;
}

void NetworkManager::Deinitialize() {
    if (host != nullptr) {
        enet_host_destroy(host);
        host = nullptr;
    }
    enet_deinitialize();
    connected = false;
    serverPeer = nullptr;
    otherPlayers.clear();
    pendingShots.clear();
    deadPeerTicks.clear();
}

bool NetworkManager::StartServer(int port, int maxClients) {
    ENetAddress address;
    address.host = ENET_HOST_ANY;
    address.port = port;

    host = enet_host_create(&address, maxClients, 2, 0, 0);
    if (host == nullptr) {
        std::cerr << "An error occurred while trying to create an ENet server host.\n";
        return false;
    }

    isServer = true;
    connected = true;
    localPeerID = 0;
    std::cout << "Server started on port " << port << "\n";
    return true;
}

bool NetworkManager::ConnectToServer(const std::string& ipAddress, int port) {
    host = enet_host_create(nullptr, 1, 2, 0, 0);
    if (host == nullptr) {
        std::cerr << "An error occurred while trying to create an ENet client host.\n";
        return false;
    }

    ENetAddress address;
    enet_address_set_host(&address, ipAddress.c_str());
    address.port = port;

    serverPeer = enet_host_connect(host, &address, 2, 0);
    if (serverPeer == nullptr) {
        std::cerr << "No available peers for initiating an ENet connection.\n";
        return false;
    }

    ENetEvent event;
    if (enet_host_service(host, &event, 5000) > 0 &&
        event.type == ENET_EVENT_TYPE_CONNECT)
    {
        std::cout << "Connection to " << ipAddress << ":" << port << " succeeded.\n";
        isServer = false;
        connected = true;
        localPeerID = 0;
        return true;
    }

    enet_peer_reset(serverPeer);
    std::cerr << "Connection to " << ipAddress << ":" << port << " failed.\n";
    return false;
}

void NetworkManager::Update() {
    if (!host) return;

    TickDeadPeers();

    ENetEvent event;
    while (enet_host_service(host, &event, 0) > 0) {
        switch (event.type) {

        case ENET_EVENT_TYPE_CONNECT:
            std::cout << "A new client connected: peer "
                << event.peer->connectID << "\n";
            otherPlayers[event.peer->connectID] = PlayerUpdatePacket();
            otherPlayers[event.peer->connectID].peerID = event.peer->connectID;
            otherPlayers[event.peer->connectID].health = 100;

            if (isServer) {
                AssignPeerPacket assignPkt;
                assignPkt.peerID = event.peer->connectID;
                SendPacketToPeer(event.peer, &assignPkt, sizeof(AssignPeerPacket), ENET_PACKET_FLAG_RELIABLE);
            }
            break;

        case ENET_EVENT_TYPE_RECEIVE:
            HandleReceivePacket(event);
            enet_packet_destroy(event.packet);
            break;

        case ENET_EVENT_TYPE_DISCONNECT:
            std::cout << "Peer " << event.peer->connectID << " disconnected.\n";
            otherPlayers.erase(event.peer->connectID);
            deadPeerTicks.erase(event.peer->connectID);
            break;

        case ENET_EVENT_TYPE_NONE:
            break;
        }
    }
}

void NetworkManager::TickDeadPeers() {
    for (auto it = deadPeerTicks.begin(); it != deadPeerTicks.end();) {
        it->second--;
        if (it->second <= 0) {
            it = deadPeerTicks.erase(it);
        }
        else {
            ++it;
        }
    }
}

void NetworkManager::ProcessShot(uint32_t shooterPeerID, const NetVec3& origin,
    const NetVec3& direction, int damage) {
    NetVec3 shotDir = NormalizeNetVec3(direction);
    if (damage <= 0 || (shotDir.x == 0.0f && shotDir.y == 0.0f && shotDir.z == 0.0f)) {
        return;
    }

    float closestT = std::numeric_limits<float>::max();
    uint32_t hitPeerID = UINT32_MAX;

    for (auto& pair : otherPlayers) {
        uint32_t peerID = pair.first;
        PlayerUpdatePacket& playerData = pair.second;

        if (peerID == shooterPeerID) continue;
        if (playerData.health <= 0) continue;

        NetVec3 pos = playerData.position;
        NetVec3 bmin = { pos.x - 0.85f, pos.y - 1.5f, pos.z - 0.85f };
        NetVec3 bmax = { pos.x + 0.85f, pos.y + 2.5f, pos.z + 0.85f };

        float t = 0.0f;
        if (RayHitsBox(origin, shotDir, bmin, bmax, t) && t < closestT) {
            closestT = t;
            hitPeerID = peerID;
        }
    }

    if (hitPeerID == UINT32_MAX) {
        return;
    }

    if (RayBlockedByWorld(origin, shotDir, closestT)) {
        return;
    }

    otherPlayers[hitPeerID].health -= damage;
    if (otherPlayers[hitPeerID].health < 0) {
        otherPlayers[hitPeerID].health = 0;
    }

    int remainingHealth = otherPlayers[hitPeerID].health;
    if (remainingHealth <= 0) {
        deadPeerTicks[hitPeerID] = DEAD_PEER_HIDE_TICKS;
        otherPlayers.erase(hitPeerID);
    }

    PlayerHitPacket hitPkt;
    hitPkt.shooterPeerID = shooterPeerID;
    hitPkt.targetPeerID = hitPeerID;
    hitPkt.damage = damage;
    hitPkt.remainingHealth = remainingHealth;
    BroadcastPacket(&hitPkt, sizeof(PlayerHitPacket), ENET_PACKET_FLAG_RELIABLE);

    if (isServer && hitPeerID == localPeerID) {
        wasHit = true;
        hitDamage = damage;
    }

    std::cout << "Peer " << shooterPeerID
        << " hit peer " << hitPeerID
        << " for " << damage << " damage. Remaining HP: "
        << remainingHealth << "\n";
}

void NetworkManager::HandleReceivePacket(ENetEvent& event) {
    if (event.packet->dataLength < sizeof(PacketType)) return;

    PacketType type = *(PacketType*)event.packet->data;

    if (type == PacketType::PLAYER_UPDATE) {
        if (event.packet->dataLength < sizeof(PlayerUpdatePacket)) return;

        PlayerUpdatePacket* p = (PlayerUpdatePacket*)event.packet->data;

        if (isServer) {
            p->peerID = event.peer->connectID;

            auto current = otherPlayers.find(p->peerID);
            if (current != otherPlayers.end()) {
                p->health = ResolveAuthoritativeHealth(current->second.health, p->health);
            }

            auto dead = deadPeerTicks.find(p->peerID);
            if (dead != deadPeerTicks.end()) {
                return;
            }

            otherPlayers[p->peerID] = *p;
            BroadcastPacket(p, sizeof(PlayerUpdatePacket), ENET_PACKET_FLAG_UNSEQUENCED);
        }
        else {
            auto dead = deadPeerTicks.find(p->peerID);
            if (dead != deadPeerTicks.end()) {
                return;
            }

            otherPlayers[p->peerID] = *p;
        }
    }
    else if (type == PacketType::PLAYER_SHOOT) {
        if (event.packet->dataLength < sizeof(PlayerShootPacket)) return;

        PlayerShootPacket* p = (PlayerShootPacket*)event.packet->data;
        p->direction = NormalizeNetVec3(p->direction);

        if (isServer) {
            p->peerID = event.peer->connectID;
            if (deadPeerTicks.count(p->peerID)) {
                return;
            }

            ProcessShot(p->peerID, p->origin, p->direction, p->damage);
            BroadcastPacket(p, sizeof(PlayerShootPacket), ENET_PACKET_FLAG_RELIABLE);
        }
        else if (p->peerID != localPeerID) {
            pendingShots.push_back(*p);
        }
    }
    else if (type == PacketType::PLAYER_HIT) {
        if (event.packet->dataLength < sizeof(PlayerHitPacket)) return;

        PlayerHitPacket* p = (PlayerHitPacket*)event.packet->data;

        if (p->targetPeerID == localPeerID) {
            wasHit = true;
            hitDamage = p->damage;
        }
        else {
            auto it = otherPlayers.find(p->targetPeerID);
            if (it != otherPlayers.end()) {
                it->second.health = p->remainingHealth;
            }

            if (p->remainingHealth <= 0) {
                otherPlayers.erase(p->targetPeerID);
                deadPeerTicks[p->targetPeerID] = DEAD_PEER_HIDE_TICKS;
            }
        }
    }
    else if (type == PacketType::ASSIGN_PEER_ID) {
        if (event.packet->dataLength < sizeof(AssignPeerPacket)) return;

        AssignPeerPacket* p = (AssignPeerPacket*)event.packet->data;
        if (!isServer) {
            localPeerID = p->peerID;
            std::cout << "Assigned network peer ID: " << localPeerID << "\n";
        }
    }
}

void NetworkManager::BroadcastPacket(const void* data, size_t size, uint32_t flag) {
    if (!host) return;
    ENetPacket* packet = enet_packet_create(data, size, flag);
    enet_host_broadcast(host, 0, packet);
}

void NetworkManager::SendPacketToPeer(ENetPeer* peer, const void* data, size_t size, uint32_t flag) {
    if (!peer) return;
    ENetPacket* packet = enet_packet_create(data, size, flag);
    enet_peer_send(peer, 0, packet);
}

void NetworkManager::SendPlayerUpdate(const NetVec3& pos, float pitch, float yaw,
    int health, int animIndex) {
    if (!connected) return;

    PlayerUpdatePacket p;
    p.position = pos;
    p.pitch = pitch;
    p.yaw = yaw;
    p.health = health;
    p.animIndex = animIndex;

    if (isServer) {
        p.peerID = 0;

        if (deadPeerTicks.count(0)) {
            return;
        }

        if (otherPlayers.count(0)) {
            p.health = ResolveAuthoritativeHealth(otherPlayers[0].health, p.health);
        }

        otherPlayers[0] = p;
        BroadcastPacket(&p, sizeof(PlayerUpdatePacket), ENET_PACKET_FLAG_UNSEQUENCED);
    }
    else {
        p.peerID = localPeerID;
        SendPacketToPeer(serverPeer, &p, sizeof(PlayerUpdatePacket), ENET_PACKET_FLAG_UNSEQUENCED);
    }
}

void NetworkManager::SendPlayerShoot(const NetVec3& origin, const NetVec3& direction, int damage) {
    if (!connected) return;

    PlayerShootPacket p;
    p.origin = origin;
    p.direction = NormalizeNetVec3(direction);
    p.damage = damage;

    if (isServer) {
        p.peerID = 0;
        if (deadPeerTicks.count(0)) {
            return;
        }

        ProcessShot(0, origin, p.direction, damage);
        BroadcastPacket(&p, sizeof(PlayerShootPacket), ENET_PACKET_FLAG_RELIABLE);
    }
    else {
        p.peerID = localPeerID;
        SendPacketToPeer(serverPeer, &p, sizeof(PlayerShootPacket), ENET_PACKET_FLAG_RELIABLE);
    }
}

bool NetworkManager::RayHitsBox(
    const NetVec3& orig, const NetVec3& dir,
    const NetVec3& bmin, const NetVec3& bmax,
    float& tHit)
{
    return RayHitsNetBox(orig, dir, bmin, bmax, tHit);
}

