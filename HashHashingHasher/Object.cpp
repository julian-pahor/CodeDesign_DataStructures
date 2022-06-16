#include "Object.h"

void Object::Draw()
{
	DrawTexture(m_texture, m_pos.x, m_pos.y, RAYWHITE);
}
