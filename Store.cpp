#include "Store.h"

Store store;

int Index_Store = 1;
int Index_Item = 0;

Store::Store() :
	Attribute_Weapon{ {"Damage++" , "Speed++"} , {"" , ""} },
	Attribute_Defence{ {"Defence++" , "Durability++"} , {"" , ""} },
	Attribute_Speacial{ {"Health++" , "Special\nItem"} , {"" , ""} },

	C1{ "Increases Bullet \ndamage to \nother players" , "Increases \nSpeed giving \nyou advantage of\n runnning away" , "Stil \nWorking" , "Still\n Working" },
	C2{ "Increases Defence\n and \nreducing damage" , "Increases Armour \nDurability" , "Still Working" , "Still Working" },
    C3{ "Increases Health" , "Gives you a \nspecial item \n:)" , "Still Working" , "Still Working" },
	Tex1{ 0 , 0 , 0 , 0},
	Tex2{ 0 , 0 , 0 , 0},
	Tex3{ 0 , 0 , 0 , 0}
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
	DrawStoreMenuBox({ Window.x + 20  , Window.y + 10, 400, 80 }, Fade(GREEN, 0.5f), Fade(BLACK, 0.3f), Fade(RED, 0.4f), Fade(GRAY, 0.6f) , 1);
	DrawStoreMenuBox({ Window.x + 540 , Window.y + 10, 400, 80 }, Fade(GREEN, 0.5f), Fade(BLACK, 0.3f), Fade(RED, 0.4f), Fade(GRAY, 0.6f) , 2);
	DrawStoreMenuBox({ Window.x + 1060, Window.y + 10, 400, 80 }, Fade(GREEN, 0.5f), Fade(BLACK, 0.3f), Fade(RED, 0.4f), Fade(GRAY, 0.6f) , 3);

	// Store Text
	DrawStoreText({ Window.x + 20 , Window.y + 10, 400, 80 } , "Weapons", BLACK, color.LightDark, RED);
	DrawStoreText({ Window.x + 540, Window.y + 10, 400, 80 } , "Defence", BLACK, color.LightDark, RED);
	DrawStoreText({ Window.x + 1060, Window.y + 10, 400, 80 } , "Special" , BLACK , color.LightDark , RED);

	// That Line between items and item info
	DrawRectangleGradientH(Window.x + 1200, Window.y + 100.0f , 50.0f, Window.height - 100.0f , Fade(color.MidDark , 1.0f), Fade(BLACK, 0.4f));

	// ----- Draw Small Info Window ----- 
	DrawRectangleGradientH(Window.x + 1250.0f , Window.y + 150.0f , 500 , 600 , WHITE, RAYWHITE);
}


// ---------- DRAW INSIDE ITEMS IN THE WINDOW ----------
void Store::DrawInsideWindow(int index , std::string C[4], Texture2D Tex[4]) {
	// Draw Selected Item Attribute
	if (Index_Store == index) {
		for (int i = 0; i < 4; i++) {
			DrawWindowItemSelection(i + 1, C[i] , Tex[i]);
		}
	}

	// Draw Selected Window
	DrawWindowSelection(1, Attribute_Weapon , color.FaintRed , Fade(RED , 0.4f) , Fade(color.MidRed , 0.5f) , BLACK);
	DrawWindowSelection(2, Attribute_Defence , Fade(BLUE , 0.4f) , Fade(SKYBLUE , 0.7f) , Fade(DARKBLUE , 0.4f) , BLACK);
	DrawWindowSelection(3, Attribute_Speacial , Fade(color.LightGreen , 0.7f) , color.Green , Fade(DARKGREEN , 0.5f) , BLACK);
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
	DrawTextEx(Azonix, Name, Location, 32, 2, BLACK);
}


void Store::DrawStoreMenuBox(Rectangle Win, Color c1, Color c2, Color c3, Color c4 , int index) {
	// Checking collision from mouse and btn
	bool Check = CheckCollisionPointRec(MP, Win);

	// Checking states
	if (Check && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        PlaySound(Click);
        Index_Store = index;
		Index_Item = 0;
    }

    // State priority
    if (Index_Store == index) {
        c1 = c4;
        c2 = c3;
    }
    else if (Check && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        c1 = c4;
        c2 = c3;
    }
    else if (Check) {
        c1 = c3;
        c2 = c4;
    }

	DrawRectangleGradientH(Win.x, Win.y, Win.width, Win.height , c1, c2);
	DrawRectangleLinesEx(Win, 5.0f, c1);
	DrawRectangleLinesEx(Win, 2.5f, c2);
}


void Store::DrawItemBox(Rectangle Box, Color N, Color H, Color P , Color B, const char* Attribute , int index) {
	bool Check = CheckCollisionPointRec(MP, Box);

	if (Check) { N = H; }
	if (Check && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) { N = P; }
	if (Check && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) { PlaySound(Click);  N = P; Index_Item = index; }

	Vector2 TextSize = MeasureTextEx(Azonix, Attribute, 32, 2);

	Vector2 Location = {
		Box.x + (Box.width - TextSize.x) / 2 ,
		Box.y + (Box.height - TextSize.y) / 2
	};
	
	DrawRectangleRec(Box, N);
	DrawTextEx(Azonix, Attribute, Location, 32, 2, BLACK);
	DrawRectangleLinesEx(Box, 2.5f , Fade(B , 0.6f));
}


void Store::DrawWindowSelection(int index, std::string S[2][2] , Color c1 , Color c2 , Color c3 , Color c4) {
	// Drawing Item Boxes
	if (Index_Store == index) {
		DrawItemBox({ ItemBox.x + (600.0f * 0) , ItemBox.y + (400.0f * 0) , ItemBox.width , ItemBox.height }, c1 , c2 , c3 , c4 , S[0][0].c_str(), 1);
		DrawItemBox({ ItemBox.x + (600.0f * 0) , ItemBox.y + (400.0f * 1) , ItemBox.width , ItemBox.height }, c1 , c2 , c3 , c4 , S[0][1].c_str(), 2);
		DrawItemBox({ ItemBox.x + (600.0f * 1) , ItemBox.y + (400.0f * 0) , ItemBox.width , ItemBox.height }, c1 , c2 , c3 , c4 , S[1][0].c_str(), 3);
		DrawItemBox({ ItemBox.x + (600.0f * 1) , ItemBox.y + (400.0f * 1) , ItemBox.width , ItemBox.height }, c1 , c2 , c3 , c4 , S[1][1].c_str(), 4);
	}
	
}


void Store::DrawWindowItemSelection(int index , std::string Context, Texture2D Tex) {
	Rectangle Win = { Window.x + 1250.0f , Window.y + 150.0f , 500 , 600 };
	Vector2 TxtSize = MeasureTextEx(Azonix, Context.c_str(), 32, 2);   // Getting text's x,y pos

	// getting center location of text from button
	Vector2 Location = {
		Win.x + (Win.width - TxtSize.x) / 2 ,
		Win.y + (Win.height - TxtSize.y) / 2
	};

	if (Index_Item == index) {
		// ----- Drawing the Store Text -----
		DrawTextEx(Azonix, Context.c_str(), Location, 32, 2, BLACK);
		DrawTextureEx(Tex, { Win.x + 50.0f  , Win.y }, 0.0f, 0.3f, WHITE);
	}
}


// ---------- SHOW WINDOW ---------- 
void Store::ShowWindow(bool &show) {
	if (IsKeyPressed(KEY_P)) {
		show = !show;
		std::cout << "\033[1;91m \nP pressed\n \033[0m";
	}
	if (show) {
		DrawWindow();
		if (Index_Store == 1) DrawInsideWindow(1, C1 , Tex1); 
		else if (Index_Store == 2) DrawInsideWindow(2, C2 , Tex2);
		else if (Index_Store == 3) DrawInsideWindow(3, C3 , Tex3);
	}
}


// --------- LOAD WINDOW ASSETS ---------
void Store::LoadWindowAssets() {
	Tex1[0] = DamageIcon;
	Tex1[1] = SpeedIcon;
	Tex1[2] = { 0 };
	Tex1[3] = { 0 };

	Tex2[0] = DefenceIcon;
	Tex2[1] = SheildIcon;
	Tex2[2] = ArmourIcon;
	Tex2[3] = { 0 };

	Tex3[0] = HealthIcon;
	Tex3[1] = ArmourIcon;
	Tex3[2] = { 0 };
	Tex3[3] = { 0 };
}