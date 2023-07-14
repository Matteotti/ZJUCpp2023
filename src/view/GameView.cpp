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

/* void GameView::setPlayerAttackCommand(std::function<void(int)> command)
{
    playerAttackCommand = command;
} */





void GameView::Attack()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && IsKeyDown(KEY_W))
    {
        attackTopCommand();
    }
    else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && IsKeyDown(KEY_S))
    {
        attackDownCommand();
    }
}

void GameView::setAttackTopCommand(std::function<void()> command)
{
    attackTopCommand = command;
}

void GameView::setAttackDownCommand(std::function<void()> command)
{
    attackDownCommand = command;
}

void GameView::Draw(
        std::string path,
        raylib::Vector2 position,
        raylib::Rectangle src
)
{
    raylib::Texture2DUnmanaged temp = LoadTexture(path.c_str());
    temp.Draw(src, position);
    //temp.Unload();
}


