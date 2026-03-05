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
	Vector3 Pos;
	Camera3D cam;

	Player();
	void InitializeCamera();
};
extern Player P;
