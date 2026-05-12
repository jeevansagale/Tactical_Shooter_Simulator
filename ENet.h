#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdint>


struct _ENetHost;
typedef struct _ENetHost ENetHost;
struct _ENetPeer;
typedef struct _ENetPeer ENetPeer;
struct _ENetEvent;
typedef struct _ENetEvent ENetEvent;


struct NetVec3 {
    float x, y, z;
};


enum class PacketType : uint8_t {
    CONNECT = 0,
    DISCONNECT,
    PLAYER_UPDATE,
    PLAYER_SHOOT,
    PLAYER_HIT,
    ASSIGN_PEER_ID
};

#pragma pack(push, 1)

struct PlayerUpdatePacket {
    PacketType type = PacketType::PLAYER_UPDATE;
    uint32_t peerID;
    NetVec3 position;
    float pitch;
    float yaw;
    int health;
    int animIndex;
};

struct PlayerShootPacket {
    PacketType type = PacketType::PLAYER_SHOOT;
    uint32_t peerID;
    NetVec3 origin;
    NetVec3 direction;
    int damage;
};

struct PlayerHitPacket {
    PacketType type = PacketType::PLAYER_HIT;
    uint32_t shooterPeerID;
    uint32_t targetPeerID;
    int damage;
    int remainingHealth;
};

struct AssignPeerPacket {
    PacketType type = PacketType::ASSIGN_PEER_ID;
    uint32_t peerID;
};

#pragma pack(pop)


class NetworkManager {
public:
    NetworkManager();
    ~NetworkManager();

    bool Initialize();
    void Deinitialize();

    bool StartServer(int port, int maxClients = 32);
    bool ConnectToServer(const std::string& ipAddress, int port);

    void Update();

    void SendPlayerUpdate(const NetVec3& pos, float pitch, float yaw, int health, int animIndex);
    void SendPlayerShoot(const NetVec3& origin, const NetVec3& direction, int damage);

    bool IsServer()    const { return isServer; }
    bool IsConnected() const { return connected; }

    std::map<uint32_t, PlayerUpdatePacket> otherPlayers;
    std::vector<PlayerShootPacket> pendingShots;

    uint32_t localPeerID = 0;

    bool wasHit = false;
    int  hitDamage = 0;

private:
    void HandleReceivePacket(ENetEvent& event);
    void BroadcastPacket(const void* data, size_t size, uint32_t flag);
    void SendPacketToPeer(ENetPeer* peer, const void* data, size_t size, uint32_t flag);
    void TickDeadPeers();
    void ProcessShot(uint32_t shooterPeerID, const NetVec3& origin,
        const NetVec3& direction, int damage);

    static bool RayHitsBox(
        const NetVec3& orig, const NetVec3& dir,
        const NetVec3& bmin, const NetVec3& bmax,
        float& tHit
    );

    ENetHost* host;
    ENetPeer* serverPeer;
    std::map<uint32_t, int> deadPeerTicks;

    bool isServer;
    bool connected;
};

extern NetworkManager netManager;
