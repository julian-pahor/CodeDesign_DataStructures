#include "HashTable.h"
#include "raylib.h"

HashTable::HashTable(unsigned int size)
{
	m_size = size;
	m_data = new Pair[size];
}

void HashTable::loadTexture(std::string key)
{

	auto hashedKey = hashFunction(key) % m_size;

	const char* keyChars = key.c_str();


	if (!m_data[hashedKey].first)
	{
		m_data[hashedKey].second = LoadTexture(keyChars);
		m_data[hashedKey].first = true;
	}
	else
	{
		std::cout << "There is already a texture loaded there!" << std::endl;
	}
	

	
}

Texture2D HashTable::getTexture(std::string key)
{
	auto hashedKey = hashFunction(key) % m_size;

	if (m_data[hashedKey].first)
	{
		return m_data[hashedKey].second;
	}
	else
	{
		throw std::runtime_error("No texture in that key: " + key);
	}
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
