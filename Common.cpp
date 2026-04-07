#include "Common.h"

// ---------- 2D Vector ----------
Vector2 MP;        // Get Mouse Position
Vector2 MD;        // Get Mouse Delta


// gets frame per time
float DT;


// Game States
State CurrentState = MENU;


// Camera State;
CameraState CamState = CAM_MENU;
