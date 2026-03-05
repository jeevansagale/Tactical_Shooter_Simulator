#include "Assets.h"

// -------------------- FONTS --------------------
Font Doom;
Font DoomOutline;
Font GamePixel;
Font Azonix;


// -------------------- TEXTURES --------------------
Texture2D Player_Tex;


// -------------------- MODELS --------------------
Model Char;
Model Dummy;

Model FloorA;
Model FloorB;

Model WallA;
Model WallB;

Model BarrelA;
Model BarrelB;
Model BarrelC;

Model Table;
Model TableDecoA;
Model TableDecoB;

Model BoxA;
Model BoxB;

Model Target;
Model UIBackground;


// -------------------- SOUND --------------------
Sound Click;


void LoadAssets() {
	Doom = LoadFontEx("Assets/Fonts/AmazDooMLeft.ttf", 128, 0, 0);
	DoomOutline = LoadFontEx("Assets/Fonts/AmazDooMLeftOutline.ttf", 128, 0, 0);
	GamePixel = LoadFontEx("Assets/Fonts/PixelGamer-Regular.otf", 64, 0, 0);
	Azonix = LoadFontEx("Assets/Fonts/Azonix.otf", 64, 0, 0);


	Player_Tex = LoadTexture("Assets/stylized-military-character/textures/Soldier_Base_Color.png");


	FloorA = LoadModel("Assets/Assets/gltf/Floor.gltf");
	FloorB = LoadModel("Assets/Assets/gltf/Floor_Dirt.gltf");
	
	WallA  = LoadModel("Assets/Assets/gltf/Wall.gltf");
	WallB  = LoadModel("Assets/Assets/gltf/Wall_Decorated.gltf");

	Table = LoadModel("Assets/Assets/gltf/table_medium_long.gltf");
	TableDecoA = LoadModel("Assets/Assets/gltf/table_medium_Decorated.gltf");
	TableDecoB = LoadModel("Assets/Assets/gltf/target_stand_A_Decorated.gltf");

	BoxA = LoadModel("Assets/Assets/gltf/Box_A.gltf");
	BoxB = LoadModel("Assets/Assets/gltf/Box_B.gltf");
	
	BarrelA = LoadModel("Assets/Assets/gltf/Barrel_A.gltf");
	BarrelB = LoadModel("Assets/Assets/gltf/Barrel_B.gltf");
	BarrelC = LoadModel("Assets/Assets/gltf/Barrel_C.gltf");

	Target = LoadModel("Assets/Assets/gltf/target_wall_large_A.gltf");
	UIBackground = LoadModel("Assets/Assets/gltf/shooter.glb");

	Char = LoadModel("Assets/stylized-military-character/source/Char.glb");
	Dummy = LoadModel("Assets/Assets/gltf/Dummy_Base.gltf");
	Char.materials[0].maps[MATERIAL_MAP_SPECULAR].texture = Player_Tex;

	Click = LoadSound("Assets/Sound/UI Soundpack/UI Soundpack/MP3/Coffee1.mp3");
}


void UnloadAssets() {
	UnloadFont(Doom);
	UnloadFont(DoomOutline);
	UnloadFont(GamePixel);
	UnloadFont(Azonix);

    UnloadModel(Char);
	UnloadModel(Dummy);

	UnloadModel(FloorA);
	UnloadModel(FloorB);
	
	UnloadModel(Table);
	UnloadModel(TableDecoA);
	UnloadModel(TableDecoB);
	
	UnloadModel(BoxA);
	UnloadModel(BoxB);

	UnloadModel(WallA);
	UnloadModel(WallB);
	
	UnloadModel(BarrelA);
	UnloadModel(BarrelB);
	UnloadModel(BarrelC);
	
	UnloadModel(Target);
	UnloadModel(UIBackground);

	UnloadSound(Click);

	UnloadTexture(Player_Tex);
}