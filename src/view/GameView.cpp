//
// Created by Hjuntao on 2023/7/12.
//

#include "raylib.h"
#include "GameView.h"
#include <stdlib.h>
#include <string>

void GameView::draw(int score, bool gameOver)
{
    DrawText(("Game Score: " + std::to_string(score)).c_str(), 10, 10, 20, BLACK);
    if (gameOver)
    {
        DrawText("Game Over", 10, 70, 20, RED);
    }
}

void GameView::UpdateScore()
{
    if (IsKeyPressed(KEY_SPACE))
    {
        updateViewCommand();
    }
}

void GameView::GameOver()
{
    if (IsKeyPressed(KEY_ENTER))
    {
        setGameOverCommand(true);
    }
}

std::function<void()> GameView::setUpdateViewCommand(std::function<void()> command)
{
    return updateViewCommand = command;
}
std::function<void()> GameView::setIncreaseScoreCommand(std::function<void()> command)
{
    return increaseScoreCommand = command;
}
std::function<void(bool)> GameView::setSetGameOverCommand(std::function<void(bool)> command)
{
    return setGameOverCommand = command;
}
