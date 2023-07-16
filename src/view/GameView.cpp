//
// Created by Hjuntao on 2023/7/12.
//

#include "raylib.h"
#include "GameView.h"
#include <string>

GameView::GameView()
{
    // initialize ui
    ui = UI("../assets/ui/HP_bar_unit.png", "../assets/ui/HP_bar_unit_empty.png", "../assets/ui/MP_bar.png", "../assets/ui/Background.png");
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
        if (IsKeyDown(KEY_UP))
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

void GameView::UpdateCamera(Camera2D *camera, raylib::Vector2 position, int width, int height)
{
    camera->offset = raylib::Vector2(width / 2.0f, height / 2.0f);
    camera->target = position;
}

void GameView::UpdatePlayer()
{
    playerUpdateJumpSpeedCommand();
    playerCheckWallCommand();
    playerAniamtorUpdateCommand();
    playerAniamtionUpdateCommand();
    playerUpdatePositionCommand();
    playerUpdateAnimationFrameCommand();
    UpdatePlayerAttack(gameCommonPtr->GetPlayerIsFacingRight());
    UpdateCamera(&camera, raylib::Vector2(gameCommonPtr->GetPlayerPosition().x, gameCommonPtr->GetPlayerPosition().y - 100), 1600, 900);
    playerUpdateAnimationRectCommand(raylib::Vector2(PLAYER_ANIMATION_BIAS_X, 0));
    // drawPlayerCommand();
}

void GameView::UpdateEnemy()
{
    updateEnemyAnimStateCommand();
    updateEnemySpeedCommand();
    updateEnemyWallCheckCommand();
    updateEnemySpeedPhysicallyCommand();
    updateEnemyAnimationCommand();
    updateEnemyPositionCommand();
    updateEnemyColliderPositionCommand();
    updateEnemyAnimationFrameCommand();
    updateEnemyAnimationRectCommand();
    checkCollisionWithPlayerCommand();
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

void GameView::SetPlayerUpdateAnimationRectCommand(std::function<void(raylib::Vector2)> command)
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

void GameView::SetUpdateEnemyAnimState(std::function<void()> command)
{
    updateEnemyAnimStateCommand = command;
}

void GameView::SetUpdateEnemySpeed(std::function<void()> command)
{
    updateEnemySpeedCommand = command;
}

void GameView::SetUpdateEnemySpeedPhysically(std::function<void()> command)
{
    updateEnemySpeedPhysicallyCommand = command;
}

void GameView::SetUpdateEnemyAnimation(std::function<void()> command)
{
    updateEnemyAnimationCommand = command;
}

void GameView::SetUpdateEnemyPosition(std::function<void()> command)
{
    updateEnemyPositionCommand = command;
}

void GameView::SetUpdateEnemyColliderPosition(std::function<void()> command)
{
    updateEnemyColliderPositionCommand = command;
}

void GameView::SetUpdateEnemyAnimationFrame(std::function<void()> command)
{
    updateEnemyAnimationFrameCommand = command;
}

void GameView::SetUpdateEnemyAnimationRect(std::function<void()> command)
{
    updateEnemyAnimationRectCommand = command;
}

void GameView::SetCheckCollisionWithPlayer(std::function<void()> command)
{
    checkCollisionWithPlayerCommand = command;
}

void GameView::SetUpdateEnemyWallCheck(std::function<void()> command)
{
    updateEnemyWallCheckCommand = command;
}

void GameView::Draw(
    std::string path,
    raylib::Vector2 position,
    raylib::Rectangle src)
{
    temp = LoadTexture(path.c_str());
    temp.Draw(src, position);
    // temp.Unload();
}

void GameView::SetCommon(std::shared_ptr<GameCommon> gameCommon)
{
    gameCommonPtr = gameCommon;
}
