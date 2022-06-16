#pragma once
#include "raylib.h"

class Object
{
public:

	Object(Texture2D texture, Vector2 pos)
	{
		m_texture = texture;
		m_pos = pos;
	}

	void Draw();


private:
	Vector2 m_pos;
	Texture2D m_texture;

};

