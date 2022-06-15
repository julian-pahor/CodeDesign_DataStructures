#pragma once
#include "raylib.h"

class ResourceManager
{
public:

	ResourceManager() {};
	Texture2D* get(const char* filename);
	unsigned long hash(const char* filename); //implementing djb2 hash

private:
	
	

	int tableSize = 100;
	Texture2D** hashTable = new Texture2D * [tableSize];
};

