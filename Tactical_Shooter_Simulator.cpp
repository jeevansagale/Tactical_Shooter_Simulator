// ---------- TACTICAL SHOOTER ----------
// --------------------------------------


// Libraries used
#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>
#include <string>

#include "Common.h"
#include "Assets.h"
#include "UI.h"
#include "Player.h"
#include "MainGame.h"

// MainCamera to decide which camera is active
Camera3D *ActiveCam = &CamUI.cam;


// ---------- Functions Declaration ----------
// Draw Menu
void Menu3D();      // 3D 
void Menu2D();      // 2D 


int main() {
	// Initializing game screen and basic functions
	InitWindow(SW, SH, "Test");
	InitAudioDevice();
	SetTargetFPS(60);
	SetExitKey(KEY_NULL);

	// Ininitialize camera's and loading assets
	P.InitializeCamera();
	CamUI.InitializeCam();
	LoadAssets();

	MW.GetHitBox();


	// Main Game Loop
	while (!WindowShouldClose()) {

		MP = GetMousePosition();    // Gets Mouse Position
		MD = GetMouseDelta();       // Gets Mouse Delta [How much mouse's x and y cords are changed from their previous postion ]
		DT = GetFrameTime();        // Frame per time [depends on PC/Laptop]
		
		// Which  Camera is active
		if (CamState == CAM_MENU || CurrentState == MENU) { ActiveCam = &CamUI.cam; UpdateCamera(ActiveCam, CAMERA_ORBITAL); }
		if (CamState == CAM_MAIN_GAME || CurrentState == START) {ActiveCam = &P.cam; UpdateCamera(ActiveCam, CAMERA_FIRST_PERSON); }

		// Update camera
		if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
			UpdateCamera(ActiveCam, CAMERA_FREE);
		}



		// ----- Drawing Begins -----
		BeginDrawing();
		ClearBackground(RAYWHITE);   // Background Color

		// BEGIN 3D MODE 
		BeginMode3D(*ActiveCam);

		// State: Menu
		if (CurrentState == MENU) {
			Menu3D();
		}

		// State: Start
		else if (CurrentState == START) {
			DisableCursor();
			DrawCube({ P.cam.position.x, P.cam.position.y, P.cam.position.z }, 1, 1, 1, BLACK);
			MF.Draw();
			MW.Draw();
			for (auto& box : MW.HitBox)
				DrawBoundingBox(box, GREEN);
		}

		
		// END 3D MODE
		EndMode3D();


		// DRAW 2D 
		//State: Menu
		if (CurrentState == MENU) {
			Menu2D();
		}

		else if (CurrentState == START) {
			DrawText(TextFormat("%1.f %1.f %1.f", P.cam.position.x, P.cam.position.y, P.cam.position.z), 10, 10, 30, BLACK);
			DrawText(TextFormat("%d", GetFPS()), 10, 30, 30, BLACK);
		}

		// State: Exit
		else if (CurrentState == EXIT) { break; }


		// END 2D DRAW
		EndDrawing();
	}


	// Closing assets, Music and Window
	UnloadAssets();
	CloseAudioDevice();
	CloseWindow();
	return 0;
}


// ---------- Functions Definiations ----------
void Menu3D() {
	F.Draw();
	B.Draw();
	W.Draw();
	OS.Draw();
	DrawModel(Char, { 1 ,1 ,1 }, 0.5f, WHITE);
}


void Menu2D() {
	T.MakeTitle("TACTICAL SHOOTER");
	MakeButton({ 100 , 400 , 300 , 70 }, "START", GREEN, DARKGREEN, LIME, START);
	MakeButton({ 100 , 500 , 300 , 70 }, "EXIT", RED, ORANGE, MAROON, EXIT);
}