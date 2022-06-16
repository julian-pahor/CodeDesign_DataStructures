// HashHashingHasher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "HashTable.h"
#include"Object.h"
#include <string>
#include<vector>

void Plop(std::string key);

HashTable* hashTable;
std::vector<Object*> objects;

int main()
{
    InitWindow(800, 450, "raylib [core] example - basic window");
    
    SetTargetFPS(60);

    hashTable = new HashTable(20);

    hashTable->loadTexture("hotdog.png");
    hashTable->loadTexture("police.png");
    hashTable->loadTexture("riot.png");
    hashTable->loadTexture("scooter.png");
    hashTable->loadTexture("trucktank.png");

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_A))
        {
            Plop("hotdog.png");
        }
        if (IsKeyPressed(KEY_S))
        {
            Plop("police.png");
        }
        if (IsKeyPressed(KEY_D))
        {
            Plop("riot.png");
        }
        if (IsKeyPressed(KEY_F))
        {
            Plop("scooter.png");
        }
        if (IsKeyPressed(KEY_G))
        {
            Plop("trucktank.png");
        }

        BeginDrawing();

        for (Object* o : objects)
        {
            o->Draw();
        }

        ClearBackground(RAYWHITE);
        DrawText("Congrats! You're being overrun by vehicles!", 190, 200, 20, BLACK);
        DrawFPS(10, 10);
        EndDrawing();
    }

    for (Object* o : objects)
    {
        delete o;
    }

    CloseWindow();

    return 0;
}

void Plop(std::string key)
{
    Vector2 pos = { GetRandomValue(0, GetScreenWidth()), GetRandomValue(0, GetScreenHeight()) };
    Object* newObject = new Object(hashTable->getTexture(key), pos);
    objects.push_back(newObject);
}
