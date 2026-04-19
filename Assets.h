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


// -------------------- MODELS --------------------
extern Model FloorA;  
extern Model FloorB;  

extern Model WallA;
extern Model WallB;

extern Model BarrelA;
extern Model BarrelB;
extern Model BarrelC;

extern Model CanA;
extern Model CanB;

extern Model Table;
extern Model TableDecoA;

extern Model BoxA;
extern Model BoxB;

extern Model Target;
extern Model TarGetStand;

extern Model Skeleton_Mage_Custom;
extern Model Mage_Custom;
extern Model Skeleton_Mage;
extern Model Mage;


// -------------------- TEXTURES --------------------
extern Texture2D Player_Tex;
extern Texture2D Enemy_Tex;


// -------------------- SOUND --------------------
extern Sound Click;


// -------------------- SOUND --------------------
extern Texture2D PlayIcon;    
extern Texture2D ArmourIcon;   
extern Texture2D HealthIcon;   
extern Texture2D DefenceIcon;  
extern Texture2D PistolIcon;   
extern Texture2D ExitIcon;    
extern Texture2D DeathIcon;   
extern Texture2D SpeedIcon;   
extern Texture2D SettingIcon; 
extern Texture2D SheildIcon;
extern Texture2D DamageIcon;


// -------------------- LOAD --------------------
class Assets {
public:
	virtual void Load() = 0;
};


class Objects : public Assets {
public:
	void Load() override;
	~Objects();
};
extern Objects objects;


class Furniture : public Assets {
public:
	void Load() override;
	~Furniture();
};
extern Furniture furniture;


class Character : public Assets {
public:
	void Load() override;
	~Character();
};
extern Character character;


class Fonts : public Assets {
public:
	void Load() override;
	~Fonts();
};
extern Fonts font;            


class SoundMusic : public Assets {
public:
	void Load() override;
	~SoundMusic();
};
extern SoundMusic soundmusic;


class Images : public Assets {
public:
	void Load() override;
	~Images();
};
extern Images images;   


class Icon : public Assets {
public:
	void Load() override;
	~Icon();
};
extern Icon icon;