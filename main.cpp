#include <iostream>
#include <raylib.h>

using namespace std;

int main()
{
    InitWindow(800, 600, "Hello World");
    SetTargetFPS(60);

    Image red = GenImageColor(256, 256, RED);
    Texture2D texture = LoadTextureFromImage(red);
    UnloadImage(red);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(texture, 100, 0, WHITE);
        EndDrawing();
    }

    UnloadTexture(texture);
    CloseWindow();
    return 0;
}