//
// Created by Hjuntao on 2023/7/12.
//

#include "GameModel.h"

GameModel::GameModel()
{
    this->gameCommonPtr = std::make_shared<GameCommon>();
}

std::shared_ptr<GameCommon> GameModel::GetGameCommonPtr()
{
    return gameCommonPtr;
}

#pragma region Player
raylib::Vector2 GameModel::GetPlayerPosition()
{
    return gameCommonPtr->GetPlayerPosition();
}
void GameModel::SetPlayerPosition(raylib::Vector2 position)
{
    gameCommonPtr->SetPlayerPosition(position);
}
raylib::Vector2 GameModel::GetPlayerSpeed()
{
    return player->currentSpeed;
}
void GameModel::SetPlayerSpeed(raylib::Vector2 speed)
{
    player->currentSpeed = speed;
}
AnimatorState GameModel::GetPlayerAnimatorState()
{
    return player->currentState;
}
void GameModel::GameModel::SetPlayerAnimatorState(AnimatorState state)
{
    player->currentState = state;
}
int GameModel::GetPlayerHP()
{
    return player->HP;
}
void GameModel::SetPlayerHP(int hp)
{
    player->HP = hp;
}
int GameModel::GetPlayerMP()
{
    return player->MP;
}
void GameModel::SetPlayerMP(int mp)
{
    player->MP = mp;
}
int GameModel::GetPlayerJumpCount()
{
    return player->jumpCount;
}
void GameModel::SetPlayerJumpCount(int jumpCount)
{
    player->jumpCount = jumpCount;
}
bool GameModel::GetPlayerIsGrounded()
{
    return player->isGrounded;
}
void GameModel::SetPlayerIsGrounded(bool isGrounded)
{
    player->isGrounded = isGrounded;
}
bool GameModel::GetPlayerIsLeftWalled()
{
    return player->isLeftWalled;
}
void GameModel::SetPlayerIsLeftWalled(bool isLeftWalled)
{
    player->isLeftWalled = isLeftWalled;
}
bool GameModel::GetPlayerIsRightWalled()
{
    return player->isRightWalled;
}
void GameModel::SetPlayerIsRightWalled(bool isRightWalled)
{
    player->isRightWalled = isRightWalled;
}
bool GameModel::GetPlayerIsCeilinged()
{
    return player->isCeilinged;
}
void GameModel::SetPlayerIsCeilinged(bool isCeilinged)
{
    player->isCeilinged = isCeilinged;
}
bool GameModel::GetPlayerIsJumping()
{
    return player->isJumping;
}
void GameModel::SetPlayerIsJumping(bool isJumping)
{
    player->isJumping = isJumping;
}
bool GameModel::GetPlayerIsFacingRight()
{
    return player->isFacingRight;
}
void GameModel::SetPlayerIsFacingRight(bool isFacingRight)
{
    player->isFacingRight = isFacingRight;
}
std::string GameModel::GetPlayerAnimationPath()
{
    return player->playerAnimationInfo->path;
}
void GameModel::SetPlayerAnimationPath(std::string path)
{
    player->playerAnimationInfo->path = path;
}
bool GameModel::GetPlayerAnimationIsStop()
{
    return player->playerAnimationInfo->stop;
}
void GameModel::SetPlayerAnimationIsStop(bool stop)
{
    player->playerAnimationInfo->stop = stop;
}
int GameModel::GetPlayerAnimationFrameCount()
{
    return player->playerAnimationInfo->frameCount;
}
void GameModel::SetPlayerAnimationFrameCount(int frameCount)
{
    player->playerAnimationInfo->frameCount = frameCount;
}
int GameModel::GetPlayerAnimationCurrentFrame()
{
    return player->playerAnimationInfo->currentFrame;
}
void GameModel::SetPlayerAnimationCurrentFrame(int currentFrame)
{
    player->playerAnimationInfo->currentFrame = currentFrame;
}
float GameModel::GetPlayerAnimationFrameWidth()
{
    return player->playerAnimationInfo->frameWidth;
}
void GameModel::SetPlayerAnimationFrameWidth(float frameWidth)
{
    player->playerAnimationInfo->frameWidth = frameWidth;
}
float GameModel::GetPlayerAnimationFrameHeight()
{
    return player->playerAnimationInfo->frameHeight;
}
void GameModel::SetPlayerAnimationFrameHeight(float frameHeight)
{
    player->playerAnimationInfo->frameHeight = frameHeight;
}
float GameModel::GetPlayerAnimationFrameTime()
{
    return player->playerAnimationInfo->frameTime;
}
void GameModel::SetPlayerAnimationFrameTime(float frameTime)
{
    player->playerAnimationInfo->frameTime = frameTime;
}
float GameModel::GetPlayerAnimationFrameTimeCounter()
{
    return player->playerAnimationInfo->frameTimeCounter;
}
void GameModel::SetPlayerAnimationFrameTimeCounter(float frameTimeCounter)
{
    player->playerAnimationInfo->frameTimeCounter = frameTimeCounter;
}
#pragma endregion
