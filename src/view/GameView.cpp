//
// Created by Hjuntao on 2023/7/12.
//

#include "raylib.h"
#include "GameView.h"
#include <string>

GameView::GameView() {
    //initialize ui
    ui = UI();
    //initialize buttons
}

// executes every frame
void GameView::UpdatePlayerMove()
{
    if (!(IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_RIGHT)))
    {
        if (IsKeyDown(KEY_LEFT))
        {
            playerMoveCommand(LEFT);
        }
        else if (IsKeyDown(KEY_RIGHT))
        {
            playerMoveCommand(RIGHT);
        }
    }
    if ((!IsKeyDown(KEY_LEFT)) && IsKeyReleased(KEY_RIGHT))
    {
        playerMoveCommand(STILL);
    }
    else if ((!IsKeyDown(KEY_RIGHT)) && IsKeyReleased(KEY_LEFT))
    {
        playerMoveCommand(STILL);
    }
    else if (IsKeyReleased(KEY_LEFT) && IsKeyReleased(KEY_RIGHT))
    {
        playerMoveCommand(STILL);
    }
}

void GameView::UpdatePlayerJump()
{
    if (IsKeyPressed(KEY_SPACE))
    {
        playerJumpCommand(true);
    }
    else if (IsKeyReleased(KEY_SPACE))
    {
        playerJumpCommand(false);
    }
}

void GameView::UpdatePlayerAttack(bool isFacingRight)
{
    if (IsKeyPressed(KEY_Z))
    {
        if (IsKeyDown(KEY_RIGHT))
        {
            playerAttackCommand(RIGHT);
        }
        else if (IsKeyDown(KEY_LEFT))
        {
            playerAttackCommand(LEFT);
        }
        else if (IsKeyDown(KEY_UP))
        {
            playerAttackCommand(UP);
        }
        else if (IsKeyDown(KEY_DOWN))
        {
            playerAttackCommand(DOWN);
        }
        else
        {
            if (isFacingRight)
            {
                playerAttackCommand(RIGHT);
            }
            else
            {
                playerAttackCommand(LEFT);
            }
        }
    }
}

void GameView::Update()
{
    playerUpdateJumpSpeedCommand();
    playerCheckWallCommand();
    playerAniamtorUpdateCommand();
    playerAniamtionUpdateCommand();
    playerUpdatePositionCommand();
    playerUpdateAnimationFrameCommand();
    playerUpdateAnimationRectCommand();
    // drawPlayerCommand();
}

void GameView::SetPlayerMoveCommand(std::function<void(direction)> command)
{
    playerMoveCommand = command;
}

void GameView::SetPlayerJumpCommand(std::function<void(bool)> command)
{
    playerJumpCommand = command;
}

void GameView::SetPlayerUpdateJumpSpeedCommand(std::function<void()> command)
{
    playerUpdateJumpSpeedCommand = command;
}

void GameView::SetPlayerCheckWallCommand(std::function<void()> command)
{
    playerCheckWallCommand = command;
}

void GameView::SetPlayerAnimatorUpdateCommand(std::function<void()> command)
{
    playerAniamtorUpdateCommand = command;
}

void GameView::SetPlayerAnimationUpdateCommand(std::function<void()> command)
{
    playerAniamtionUpdateCommand = command;
}

void GameView::SetPlayerUpdatePositionCommand(std::function<void()> command)
{
    playerUpdatePositionCommand = command;
}

void GameView::SetPlayerUpdateAnimationFrameCommand(std::function<void()> command)
{
    playerUpdateAnimationFrameCommand = command;
}

void GameView::SetPlayerUpdateAnimationRectCommand(std::function<void()> command)
{
    playerUpdateAnimationRectCommand = command;
}

void GameView::SetPlayerAttackCommand(std::function<void(direction)> command)
{
    playerAttackCommand = command;
}
void GameView::SetDrawPlayerCommand(std::function<void()> command)
{
    drawPlayerCommand = command;
}

void GameView::Draw(
    std::string path,
    raylib::Vector2 position,
    raylib::Rectangle src)
{
    raylib::Texture2DUnmanaged temp = raylib::Texture2DUnmanaged(path);
    temp.Draw(src, position);
    // temp.Unload();
}


void GameView::SetCommon(std::shared_ptr<GameCommon> gameCommon)
{
    gameCommonPtr = gameCommon;
}

