#pragma once
#include "raylib.h"
#include <string>
#include <iostream>

class HashTable
{

	struct Pair
	{
		bool first = false;
		Texture2D second;
	};

public:
	HashTable(unsigned int size);

	~HashTable() { delete[] m_data; }


	/*Texture2D operator [] (std::string key)
	{
		auto hashedKey = hashFunction(key) % m_size;
		return m_data[hashedKey];
	}*/

	void loadTexture(std::string key);
	
	Texture2D getTexture(std::string key);

	
private:

	unsigned int hashFunction(std::string key);

	Pair* m_data;
	unsigned int m_size;

};

