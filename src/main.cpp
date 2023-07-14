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
    const int screenWidth = 1600;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "MVVM Example");

    GameModel model;

    GameView view;
    GameViewModel viewModel;

    //Init map

    model.SetMapModel("ground_1", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(0, 700));
    model.SetMapModel("ground_2", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279, 700));
    model.SetMapModel("ground_3", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279, 600));
    model.SetMapModel("ground_4", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279*1, 700));
    model.SetMapModel("ground_5", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279*2, 700));
    model.SetMapModel("ground_6", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279*3, 700));
    model.SetMapModel("ground_7", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279*4, 700));
    model.SetMapModel("ground_8", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279*5, 700));
    model.SetMapModel("ground_9", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279*6, 700));
    model.SetMapModel("ground_10", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279*7, 700));
    model.SetMapModel("ground_11", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279*8, 700));
    model.SetMapModel("ground_12", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279, 300));

    
    



    viewModel.setModel(&model);
    view.setCommon(model.GetGameCommonPtr());

    SetTargetFPS(5);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);
        
        for(int i = 0; i < model.getMaplist().size();i++)
        {
            view.Draw(model.getMaplist()[i].getPath(), model.getMaplist()[i].getPosition(), raylib::Rectangle(0.0f, 0.0f,model.GetMapWidth(i) , model.GetMapHeight(i)));
        }
        // view.draw(view.getGameCommonPtr()->getScore(), view.getGameCommonPtr()->getGameOver());

        EndDrawing();
    }

    CloseWindow();

    return 0;
}