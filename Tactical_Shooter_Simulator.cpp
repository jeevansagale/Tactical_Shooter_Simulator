// ---------- TACTICAL SHOOTER ----------
// --------------------------------------

// Libraries used
#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>
#include <string>

// Custom Libraries
#include "Common.h"
#include "Assets.h"
#include "UI.h"
#include "Player.h"
#include "MainGame.h"
#include "Store.h"
#include "ShootSystem.h"
#include "ENet.h"


// Define constants
#define SkyColor {160 , 217 , 239}

// MainCamera to decide which camera is act-ive
Camera3D *ActiveCam = &CamUI.cam;


// ---------- Functions Declaration ----------
void ToggleCursor();
void LoadAssets();
void InitializeCamera();
void GetHitBoxes();


// Draw Menu
void Menu3D();      // 3D 
void Menu2D();      // 2D 


// MainGame
void MainGame3D(); 
void MainGame2D();


// Variable for showing window
bool Show = false;
bool showChar = false;

int main() {
	// Initializing game screen, Audio device, FPS, and Exit key
	InitWindow(SW, SH, "TactMage Area");
	InitAudioDevice();
	SetTargetFPS(60);
	SetExitKey(KEY_NULL);


	// Initialize networking
	if (!netManager.Initialize()) {
		CloseWindow();
		return -1;
	}

	// Initialize camera's and loading assets
	InitializeCamera();

	// Load Assets
	LoadAssets();


	// Getting Hitboxes 
	GetHitBoxes();


	// Main Game Loop
	while (!WindowShouldClose()) {


		// Poll networking events
		netManager.Update();

		// Simple Host/Join hotkeys
		if (IsKeyPressed(KEY_H) && !netManager.IsConnected()) {
			netManager.StartServer(7777);
		}
		if (IsKeyPressed(KEY_J) && !netManager.IsConnected()) {
			netManager.ConnectToServer("10.147.19.223", 7777);
		}

		MP = GetMousePosition();    // Gets Mouse Position
		MD = GetMouseDelta();       // Gets Mouse Delta [How much mouse's x and y cords are changed from their previous position]
		DT = GetFrameTime();        // Frame per time [depends on PC/Laptop]
		

		// Which  Camera is active
		if (CurrentState == MENU) { ActiveCam = &CamUI.cam; UpdateCamera(ActiveCam, CAMERA_ORBITAL); }
		if (CurrentState == START) {ActiveCam = &player_main.cam; UpdateCamera(ActiveCam, CAMERA_CUSTOM); }


		// Update camera
		if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
			ActiveCam = &CamUI.cam;
			UpdateCamera(ActiveCam, CAMERA_FREE);
		}

		// Get Player Camera Position and Begin Animation Loop
		player_main.CameraPos();
		player_main.PlayerAnimation();


		// ----- Drawing Begins -----
		BeginDrawing();
		ClearBackground(SkyColor);   // Background Color


		// BEGIN 3D MODE 
		BeginMode3D(*ActiveCam);


		// State: Menu
		if (CurrentState == MENU) {
			Menu3D();
		}


		// State: Start
		else if (CurrentState == START) {
			MainGame3D();	
		}

		
		// END 3D MODE
		EndMode3D();


		// ----- DRAW 2D -----
		// -------------------
		// State: Menu
		if (CurrentState == MENU) {
			Menu2D();
		}

		// State: Start
		else if (CurrentState == START) {
			MainGame2D();
		}

		// State: Exit
		else if (CurrentState == EXIT) { break; }

		// Getting Player Position for further Movement
		player_main.cam.position = Vector3Add(player_main.Pos, { 0.0f , 2.0f , 0.0f });
		player_main.cam.target = Vector3Add(player_main.cam.position, player_main.MouseMovement);

		// END 2D DRAW
		EndDrawing();
	}


	// Closing window and audio device and server
	netManager.Deinitialize();

	CloseAudioDevice();
	CloseWindow();
	return 0;
}


// ---------- Functions Definitions ----------
// Toggle Mouse 
void ToggleCursor() {
	static bool IsCursorON = false;

	// When Key T is pressed
	if (IsKeyPressed(KEY_T)) {
		IsCursorON = !IsCursorON;  // Toggle Condition
		if (IsCursorON) { DisableCursor();}
		else { EnableCursor(); }
	}
}


// Load Different Assets
void LoadAssets() {
	// Loading 
	character.Load();   // Character
	furniture.Load();   // Furniture [Tables , Boxes , Cans , Targets , Barrels]
	objects.Load();     // Objects [Floors and Walls]
	images.Load();      // Images
	soundmusic.Load();  // Sound [click]
	font.Load();        // Fonts
	icon.Load();        // Icons

	player_main.LoadAnimation();  // Player Animation
	store.LoadWindowAssets();     // StoreWindow Assets
	uichar.LoadAnimation();
}


// Initializes Camera's
void InitializeCamera() {
	player_main.InitializeCamera();    // Player's
	player_enemy.InitializeCamera();   // Enemy's
	CamUI.InitializeCam();             // UI's
}


// Getting hitboxes
void GetHitBoxes() {
	MW.GetHitBox();
	MB.GetHitBox();
}


// Drawing the MENU: 3D
void Menu3D() {
	ToggleCursor();    // Toggle Cursor
	if (IsKeyPressed(KEY_Y)) { showChar = !showChar; }
	if (showChar) { uichar.DrawUICharacter(); }
	F.Draw();
	B.Draw();
	W.Draw();
	OS.Draw();
}


// Drawing the MENU: 2D
void Menu2D() {
	DrawRectangleGradientEx({ 0 , 0 , SW , SH }, Fade(color.UI_BACKGROUND, 0.3f), Fade(color.UI_SECONDARY, 0.2f), Fade(color.UI_SECONDARY, 0.2f), Fade(color.UI_BACKGROUND , 0.3f));

	DrawRectangleRounded({ 60, 100, 660, 600 } , 0.1f , 30.0f ,  Fade(color.UI_PANEL_GLASS, 0.7f));
	DrawRectangleRoundedLinesEx({ 60 , 100 , 660 , 600 }, 0.1f, 30.0f, 5.f , Fade(color.TACTICAL_CYAN, 0.5f));

	T.MakeTitle("TACTICAL SHOOTER");
	MakeButton({ 100 , 300 , 270 , 70 }, "START", color.START_TOP, color.START_BOTTOM, LIME, START);
	MakeButton({ 100 , 400 , 270 , 70 }, "CREDITS", color.CREDITS_TOP, color.CREDITS_BOTTOM, GOLD, CREDITS);
	MakeButton({ 100 , 500 , 270 , 70 }, "EXIT", color.EXIT_TOP, color.EXIT_BOTTOM, MAROON, EXIT);

	DrawTextureEx(PlayIcon, { 110, 310 }, 0 , 0.09f, WHITE);
	DrawTextureEx(ExitIcon, { 110, 510 }, 0 , 0.09f, WHITE);

	DrawText(TextFormat("%.1f %.1f", MP.x, MP.y), 30, 10, 30, RED);
}


// Main Game: 3D
void MainGame3D() {
	ToggleCursor();    // Toggle Cursor
	// ----- Draw -----
	MF.Draw();     // Floors
	MW.Draw();     // Walls
	MB.Draw();     // Boxes
	MT.Draw();     // Tables
	MWT.Draw();    // Wall-Target 
	MST.Draw();    // Standing Target
	MC.Draw();     // Cans
	MBR.Draw();    // Barrels

	player_main.PlayerMovement();   // Player movement
	DrawBoundingBox(player_main.PlayerHitbox, GREEN);
	bullet.ShowBullet();
	bullet.HitBullet();

	if (IsKeyPressed(KEY_ESCAPE)) CurrentState = MENU;


    // Send my data to the network
	NetVec3 myPos = { player_main.Pos.x, player_main.Pos.y, player_main.Pos.z };
	netManager.SendPlayerUpdate(myPos, player_main.pitch, player_main.yaw, player_main.Health, player_main.AnimIndex);

	// FIX: Only CLIENTS should pull health from the network. 
	// The Server's 'player_main.Health' is already the source of truth.
	if (!netManager.IsServer() && netManager.IsConnected()) {
		// If we are a client, the server will have sent our peerID's updated health in the map
		if (netManager.otherPlayers.count(netManager.localPeerID)) {
			player_main.Health = netManager.otherPlayers[netManager.localPeerID].health;
		}
	}

	// Draw other network players
	for (auto& pair : netManager.otherPlayers) {
		PlayerUpdatePacket& p = pair.second;
		
		// Ensure animation index is valid before applying it
		if (p.animIndex >= 0 && p.animIndex < player_main.AnimCount) {
			// Apply the networked player's animation to the shared model
			UpdateModelAnimation(player_main.model, player_main.Anim[p.animIndex], player_main.CurrentFrame);
		}

		// Draw the 3D model using the network position and yaw
		Vector3 otherPos = { p.position.x, p.position.y, p.position.z };
		DrawModelEx(player_main.model, Vector3Subtract(otherPos, { 0, 1.5f, 0 }), { 0, 1, 0 }, p.yaw, { 1, 1, 1 }, WHITE);
	}
}


// Main Game: 2D
void MainGame2D() {
	store.ShowWindow(Show);    // Store Window 
	DrawText(TextFormat("%1.f %1.f %1.f", player_main.cam.position.x, player_main.cam.position.y, player_main.cam.position.z), 10, 30, 50, BLACK);   // Player co-ordiantes
	DrawText(TextFormat("%d", GetFPS()), 10, 90, 50, BLACK);    // FPS Rate
	DrawText(TextFormat("%d", player_main.Health), 10, 150, 50, BLACK);    // FPS Rate

	if (player_main.Health <= 0) {
		// Basic Respawn Logic
		player_main.Pos = { 1.0f, 2.5f, 1.0f };
		player_main.Health = 100;
		std::cout << "RESPAWNED" << std::endl;
	}

	DrawCursor();
}