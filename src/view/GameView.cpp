//
// Created by Hjuntao on 2023/7/12.
//

#include "raylib.h"
#include "GameView.h"
#include <stdlib.h>
#include <string>

GameView::GameView() {}

void GameView::setCommon(std::shared_ptr<GameCommon> gameCommonPtr) {
    this->gameCommonPtr = gameCommonPtr;
}

void GameView::draw(int score, bool gameOver)
{
    DrawText("MVVM test", 10, 10, 20, BLACK);
    DrawText(("Game Score: " + std::to_string(score)).c_str(), 10, 40, 20, BLACK);
    if (gameOver)
    {
        DrawText("Game Over", 10, 70, 20, RED);
    }
}

void GameView::UpdateScore()
{
    if (IsKeyPressed(KEY_SPACE))
    {
        increaseScoreCommand();
    }
}

void GameView::GameOver()
{
    if (IsKeyPressed(KEY_ENTER))
    {
        setGameOverCommand(true);
    }
}

void GameView::setIncreaseScoreCommand(std::function<void()> command)
{
    increaseScoreCommand = command;
}
void GameView::setSetGameOverCommand(std::function<void(bool)> command)
{
    setGameOverCommand = command;
}
