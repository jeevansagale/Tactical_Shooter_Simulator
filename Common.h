#pragma once

#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>
#include <string>


#define SW /*1920*/ float(GetScreenWidth())
#define SH /*960*/ float(GetScreenHeight())

// ---------- 2D Vector ----------
extern Vector2 MP;        // Get Mouse Position
extern Vector2 MD;        // Get Mouse Delta


// gets frame per time
extern float DT;


// Game States
enum State {
	MENU,
	START,
	CREDITS,
	EXIT
};
extern State CurrentState;


// Camera States
enum CameraState {
	CAM_MENU,
	CAM_PLAYER,
	CAM_MAIN_GAME
};
extern CameraState CamState;


// ------ COLOR -----
class Color_Palette {
public:

	Color_Palette();

	// Dark shades
	Color LightDark;
	Color LightDark2;
	Color MidDark;
	Color MidDark2 ;
	Color Dark;

	// Red shades
	Color Red;
	Color LightRed;
	Color MidRed;
	Color FaintRed;
	Color FaintRed2;

	// Green shades
	Color FaintGreen;
	Color LightGreen;
	Color MidGreen;
	Color Green;
	Color DarkGreen;

	// Color Palette for UI: MENU
	Color UI_BACKGROUND;
	Color UI_SECONDARY;
	Color UI_PANEL_GLASS;


	Color TACTICAL_CYAN;
	Color NEON_GREEN;
	Color DANGER_RED;
	Color WARM_GOLD;

	// Shades for Text
	Color TEXT_WHITE;
	Color TEXT_SECONDARY;

	// Shades for Buttons
	Color START_TOP;
	Color START_BOTTOM;

	Color CREDITS_TOP;
	Color CREDITS_BOTTOM;

	Color EXIT_TOP;
	Color EXIT_BOTTOM;

	// Extra's
	Color AMBIENT_BLUE;
	Color EMISSIVE_CYAN;
	Color BORDER_SOFT;

	// Store UI Extensions
	Color ROYAL_PURPLE;
	Color DEEP_PURPLE;
	Color CYBER_BLUE;
	Color ELECTRIC_BLUE;
	Color MAGENTA_GLOW;
	Color HOT_PINK;
	Color ORANGE_FIRE;
	Color SUNSET_ORANGE;
	Color LUXURY_GOLD;
	Color RICH_GOLD;
	Color PLASMA_PURPLE;
	Color NEON_VIOLET;

	// Item Rarity Colors
	Color RARITY_COMMON;
	Color RARITY_UNCOMMON;
	Color RARITY_RARE;
	Color RARITY_EPIC;
	Color RARITY_LEGENDARY;
	Color RARITY_MYTHIC;

	// Store Card / Item Backgrounds
	Color CARD_BG_DARK;
	Color CARD_BG_LIGHT;
	Color CARD_HOVER;
	Color CARD_SELECTED;
	Color ITEM_SHADOW;
	Color ITEM_GLOW_BLUE;
	Color ITEM_GLOW_PURPLE;

	// Futuristic Glass / Overlay Colors
	Color GLASS_DARK;
	Color GLASS_LIGHT;
	Color OVERLAY_DARK;
	Color OVERLAY_LIGHT;
	Color SCANLINE_BLUE;
	Color HUD_CYAN;

	// Hover / Interactive Effects
	Color BUTTON_HOVER;
	Color BUTTON_PRESS;
	Color SUCCESS_GREEN;
	Color WARNING_YELLOW;
	Color ERROR_RED;
	Color XP_BLUE;
	Color CREDIT_GOLD;

	// Animated Gradient Suggestions
	Color GRADIENT_BLUE_TOP;
	Color GRADIENT_BLUE_BOTTOM;
	Color GRADIENT_PURPLE_TOP;
	Color GRADIENT_PURPLE_BOTTOM;
	Color GRADIENT_GOLD_TOP;
	Color GRADIENT_GOLD_BOTTOM;
};
extern Color_Palette color;
