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
	DrawRectangleRounded(Btn, 16 , 8,  Fade(N , 0.6f));
	DrawRectangleRoundedLines(Btn, 32, 16, Fade(BLACK, 0.9f)); 
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

	if (DirX >= 150.0f) {
		DirX = 150.0f; 
		DirX = Clamp(DirX, -1100.0f, 200.0f);
		DirY += DT * Dir;
	}
	if (DirY >= 80.0f) { Dir = -1; }
	if (DirY <= 140.0f) { Dir = 1; }

	if (DirX >= 20.0f) { Alpha += DT; }
	if (Alpha >= 1.0f) { Alpha = 1.0f; Alpha = Clamp(Alpha, 0.0f, 1.0f); }

	//std::string T = std::string(Title);
	//DrawRectangleRounded({ (DirX - 100.0f) , (DirY - 20.0f) , 670.0f , 120.0f }, 0.3f, 30.0f, Fade(BLACK, 0.2f));
	//DrawRectangleRoundedLinesEx({ (DirX - 100.0f) , (DirY - 20.0f) , 670.0f , 120.0f }, 0.3f, 30.0f, 5.0f, Fade(WHITE, 0.1f));
	
	DrawTextEx(Doom, Title, Location, 128, 2, Fade(BLACK, Alpha));
	DrawTextEx(DoomOutline, Title, { Location.x + 2 , Location.y + 2 }, 128, 2, Fade(BLACK, Alpha));
	DrawTextureEx(PistolIcon, { Location.x - 100.0f , Location.y }, 0.0f, 0.2f, WHITE);
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


// --------------- Making character for the menu ---------------
UIChar uichar;

UIChar::UIChar() {
	AnimIndex = 0;
	AnimCount = 0;
	CurrentFrame = 0;
	Position = {4 , 1.5f , 4};
}

void UIChar::LoadAnimation() {
	
	model = LoadModel("Assets/characterbystyloov1.2/characterbystyloo/character_root.glb");
	Anim = LoadModelAnimations("Assets/characterbystyloov1.2/characterbystyloo/character_root.glb", &AnimCount);
}

void UIChar::DrawUICharacter() {
	CurrentFrame++;

	if (CurrentFrame >= Anim[AnimIndex].frameCount) { CurrentFrame = 0; }
	UpdateModelAnimation(model, Anim[AnimIndex], CurrentFrame);
	DrawModel(model, Position, 1.5f,  WHITE);

	if (IsKeyPressed(KEY_ZERO)) { AnimIndex = 0; }
	if (IsKeyPressed(KEY_ONE)) { AnimIndex = 1; }
	if (IsKeyPressed(KEY_TWO)) { AnimIndex = 2; }
	if (IsKeyPressed(KEY_THREE)) { AnimIndex = 3; }
	if (IsKeyPressed(KEY_FOUR)) { AnimIndex = 4; }
	if (IsKeyPressed(KEY_FIVE)) { AnimIndex = 5; }
	if (IsKeyPressed(KEY_SIX)) { AnimIndex = 6; }
	if (IsKeyPressed(KEY_SEVEN)) { AnimIndex = 7; }
	if (IsKeyPressed(KEY_EIGHT)) { AnimIndex = 8; }
	if (IsKeyPressed(KEY_NINE)) { AnimIndex = 9; }
	if (IsKeyPressed(KEY_KP_1)) { AnimIndex = 10; }
	if (IsKeyPressed(KEY_KP_2)) { AnimIndex = 11; }
	if (IsKeyPressed(KEY_KP_3)) { AnimIndex = 12; }
	if (IsKeyPressed(KEY_KP_4)) { AnimIndex = 13; }
	if (IsKeyPressed(KEY_KP_5)) { AnimIndex = 14; }
	if (IsKeyPressed(KEY_KP_6)) { AnimIndex = 15; }
}

UIChar::~UIChar() {
	std::cout << "\n\033[1;93m UI Character Unloded \033[0m\n\n";
	UnloadModel(model);
	UnloadModelAnimations(Anim, AnimCount);
}


void DrawCursor() {
	int cx = SW / 2;
	int cy = SH / 2;
	int size = 10;      // arm length
	int gap = 3;       // center gap
	int thickness = 2;

	DrawLineEx({ (float)(cx - size), (float)cy }, { (float)(cx - gap), (float)cy }, thickness, WHITE);  // left
	DrawLineEx({ (float)(cx + gap),  (float)cy }, { (float)(cx + size), (float)cy }, thickness, WHITE);  // right
	DrawLineEx({ (float)cx, (float)(cy - size) }, { (float)cx, (float)(cy - gap) }, thickness, WHITE);  // top
	DrawLineEx({ (float)cx, (float)(cy + gap) }, { (float)cx, (float)(cy + size) }, thickness, WHITE); // bottom
}