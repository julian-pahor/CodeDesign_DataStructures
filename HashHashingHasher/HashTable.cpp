#include "HashTable.h"
#include "raylib.h"

HashTable::HashTable(unsigned int size)
{
	m_size = size;
	m_data = new Texture2D[size];
}

void HashTable::loadTexture(std::string key)
{

	auto hashedKey = hashFunction(key) % m_size;

	const char* keyChars = key.c_str();

	m_data[hashedKey] = LoadTexture(keyChars);

	
}

Texture2D HashTable::getTexture(std::string key)
{
	auto hashedKey = hashFunction(key) % m_size;

	return m_data[hashedKey];
}

unsigned int HashTable::hashFunction(std::string key)
{
	//djb2 hash implementation

	unsigned int hash = 5381;

	int length = key.length();

	for (int i = 0; i < length; i++)
	{
		hash = ((hash << 5) + hash) + key[i];
	}

	return hash;
}
