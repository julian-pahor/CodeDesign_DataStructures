#include "ResourceManager.h"

Texture2D* ResourceManager::get(const char* filename)
{
	return nullptr;
}

unsigned long ResourceManager::hash(const char* filename) //djb2 hashing algorithm
{
	unsigned long hash = 5381;
	int i = 0;

	for (char c = filename[i]; c != '\0'; i++)
	{
		hash = ((hash << 5) + hash) + c;
		c = filename[i];
	}

	return hash;
}
