#include "Player.h"


// ----- Class Object Declaration -----
Player_Main player_main;
Player_Enemy player_enemy;


// ---------- Player: Main ----------
Player_Main::Player_Main() {
	Health = 100;
	Speed = 10.0f;
	pitch = 0.0f;
	yaw = 0.0f;

	Pos = { 1 ,3.0f ,1 };
	cam = { 0 };

	CurrentFrame = 0;
	AnimIndex = 6;
	AnimCount = 0;

	PlayerHitbox = { {-1, -5, -1} , {1, 5 ,1} };
}


void Player_Main::InitializeCamera() {
	cam.fovy = 45.0f;
	cam.projection = CAMERA_PERSPECTIVE;
	cam.up = { 0, 1 , 0 };
	cam.position = { -92 , 4 , -92 };
	cam.target = { 1 , 1 , 1 };
}


void Player_Main::CameraPos() {
	yaw -= MD.x * 0.15f;
	pitch -= MD.y * 0.15;

	pitch = Clamp(pitch, -89.0f, 89.0f);

	MouseMovement = {
		sinf(DEG2RAD * yaw) * cosf(DEG2RAD * pitch),
		sinf(DEG2RAD * pitch),
		cosf(DEG2RAD * yaw) * cosf(DEG2RAD * pitch)
	};
}


void Player_Main::PlayerMovement() {
	Forward = { MouseMovement.x , 0 , MouseMovement.z };
	Right = Vector3Normalize(Vector3CrossProduct(Forward, { 0 , 1 , 0 }));

	if (IsKeyDown(KEY_W)) { Pos = Vector3Add(Pos, Vector3Scale(Vector3Normalize(Forward), 5 * DT)); AnimIndex = 8; }
	else if (IsKeyDown(KEY_S)) { Pos = Vector3Subtract(Pos, Vector3Scale(Vector3Normalize(Forward), 5 * DT)); AnimIndex = 8; }
	else if (IsKeyDown(KEY_A)) { Pos = Vector3Subtract(Pos, Vector3Scale(Right, 5 * DT)); AnimIndex = 8; }
	else if (IsKeyDown(KEY_D)) { Pos = Vector3Add(Pos, Vector3Scale(Right, 5 * DT)); AnimIndex = 8; }
	else { AnimIndex = 7; }

	UpdateModelAnimation(model, Anim[AnimIndex], CurrentFrame);
	
	DrawModelEx(model, Vector3Subtract(Pos, { 0 , 1.5f , 0 }), { 0 , 1 , 0 }, yaw, { 1 , 1 , 1 }, WHITE);
}


void Player_Main::LoadAnimation() {
	model = LoadModel("Assets/KayKit_Character_Animations_1.1/Mannequin Character/characters/Mannequin_medium_fix.glb");
	Anim = LoadModelAnimations("Assets/KayKit_Character_Animations_1.1/Mannequin Character/characters/Mannequin_medium_fix.glb", &AnimCount);
	Tex = LoadTexture("Assets/KayKit_Character_Animations_1.1/Mannequin Character/Textures/mannequin_texture.png");
	// "Assets/KayKit_Character_Animations_1.1/Animations/gltf/Rig_Medium/Rig_Medium_MovementBasic.glb"

	// "Assets/KayKit_Character_Animations_1.1/Mannequin Character/characters/Mannequin_medium_fix.glb"

	//"Assets/characterbystyloov1.2/characterbystyloocharacter_root.glb"

	model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = Tex;
}


void Player_Main::PlayerAnimation() {
	CurrentFrame++;

	if (CurrentFrame >= Anim[AnimIndex].frameCount) CurrentFrame = 0;
}


Player_Main::~Player_Main() {
	std::cout << "\n\033[1;93m Player Unloded \033[0m\n\n";
	UnloadModel(model);
	UnloadTexture(Tex);
	UnloadModelAnimations(Anim , AnimCount);
}


// ---------- Player: Enemy ----------
Player_Enemy::Player_Enemy() {
	Health = 100;
	Speed = 10.0f;

	Pos = { 1 ,1 ,1 };
	cam = { 0 };

	CurrentFrame = 0;
	AnimIndex = 0;
	AnimCount = 0;

	//Anim = LoadModelAnimations("Assets/KayKit_Skeletons_1.1_FREE/KayKit_Skeletons_1.1_FREE/Animations/gltf/Rig_Medium/Rig_Medium_MovementBasic.glb", &AnimCount);

	PlayerHitbox = { {0 , 0, 0} , {0, 0 ,0} };
}


void Player_Enemy::InitializeCamera() {
	cam.fovy = 45.0f;
	cam.projection = CAMERA_PERSPECTIVE;
	cam.up = { 0, 1 , 0 };
	cam.position = { 5 , 5 , 5 };
	cam.target = { 1 , 1 , 1 };
}


void Player_Enemy::CameraPos() {

}


void Player_Enemy::PlayerMovement() {
	//UpdateModelAnimation(Skeleton_Mage, Anim[AnimIndex], CurrentFrame);
	//DrawModel(Skeleton_Mage, { 5 , 5 , 5 }, 1.0f, WHITE);
}


void Player_Enemy::LoadAnimation() {
	//Anim = LoadModelAnimations("Assets/KayKit_Skeletons_1.1_FREE/KayKit_Skeletons_1.1_FREE/Animations/gltf/Rig_Medium/Rig_Medium_General.glb", &AnimCount);
}


void Player_Enemy::PlayerAnimation() {
	CurrentFrame++;

	if (CurrentFrame >= Anim[AnimIndex].frameCount) CurrentFrame = 0;
}