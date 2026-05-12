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
};
extern Color_Palette color;
