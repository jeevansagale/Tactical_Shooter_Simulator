#pragma once

#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>
#include <string>

#include "Common.h"
#include "Assets.h"
#include "MainGame.h"


class Player {
public:
	int Health;
	float Speed;

	Vector3 Pos;
	Camera3D cam;
	BoundingBox PlayerHitbox;

	int CurrentFrame;
	int AnimIndex;
	int AnimCount;

	Model model;
	ModelAnimation* Anim;
	Texture2D Tex;

	virtual void InitializeCamera() = 0;
	virtual void PlayerMovement() = 0;
	virtual void LoadAnimation() = 0;
	virtual void PlayerAnimation() = 0;
};


class Player_Main : public Player {
public:

	Player_Main();
	void InitializeCamera() override;
	void PlayerMovement() override;
	void LoadAnimation() override;
	void PlayerAnimation() override;

	~Player_Main();

};
extern Player_Main player_main;


class Player_Enemy : public Player {
public:

	Player_Enemy();
	void InitializeCamera() override;
	void PlayerMovement() override;
	void LoadAnimation() override;
	void PlayerAnimation() override;

};
extern Player_Enemy player_enemy;