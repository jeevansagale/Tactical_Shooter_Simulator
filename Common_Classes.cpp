//#include <raylib.h>
//#include <raymath.h>
//#include <iostream>
//#include <vector>
//#include <string>
//
//Vector3 player = { 1 , 1 , 1 };
//Vector3 MouseMovent;
//Vector3 potentialPos;
//Vector3 Forward;
//Vector3 Right;
//
//Vector2 MP;
//Vector2 MD;
//
//float yaw = 0.0f;
//float pitch = 0.0f;
//float dt;
//
//bool press = false;
//bool Collide = false;
//
//BoundingBox Wall[5];
//Vector3 WallPos[5] = {
//	{10 , 0 , 10} ,
//	{10 , 0 , 30} ,
//	{40 , 0 , 10} ,
//	{60 , 0 , 40} ,
//	{100 , 0 , 20} ,
//};
//void initialize() {
//	for (int i = 0; i < 5; i++) {
//		Wall[i].min = { -1 , -5 , -5 };
//		Wall[i].max = { 1 , 5 , 5 };
//	}
//}
//
//Camera3D cam = { 0 };
//RayCollision Check;
//Color color = RED;
//
//
//class Bullet {
//public:
//	bool active = false;
//	Vector3 Pos;
//	Vector3 Velo;
//};
//Bullet B;
//
//
//void DrawPlayer() {
//	Forward = { MouseMovent.x , 0 , MouseMovent.z };
//	Right = Vector3Normalize(Vector3CrossProduct(Forward, { 0 , 1 , 0 }));
//
//	if (IsKeyDown(KEY_W)) { player = Vector3Add(player, Vector3Scale(Vector3Normalize(Forward), 5 * dt)); }
//	if (IsKeyDown(KEY_S)) { player = Vector3Subtract(player, Vector3Scale(Vector3Normalize(Forward), 5 * dt)); }
//	if (IsKeyDown(KEY_A)) { player = Vector3Subtract(player, Vector3Scale(Right, 5 * dt)); }
//	if (IsKeyDown(KEY_D)) { player = Vector3Add(player, Vector3Scale(Right, 5 * dt)); }
//
//	if (IsKeyDown(KEY_LEFT_SHIFT)) { player.y -= 5 * dt; }
//	if (IsKeyDown(KEY_SPACE)) { player.y += 5 * dt; }
//
//	DrawCube(player, 1, 1, 1, DARKGRAY);
//}
//
//void CameraPos() {
//
//	yaw -= MD.x * 0.15f;
//	pitch -= MD.y * 0.15f;
//
//	pitch = Clamp(pitch, -89.0f, 89.0f);
//
//	MouseMovent = {
//		sinf(DEG2RAD * yaw) * cosf(DEG2RAD * pitch),
//		sinf(DEG2RAD * pitch),
//		cosf(DEG2RAD * yaw) * cosf(DEG2RAD * pitch)
//	};
//}
//
//
//int main() {
//	InitWindow(1020, 800, "Test");
//	SetTargetFPS(60);
//	SetExitKey(KEY_NULL);
//
//	Model Char = LoadModel("Assets/stylized-military-character/source/Char.glb");
//	Model Ani = LoadModel("Assets/Animations/gltf/Rig_Large/Rig_Large_Simulation.glb");
//	Texture2D Tex = LoadTexture("Assets/stylized-military-character/textures/Soldier_Base_Color.png");
//	Char.materials[0].maps[MATERIAL_MAP_SPECULAR].texture = Tex;
//
//	int AniCount = 0;
//	int AniFrame = 0;
//	int AniIndex = 0;
//	ModelAnimation* animation = LoadModelAnimations("Assets/Animations/gltf/Rig_Large/Rig_Large_Simulation.glb", &AniCount);
//
//
//	cam.fovy = 45.0f;
//	cam.up = { 0 , 1 , 0 };
//	//cam.target = player;
//	//cam.position = Vector3Add(player, { 3 , 3 , 3 });
//	cam.projection = CAMERA_PERSPECTIVE;
//
//
//	bool show = false;
//
//	while (!WindowShouldClose()) {
//		dt = GetFrameTime();
//		MD = GetMouseDelta();
//		MP = GetMousePosition();
//		AniFrame++;
//		initialize();
//		UpdateCamera(&cam, CAMERA_CUSTOM);
//		potentialPos = player;
//
//		BoundingBox Box = {
//		Vector3Add({-0.5, -0.5 , -0.5} , player),
//		Vector3Add({0.5 , 0.5 , 0.5} , player)
//		};
//
//		BoundingBox Bullet = {
//			Vector3Add({-0.5, -0.5 , -0.5} , B.Pos),
//			Vector3Add({0.5 , 0.5 , 0.5} , B.Pos)
//		};
//
//		for (int i = 0; i < 5; i++) {
//			Wall[i] = { Vector3Add(Wall[i].min , WallPos[i]) , Vector3Add(Wall[i].max , WallPos[i]) };
//		}
//
//		BoundingBox WorldBox = {
//		{ -100.0f, -0.5f, -100.0f },
//		{  100.0f,  0.5f,  100.0f }
//		};
//
//		BeginDrawing();
//		ClearBackground(RAYWHITE);
//
//		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
//			show = !show;
//			if (show) {
//				DisableCursor();  // lock mouse
//			}
//			else {
//				EnableCursor();   // release mouse
//			}
//		}
//
//		BeginMode3D(cam);
//		DrawPlane({ 0 , 0 ,0 }, { 200 , 200 }, GRAY);
//
//		for (int i = 0; i < 5; i++) {
//			DrawCube(WallPos[i], 2, 10, 10, BLACK); // width matches min/max
//			DrawBoundingBox(Wall[i], PINK);
//		}
//
//		DrawBoundingBox(Box, BLUE);
//		DrawBoundingBox(WorldBox, RED);
//		DrawBoundingBox(Bullet, GREEN);
//
//		Ray ray = GetMouseRay({ 510 , 400 }, cam);
//		for (int i = 0; i < 5; i++) {
//			Check = GetRayCollisionBox(ray, Wall[i]);
//		}
//
//		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//			B.active = true;
//			B.Pos = cam.position;
//			Vector3 Dir = Vector3Normalize(cam.target - cam.position);
//			B.Velo = Vector3Scale(Dir, 20.0f);
//		}
//		if (B.active) {
//			B.Pos = Vector3Add(B.Pos, Vector3Scale(B.Velo, dt));
//		}
//		if (B.active) {
//			DrawSphere(B.Pos, 1.0f, color);
//		}
//		DrawPlayer();
//
//		CameraPos();
//		/*if (!Collide) {
//			player = potentialPos;
//			Collide = false;
//		}*/
//		//if (CheckCollisionPointBox(GetMousePosition(), Bullet)) { color = BLUE; }
//
//		DrawModelEx(Char, Vector3Subtract(player, { 0 , 1.5f , 0 }), { 0 , 1 , 0 }, yaw, { 1 , 1 , 1 }, WHITE);
//
//		UpdateModelAnimation(
//			Ani,
//			animation[AniIndex],
//			AniFrame
//		);
//		if (AniFrame >= animation[AniIndex].frameCount) { AniFrame = 0; }
//		//DrawModel(Ani, { 1 , 1, 1 }, 0.5f, WHITE);
//
//		if (!CheckCollisionBoxes(Box, WorldBox)) {
//			player.y -= 5 * dt;
//		}
//		if (player.y <= -20.0f) { player.y = 20.0f; }
//		player.y = Clamp(player.y, -100, 100);
//
//		for (int i = 0; i < 5; i++) {
//			if (CheckCollisionBoxes(Box, Wall[i])) {
//				Collide = true;
//				break;
//			}
//		}
//
//
//
//		EndMode3D();
//
//
//		if (Check.hit) {
//			DrawText("YOU ARE LOOKING", 10, 30, 20, DARKGRAY);
//		}
//		for (int i = 0; i < 5; i++) {
//			if (CheckCollisionBoxes(Wall[i], Bullet)) {
//				DrawText("YOU HIT ME", 10, 50, 20, BLACK);
//			}
//		}
//
//		DrawText("Raylib 3D Cube", 10, 10, 20, DARKGRAY);
//		DrawLineEx({ 510 - 8, 400 }, { 510 + 8, 400 }, 40, GREEN);
//		DrawLineEx({ 510 , 400 - 8 }, { 510, 400 + 8 }, 40, GREEN);
//		DrawCircle(510, 400, 2, GREEN);
//		cam.position = Vector3Add(player, { 0.0f , 2.0f , 0.0f });
//		cam.target = Vector3Add(cam.position, MouseMovent);
//		EndDrawing();
//	}
//
//	UnloadModel(Char);
//	UnloadModelAnimations(animation, AniCount);
//	UnloadModel(Ani);
//	UnloadTexture(Tex);
//	CloseWindow();
//	return 0;
//}