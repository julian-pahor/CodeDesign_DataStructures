#include <iostream>

#include "DoubleLinkedList.h"
#include "raylib.h"
#include <string>
#include <vector>

int main()
{
    DoubleLinkedList list; 

    const static int textureCount = 5;
    Texture2D textures[textureCount];
    Vector2 pos = { 20, 20 };
    std::vector<int> data;

    InitWindow(1600, 900, "raylib [core] example - basic window");

    textures[0] = LoadTexture("tree.png");
    textures[1] = LoadTexture("treePineSnow.png");
    textures[2] = LoadTexture("treePineOrange.png");
    textures[3] = LoadTexture("treePineFrozen.png");
    textures[4] = LoadTexture("treeDead.png");

    list.pushBack(0);
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);


    while (!WindowShouldClose())
    {

        if (IsKeyPressed(KEY_Q))
        {
            list.pushFront(0);
        }
        if (IsKeyPressed(KEY_W))
        {
            list.pushFront(1);
        }
        if (IsKeyPressed(KEY_E))
        {
            list.pushFront(2);
        }
        if (IsKeyPressed(KEY_R))
        {
            list.pushFront(3);
        }
        if (IsKeyPressed(KEY_T))
        {
            list.pushFront(4);
        }
        if (IsKeyPressed(KEY_L))
        {
            list.clear();
        }
        if (IsKeyPressed(KEY_P))
        {
            list.sort();
        }


        Node* node = list.begin();

        if (node != nullptr)
        {
            while (node != nullptr)
            {
                data.push_back(node->data);
                node = node->next;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i : data)
        {
            DrawTextureEx(textures[i], pos, 0, 0.3, RAYWHITE);
            pos.x += 30;
        }

        EndDrawing();

        pos.x = 20;
        data.clear();
    }

    CloseWindow();

    return 0;

}
