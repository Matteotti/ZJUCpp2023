//
// Created by Hjuntao on 2023/7/12.
//

#include <iostream>
#include <string>

#include "raylib.h"
#include "raylib-cpp.hpp"

#include "raylib.h"
#include "model/GameModel.h"
#include "view/GameView.h"
#include "viewModel/GameViewModel.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "MVVM Example");

    GameModel model;
    GameView view;
    GameViewModel viewModel(&model, &view);

    SetTargetFPS(60);

    viewModel.Bind();

    while (!WindowShouldClose())
    {
        if (!model.gameOver)
        {
            view.UpdateScore();
            view.GameOver();
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        view.draw(model.score, model.gameOver);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}