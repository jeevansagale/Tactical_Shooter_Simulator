#pragma once

#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>
#include <string>

#include "Common.h"
#include "Assets.h"


// ---------- Camera for menu ----------
class CameraUI {
public:
	Camera3D cam;

	CameraUI();
	void InitializeCam();
};
extern CameraUI CamUI;


// ---------- Making Buttons
void MakeButton(Rectangle Btn, const char* BtnName, Color N, Color H, Color P, State NewState);


// ---------- TITLE ----------
class Title {
public:
	float Alpha;
	float DirX;
	float DirY;
	int Dir;

	Title();
	void MakeTitle(const char* Title);
};
extern Title T;


// ---------- Making Menu's Background ----------
class Menu {
public:
	float TileSize;
	std::vector<Vector3> Location;
	virtual void Draw() = 0;      // Pure Virtual Function
};


class Floor:virtual public Menu {
public:
	Floor();
	void Draw() override;
};
extern Floor F;


class Barrel:virtual public Menu {
public:
	Barrel();
	void Draw() override;
};
extern Barrel B;


class Wall :virtual public Menu {
public:
	Wall();
	void Draw() override;
};
extern Wall W;


class OtherStuff :virtual public Menu {
public:
	OtherStuff();
	void Draw() override;
};
extern OtherStuff OS;

