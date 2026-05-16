#pragma once		//this prevents header file from being included multiple times in the same file, which can cause errors

//Libraries
#include <raylib.h>
#include <raymath.h>

//custom headers
#include "UI.h"
#include "Assets.h"
#include "Common.h"

//using extern this variables are made in another file but can be used in this files
extern int Index_Store;
extern int Index_Item;
extern int Index_Select;

//Store class declaration
class Store {
public:
	bool Show;	//this controls whether the store window is visible or not

	//Store Window and Item Box definitions
	Rectangle Window;	
	Rectangle ItemBox;

	std::string Attribute_Weapon[5];	//weapon attributes
	std::string Attribute_Defence[5];	//defence attributes
	std::string Attribute_Special[5];	//special attributes

	//weapon prices and rarities
	int Price_Weapon[5];
	int Rarity_Weapon[5];

	//defence prices and rarities
	int Price_Defence[5];
	int Rarity_Defence[5];

	//special prices and rarities
	int Price_Special[5];
	int Rarity_Special[5];

	//description for each item - weapon , defence and special
	std::string C1[5];
	std::string C2[5];
	std::string C3[5];

	// Textures for each item - weapon , defence and special
	Texture2D Tex1[5];
	Texture2D Tex2[5];
	Texture2D Tex3[5];

	Color GetRarityColor(int rarity);	//returns color based on item rarity - common(grey), rare(blue), epic(purple), legendary(gold)	

	Store();	//default constructor

	void ShowWindow(bool& show);	//open/closes and displays store window 

	void DrawWindow();		//draws the main store UI

	void LoadWindowAssets();	//load store textures / assets 

	// Draws items inside selected category
	// Parameters:
	// index = category index
	// C = description array
	// Tex = texture array
	void DrawInsideWindow(int index, std::string C[5], Texture2D Tex[5]);	

	// Draws category tabs/buttons
	// Example:
	// Weapons | Defence | Special
	void DrawStoreMenuBox(Rectangle Win, Color c1, Color c2, Color c3, Color c4, int index);

	void DrawStoreText(Rectangle Win, const char* Name, Color N, Color H, Color P);	// Draws text inside menu boxes
	void DrawItemBox(Rectangle Box, Color N, Color H, Color P, Color B, const char* Attribute, int index, int rarity);	// Draws individual item cards

	void DrawWindowSelection(int index, std::string S[5], int Rarities[5], Color c1, Color c2, Color c3, Color c4);	// Draws all selectable items in category

	// Draws detailed selected item information
	// Example:
	// Name
	// Description
	// Price
	// Buy button
	// Texture/Icon
	void DrawWindowItemSelection(int index, std::string Name, std::string Context, int Rarity, int Price, Texture2D Tex);	

};

// Allows the same Store object to be accessed globally
extern Store store;