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

	std::string Attribute_Weapon[2][2];  
	std::string Attribute_Defence[2][2];
	std::string Attribute_Speacial[2][2];
	std::string C1[100];
	std::string C2[100];
	std::string C3[100];

	Texture2D Tex1[4];
	Texture2D Tex2[4];
	Texture2D Tex3[4];

	Store();

	void ShowWindow(bool &show);
	void DrawWindow();

	void LoadWindowAssets();

	void DrawInsideWindow(int index, std::string C[4], Texture2D Tex[4]);

	void DrawStoreMenuBox(Rectangle Win, Color c1 , Color c2 , Color c3 , Color c4 , int index);
	void DrawStoreText(Rectangle Win, const char* Name, Color N, Color H, Color P);
	void DrawItemBox(Rectangle Box, Color N, Color H, Color P , Color B, const char* Attribute , int index);

	void DrawWindowSelection(int index, std::string S[2][2] , Color c1, Color c2, Color c3, Color c4);
	void DrawWindowItemSelection(int index, std::string Context , Texture2D Tex);

};
extern Store store;