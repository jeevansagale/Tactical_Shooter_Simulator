#include "Player.h"


Player P;

Player::Player() {
	Pos = { 1 ,1 ,1 };
	cam = { 0 };
}

void Player::InitializeCamera() {
	cam.fovy = 45.0f;
	cam.projection = CAMERA_PERSPECTIVE;
	cam.up = { 0, 1 , 0 };
	cam.position = { 5 , 5 , 5 };
	cam.target = {1 , 1 , 1};
}
