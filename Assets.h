#pragma once

#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>
#include <string>

#include "Common.h"


// -------------------- FONTS --------------------
extern Font Doom;
extern Font DoomOutline;
extern Font GamePixel;
extern Font Azonix;


// -------------------- TEXTURES --------------------
extern Texture2D Player_Tex;


// -------------------- MODELS --------------------
extern Model Char;
extern Model Dummy;

extern Model FloorA;  
extern Model FloorB;  

extern Model WallA;
extern Model WallB;

extern Model BarrelA;
extern Model BarrelB;
extern Model BarrelC;

extern Model Table;
extern Model TableDecoA;
extern Model TableDecoB;

extern Model BoxA;
extern Model BoxB;

extern Model Target;
extern Model UIBackground;


// -------------------- SOUND --------------------
extern Sound Click;


void LoadAssets();
void UnloadAssets();
