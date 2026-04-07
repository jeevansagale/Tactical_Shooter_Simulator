#include "UI.h"

// ---------- Class Declaration ---------------
CameraUI CamUI;
Title T;
Floor F;
Wall W ;
Barrel B ;
Character CHAR;
OtherStuff OS;


// --------------- MENU CAMERA ---------------
CameraUI::CameraUI() {
	cam = { 0 };
}


// Initializing Camera 
void CameraUI::InitializeCam() {
	cam.fovy = 45.0f;             // how far is the camera
	cam.up = { 0 , 1 , 0 };       // Y - axis look
	cam.position = { 10.0f  , 9.0f , 16.0f };  // Camera position
	cam.target = { 1 , 1 , 1 };   // Camera's target
	cam.projection = CAMERA_PERSPECTIVE;  // Perspective of camera
}


// --------------- UI FUNCTIONS ---------------
// --------------------------------------------

// ----- Make Buttons -----
void MakeButton(Rectangle Btn, const char* BtnName, Color N, Color H, Color P, State NewState) {
	Vector2 TxtSize = MeasureTextEx(Azonix, BtnName, 32, 2);   // Getting text's x,y pos
	
	// getting center location of text from button
	Vector2 Location = { 
		Btn.x + (Btn.width - TxtSize.x) / 2 ,
		Btn.y + (Btn.height - TxtSize.y) / 2
	};

	// Checking collision from mouse and btn
	bool Check = CheckCollisionPointRec(MP, Btn);


	// Checking states
	if (Check) { N = H; }
	if (Check && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) { N = P; }
	if (Check && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) { PlaySound(Click); N = P; CurrentState = NewState; }

	// ----- Drawing the button -----
	DrawRectangleRounded(Btn, 16 , 8,  Fade(N , 0.4f));
	DrawRectangleRoundedLines(Btn, 32, 16, Fade(BLACK, 0.5f)); 
	DrawTextEx(Azonix, BtnName, Location , 32, 2, BLACK);
}


// ----- TITLE ANIMATION -----
Title::Title() {
	Alpha = 0.0f;
	DirX = -600;
	DirY = 100.0f;
	Dir = 1;
}


void Title::MakeTitle(const char* Title) {
	DirX += DT * 300;

	Vector2 Location = { DirX , DirY };

	if (DirX >= 100.0f) {
		DirX = 100.0f; 
		DirX = Clamp(DirX, -1100.0f, 100.0f);
		DirY += DT * Dir;
	}
	if (DirY >= 70.0f) { Dir = -1; }
	if (DirY <= 130.0f) { Dir = 1; }

	if (DirX >= 20.0f) { Alpha += DT; }
	if (Alpha >= 1.0f) { Alpha = 1.0f; Alpha = Clamp(Alpha, 0.0f, 1.0f); }

	DrawTextEx(Doom, Title, Location, 128, 2, Fade(BLACK, Alpha));
	DrawTextEx(DoomOutline, Title, { Location.x + 2 , Location.y + 2 }, 128, 2, Fade(BLACK, Alpha));
}


// --------------- Making Menu's Background ---------------
Floor::Floor() {
	TileSize = 4;
	Location = {};
}
void Floor::Draw() {
	for (int i = -5; i < 5; i++) {
		for (int j = -5; j < 5; j++) {
			DrawModel(FloorA, { (float)(4 * i + TileSize) , 1 , (float)(4 * j + TileSize) }, 1, WHITE);
		}
	}
}


Barrel::Barrel() {
	TileSize = 4;
	Location = {
		 { 5 , 2.0f , 5 },
		 { -5 , 2.0f , 5 },
		 { 12 , 2.0f , 5 },
		 { 5 , 2.0f , 2 },
		 { -8 , 2.0f , 15},
		 { -16 , 2.0f , -5 }
	};
}
void Barrel::Draw() {
	DrawModel(BarrelA, Location[0], 1, WHITE);
	DrawModel(BarrelA, Location[1], 1, WHITE);
	DrawModel(BarrelB, Location[2], 1, WHITE);
	DrawModel(BarrelB, Location[3], 1, WHITE);
	DrawModel(BarrelC, Location[4], 1, WHITE);
	DrawModel(BarrelC, Location[5], 1, WHITE);
}


Wall::Wall() {
	TileSize = 4;
	Location = {};
}
void Wall::Draw() {
	for (int i = -5; i < 5; i++) {
		DrawModel(WallA, { (float)(4 * i + TileSize) , 1.5f , (float)22 }, 1, WHITE);
		DrawModelEx(WallA, { (float)22, 1.5f , (float)(4 * i + TileSize) }, { 0 , 1.5f , 0 }, 90, { 1 , 1.0f , 1 }, WHITE);
		DrawModelEx(WallA, { -(float)18, 1.5f , (float)(4 * i + TileSize) }, { 0 , 1.5f , 0 }, 90, { 1 , 1.0f , 1 }, WHITE);
		DrawModel(WallA, { (float)(4 * i + TileSize) , 1.5f , -(float)18 }, 1, WHITE);
	}
}


OtherStuff::OtherStuff() {
	TileSize = 4;
	Location = {

		// ----- Boxes -----
		{ 15 , 2.0f , 15 },
		{ 15 , 2.0f , -15 },

		// ----- Tableware -----
		{ -10 , 2.0f , -15 },
		{ 8, 2.0f, -15 },
		{ -10, 2.0f, 10 },

		// ----- Target dummies -----
		{ 4 , 3.5f , 21 },
		{ 0, 3.0f, -17 }
	};
}
void OtherStuff::Draw() {
	DrawModel(BoxA, Location[0], 10, WHITE);
	DrawModel(BoxB, Location[1], 10, WHITE);

	DrawModel(TableDecoA, Location[2], 2, WHITE);
	DrawModel(TarGetStand, Location[3], 2, WHITE);
	DrawModel(Table, Location[4], 2, WHITE);

	DrawModel(Target, Location[5], 1, WHITE);
	DrawModel(Target, Location[6], 1, WHITE);
}