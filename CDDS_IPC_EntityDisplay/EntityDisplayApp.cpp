#include "EntityDisplayApp.h"

EntityDisplayApp::EntityDisplayApp(int screenWidth, int screenHeight) : m_screenWidth(screenWidth), m_screenHeight(screenHeight) {

	entityHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"MyEntityMemory");
	intHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"MyIntMemory");
}

EntityDisplayApp::~EntityDisplayApp() {

	delete[] entityArray;
	CloseHandle(entityHandle);
	CloseHandle(intHandle);

}

bool EntityDisplayApp::Startup() {

	InitWindow(m_screenWidth, m_screenHeight, "EntityDisplayApp");
	SetTargetFPS(60);

	int* enemyCount = (int*)MapViewOfFile(intHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(int));

	m_entityCount = *enemyCount;

	entityArray = new Entity[m_entityCount];

	UnmapViewOfFile(enemyCount);

	return true;
}

void EntityDisplayApp::Shutdown() {

	CloseWindow();        // Close window and OpenGL context
}

void EntityDisplayApp::Update(float deltaTime) {

	

	Entity* entity = (Entity*)MapViewOfFile(entityHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(Entity) * m_entityCount);


	for (int i = 0; i < m_entityCount; i++)
	{
		entityArray[i] = entity[i];
	}

	
	UnmapViewOfFile(entity);

	
}

void EntityDisplayApp::Draw() {
	BeginDrawing();

	ClearBackground(RAYWHITE);

	for (int i = 0; i < m_entityCount; i++)
	{
		DrawRectanglePro(
			Rectangle{ entityArray[i].x, entityArray[i].y, entityArray[i].size, entityArray[i].size}, // rectangle
			Vector2{ entityArray[i].size / 2, entityArray[i].size / 2 }, // origin
			entityArray[i].rotation,
			Color{ entityArray[i].r, entityArray[i].g, entityArray[i].b, 255 });
	}

	// output some text, uses the last used colour
	DrawText("Press ESC to quit", 630, 15, 12, LIGHTGRAY);

	EndDrawing();
}