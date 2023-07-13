//
// Created by Hjuntao on 2023/7/12.
//

#include <iostream>
#include <string>
#include <memory>

#include "raylib.h"
#include "raylib-cpp.hpp"

#include "raylib.h"
#include "model/GameModel.h"
#include "view/GameView.h"
#include "viewModel/GameViewModel.h"
#include "common/GameCommon.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "MVVM Example");

    GameModel model;

    GameView view;
    GameViewModel viewModel;

    viewModel.setModel(&model);
    view.setCommon(model.GetGameCommonPtr());

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        // view.draw(view.getGameCommonPtr()->getScore(), view.getGameCommonPtr()->getGameOver());

        EndDrawing();
    }

    CloseWindow();

    return 0;
}