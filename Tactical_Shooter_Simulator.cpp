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

// MainCamera to decide which camera is act-ive
Camera3D *ActiveCam = &CamUI.cam;


// ---------- Functions Declaration ----------
void ToggleCursor();
void LoadAssets();


// Draw Menu
void Menu3D();      // 3D 
void Menu2D();      // 2D 


// MainGame
void MainGame3D();
void MainGame2D();


int main() {
	// Initializing game screen and basic functions
	InitWindow(SW, SH, "TactMage Area");
	InitAudioDevice();
	SetTargetFPS(60);
	SetExitKey(KEY_NULL);

	// Ininitialize camera's and loading assets
	player_main.InitializeCamera();
	player_enemy.InitializeCamera();
	CamUI.InitializeCam();
	

	// Load Assets
	LoadAssets();
	player_main.LoadAnimation();


	// Getting Hitboxes 
	MW.GetHitBox();
	MB.GetHitBox();


	// Main Game Loop
	while (!WindowShouldClose()) {

		MP = GetMousePosition();    // Gets Mouse Position
		MD = GetMouseDelta();       // Gets Mouse Delta [How much mouse's x and y cords are changed from their previous postion ]
		DT = GetFrameTime();        // Frame per time [depends on PC/Laptop]
		

		// Which  Camera is active
		if (CamState == CAM_MENU || CurrentState == MENU) { ActiveCam = &CamUI.cam; UpdateCamera(ActiveCam, CAMERA_ORBITAL); }
		if (CamState == CAM_MAIN_GAME || CurrentState == START) {ActiveCam = &player_main.cam; UpdateCamera(ActiveCam, CAMERA_FIRST_PERSON); }


		// Update camera
		if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
			UpdateCamera(ActiveCam, CAMERA_FREE);
		}


		player_main.PlayerAnimation();

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
			MainGame3D();
			DrawBoundingBox(player_main.PlayerHitbox, RED);
			player_main.PlayerMovement();
		}

		
		// END 3D MODE
		EndMode3D();


		// DRAW 2D 
		//State: Menu
		if (CurrentState == MENU) {
			Menu2D();
		}

		else if (CurrentState == START) {
			MainGame2D();
		}

		// State: Exit
		else if (CurrentState == EXIT) { break; }


		// END 2D DRAW
		EndDrawing();
	}


	// Closing window and audio device
	CloseAudioDevice();
	CloseWindow();
	return 0;
}


// ---------- Functions Definiations ----------
void ToggleCursor() {
	static bool IsCursorON = false;

	if (IsKeyPressed(KEY_T)) {
		IsCursorON = !IsCursorON;
		if (IsCursorON) { DisableCursor(); }
		else { EnableCursor(); }
	}
}


void LoadAssets() {
	character.Load();
	furniture.Load();
	objects.Load();
	images.Load();
	soundmusic.Load();
	font.Load();
}


void Menu3D() {
	F.Draw();
	B.Draw();
	W.Draw();
	OS.Draw();
}


void Menu2D() {
	T.MakeTitle("TACTICAL SHOOTER");
	MakeButton({ 100 , 400 , 300 , 70 }, "START", GREEN, DARKGREEN, LIME, START);
	MakeButton({ 100 , 500 , 300 , 70 }, "EXIT", RED, ORANGE, MAROON, EXIT);
}


void MainGame3D() {
	ToggleCursor();
	MF.Draw();
	MW.Draw();
	MB.Draw();
	MT.Draw();
	MWT.Draw();
	MST.Draw();
	MC.Draw();
	MBR.Draw();
	for (auto& box : MW.HitBox) { DrawBoundingBox(box, GREEN); }
	for (auto& box : MB.HitBox) { DrawBoundingBox(box, BLUE); }
}


void MainGame2D() {
	DrawText(TextFormat("%1.f %1.f %1.f", player_main.cam.position.x, player_main.cam.position.y, player_main.cam.position.z), 10, 10, 30, BLACK);
	DrawText(TextFormat("%d", GetFPS()), 10, 30, 30, BLACK);
}