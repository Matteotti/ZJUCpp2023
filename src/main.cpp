//
// Created by Hjuntao on 2023/7/12.
//

#include <iostream>
#include <string>
#include <memory>

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
    model.setScore(10);

    GameView view;
    GameViewModel viewModel;

    viewModel.setModel(&model);
    view.setCommon(model.getGameCommonPtr());

    SetTargetFPS(60);

    view.setIncreaseScoreCommand(viewModel.getIncreaseScoreCommand());
    view.setSetGameOverCommand(viewModel.getSetGameOverCommand());

    while (!WindowShouldClose())
    {
        if (!view.getGameCommonPtr()->getGameOver())
        {
            view.UpdateScore();
            view.GameOver();
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        view.drawExample(view.getGameCommonPtr()->getScore(), view.getGameCommonPtr()->getGameOver());

        EndDrawing();
    }

    CloseWindow();

    return 0;
}