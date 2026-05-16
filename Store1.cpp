#include "Store.h"	// Includes Store class declarations and dependencies

Store store;	// Creates one global store object

// Current selected store category
// 1 = Weapons
// 2 = Defence
// 3 = Special
int Index_Store = 1;

int Index_Item = 0;  // Current selected item inside category


// Returns color based on item rarity
Color Store::GetRarityColor(int rarity) {
	switch (rarity) {
	case 0: return color.RARITY_COMMON;
	case 1: return color.RARITY_RARE;
	case 2: return color.RARITY_EPIC;
	case 3: return color.RARITY_LEGENDARY;
	default: return color.RARITY_COMMON;
	}
}

// Initializes all store data when Store object is created
Store::Store() :

	//Weapon Attributes, Rarities and Prices
	Attribute_Weapon{ "Damage++", "Speed++", "Fire Rate++", "Critical Hit++", "Ammo Capacity++" },
	Rarity_Weapon{ 0, 1, 1, 2, 0 },
	Price_Weapon{ 1500, 2000, 2500, 3500, 1200 },

	//Defence Attributes, Rarities and Prices
	Attribute_Defence{ "Armour++", "Durability++", "Shield++", "Damage Reduction++", "Regeneration++" },
	Rarity_Defence{ 0, 0, 1, 2, 3 },
	Price_Defence{ 1200, 1000, 2800, 4000, 5000 },

	//Special Attributes, Rarities and Prices
	Attribute_Special{ "Health++", "Anti Gravity Boots", "Invisibility", "Dash Ability", "Energy Boost" },
	Rarity_Special{ 0, 2, 3, 2, 1 },
	Price_Special{ 1000, 4500, 7500, 3000, 1800 },

	// Descriptions for each item - weapon , defence and special
	C1{ "Increases Bullet damage\nto other players.", "Increases Speed giving\nyou advantage of running.", "Increases your weapon's\nrate of fire.", "Higher chance to land\ncritical hits.", "Increases your maximum\nammo capacity." },
	C2{ "Increases Defence and\nreduces incoming damage.", "Increases Armour\nDurability.", "Adds an energy shield\nthat recharges.", "Passively reduces all\nincoming damage by 15%.", "Slowly regenerates health\nover time." },
	C3{ "Increases your maximum\nHealth points.", "Allows you to jump higher\nand fall slower.", "Become temporarily invisible\nto enemies.", "Quickly dash in any\ndirection to avoid fire.", "Increases energy regeneration\nfor abilities." },
	
	// Initializes all textures as empty
	Tex1{ {0}, {0}, {0}, {0}, {0} },
	Tex2{ {0}, {0}, {0}, {0}, {0} },
	Tex3{ {0}, {0}, {0}, {0}, {0} }
{
	Show = false;	// Store initially hidden

	Window = { 70.0f , 100.0f , 1800.0f , 800.0f };		// Main store window size and position

	ItemBox = { 200.0f , 300.0f , 400.0f , 100.0f };	// Base item box size
}



// ---------- DRAW THE MAIN WINDOW ---------
void Store::DrawWindow() {
	// Main Store Window with dark gamer background
	DrawRectangleGradientH(Window.x, Window.y, Window.width, Window.height, color.CARD_BG_DARK, color.CARD_BG_LIGHT);

	// Optional scanline effect overlay
	int scanlineY = (int)(GetTime() * 100.0) % (int)Window.height;
	DrawRectangle(Window.x, Window.y + scanlineY, Window.width, 10, Fade(color.HUD_CYAN, 0.1f));

	// Upper header background
	DrawRectangleGradientV(Window.x, Window.y, Window.width, 100, color.GLASS_DARK, Fade(BLACK, 0.0f));

	// Upper Sub-Header (Tabs)
	DrawStoreMenuBox({ Window.x + 20  , Window.y + 10, 400, 80 }, Fade(color.HOT_PINK, 0.6f), color.CARD_BG_DARK, Fade(color.MAGENTA_GLOW, 0.8f), color.CARD_HOVER, 1);
	DrawStoreMenuBox({ Window.x + 540 , Window.y + 10, 400, 80 }, Fade(color.CYBER_BLUE, 0.6f), color.CARD_BG_DARK, Fade(color.ELECTRIC_BLUE, 0.8f), color.CARD_HOVER, 2);
	DrawStoreMenuBox({ Window.x + 1060, Window.y + 10, 400, 80 }, Fade(color.RICH_GOLD, 0.6f), color.CARD_BG_DARK, Fade(color.LUXURY_GOLD, 0.8f), color.CARD_HOVER, 3);

	// Store Text for Tabs
	DrawStoreText({ Window.x + 20 , Window.y + 10, 400, 80 }, "Weapons", WHITE, color.MAGENTA_GLOW, color.ROYAL_PURPLE);
	DrawStoreText({ Window.x + 540, Window.y + 10, 400, 80 }, "Defense", WHITE, color.ELECTRIC_BLUE, color.CYBER_BLUE);
	DrawStoreText({ Window.x + 1060, Window.y + 10, 400, 80 }, "Special", WHITE, color.LUXURY_GOLD, color.RICH_GOLD);

	// That Line between items and item info
	DrawRectangleGradientH(Window.x + 1200, Window.y + 100.0f, 50.0f, Window.height - 100.0f, Fade(color.CARD_BG_DARK, 1.0f), Fade(BLACK, 0.4f));

	// ----- Draw Small Info Window ----- 
	DrawRectangleGradientV(Window.x + 1250.0f, Window.y + 150.0f, 500, 600, color.CARD_BG_LIGHT, color.CARD_BG_DARK);
	DrawRectangleLines(Window.x + 1250.0f, Window.y + 150.0f, 500, 600, color.BORDER_SOFT);
}


// ---------- DRAW INSIDE ITEMS IN THE WINDOW ----------
void Store::DrawInsideWindow(int index, std::string C[5], Texture2D Tex[5]) {
	// Draw Selected Item Attribute
	if (Index_Store == index) {
		for (int i = 0; i < 5; i++) {
			int rarity = 0;
			int price = 0;
			std::string name = "";
			if (index == 1) { name = Attribute_Weapon[i]; rarity = Rarity_Weapon[i]; price = Price_Weapon[i]; }
			else if (index == 2) { name = Attribute_Defence[i]; rarity = Rarity_Defence[i]; price = Price_Defence[i]; }
			else if (index == 3) { name = Attribute_Special[i]; rarity = Rarity_Special[i]; price = Price_Special[i]; }

			DrawWindowItemSelection(i + 1, name, C[i], rarity, price, Tex[i]);
		}
	}

	// Draw Selected Window items
	DrawWindowSelection(1, Attribute_Weapon, Rarity_Weapon, color.CARD_BG_DARK, Fade(color.MAGENTA_GLOW, 0.5f), Fade(color.HOT_PINK, 0.8f), color.CARD_SELECTED);
	DrawWindowSelection(2, Attribute_Defence, Rarity_Defence, color.CARD_BG_DARK, Fade(color.CYBER_BLUE, 0.5f), Fade(color.ELECTRIC_BLUE, 0.8f), color.CARD_SELECTED);
	DrawWindowSelection(3, Attribute_Special, Rarity_Special, color.CARD_BG_DARK, Fade(color.RICH_GOLD, 0.5f), Fade(color.LUXURY_GOLD, 0.8f), color.CARD_SELECTED);
}


// ---------- HELPER FUNCTIONS TO DRAW WINDOW ----------
// -----------------------------------------------------
void Store::DrawStoreText(Rectangle Win, const char* Name, Color N, Color H, Color P) {
	Vector2 TxtSize = MeasureTextEx(GetFontDefault(), Name, 32, 2);

	Vector2 Location = {
		Win.x + (Win.width - TxtSize.x) / 2 ,
		Win.y + (Win.height - TxtSize.y) / 2
	};

	bool Check = CheckCollisionPointRec(GetMousePosition(), Win);

	if (Check) { N = H; }
	if (Check && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) { N = P; }

	// Add glow effect text for selected store index
	if (Index_Store > 0) {
		// Glow shadow
		DrawTextEx(GetFontDefault(), Name, { Location.x + 2, Location.y + 2 }, 32, 2, Fade(color.MAGENTA_GLOW, 0.5f * abs(sin(GetTime() * 3))));
	}

	DrawTextEx(GetFontDefault(), Name, Location, 32, 2, WHITE);
}


void Store::DrawStoreMenuBox(Rectangle Win, Color c1, Color c2, Color c3, Color c4, int index) {
	bool Check = CheckCollisionPointRec(GetMousePosition(), Win);

	if (Check && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
		Index_Store = index;
		Index_Item = 0;
	}

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

	DrawRectangleGradientH(Win.x, Win.y, Win.width, Win.height, c1, c2);

	// Animated border pulse for selected tab
	if (Index_Store == index) {
		float pulse = (sin(GetTime() * 4.0f) + 1.0f) / 2.0f;
		DrawRectangleLinesEx(Win, 4.0f + (pulse * 2.0f), Fade(color.HUD_CYAN, 0.8f + (pulse * 0.2f)));
	}
	else {
		DrawRectangleLinesEx(Win, 2.0f, c1);
	}
}


void Store::DrawItemBox(Rectangle Box, Color N, Color H, Color P, Color B, const char* Attribute, int index, int rarity) {
	bool Check = CheckCollisionPointRec(GetMousePosition(), Box);

	if (Check) { N = H; }
	if (Check && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) { N = P; }
	if (Check && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) { N = P; Index_Item = index; }

	if (Index_Item == index) { N = P; } // Selected state

	Vector2 TextSize = MeasureTextEx(GetFontDefault(), Attribute, 24, 2);
	Vector2 Location = { Box.x + (Box.width - TextSize.x) / 2, Box.y + (Box.height - TextSize.y) / 2 };

	Color rarityColor = GetRarityColor(rarity);

	// Draw rounded futuristic card
	DrawRectangleRounded(Box, 0.2f, 10, N);

	// Draw glow if hovered or selected
	if (Check || Index_Item == index) {
		float glowOffset = (sin(GetTime() * 5.0f) + 1.0f) * 2.0f;
		DrawRectangleRoundedLines({ Box.x - glowOffset, Box.y - glowOffset, Box.width + glowOffset * 2, Box.height + glowOffset * 2 }, 0.2f, 10, Fade(rarityColor, 0.4f));
	}

	// Draw rarity border
	DrawRectangleRoundedLines(Box, 0.2f, 10, rarityColor);

	// Draw Item Name
	DrawTextEx(GetFontDefault(), Attribute, Location, 24, 2, WHITE);
}


void Store::DrawWindowSelection(int index, std::string S[5], int Rarities[5], Color c1, Color c2, Color c3, Color c4) {
	if (Index_Store == index) {
		float startX = ItemBox.x - 50.0f;
		float startY = ItemBox.y - 100.0f;
		float spacingX = 350.0f;
		float spacingY = 150.0f;
		float cardWidth = 300.0f;
		float cardHeight = 100.0f;

		for (int i = 0; i < 5; i++) {
			float x = startX + (i % 3) * spacingX;
			float y = startY + (i / 3) * spacingY;
			DrawItemBox({ x, y, cardWidth, cardHeight }, c1, c2, c3, c4, S[i].c_str(), i + 1, Rarities[i]);
		}
	}
}


void Store::DrawWindowItemSelection(int index, std::string Name, std::string Context, int Rarity, int Price, Texture2D Tex) {
	Rectangle Win = { Window.x + 1250.0f, Window.y + 150.0f, 500, 600 };

	if (Index_Item == index) {
		Color rColor = GetRarityColor(Rarity);
		std::string rText = "Common";
		if (Rarity == 1) rText = "Rare";
		if (Rarity == 2) rText = "Epic";
		if (Rarity == 3) rText = "Legendary";

		// Draw Title
		DrawTextEx(GetFontDefault(), Name.c_str(), { Win.x + 20, Win.y + 20 }, 40, 2, rColor);
		DrawTextEx(GetFontDefault(), rText.c_str(), { Win.x + 20, Win.y + 70 }, 24, 2, Fade(rColor, 0.8f));

		// Draw Separator Line
		DrawRectangleGradientH(Win.x + 20, Win.y + 110, 460, 4, rColor, Fade(rColor, 0.0f));

		// Draw Description
		DrawTextEx(GetFontDefault(), Context.c_str(), { Win.x + 20, Win.y + 140 }, 24, 2, Fade(WHITE, 0.8f));

		// Draw Price
		std::string priceStr = "PRICE : " + std::to_string(Price) + " Credits";
		DrawTextEx(GetFontDefault(), priceStr.c_str(), { Win.x + 20, Win.y + 300 }, 30, 2, color.CREDIT_GOLD);

		// Draw BUY button
		Rectangle buyBtn = { Win.x + 150, Win.y + 450, 200, 60 };
		bool hoverBuy = CheckCollisionPointRec(GetMousePosition(), buyBtn);
		Color btnColor = hoverBuy ? color.BUTTON_HOVER : color.CARD_BG_DARK;
		if (hoverBuy && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) btnColor = color.BUTTON_PRESS;

		DrawRectangleRounded(buyBtn, 0.3f, 10, btnColor);
		DrawRectangleRoundedLines(buyBtn, 0.3f, 10, color.HUD_CYAN);

		Vector2 buyTextSize = MeasureTextEx(GetFontDefault(), "BUY", 32, 2);
		DrawTextEx(GetFontDefault(), "BUY", { buyBtn.x + (buyBtn.width - buyTextSize.x) / 2, buyBtn.y + (buyBtn.height - buyTextSize.y) / 2 }, 32, 2, color.HUD_CYAN);

		// Draw Glow behind texture
		DrawCircleGradient(Win.x + 250, Win.y + 150, 100, Fade(rColor, 0.3f), Fade(rColor, 0.0f));
		if (Tex.id != 0) {
			DrawTextureEx(Tex, { Win.x + 150.0f, Win.y }, 0.0f, 0.3f, WHITE);
		}
	}
}


// ---------- SHOW WINDOW ---------- 
void Store::ShowWindow(bool& show) {
	if (IsKeyPressed(KEY_P)) {
		show = !show;
		std::cout << "\033[1;91m \nP pressed\n \033[0m";
	}
	if (show) {
		DrawWindow();
		if (Index_Store == 1)      DrawInsideWindow(1, C1, Tex1);
		else if (Index_Store == 2) DrawInsideWindow(2, C2, Tex2);
		else if (Index_Store == 3) DrawInsideWindow(3, C3, Tex3);
	}
}


// --------- LOAD WINDOW ASSETS ---------
void Store::LoadWindowAssets() {
	for (int i = 0; i < 5; i++) {
		Tex1[i] = { 0 };
		Tex2[i] = { 0 };
		Tex3[i] = { 0 };
	}
}