#pragma once

#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>
#include <string>

#define SW 1920
#define SH 960

// ---------- 2D Vector ----------
extern Vector2 MP;        // Get Mouse Position
extern Vector2 MD;        // Get Mouse Delta


// gets frame per time
extern float DT;


// Game States
enum State {
	MENU,
	START,
	EXIT
};
extern State CurrentState;


// Camera States
enum CameraState {
	CAM_MENU,
	CAM_PLAYER,
	CAM_MAIN_GAME
};
extern CameraState CamState;

