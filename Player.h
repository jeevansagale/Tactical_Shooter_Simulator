#pragma once

#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>
#include <string>

#include "Common.h"
#include "Assets.h"
#include "MainGame.h"


// ---------- Base class: Player ----------
class Player {
public:
	// ----- Stats -----
	int Health;    // health
	float Speed;   // speed

	// Player mouse X and Y movement
	float pitch;  
	float yaw;

	
	Vector3 Pos;    // Position 
	Camera3D cam;   // Camera following 
	Vector3 MouseMovement;    // MouseMovement [from one pos to another]


	Vector3 Forward;  // Player moving forward movement
	Vector3 Right;    // Following the dir of movement

	BoundingBox PlayerHitbox;   // Hitbox

	// Animation 
	int CurrentFrame;
	int AnimIndex;
	int AnimCount;

	Model model;
	ModelAnimation* Anim;
	Texture2D Tex;

	virtual void InitializeCamera() = 0;
	virtual void CameraPos() = 0;
	virtual void PlayerMovement() = 0;
	virtual void LoadAnimation() = 0;
	virtual void PlayerAnimation() = 0;
};


// ---------- Main Player ----------
class Player_Main : public Player {
public:

	Player_Main();
	void InitializeCamera() override;
	void CameraPos() override;
	void PlayerMovement() override;
	void LoadAnimation() override;
	void PlayerAnimation() override;

	~Player_Main();

};
extern Player_Main player_main;


// ---------- Enemy player ----------
class Player_Enemy : public Player {
public:

	Player_Enemy();
	void InitializeCamera() override;
	void CameraPos() override;
	void PlayerMovement() override;
	void LoadAnimation() override;
	void PlayerAnimation() override;
};
extern Player_Enemy player_enemy;