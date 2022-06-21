#include "EntityDisplayApp.h"

EntityDisplayApp::EntityDisplayApp(int screenWidth, int screenHeight) : m_screenWidth(screenWidth), m_screenHeight(screenHeight) {

	h = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"MyEntityMemory");
}

EntityDisplayApp::~EntityDisplayApp() {
	CloseHandle(h);
}

bool EntityDisplayApp::Startup() {

	InitWindow(m_screenWidth, m_screenHeight, "EntityDisplayApp");
	SetTargetFPS(60);

	return true;
}

void EntityDisplayApp::Shutdown() {

	CloseWindow();        // Close window and OpenGL context
}

void EntityDisplayApp::Update(float deltaTime) {

	/*Entity* entitys = (Entity*)MapViewOfFile(h, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(Entity));

	UnmapViewOfFile(entitys);*/

	/*int* entityCount = (int*)MapViewOfFile(h, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(int));

	m_entityCount = *entityCount;*/

	Entity* entity = (Entity*)MapViewOfFile(h, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(Entity));

	m_entities.push_back(*entity);

	UnmapViewOfFile(entity);

	//UnmapViewOfFile(entityCount);
}

void EntityDisplayApp::Draw() {
	BeginDrawing();

	ClearBackground(RAYWHITE);

	// draw entities
	for (auto& entity : m_entities) {
		DrawRectanglePro(
			Rectangle{ entity.x, entity.y, entity.size, entity.size }, // rectangle
			Vector2{ entity.size / 2, entity.size / 2 }, // origin
			entity.rotation,
			Color{ entity.r, entity.g, entity.b, 255 });
	}

	// output some text, uses the last used colour
	DrawText("Press ESC to quit", 630, 15, 12, LIGHTGRAY);

	EndDrawing();
}