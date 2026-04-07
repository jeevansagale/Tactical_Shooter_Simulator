// Main Game File
// -----------------------
// Used for making the main game map
// Getting Hitboxes for the objects
#pragma once


// ---------- Libraries Used ----------
#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>
#include <string>

#include "Common.h"  
#include "Assets.h"
#include "Player.h"


// ---------- DRAWING THE MAIN MAP ----------
class Map {
public:
	float TileSize;       // Tile size [Size of object]
	std::vector<Vector3>Location;    // Location of objects
	std::vector<Vector3>Location_Inverted;   // Inverted location 
	std::vector<BoundingBox>HitBox;          // Getting hitboxes
	virtual void Draw() = 0;         // Pure Virtual function
};


// ---------- DRAWING ----------
// ----- Floor -----
class Map_Floor :virtual public Map {
public:
	Map_Floor();          // constructor used for initializing location, obj size and hitbox
	void Draw() override; 
};
extern Map_Floor MF;


// ----- Walls -----
class Map_Wall :virtual public Map {
public:
	Map_Wall();
	void GetHitBox();
	void Draw() override;
};
extern Map_Wall MW;


// ----- Boxes -----
class Map_Box :virtual public Map {
public:
	Map_Box();
	void GetHitBox();
	void Draw() override;
};
extern Map_Box MB;


// ----- Tables ------
class Map_Table :virtual public Map {
public:
	Map_Table();
	void GetHitBox();
	void Draw() override;
};
extern Map_Table MT;


// ----- Standing Target -----
class Map_StandTarget : virtual public Map {
public:
	Map_StandTarget();
	void Draw() override;
};
extern Map_StandTarget MST;


// ----- Taget on Wall -----
class Map_WallTarget : virtual public Map {
public:
	Map_WallTarget();
	void Draw() override;
};
extern Map_WallTarget MWT;


// ----- Cans -----
class Map_Can : virtual public Map {
public:
	Map_Can();
	void Draw() override;
};
extern Map_Can MC;


// ----- Barrels -----
class Map_Barrel : virtual public Map {
public:
	Map_Barrel();
	void Draw() override;
};
extern Map_Barrel MBR;
