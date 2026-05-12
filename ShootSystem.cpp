#include "ShootSystem.h"

Bullet bullet;

struct ShotTracer {
    Vector3 start;
    Vector3 end;
    float lifetime;
};

static std::vector<ShotTracer> shotTracers;

static Vector3 ToVector3(const NetVec3& v) {
    return { v.x, v.y, v.z };
}

static NetVec3 ToNetVec3(const Vector3& v) {
    return { v.x, v.y, v.z };
}

static bool FindClosestWorldImpact(const Ray& shotRay, float range, Vector3& point) {
    bool found = false;
    float closestDistance = range;

    for (int i = 0; i < (int)MW.HitBox.size(); i++) {
        RayCollision hit = GetRayCollisionBox(shotRay, MW.HitBox[i]);
        if (hit.hit && hit.distance < closestDistance) {
            closestDistance = hit.distance;
            point = hit.point;
            found = true;
        }
    }

    for (int i = 0; i < (int)MB.HitBox.size(); i++) {
        RayCollision hit = GetRayCollisionBox(shotRay, MB.HitBox[i]);
        if (hit.hit && hit.distance < closestDistance) {
            closestDistance = hit.distance;
            point = hit.point;
            found = true;
        }
    }

    return found;
}

static void AddTracer(Vector3 start, Vector3 direction, float range) {
    Vector3 end = Vector3Add(start, Vector3Scale(Vector3Normalize(direction), range));
    shotTracers.push_back({ start, end, 0.08f });
}

static void DrawAndUpdateTracers(float dt) {
    for (int i = 0; i < (int)shotTracers.size();) {
        ShotTracer& tracer = shotTracers[i];
        float alpha = tracer.lifetime / 0.08f;
        DrawLine3D(tracer.start, tracer.end, Fade(YELLOW, alpha));

        tracer.lifetime -= dt;
        if (tracer.lifetime <= 0.0f) {
            shotTracers.erase(shotTracers.begin() + i);
        }
        else {
            i++;
        }
    }
}

Bullet::Bullet() {
    Damage = 45;
    Range = 120.0f;
    FireCooldown = 0.18f;
    cooldownTimer = 0.0f;
}

void Bullet::ShowBullet() {
    if (cooldownTimer > 0.0f) {
        cooldownTimer -= DT;
    }

    Vector3 shotDirection = Vector3Normalize(player_main.MouseMovement);
    ray.position = player_main.cam.position;
    ray.direction = shotDirection;

    for (const PlayerShootPacket& shot : netManager.pendingShots) {
        AddTracer(ToVector3(shot.origin), ToVector3(shot.direction), Range);
    }
    netManager.pendingShots.clear();

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && cooldownTimer <= 0.0f && player_main.Health > 0) {
        cooldownTimer = FireCooldown;

        netManager.SendPlayerShoot(ToNetVec3(ray.position), ToNetVec3(ray.direction), Damage);
        AddTracer(ray.position, ray.direction, Range);

        Vector3 hitPoint = { 0, 0, 0 };
        if (FindClosestWorldImpact(ray, Range, hitPoint)) {
            impactPoint = hitPoint;
            hasImpactPoint = true;
            impactTimer = 0.5f;
        }
    }

    if (hasImpactPoint) {
        DrawSphere(impactPoint, 0.12f, RED);
        impactTimer -= DT;
        if (impactTimer <= 0.0f) {
            hasImpactPoint = false;
        }
    }

    DrawAndUpdateTracers(DT);
}

void Bullet::HitBullet() {
    if (!netManager.wasHit) return;

    player_main.Health -= netManager.hitDamage;
    if (player_main.Health < 0) {
        player_main.Health = 0;
    }

    netManager.wasHit = false;
    netManager.hitDamage = 0;
    std::cout << "You were hit! HP: " << player_main.Health << "\n";
}
