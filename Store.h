#pragma once

#include <raylib.h>
#include <raymath.h>
#include "UI.h"
#include "Assets.h"
#include "Common.h"


class Store {
public:
	bool Show;

	Rectangle Window;
	Rectangle ItemBox;

	std::string Attribute_Weapon[2][2];  
	std::string Attribute_Defence[2][2];
	std::string Attribute_Speacial[2][2];

	int Index_Store;
	int Index_Item;
	
	Store();

	void ShowWindow(bool &show);
	void DrawWindow();
	void DrawInsideWindow();

	void DrawStoreMenuBox(Rectangle Win, Color c1 , Color c2 , Color c3 , Color c4);
	void DrawStoreText(Rectangle Win, const char* Name, Color N, Color H, Color P);
	void DrawItemBox(Rectangle Box, Color N, Color H, Color P , Color B, const char* Attribute);

};
extern Store store;