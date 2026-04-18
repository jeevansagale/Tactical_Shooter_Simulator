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


// ------ Color -------
Color_Palette color;

Color_Palette::Color_Palette() {
	LightDark = { 77, 77, 77 , 255};
	LightDark2 = { 60, 60, 60 , 255};
	MidDark = { 30, 30, 30 , 255};
	MidDark2 = { 17, 17, 17 , 255};
	Dark = { 0 , 0 , 0 , 255};

	Red = { 144, 0, 0 };
	LightRed = { 238, 36, 0 , 255};
	MidRed = { 255, 176, 156 , 255};
	FaintRed = { 251, 217, 211 , 255};
	FaintRed2 = { 255, 239, 234 , 255};

	FaintGreen = { 236, 236, 163 , 255};
	LightGreen = { 181, 229, 80 , 255};
	MidGreen = { 171, 195, 47 , 255};
	Green = { 128, 156, 19 , 255};
	DarkGreen = { 96, 124, 60 , 255};
}
