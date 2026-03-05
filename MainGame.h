#pragma once

#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>
#include <string>

#include "Common.h"
#include "Assets.h"
#include "Player.h"


// Draw the Main Map
class Map {
public:
	int TileSize;
	std::vector<Vector3>Location;
	std::vector<Vector3>Location_Inverted;
	std::vector<BoundingBox>HitBox;
	virtual void Draw() = 0; 
};


class Map_Floor :virtual public Map {
public:
	Map_Floor();
	void Draw() override;
};
extern Map_Floor MF;


class Map_Wall :virtual public Map {
public:

	Map_Wall();
	void GetHitBox();
	void Draw() override;
};
extern Map_Wall MW;