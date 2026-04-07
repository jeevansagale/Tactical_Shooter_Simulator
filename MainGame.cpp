#include "MainGame.h"

// ---------- OBJECT DECLARATION ----------
Map_Floor MF;
Map_Wall MW;
Map_Box MB;
Map_Table MT;
Map_WallTarget MWT;
Map_StandTarget MST;
Map_Can MC;
Map_Barrel MBR;


// ---------- FLOOR ----------
Map_Floor::Map_Floor() {
	TileSize = 4;
	Location = {};
	Location_Inverted = {};
	HitBox = {
		{
			{-102 , -1.5f , -102} , {102 , 1.5f , 102}
		}
	};
}


void Map_Floor::Draw() {
	for (int i = -25; i < 25; i++) {
		for (int j = -25; j < 25; j++) {
			DrawModel(FloorA, { (float)(TileSize * i + TileSize) , 1 , (float)(TileSize * j + TileSize) }, 1, WHITE);
		}
	}
	DrawBoundingBox(HitBox[0], RED);
}


// ---------- WALL ----------
Map_Wall::Map_Wall() {
	TileSize = 1.5f;
	Location = {
		{80 , TileSize , 94},
		{76 , TileSize , 94},
		{44 , TileSize , 94},
		{48 , TileSize , 94},
		{52 , TileSize , 94},
		{20 , TileSize , 94},
		{16 , TileSize , 94},
		{12 , TileSize , 94},
		{8  , TileSize , 94},
		{4  , TileSize , 94},
		{-36, TileSize , 94},
		{-40, TileSize , 94},
		{-44, TileSize , 94},
		{-48, TileSize , 94},
		{-52, TileSize , 94},

		{100, TileSize , 90},   
		{92 , TileSize , 90},

		{0  , TileSize ,  82},
		{-4 , TileSize ,  82},
		{-8 , TileSize ,  82},
		{-12, TileSize ,  82},
		{-16, TileSize ,  82},
		{-20, TileSize ,  82},

		{92 , TileSize , 78},
		{88 , TileSize , 78},
		{84 , TileSize , 78},
		{72 , TileSize , 78},
		{68 , TileSize , 78},

		{24 , TileSize , 74},
		{28 , TileSize , 74},
		{20 , TileSize , 74},
		{-8 , TileSize , 74},
		{-12, TileSize , 74},
		{-16, TileSize , 74},
		{-20, TileSize , 74},
		{-24, TileSize , 74},
		{-28, TileSize , 74},
		{-32, TileSize , 74},

		{76 , TileSize , 66},
		{80 , TileSize , 66},
		{84 , TileSize , 66},
		{92 , TileSize , 66},

		{52 , TileSize , 58},
		{48 , TileSize , 58},
		{44 , TileSize , 58},
		{40 , TileSize , 58},

		{24 , TileSize , 54},
		{20 , TileSize , 54},
		{16 , TileSize , 54},
		{12 , TileSize , 54},
		{8  , TileSize , 54},
		{-16, TileSize , 54},
		{-20, TileSize , 54},
		{-24, TileSize , 54},
		{-28, TileSize , 54},

		{92 , TileSize , 50},
		{88 , TileSize , 50},
		{84 , TileSize , 50},
		{96 , TileSize , 50},
		{100, TileSize , 50},
		{72 , TileSize , 50},
		{68 , TileSize , 50},
		{64 , TileSize , 50},
		{-56, TileSize , 50},
		{-60, TileSize , 50},
		{-64, TileSize , 50},
		{-68, TileSize , 50},
		{-72, TileSize , 50},
		{-76, TileSize , 50},
		{-80, TileSize , 50},
		{-84, TileSize , 50},
		{-88, TileSize , 50},
		{-92, TileSize , 50},
		{-96, TileSize , 50},

		{36 , TileSize , 46},
		{32 , TileSize , 46},
		{28 , TileSize , 46},
		{-8 , TileSize , 46},
		{-12, TileSize , 46},
		{-16, TileSize , 46},
		{-20, TileSize , 46},
		{-24, TileSize , 46},
		{-28, TileSize , 46},
		{-32, TileSize , 46},

		{-48 , TileSize ,38},
		{-52 , TileSize ,38},
		{-56 , TileSize ,38},
		{-60 , TileSize ,38},
		{-64 , TileSize ,38},
		{-68 , TileSize ,38},
		{-72 , TileSize ,38},
		{-76 , TileSize ,38},
		{-80 , TileSize ,38},

		{72 , TileSize , 34},
		{76 , TileSize , 34},
		{80 , TileSize , 34},
		{28 , TileSize , 34},
		{24 , TileSize , 34},
		{20 , TileSize , 34},

		{56 , TileSize , 30},
		{52 , TileSize , 30},
		{92 , TileSize , 30},

		{24 , TileSize , 22},
		{28 , TileSize , 22},
		{32 , TileSize , 22},
		{36 , TileSize , 22},
		{40 , TileSize , 22},
		{-44, TileSize , 22},
		{-48, TileSize , 22},
		{-52, TileSize , 22},
		{-56, TileSize , 22},
		{-60, TileSize , 22},
		{-64, TileSize , 22},
		{-68, TileSize , 22},
		{-72, TileSize , 22},
		{-76, TileSize , 22},

		{-8 , TileSize , 18},
		{-12, TileSize , 18},
		{-16, TileSize , 18},
		{-20, TileSize , 18},
		{-24, TileSize , 18},
		{-28, TileSize , 18},
		{-32, TileSize , 18},

		{68 , TileSize , 14},
		{64 , TileSize , 14},
		{60 , TileSize , 14},

		{100, TileSize , 10},
		{96 , TileSize , 10},
		{92 , TileSize , 10},
		{88 , TileSize , 10},
		{84 , TileSize , 10},
		{-36, TileSize , 10},
		{-40, TileSize , 10},
		{-44, TileSize , 10},
		{-48, TileSize , 10},
		{-52, TileSize , 10},

		{80 , TileSize , 6},
		{84 , TileSize , 6},
		{88 , TileSize , 6},
		{44 , TileSize , 6},
		{48 , TileSize , 6},
		{52 , TileSize , 6},
		{-76, TileSize , 6},
		{-80, TileSize , 6},
		{-84, TileSize , 6},
		
		{68 , TileSize ,  2},
		{12 , TileSize ,  2},
		{8  , TileSize ,  2},
		{4  , TileSize ,  2},
		{0  , TileSize ,  2},

		{56 , TileSize , -2},

		{56 , TileSize , -6},

		{92 , TileSize , -14},
		{88 , TileSize , -14},
		{84 , TileSize , -14},
		{68 , TileSize , -14},
		{64 , TileSize , -14},
		{60 , TileSize , -14},
		{56 , TileSize , -14},
		{52 , TileSize , -14},
		{16 , TileSize , -14},
		{20 , TileSize , -14},
		{24 , TileSize , -14},
		{28 , TileSize , -14},
		{32 , TileSize , -14},
		{36 , TileSize , -14},
		{40 , TileSize , -14},
		
		{80 , TileSize , -26},
		{76 , TileSize , -26},
		{72 , TileSize , -26},
		{68 , TileSize , -26},

		{48 , TileSize , -30},
		{44 , TileSize , -30},
		{40 , TileSize , -30},
		{36 , TileSize , -30},
		{-40, TileSize , -30},
		{-44, TileSize , -30},
		{-48, TileSize , -30},
		{-52, TileSize , -30},
		{-56, TileSize , -30},
		{-60, TileSize , -30},
		{-64, TileSize , -30},

		{28 , TileSize , -34},
		{24 , TileSize , -34},
		{20 , TileSize , -34},
		{16 , TileSize , -34},
		{12 , TileSize , -34},
		{8  , TileSize , -34},
		{4  , TileSize , -34},
		{0  , TileSize , -34},
		{-4 , TileSize , -34},
		{-8 , TileSize , -34},
		{-12, TileSize , -34},
		{-16, TileSize , -34},
		{-20, TileSize , -34},
		{-24, TileSize , -34},

		{96 , TileSize , -38},
		{92 , TileSize , -38},
		{-76, TileSize ,-38},
		{-80, TileSize ,-38},
		{-84, TileSize ,-38},
		{-88, TileSize ,-38},
		{-92, TileSize ,-38},
		{-96, TileSize ,-38},

		{64 , TileSize , -42},
		{60 , TileSize , -42},

		{12 , TileSize , -50},
		{8  , TileSize , -50},
		{4  , TileSize , -50},
		{0  , TileSize , -50},
		{-4 , TileSize , -50},
		{-8 , TileSize , -50},
		
		{52 , TileSize , -54},
		{56 , TileSize , -54},
		{60 , TileSize , -54},
		{64 , TileSize , -54},
		{76 , TileSize , -54},
		{80 , TileSize , -54},
		{84 , TileSize , -54},
		{88 , TileSize , -54},
		{92 , TileSize , -54},

		{16 , TileSize , -58},
		{12 , TileSize , -58},
		{8  , TileSize , -58},
		{4  , TileSize , -58},
		{0  , TileSize , -58},
		{-4 , TileSize , -58},
		{-8 , TileSize , -58},
		{-12, TileSize , -58},
		{-16, TileSize , -58},
		{-20, TileSize , -58},
		{-24, TileSize , -58},

		{28 , TileSize , -62},
		{32 , TileSize , -62},
		{36 , TileSize , -62},
		{40 , TileSize , -62},
		{56 , TileSize , -62},
		{60 , TileSize , -62},
		{64 , TileSize , -62},
		{68 , TileSize , -62},
		{72 , TileSize , -62},
		{-64, TileSize , -62},
		{-68, TileSize , -62},
		{-72, TileSize , -62},
		{-76, TileSize , -62},
		{-80, TileSize , -62},

		{48 , TileSize , -70},
		{44 , TileSize , -70},
		{40 , TileSize , -70},
		{36 , TileSize , -70},
		{32 , TileSize , -70},
		{28 , TileSize , -70},
		{24 , TileSize , -70},
		{20 , TileSize , -70},
		{16 , TileSize , -70},
		{12 , TileSize , -70},
		{8  , TileSize , -70},
		{4  , TileSize , -70},
		{0  , TileSize , -70},
		{-8 , TileSize , -70},
		{-12, TileSize , -70},
		{-16, TileSize , -70},
		{-20, TileSize , -70},
		{-24, TileSize , -70},
		{-28, TileSize , -70},
		{-32, TileSize , -70},
		{-88, TileSize , -70},
		{-92, TileSize , -70},
		{-96, TileSize , -70},

		{92 , TileSize , -74},
		{88 , TileSize , -74},
		{84 , TileSize , -74},
		{80 , TileSize , -74},
		{76 , TileSize , -74},

		{-64, TileSize , -78},
		{-60, TileSize , -78},
		{-56, TileSize , -78},
		{-36, TileSize , -78},
		{-32, TileSize , -78},
		{-28, TileSize , -78},
		{-24, TileSize , -78},
		{-20, TileSize , -78},
		{-16, TileSize , -78},
		{-12, TileSize , -78},
		{-8 , TileSize , -78},

		{-96, TileSize , -86},
		{-92, TileSize , -86},
		{-88, TileSize , -86},

		{-48, TileSize , -90},
		{-52, TileSize , -90},
		{-56, TileSize , -90},
		{-60, TileSize , -90},
		{-64, TileSize , -90}
	};

	Location_Inverted = {
		{98 , TileSize , -32},
		{98 , TileSize , -36},

		{94 , TileSize , 64},
		{94 , TileSize , 60},
		{94 , TileSize , 48},
		{94 , TileSize , 44},
		{94 , TileSize , 28},
		{94 , TileSize , 24},
		{94 , TileSize , 20},
		{94 , TileSize ,-56},
		{94 , TileSize ,-60},
		{94 , TileSize ,-64},
		{94 , TileSize ,-68},
		{94 , TileSize ,-72},

		{90 , TileSize , 100},
		{90 , TileSize , 96},
		{90 , TileSize , 92},
		{90 , TileSize ,  4},
		{90 , TileSize ,  0},
		{90 , TileSize , -4},
		{90 , TileSize , -8},

		{82 , TileSize , 80},
		{82 , TileSize , 88},
		{82 , TileSize , 92},
		{82 , TileSize , 12},
		{82 , TileSize ,-16},
		{82 , TileSize ,-20},
		{82 , TileSize ,-24},

		{78 , TileSize ,-28},
		{78 , TileSize ,-32},
		{78 , TileSize ,-36},
		{78 , TileSize ,-40},

		{74 , TileSize , 76},
		{74 , TileSize , 72},
		{74 , TileSize , 68},

		{70 , TileSize , 24},
		{70 , TileSize , 28},
		{70 , TileSize , 32},
		{70 , TileSize , 12},
		{70 , TileSize ,  8},
		{70 , TileSize ,  4},

		{66 , TileSize , 88},
		{66 , TileSize , 92},
		{66 , TileSize , 96},
		{66 , TileSize , 100},

		{62 , TileSize , 48},
		{62 , TileSize , 44},
		{62 , TileSize , 40},

		{54 , TileSize , 80},
		{54 , TileSize , 76},
		{54 , TileSize , 72},
		{54 , TileSize , 68},
		{54 , TileSize , 64},
		{54 , TileSize , -4},

		{50 , TileSize ,-16},
		{50 , TileSize ,-20},
		{50 , TileSize ,-24},
		{50 , TileSize ,-28},
		{50 , TileSize ,-32},
		{50 , TileSize ,-36},
		{50 , TileSize ,-40},
		{50 , TileSize ,-44},
		{50 , TileSize ,-48},
		{50 , TileSize ,-52},

		{42 , TileSize , 80},
		{42 , TileSize , 84},
		{42 , TileSize , 84},
		{42 , TileSize , 92},
		{42 , TileSize , 32},
		{42 , TileSize , 36},
		{42 , TileSize , 40},
		{42 , TileSize , 20},
		{42 , TileSize , 16},
		{42 , TileSize , 12},
		{42 , TileSize ,  8},

		{38 , TileSize , 56},
		{38 , TileSize , 52},
		{38 , TileSize , 48},

		{34 , TileSize ,  8},
		{34 , TileSize ,  4},
		{34 , TileSize ,  0},
		{34 , TileSize , -4},
		{34 , TileSize ,-28},
		{34 , TileSize ,-24},
		{34 , TileSize ,-44},
		{34 , TileSize ,-48},
		{34 , TileSize ,-52},

		{30 , TileSize ,100},
		{30 , TileSize , 96},
		{30 , TileSize , 92},
		{30 , TileSize , 88},
		{30 , TileSize , 80},
		{30 , TileSize , 76},

		{26 , TileSize ,-44},
		{26 , TileSize ,-48},
		{26 , TileSize ,-52},
		{26 , TileSize ,-56},
		{26 , TileSize ,-60},
		{26 , TileSize ,-64},
		{26 , TileSize ,-68},

		{22 , TileSize , 84},
		{22 , TileSize , 88},

		{18 , TileSize , 32},
		{18 , TileSize , 28},
		{18 , TileSize , 72},
		{18 , TileSize , 68},
		{18 , TileSize , 64},
		{18 , TileSize , 60},

		{14 , TileSize , 12},
		{14 , TileSize ,  8},
		{14 , TileSize ,  4},
		{14 , TileSize ,  0},
		{14 , TileSize , -4},
		{14 , TileSize , -8},

		{6 , TileSize ,  36},
		{6 , TileSize ,  32},
		{6 , TileSize ,  28},
		{6 , TileSize ,  24},

		{2 , TileSize , 100},
		{2 , TileSize ,  96},
		{2 , TileSize ,  56},
		{2 , TileSize ,  60},
		{2 , TileSize ,  64},
		{2 , TileSize ,  68},
		{2 , TileSize ,  72},

		{-2, TileSize ,   8},
		{-2, TileSize ,   4},

		{-6 ,  TileSize , -96},
		{-6 ,  TileSize , -92},
		{-6 ,  TileSize , -88},
		{-6 ,  TileSize , -84},
		{-6 ,  TileSize , -80},
		{-6 ,  TileSize , -76},
		{-6 ,  TileSize , -72},
		{-6 ,  TileSize ,  64},
		{-6 ,  TileSize ,  60},
		{-6 ,  TileSize ,  56},
		{-6 ,  TileSize ,  52},
		{-6 ,  TileSize ,  48},

		{-14 , TileSize ,  56},
		{-14 , TileSize ,  60},
		{-14 , TileSize ,  64},

		{-18 , TileSize ,  20},
		{-18 , TileSize ,  16},
		{-18 , TileSize ,  12},
		{-18 , TileSize ,  8 },
		{-18 , TileSize ,  4 },
		{-18 , TileSize ,  0 },

		{-22 , TileSize , 84},
		{-22 , TileSize , 88},
		{-22 , TileSize , 92},
		{-22 , TileSize , 96},
		{-22 , TileSize ,100},

		{-26 , TileSize ,-80},
		{-26 , TileSize ,-84},
		{-26 , TileSize ,-88},
		{-26 , TileSize ,-56},
		{-26 , TileSize ,-52},
		{-26 , TileSize ,-48},
		{-26 , TileSize ,-44},
		{-26 , TileSize ,-40},
		{-26 , TileSize ,-36},

		{-34 , TileSize , 76},
		{-34 , TileSize , 80},
		{-34 , TileSize , 84},
		{-34 , TileSize , 88},
		{-34 , TileSize , 92},

		{-38 , TileSize , 36},
		{-38 , TileSize , 32},
		{-38 , TileSize , 28},
		{-38 , TileSize , 24},
		{-38 , TileSize , 20},
		{-38 , TileSize , 16},
		{-38 , TileSize , 12},
		{-38 , TileSize , 8 },
		{-38 , TileSize , 4 },
		{-38 , TileSize , 0 },
		{-38 , TileSize , -4},
		{-38 , TileSize , -8},
		{-38 , TileSize ,-12},
		{-38 , TileSize ,-16},
		{-38 , TileSize ,-20},

		{-46 , TileSize , -72},
		{-46 , TileSize , -76},
		{-46 , TileSize , -80},
		{-46 , TileSize , -84},
		{-46 , TileSize , -88},

		{-54 , TileSize ,  84},
		{-54 , TileSize ,  80},
		{-54 , TileSize ,  76},
		{-54 , TileSize ,  72},
		{-54 , TileSize ,  68},
		{-54 , TileSize ,  64},
		{-54 , TileSize ,  0 },
		{-54 , TileSize ,  -4},
		{-54 , TileSize ,  -8},
		{-54 , TileSize , -12},
		{-54 , TileSize , -16},

		{-74 , TileSize , -84},
		{-74 , TileSize , -88},
		{-74 , TileSize , -72},

		{-82 , TileSize , -84},
		{-82 , TileSize , -80},
		{-82 , TileSize , -76},
		{-82 , TileSize , -72},
		{-82 , TileSize , -68},
		{-82 , TileSize , -64},

		{-86 , TileSize ,-88},
		{-86 , TileSize ,-96},

		{-90 , TileSize , 44},
		{-90 , TileSize , 40},
		{-90 , TileSize , 36},
		{-90 , TileSize , 32},
		{-90 , TileSize , 28},
		{-90 , TileSize , 24},
		{-90 , TileSize , 20},
		{-90 , TileSize , 16},
		{-90 , TileSize , -4},
		{-90 , TileSize , -8},
		{-90 , TileSize ,-12},
		{-90 , TileSize ,-16},
		{-90 , TileSize ,-20},
		{-90 , TileSize ,-24},
		{-90 , TileSize ,-28}
		
	};
}


void Map_Wall::GetHitBox() {
	HitBox.clear();
	HitBox.reserve(Location.size() + Location_Inverted.size() + 33);

	for (int i = 0; i < Location.size(); i++) {
		Vector3 Pos1 = Location[i];

		BoundingBox box1 = {
			{Pos1.x - 2.0f , Pos1.y - 4.0f , Pos1.z - 0.3f } ,
			{Pos1.x + 2.0f , Pos1.y + 4.0f , Pos1.z + 0.3f}
		};
		HitBox.push_back(box1);
	}

	for (int j = 0; j < Location_Inverted.size(); j++) {
		Vector3 Pos2 = Location_Inverted[j];

		BoundingBox box2 = {
			{Pos2.x - 0.3f , Pos2.y - 4.0f , Pos2.z - 2.0f } ,
			{Pos2.x + 0.3f , Pos2.y + 4.0f , Pos2.z + 2.0f}
		};
		HitBox.push_back(box2);
	}

	for (int k = 0; k < 11; k++) {
		Vector3 Pos1 = { (float)(10 + 8 * k) , 1.5f , -80.0f };
		Vector3 Pos2 = { (float)(10 + 8 * k) , 1.5f , -84.0f };
		Vector3 Pos3 = { (float)(10 + 8 * k) , 1.5f , -88.0f };

		BoundingBox box1 = {
			{Pos1.x - 0.3f , Pos1.y - 4.0f , Pos1.z - 2.0f},
			{Pos1.x + 0.3f , Pos1.y + 4.0f , Pos1.z + 2.0f}
		};

		BoundingBox box2 = {
			{Pos2.x - 0.3f , Pos2.y - 4.0f , Pos2.z - 2.0f},
			{Pos2.x + 0.3f , Pos2.y + 4.0f , Pos2.z + 2.0f}
		};

		BoundingBox box3 = {
			{Pos3.x - 0.3f , Pos3.y - 4.0f , Pos3.z - 2.0f},
			{Pos3.x + 0.3f , Pos3.y + 4.0f , Pos3.z + 2.0f}
		};

		HitBox.push_back(box1);
		HitBox.push_back(box2);
		HitBox.push_back(box3);
	}

	BoundingBox OuterWall_Left = { Vector3Add({102 , 1.5f , -98}, { -0.3f , -4.0f , -2.0f }) , Vector3Add({102 , 1.5f , 102}, { 0.3f , 4.0f , 2.0f }) };
	BoundingBox OuterWall_Right = { Vector3Add({-98 , 1.5f , -98}, { -2.0f , -4.0f , -0.3f }) , Vector3Add({102 , 1.5f , -98}, {  2.0f , 4.0f , 0.3f }) };
	BoundingBox OuterWall_Top = { Vector3Add({-98 , 1.5f , -98 }, { -0.3f , -4.0f , -2.0f }) , Vector3Add({-98 , 1.5f , 102} , { 0.3f , 4.0f , 2.0f }) };
	BoundingBox OuterWall_Bottom = { Vector3Add({-98 , 1.5f , 102}, { -2.0f , -4.0f , -0.3f }) , Vector3Add({102 , 1.5f , 102}, { 2.0f , 4.0f , 0.3f }) };
	HitBox.push_back(OuterWall_Left);
	HitBox.push_back(OuterWall_Right);
	HitBox.push_back(OuterWall_Top);
	HitBox.push_back(OuterWall_Bottom);
}


void Map_Wall::Draw() {
	SetRandomSeed(12345);

	for (int i = -25; i < 25; i++) {
		DrawModel(WallA, { (float)(4 * i + 4) , 1.5f , (float)102 }, 1, WHITE);
		DrawModelEx(WallA, { (float)102, 1.5f , (float)(4 * i + 4) }, { 0 , 1.5f , 0 }, 90, { 1 , 1.0f , 1 }, WHITE);
		DrawModelEx(WallA, { -(float)98, 1.5f , (float)(4 * i + 4) }, { 0 , 1.5f , 0 }, 90, { 1 , 1.0f , 1 }, WHITE);
		DrawModel(WallA, { (float)(4 * i + 4) , 1.5f , -(float)98 }, 1, WHITE);
	}


	for (int i = 0; i < Location_Inverted.size(); i++) {
		int roll = GetRandomValue(1, 100);

		if (roll <= 5)  DrawModelEx(WallB, Location_Inverted[i], { 0,1.5f,0 }, 90, { 1,1,1 }, WHITE);
		else if (roll <= 10) DrawModelEx(WallB, Location_Inverted[i], { 0,1.5f,0 }, -90, { 1,1,1 }, WHITE);
		else if (roll <= 50) DrawModelEx(WallA, Location_Inverted[i], { 0,1.5f,0 }, -90, { 1,1,1 }, WHITE);
		else                 DrawModelEx(WallA, Location_Inverted[i], { 0,1.5f,0 }, 90, { 1,1,1 }, WHITE);
	}


	for (int i = 0; i < Location.size(); i++) {
		int roll = GetRandomValue(1, 100);

		if (roll <= 5)  DrawModelEx(WallB, Location[i], { 0,1.5f,0 }, 0, { 1,1,1 }, WHITE);
		else if (roll <= 10) DrawModelEx(WallB, Location[i], { 0,1.5f,0 }, 180, { 1,1,1 }, WHITE);
		else if (roll <= 50) DrawModelEx(WallA, Location[i], { 0,1.5f,0 }, 180, { 1,1,1 }, WHITE);
		else                 DrawModelEx(WallA, Location[i], { 0,1.5f,0 }, 0, { 1,1,1 }, WHITE);
	}


	for (int i = 0; i < 11; i++) {
		if (i == 2 || i == 5 ) {
			DrawModelEx(WallB, { (float)(10 + 8 * i) , 1.5f , -80.0f }, { 0 , 1.5f , 0 }, 90, { 1 , 1 , 1 }, WHITE);
			DrawModelEx(WallA, { (float)(10 + 8 * i) , 1.5f , -84.0f }, { 0 , 1.5f , 0 }, -90, { 1 , 1 , 1 }, WHITE);
			DrawModelEx(WallA, { (float)(10 + 8 * i) , 1.5f , -88.0f }, { 0 , 1.5f , 0 }, -90, { 1 , 1 , 1 }, WHITE);
		}
		else if (i == 1 || i == 3 || i == 9) {
			DrawModelEx(WallA, { (float)(10 + 8 * i) , 1.5f , -80.0f }, { 0 , 1.5f , 0 }, 90, { 1 , 1 , 1 }, WHITE);
			DrawModelEx(WallB, { (float)(10 + 8 * i) , 1.5f , -84.0f }, { 0 , 1.5f , 0 }, -90, { 1 , 1 , 1 }, WHITE);
			DrawModelEx(WallB, { (float)(10 + 8 * i) , 1.5f , -88.0f }, { 0 , 1.5f , 0 }, -90, { 1 , 1 , 1 }, WHITE);
		}
		else {
			DrawModelEx(WallA, { (float)(10 + 8 * i) , 1.5f , -80.0f }, { 0 , 1.5f , 0 }, -90, { 1 , 1 , 1 }, WHITE);
			DrawModelEx(WallA, { (float)(10 + 8 * i) , 1.5f , -84.0f }, { 0 , 1.5f , 0 }, 90, { 1 , 1 , 1 }, WHITE);
			DrawModelEx(WallA, { (float)(10 + 8 * i) , 1.5f , -88.0f }, { 0 , 1.5f , 0 }, -90, { 1 , 1 , 1 }, WHITE);
		}
	}
}


// ---------- BOX ----------
Map_Box::Map_Box() {
	TileSize = 1.5f;
	Location = {
		{92 , TileSize , 100},
		{100, TileSize , 64 },
		{4  , TileSize , 100},
		{-98, TileSize , 48 },
		{-92, TileSize , -56},
		{-44, TileSize , -88},
		{96 , TileSize , -40},
		{12 , TileSize , 0  },
		{-36, TileSize , -4 },
		{-53, TileSize , -34},
		{5  , TileSize , -65},
		{-91, TileSize ,  61},
		{-50, TileSize ,  25}
	};
	Location_Inverted = {
		{40 , TileSize , 64},
		{-20, TileSize , 84},
		{-36, TileSize , 52},
		{-72, TileSize , -4},
		{-88, TileSize ,-96},
		{-8 , TileSize ,-76},
		{28 , TileSize ,-72},
		{72 , TileSize ,  4},
		{-20, TileSize , 16},
		{-36, TileSize , 96},
		{86 , TileSize ,-18},
		{69 , TileSize , 90},
		{-70, TileSize , 95},
		{72 , TileSize ,-84}
	};
}


void Map_Box::GetHitBox() {
	Vector3 Pos;
	HitBox.clear();
	HitBox.reserve(Location.size() + Location_Inverted.size());

	for (int i = 0; i < Location.size(); i++) {
		Pos = Location[i];

		BoundingBox box = {
			{Pos.x - 1.0f , Pos.y - 1.5f , Pos.z - 1.0f},
			{Pos.x + 1.0f , Pos.y + 1.5f , Pos.z + 1.0f}
		};

		HitBox.push_back(box);
	}

	for (int i = 0; i < Location_Inverted.size(); i++) {
		Pos = Location_Inverted[i];

		BoundingBox box = {
			{Pos.x - 1.0f , Pos.y - 1.5f , Pos.z - 1.0f},
			{Pos.x + 1.0f , Pos.y + 1.5f , Pos.z + 1.0f}
		};

		HitBox.push_back(box);
	}
}


void Map_Box::Draw() {
	for (int i = 0; i < Location.size(); i++) {
		DrawModel(BoxB, Location[i], 5, WHITE);
	}
	for (int i = 0; i < Location_Inverted.size(); i++) {
		DrawModel(BoxA, Location_Inverted[i], 5, WHITE);
	}
}


// ---------- TABLE ----------
Map_Table::Map_Table() {
	TileSize = 1.5f;
	Location = {
		{4  , TileSize ,  4},
		{56 , TileSize , 32},
		{92 , TileSize ,-56},
		{96 , TileSize ,-96},
		{-24, TileSize ,-44},
		{-12, TileSize , 96},
		{-12, TileSize , 44}
	};

	Location_Inverted = {
		{-16 , TileSize , 56},
		{100 , TileSize ,  8},
		{-12 , TileSize ,-80},
		{88  , TileSize , -4},
		{32  , TileSize ,  0}
	};
}


void Map_Table::Draw() {
	for (int i = 0; i < Location.size(); i++) {
		if (i == 4) DrawModelEx(TableDecoA, Location[i], { 0 , 1 , 0 }, 90, { 1.5f , 1.5f , 1.5f }, WHITE);
		else DrawModel(TableDecoA, Location[i], 1.5f, WHITE);
	}
	for (int i = 0; i < Location_Inverted.size(); i++) {
		if( i == 0) DrawModel(Table, Location_Inverted[i], 1.5f, WHITE);
		else if (i == 1) DrawModel(Table, Location_Inverted[i], 1.5f, WHITE);
		else if (i == 2) DrawModel(Table, Location_Inverted[i], 1.5f, WHITE);
		else DrawModelEx(Table, Location_Inverted[i], { 0 , 1 , 0 }, 90, {1.5f , 1.5f , 1.5f}, WHITE);
	}
}


// ---------- STANDIND TARGET ----------
Map_StandTarget::Map_StandTarget() {
	TileSize = 1.5f;
	Location = {
		{ -24 , TileSize , -56 },
		{ -84 , TileSize , -96 },
		{ -48 , TileSize , -88 },
		{ 92  , TileSize , -72 },
		{ 96  , TileSize , -36 },
		{ 76  , TileSize ,  68 }
	};

	Location_Inverted = {
		{ 4   , TileSize ,  96 },
		{ 20  , TileSize ,  68 },
		{ 92  , TileSize ,  92 },
		{ 64  , TileSize ,  48 },
		{ 20  , TileSize ,  32 },
		{ 52  , TileSize , -16 },
		{ 28  , TileSize , -64 },
		{ -4  , TileSize , -96 },
		{ -24 , TileSize , -36 }
	};
}


void Map_StandTarget::Draw() {
	for (int i = 0; i < Location.size(); i++) {
		DrawModelEx(TarGetStand, Location[i], { 0 , 1 , 0 }, 0, { 1.5f , 1.5f , 1.5f }, WHITE);
	}
	for (int i = 0; i < Location_Inverted.size(); i++) {
		DrawModelEx(TarGetStand, Location_Inverted[i], { 0 , 1 , 0 }, 90, { 1.5f , 1.5f , 1.5f }, WHITE);
	}
}


// ---------- TARGET ON WALL ----------
Map_WallTarget::Map_WallTarget() {
	TileSize = 4.0f;
	Location = {
		{84 , TileSize , -14.3f},
		{80 , TileSize ,  6.3f },
		{52 , TileSize , 58.3f },
		{88 , TileSize , 77.7f },
		{32 , TileSize , 101.7f},
		{-48, TileSize , 38.3f },
		{-64, TileSize , 22.3f }
	};

	Location_Inverted = {
		{6.3f   , TileSize , 28},
		{-6.3f  , TileSize , 52},
		{-22.3f , TileSize , 92},
		{-14.3f , TileSize , 60},
		{-97.4f , TileSize , 76},
		{-18.3f , TileSize , 20},
		{-13.7f , TileSize , 56},
		{-89.3f , TileSize , 32},
		{-97.3f , TileSize ,-96},
		{-26.3f , TileSize ,-80},
		{49.3f  , TileSize ,-80},
		{101.7f , TileSize ,-88}
	};
}


void Map_WallTarget::Draw() {
	for (int i = 0; i < Location.size(); i++) {
		DrawModelEx(Target, Location[i], { 0 , 1 , 0 }, 0, { 1 , 1 , 1 }, WHITE);
	}
	for (int i = 0; i < Location_Inverted.size(); i++) {
		DrawModelEx(Target, Location_Inverted[i], { 0 , 1 , 0 }, 90, { 1 , 1 , 1 }, WHITE);
	}
}


// ---------- CANS ----------
Map_Can::Map_Can() {
	TileSize = 1.5f;
	Location = {
		{13 , TileSize ,  3},
        {13 , TileSize ,  5},
        {5  , TileSize ,  2},
        {5  , TileSize ,  1},
        {4  , TileSize ,  2},
        {15 , TileSize , -4},
        {15 , TileSize , -5},
        {81 , TileSize ,-26},
        {83 , TileSize , 11},
        {94 , TileSize , 17},
        {95 , TileSize , 28},
        {66 , TileSize ,100},
        {50 , TileSize , 95},
        {-5 , TileSize , 83},
        {-5 , TileSize , 84},
        {-4 , TileSize , 83},
        {-33, TileSize , 75},
        {-86, TileSize , 80},
        {-86, TileSize , 84},
        {-83, TileSize , 80},
        {-81, TileSize , 78},
        {-68, TileSize , 58},
        {-76, TileSize ,-17},
        {-84, TileSize ,-37},
        {-96, TileSize ,-68},
        {-96, TileSize ,-66}
	};

	Location_Inverted = {
		{14 , TileSize , -4},
        {33 , TileSize , 10},
        {33 , TileSize , 11},
        {32 , TileSize , 10},
        {53 , TileSize ,  5},
        {53 , TileSize ,  4},
        {55 , TileSize , -5},
        {54 , TileSize , -5},
        {55 , TileSize , -4},
        {95 , TileSize , 27},
        {101, TileSize , 49},
        {100, TileSize , 49},
        {99 , TileSize , 49},
        {98 , TileSize , 49},
        {97 , TileSize , 49},
        {96 , TileSize , 49},
        {95 , TileSize , 49},
        {77 , TileSize , 66},
        {82 , TileSize , 86},
        {78 , TileSize , 94},
        {-71, TileSize , 49},
        {-91, TileSize , 45},
        {-97, TileSize , 27},
        {-86, TileSize , 6 },
        {-95, TileSize ,-68},
        {-95, TileSize ,-67},
        {-88, TileSize ,-88}
	};
}

void Map_Can::Draw() {
	for (int i = 0; i < Location.size(); i++) {
		DrawModel(CanA, Location[i], 1.5f, WHITE);
	}

	for (int i = 0; i < Location_Inverted.size(); i++) {
		DrawModel(CanB, Location_Inverted[i], 1.5f, WHITE);
	}
}


// ---------- BARRELS ----------
Map_Barrel::Map_Barrel() {
	TileSize = 2.0f;
	Location = {
		{42  , TileSize , 74},
        {29  , TileSize , 81},
        {-3  , TileSize , 99},
        {-24 , TileSize , 95},
        {-51 , TileSize , 82},
        {-56 , TileSize , 68},
        {-12 , TileSize ,-23},
        {14  , TileSize ,-16},
        {32  , TileSize ,-96},
        {33  , TileSize ,-84},
        {100 , TileSize ,  1},
        {91  , TileSize ,  5},
        {-4  , TileSize ,  4},
        {-10 , TileSize ,-24},
        {21  , TileSize , 60},
        {67  , TileSize ,100},
        {-16 , TileSize , 98}
	};

	Location_Inverted = {
		{-85 , TileSize , 54},
        {-87 , TileSize , 98},
        {-79 , TileSize , 70},
        {-4  , TileSize , 80},
        {-13 , TileSize , 86},
        {64  , TileSize ,-50},
        {81  , TileSize ,-24},
        {92  , TileSize , -4},
        {-95 , TileSize , 72},
        {40  , TileSize ,-33},
        {24  , TileSize ,-48},
        {-33 , TileSize , 93},
        {-50 , TileSize , 95},
        {101 , TileSize , 89},
        {83  , TileSize , 69}
	};
}

void Map_Barrel::Draw() {
	for (int i = 0; i < Location.size(); i++) {
		if (i % 2 == 0)      DrawModelEx(BarrelA, Location[i], { 0 , 1 , 0 }, 0 , { 1.5f , 2.0f , 1.5f}, WHITE);
		else if (i % 3 == 0) DrawModelEx(BarrelC, Location[i], { 0 , 1 , 0 }, 0 , { 1.5f , 2.0f , 1.5f}, WHITE);
		else                 DrawModelEx(BarrelB, Location[i], { 0 , 1 , 0 }, 0 , { 1.5f , 2.0f , 1.5f}, WHITE);
	}

	for (int i = 0; i < Location_Inverted.size(); i++) {
		if (i % 2 == 0)      DrawModelEx(BarrelC, Location_Inverted[i], { 0 , 1 , 0 }, 0, { 1.5f , 2.0f , 1.5f }, WHITE);
		else if (i % 3 == 0) DrawModelEx(BarrelB, Location_Inverted[i], { 0 , 1 , 0 }, 0, { 1.5f , 2.0f , 1.5f }, WHITE);
		else                 DrawModelEx(BarrelA, Location_Inverted[i], { 0 , 1 , 0 }, 0, { 1.5f , 2.0f , 1.5f }, WHITE);
	}
}
