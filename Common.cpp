#include "Common.hpp"

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
	// Shades of Black
	LightDark  = { 77, 77, 77 , 255};
	LightDark2 = { 60, 60, 60 , 255};
	MidDark    = { 30, 30, 30 , 255};
	MidDark2   = { 17, 17, 17 , 255};
	Dark       = { 0 , 0 , 0 , 255};

	// Shades of Red
	Red        = { 144, 0, 0 };
	LightRed   = { 238, 36, 0 , 255};
	MidRed     = { 255, 176, 156 , 255};
	FaintRed   = { 251, 217, 211 , 255};
	FaintRed2  = { 255, 239, 234 , 255};

	// Shades of Green
	FaintGreen = { 236, 236, 163 , 255};
	LightGreen = { 181, 229, 80 , 255};
	MidGreen   = { 171, 195, 47 , 255};
	Green      = { 128, 156, 19 , 255};
	DarkGreen  = { 96, 124, 60 , 255};

	// Color Palette for UI: MENU
	UI_BACKGROUND  = { 17,  22,  29, 255 };
	UI_SECONDARY   = { 27,  36,  48, 255 };
	UI_PANEL_GLASS = { 20,  28,  38, 180 };


	TACTICAL_CYAN = { 59, 201, 219, 255 }; 
	NEON_GREEN    = { 50, 215,  75, 255 }; 
	DANGER_RED    = { 255,  93, 115, 255 }; 
	WARM_GOLD     = { 246, 196,  83, 255 }; 

	// Shades for Text
	TEXT_WHITE     = { 234, 242, 248, 255 }; 
	TEXT_SECONDARY = { 154, 166, 178, 255 };

	// Shades for Buttons
	START_TOP      = { 50, 215,  75, 255 };
	START_BOTTOM   = { 31, 174,  56, 255 };

	CREDITS_TOP    = { 70,  92, 110, 255 };
	CREDITS_BOTTOM = { 52,  68,  82, 255 };

	EXIT_TOP       = { 255,  93, 15 };
	EXIT_BOTTOM    = { 214,  69,  93, 255 };

	// Extra's
	AMBIENT_BLUE  = { 175, 199, 217, 255 };
	EMISSIVE_CYAN = { 59, 201, 219, 255 };
	BORDER_SOFT   = { 44,  57,  71, 255 };

	// ==========================================================
// STORE UI EXTENSIONS
// ==========================================================

// ----------------------------------------------------------
// Premium / Exotic Colors
// ----------------------------------------------------------
ROYAL_PURPLE      = { 138,  79, 255, 255 };
DEEP_PURPLE       = {  88,  45, 180, 255 };

CYBER_BLUE        = {   0, 174, 255, 255 };
ELECTRIC_BLUE     = {  73, 220, 255, 255 };

MAGENTA_GLOW      = { 255,  58, 136, 255 };
HOT_PINK          = { 255, 105, 180, 255 };

ORANGE_FIRE       = { 255, 140,  40, 255 };
SUNSET_ORANGE     = { 255, 180,  70, 255 };

LUXURY_GOLD       = { 255, 215,   0, 255 };
RICH_GOLD         = { 212, 175,  55, 255 };

PLASMA_PURPLE     = { 186,  85, 255, 255 };
NEON_VIOLET       = { 149,   0, 255, 255 };

// ----------------------------------------------------------
// Item Rarity Colors
// ----------------------------------------------------------
RARITY_COMMON     = { 180, 180, 180, 255 };
RARITY_UNCOMMON   = {  72, 255, 115, 255 };
RARITY_RARE       = {  70, 160, 255, 255 };
RARITY_EPIC       = { 180,  80, 255, 255 };
RARITY_LEGENDARY  = { 255, 170,  40, 255 };
RARITY_MYTHIC     = { 255,  60, 140, 255 };

// ----------------------------------------------------------
// Store Card / Item Backgrounds
// ----------------------------------------------------------
CARD_BG_DARK      = {  22,  30,  40, 255 };
CARD_BG_LIGHT     = {  32,  42,  54, 255 };

CARD_HOVER        = {  48,  62,  78, 255 };
CARD_SELECTED     = {  60,  90, 120, 255 };

ITEM_SHADOW       = {   0,   0,   0, 120 };
ITEM_GLOW_BLUE    = {   0, 200, 255, 120 };
ITEM_GLOW_PURPLE  = { 170,  70, 255, 120 };

// ----------------------------------------------------------
// Futuristic Glass / Overlay Colors
// ----------------------------------------------------------
GLASS_DARK        = {  15,  20,  28, 180 };
GLASS_LIGHT       = { 255, 255, 255,  20 };

OVERLAY_DARK      = {   0,   0,   0, 140 };
OVERLAY_LIGHT     = { 255, 255, 255,  30 };

SCANLINE_BLUE     = {  70, 180, 255,  35 };
HUD_CYAN          = {  90, 240, 255, 255 };

// ----------------------------------------------------------
// Hover / Interactive Effects
// ----------------------------------------------------------
BUTTON_HOVER      = {  80, 120, 170, 255 };
BUTTON_PRESS      = {  45,  75, 110, 255 };

SUCCESS_GREEN     = {  40, 220, 120, 255 };
WARNING_YELLOW    = { 255, 210,  70, 255 };
ERROR_RED         = { 255,  70,  70, 255 };

XP_BLUE           = {  70, 180, 255, 255 };
CREDIT_GOLD       = { 255, 210,  90, 255 };

// ----------------------------------------------------------
// Animated Gradient Suggestions
// ----------------------------------------------------------
GRADIENT_BLUE_TOP     = {  50, 140, 255, 255 };
GRADIENT_BLUE_BOTTOM  = {   0,  80, 180, 255 };

GRADIENT_PURPLE_TOP   = { 180,  90, 255, 255 };
GRADIENT_PURPLE_BOTTOM= { 100,  40, 200, 255 };

GRADIENT_GOLD_TOP     = { 255, 220, 120, 255 };
GRADIENT_GOLD_BOTTOM  = { 220, 160,  40, 255 };
}
