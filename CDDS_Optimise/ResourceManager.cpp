#include "ResourceManager.h"
#include <string>

Texture2D* ResourceManager::get(const char* filename)
{
	return nullptr;
}

unsigned long ResourceManager::hash(const char* filename) //djb2 hashing algorithm
{
	unsigned long hash = 5381;
	/*int i = 0;

	for (char c = filename[i]; c != '\0'; i++)
	{
		hash = ((hash << 5) + hash) + c;
		c = filename[i];
	}*/

	int length = strlen(filename);

	for (int i = 0; i < length; i++)
	{
		hash = ((hash << 5) + hash) + filename[i];
	}


	/*int c = 0;

	while (c = *filename++)
	{
		hash = ((hash << 5) + hash) + c;
	}*/
	
	return hash;
}
