#include "Common.h"

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
}
