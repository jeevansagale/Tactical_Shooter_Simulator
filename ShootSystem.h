#pragma once

#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>

#include "Player.h"
#include "Common.h"
#include "MainGame.h"
#include "Store.h"
#include "ENet.h"

class Bullet {
public:
    int   Damage;
    float Range;
    float FireCooldown;
    float cooldownTimer;
    Ray   ray;

    Vector3 impactPoint = { 0, 0, 0 };
    bool    hasImpactPoint = false;
    float   impactTimer = 0.0f;

    Bullet();
    void ShowBullet();
    void HitBullet();
};

extern Bullet bullet;
