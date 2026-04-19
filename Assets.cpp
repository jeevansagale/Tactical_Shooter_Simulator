#include "Assets.h"

// -------------------- Object Declation --------------------
Objects objects;
Furniture furniture;
Character character;
Fonts font;
SoundMusic soundmusic;
Images images;
Icon icon;


// -------------------- FONTS --------------------
Font Doom;
Font DoomOutline;
Font GamePixel;
Font Azonix;


// -------------------- MODELS --------------------
Model FloorA;
Model FloorB;

Model WallA;
Model WallB;

Model BarrelA;
Model BarrelB;
Model BarrelC;

Model CanA;
Model CanB;

Model Table;
Model TableDecoA;

Model BoxA;
Model BoxB;

Model Target;
Model TarGetStand;



// -------------------- TEXTURES --------------------



// -------------------- SOUND --------------------
Sound Click;


// -------------------- ICONS --------------------
Texture2D PlayIcon;
Texture2D ArmourIcon;
Texture2D HealthIcon;
Texture2D DefenceIcon;
Texture2D PistolIcon;
Texture2D ExitIcon;
Texture2D DeathIcon;
Texture2D SpeedIcon;
Texture2D SettingIcon;
Texture2D SheildIcon;
Texture2D DamageIcon;


// --------------- LOADING ASSETS ---------------
// ------------------------------------------------
void Character::Load() {

}


void Objects::Load() {
	FloorA = LoadModel("Assets/Assets/gltf/Floor.gltf");
	FloorB = LoadModel("Assets/Assets/gltf/Floor_Dirt.gltf");

	WallA = LoadModel("Assets/Assets/gltf/Wall.gltf");
	WallB = LoadModel("Assets/Assets/gltf/Wall_Decorated.gltf");
}


void Furniture::Load() {
	Table = LoadModel("Assets/Assets/gltf/table_medium_long.gltf");
	TableDecoA = LoadModel("Assets/Assets/gltf/table_medium_Decorated.gltf");

	BoxA = LoadModel("Assets/Assets/gltf/Box_A.gltf");
	BoxB = LoadModel("Assets/Assets/gltf/Box_B.gltf");

	BarrelA = LoadModel("Assets/Assets/gltf/Barrel_A.gltf");
	BarrelB = LoadModel("Assets/Assets/gltf/Barrel_B.gltf");
	BarrelC = LoadModel("Assets/Assets/gltf/Barrel_C.gltf");

	CanA = LoadModel("Assets/Assets/gltf/Can_A.gltf");
	CanB = LoadModel("Assets/Assets/gltf/Can_B.gltf");

	Target = LoadModel("Assets/Assets/gltf/target_wall_large_A.gltf");
	TarGetStand = LoadModel("Assets/Assets/gltf/target_stand_A_Decorated.gltf");
}


void Fonts::Load() {
	Doom = LoadFontEx("Assets/Fonts/AmazDooMLeft.ttf", 128, 0, 0);
	DoomOutline = LoadFontEx("Assets/Fonts/AmazDooMLeftOutline.ttf", 128, 0, 0);
	GamePixel = LoadFontEx("Assets/Fonts/PixelGamer-Regular.otf", 64, 0, 0);
	Azonix = LoadFontEx("Assets/Fonts/Azonix.otf", 64, 0, 0);
}


void Images::Load() {
	
}


void SoundMusic::Load() {
	Click = LoadSound("Assets/Sound/UI Soundpack/UI Soundpack/MP3/Coffee1.mp3");
}


void Icon::Load() {
	ArmourIcon  = LoadTexture("Assets/Icons/armor.png");
	HealthIcon  = LoadTexture("Assets/Icons/cardiogram.png");
	SpeedIcon   = LoadTexture("Assets/Icons/run.png");
	SettingIcon = LoadTexture("Assets/Icons/settings.png");
	SheildIcon  = LoadTexture("Assets/Icons/shield.png");
	DefenceIcon = LoadTexture("Assets/Icons/defence.png");
	PistolIcon  = LoadTexture("Assets/Icons/pistol.png");
	PlayIcon    = LoadTexture("Assets/Icons/play-button-arrowhead.png");
	ExitIcon    = LoadTexture("Assets/Icons/reject.png");
	DeathIcon   = LoadTexture("Assets/Icons/risk-skull.png");
	DamageIcon  = LoadTexture("Assets/Icons/muscles.png");
}


// --------------- UNLOADING ASSETS ---------------
// ------------------------------------------------
Objects::~Objects() {
	std::cout << "\033[1;93m \n Objects Unloded \033[0m\n\n";

	UnloadModel(FloorA);
	UnloadModel(FloorB);

	UnloadModel(WallA);
	UnloadModel(WallB);
}


Furniture::~Furniture() {
	std::cout << "\033[1;93m \n Furniture Unloded \033[0m\n\n";

	UnloadModel(Table);
	UnloadModel(TableDecoA);

	UnloadModel(BoxA);
	UnloadModel(BoxB);

	UnloadModel(BarrelA);
	UnloadModel(BarrelB);
	UnloadModel(BarrelC);

	UnloadModel(CanA);
	UnloadModel(CanB);

	UnloadModel(Target);
	UnloadModel(TarGetStand);
}


SoundMusic::~SoundMusic() {
	std::cout << "\033[1;93m \n Sound and Music Unloded \033[0m \n\n";
	UnloadSound(Click);
}


Fonts::~Fonts() {
	std::cout << "\033[1;93m \n Fonts Unloded \033[0m\n\n";
	UnloadFont(Doom);
	UnloadFont(DoomOutline);
	UnloadFont(GamePixel);
	UnloadFont(Azonix);
}


Images::~Images() {
	std::cout << "\033[1;93m \n Images Unloded \033[0m\n\n";
}


Character::~Character() {
	std::cout << "\033[1;93m \n Character Unloded \033[0m\n\n";
}


Icon::~Icon() {
	std::cout << "\033[1;93m \n Icon Unloded \033[0m\n\n";
	UnloadTexture(PlayIcon);
	UnloadTexture(ArmourIcon);
	UnloadTexture(HealthIcon);
	UnloadTexture(DefenceIcon);
	UnloadTexture(PistolIcon);
	UnloadTexture(ExitIcon);
	UnloadTexture(DeathIcon);
	UnloadTexture(SpeedIcon);
	UnloadTexture(SettingIcon);
	UnloadTexture(SheildIcon);
	UnloadTexture(DamageIcon);
}