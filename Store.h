#pragma once

#include <raylib.h>
#include <raymath.h>
#include "UI.h"
#include "Assets.h"
#include "Common.h"

extern int Index_Store;
extern int Index_Item;
extern int Index_Select;

class Store {
public:
	bool Show;

	Rectangle Window;
	Rectangle ItemBox;

	std::string Attribute_Weapon[5];  
	std::string Attribute_Defence[5];
	std::string Attribute_Special[5];

	int Price_Weapon[5];
	int Rarity_Weapon[5];

	int Price_Defence[5];
	int Rarity_Defence[5];

	int Price_Special[5];
	int Rarity_Special[5];

	std::string C1[5];
	std::string C2[5];
	std::string C3[5];

	Texture2D Tex1[5];
	Texture2D Tex2[5];
	Texture2D Tex3[5];

	Color GetRarityColor(int rarity);

	Store();

	void ShowWindow(bool &show);
	void DrawWindow();

	void LoadWindowAssets();

	void DrawInsideWindow(int index, std::string C[5], Texture2D Tex[5]);

	void DrawStoreMenuBox(Rectangle Win, Color c1 , Color c2 , Color c3 , Color c4 , int index);
	void DrawStoreText(Rectangle Win, const char* Name, Color N, Color H, Color P);
	void DrawItemBox(Rectangle Box, Color N, Color H, Color P , Color B, const char* Attribute , int index, int rarity);

	void DrawWindowSelection(int index, std::string S[5], int Rarities[5], Color c1, Color c2, Color c3, Color c4);
	void DrawWindowItemSelection(int index, std::string Name, std::string Context, int Rarity, int Price, Texture2D Tex);

};
extern Store store;
