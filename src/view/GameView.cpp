//
// Created by Hjuntao on 2023/7/12.
//

#include "raylib.h"
#include "GameView.h"
#include <string>

GameView::GameView() {}

void GameView::setCommon(std::shared_ptr<GameCommon> gameCommon) {
    this->gameCommonPtr = gameCommon;
}

void GameView::drawExample(int score, bool gameOver)
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
        playerJumpCommand();
    }
}

void GameView::GameOver()
{
    if (IsKeyPressed(KEY_ENTER))
    {
        setGameOverCommand(true);
    }
}

//executes every frame
void GameView::UpdatePlayerMove()
{
    if(!(IsKeyDown(KEY_LEFT)&&IsKeyDown(KEY_RIGHT))){
        if (IsKeyDown(KEY_LEFT))
        {
            playerMoveCommand(LEFT);
        } else if (IsKeyDown(KEY_RIGHT))
        {
            playerMoveCommand(RIGHT);
        }
    }
    if((!IsKeyDown(KEY_LEFT))&&IsKeyReleased(KEY_RIGHT)){
        playerMoveCommand(STILL);
    } else if((!IsKeyDown(KEY_RIGHT))&&IsKeyReleased(KEY_LEFT)){
        playerMoveCommand(STILL);
    } else if(IsKeyReleased(KEY_LEFT)&&IsKeyReleased(KEY_RIGHT)){
        playerMoveCommand(STILL);
    }
}

void GameView::UpdatePlayerJump()
{
    if (IsKeyPressed(KEY_SPACE))
    {
        playerJumpCommand();
    }
}

void GameView::UpdatePlayerAttack() {
    if(IsKeyPressed(KEY_Z)){

    }
}

void GameView::drawTexture(
        raylib::TextureUnmanaged texture,
        raylib::Vector2 position,
        raylib::Rectangle src
)
{
    texture.Draw(src, position, WHITE);
}

void GameView::setIncreaseScoreCommand(std::function<void()> command)
{
    increaseScoreCommand = command;
}
void GameView::setSetGameOverCommand(std::function<void(bool)> command)
{
    setGameOverCommand = command;
}

void GameView::setPlayerMoveCommand(std::function<void(direction)> command)
{
    playerMoveCommand = command;
}

void GameView::setPlayerJumpCommand(std::function<void()> command)
{
    playerJumpCommand = command;
}

void GameView::setPlayerAttackCommand(std::function<void(int)> command)
{
    playerAttackCommand = command;
}
