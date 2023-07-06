#include "includes/main.h"
#include <cstdio>
#include <string>


int main()
{
    InitWindow(800, 450, "Hollow Knight");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update Data Here

        // End Update

        // Draw Here
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello World", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
        // End Draw


    }
}