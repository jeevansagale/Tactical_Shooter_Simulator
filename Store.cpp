#include "Store.h"

Store store;

Store::Store() :
	Attribute_Weapon{ {"Damage++" , "Speed++"} , {"" , ""} },
	Attribute_Defence{ {"Defence++" , "Durability++"} , {"" , ""} },
	Attribute_Speacial{ {"Health++" , "Special\nItem"} , {"" , ""} } 
{
	Show = false;
	Window = { 70.0f , 100.0f , 1800.0f , 800.0f };
	ItemBox = { 200.0f , 300.0f , 400.0f , 100.0f };
}

// ---------- DRAW THE MAIN WINDOW ---------
void Store::DrawWindow() {
	// Main Store Window
	DrawRectangleGradientH(Window.x, Window.y, Window.width, Window.height, color.LightDark , color.Dark); 

	// Upper header
	DrawRectangleGradientV(Window.x, Window.y, Window.width, 100, BLACK , LIGHTGRAY);

	// Upper Sub-Header
	DrawStoreMenuBox({ Window.x + 20  , Window.y + 10, 400, 80 }, Fade(GREEN, 0.5f), Fade(BLACK, 0.3f), Fade(RED, 0.4f), Fade(GRAY, 0.6f));
	DrawStoreMenuBox({ Window.x + 540 , Window.y + 10, 400, 80 }, Fade(GREEN, 0.5f), Fade(BLACK, 0.3f), Fade(RED, 0.4f), Fade(GRAY, 0.6f));
	DrawStoreMenuBox({ Window.x + 1060 , Window.y + 10, 400, 80 }, Fade(GREEN, 0.5f), Fade(BLACK, 0.3f), Fade(RED, 0.4f), Fade(GRAY, 0.6f));

	// Store Text
	DrawStoreText({ Window.x + 20 , Window.y + 10, 400, 80 } , "Weapons", BLACK, color.LightDark, RED);
	DrawStoreText({ Window.x + 540, Window.y + 10, 400, 80 } , "Defence", BLACK, color.LightDark, RED);
	DrawStoreText({ Window.x + 1060, Window.y + 10, 400, 80 } , "Special" , BLACK , color.LightDark , RED);

	// That Line between items and item info
	DrawRectangleGradientH(Window.x + 1200, Window.y + 100.0f , 50.0f, Window.height - 100.0f , Fade(color.MidDark , 1.0f), Fade(BLACK, 0.4f));
}


// ---------- DRAW INSIDE ITEMS IN THE WINDOW ----------
void Store::DrawInsideWindow() {
	// Drawing Item Boxes
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			DrawItemBox({ ItemBox.x + (600.0f * i) , ItemBox.y + (400.0f * j) , ItemBox.width , ItemBox.height }, Fade(color.MidGreen, 0.7f), Fade(DARKGREEN, 0.6f), LIGHTGRAY, color.Dark, Attribute_Weapon[i][j].c_str());
		}
	}
}


// ---------- HELPER FUNCTIONS TO DRAW WINDOW ----------
// -----------------------------------------------------
void Store::DrawStoreText(Rectangle Win , const char* Name , Color N , Color H , Color P) {
	Vector2 TxtSize = MeasureTextEx(Azonix, Name, 32, 2);   // Getting text's x,y pos

	// getting center location of text from button
	Vector2 Location = {
		Win.x + (Win.width - TxtSize.x) / 2 ,
		Win.y + (Win.height - TxtSize.y) / 2
	};

	// Checking collision from mouse and btn
	bool Check = CheckCollisionPointRec(MP, Win);


	// Checking states
	if (Check) { N = H; }
	if (Check && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) { N = P; }
	if (Check && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) { PlaySound(Click); N = P; }

	// ----- Drawing the Store Text -----
	DrawTextEx(Azonix, Name, Location, 32, 2, N);
}


void Store::DrawStoreMenuBox(Rectangle Win, Color c1, Color c2, Color c3, Color c4) {
	// Checking collision from mouse and btn
	bool Check = CheckCollisionPointRec(MP, Win);

	// Checking states
	if (Check) { c1 = c3; c2 = c4; }
	if (Check && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) { c1 = c4; c2 = c3; }
	if (Check && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) { PlaySound(Click); c2 = c4; c1 = c3; }

	DrawRectangleGradientH(Win.x, Win.y, Win.width, Win.height , c1, c2);
	DrawRectangleLinesEx(Win, 5.0f, c1);
	DrawRectangleLinesEx(Win, 2.5f, c2);
}


void Store::DrawItemBox(Rectangle Box, Color N, Color H, Color P , Color B, const char* Attribute) {
	bool Check = CheckCollisionPointRec(MP, Box);

	if (Check) { N = H; }
	if (Check && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) { N = P; }
	if (Check && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) { PlaySound(Click);  N = P; }

	Vector2 TextSize = MeasureTextEx(Azonix, Attribute, 32, 2);

	Vector2 Location = {
		Box.x + (Box.width - TextSize.x) / 2 ,
		Box.y + (Box.height - TextSize.y) / 2
	};
	
	DrawRectangleRec(Box, N);
	DrawTextEx(Azonix, Attribute, Location, 32, 2, BLACK);
	DrawRectangleLinesEx(Box, 2.5f , Fade(B , 0.6f));
}


// ---------- SHOW WINDOW ---------- 
void Store::ShowWindow(bool &show) {
	if (IsKeyPressed(KEY_P)) {
		show = !show;
		std::cout << "\033[1;91m \nP pressed\n \033[0m";
	}
	if (show) {
		DrawWindow();
		DrawInsideWindow();
	}
}