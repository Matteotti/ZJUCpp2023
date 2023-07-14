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
raylib::Rectangle GameModel::GetPlayerSourceRec()
{
    return gameCommonPtr->GetPlayerSourceRect();
}
void GameModel::SetPlayerSourceRec(raylib::Rectangle sourceRec)
{
    gameCommonPtr->SetPlayerSourceRect(sourceRec);
}
raylib::Vector2 GameModel::GetPlayerSpeed()
{
    return player->currentSpeed;
}
void GameModel::SetPlayerSpeed(raylib::Vector2 speed)
{
    player->currentSpeed = speed;
}
std::string GameModel::GetPlayerColliderName()
{
    return player->playerCollider->colliderName;
}
void GameModel::SetPlayerColliderName(std::string name)
{
    player->playerCollider->colliderName = name;
}
raylib::Rectangle GameModel::GetPlayerColliderBox()
{
    return player->playerCollider->colliderBox;
}
void GameModel::SetPlayerColliderBox(raylib::Rectangle colliderBox_)
{
    player->playerCollider->colliderBox = colliderBox_;
}
void GameModel::SetPlayerColliderBoxPosition(raylib::Vector2 deltaPosition)
{
    player->playerCollider->colliderBox.x += deltaPosition.x;
    player->playerCollider->colliderBox.y += deltaPosition.y;
}
raylib::Vector2 GameModel::GetPlayerColliderCenter()
{
    return player->playerCollider->center;
}
void GameModel::SetPlayerColliderCenter(raylib::Vector2 center_)
{
    player->playerCollider->center = center_;
}
float GameModel::GetPlayerColliderRadius()
{
    return player->playerCollider->radius;
}
void GameModel::SetPlayerColliderRadius(float radius_)
{
    player->playerCollider->radius = radius_;
}
ColliderTag GameModel::GetPlayerColliderTag()
{
    return player->playerCollider->colliderTag;
}
void GameModel::SetPlayerColliderTag(ColliderTag tag)
{
    player->playerCollider->colliderTag = tag;
}
ColliderType GameModel::GetPlayerColliderType()
{
    return player->playerCollider->colliderType;
}
void GameModel::SetPlayerColliderType(ColliderType type)
{
    player->playerCollider->colliderType = type;
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
float GameModel::GetPlayerJumpCounter()
{
    return player->jumpCounter;
}
void GameModel::SetPlayerJumpCounter(float jumpCounter)
{
    player->jumpCounter = jumpCounter;
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
    return gameCommonPtr->GetPlayerAnimPath();
}
void GameModel::SetPlayerAnimationPath(std::string path)
{
    gameCommonPtr->SetPlayerAnimPath(path);
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
std::vector<CustomCollider *> GameModel::GetColliders()
{
    return colliders_;
}
void GameModel::SetColliders(std::vector<CustomCollider *> colliders)
{
    colliders_ = colliders;
}
void GameModel::AddCollider(CustomCollider *collider)
{
    colliders_.push_back(collider);
}
void GameModel::RemoveCollider(CustomCollider *collider)
{
    for (int i = 0; i < colliders_.size(); i++)
    {
        if (collider->colliderName == colliders_[i]->colliderName)
        {
            colliders_.erase(colliders_.begin() + i);
        }
    }
}
void GameModel::ClearColliders()
{
    colliders_.clear();
}
void GameModel::UpdateColliderPosition(std::string name, raylib::Vector2 position)
{
    for (int i = 0; i < colliders_.size(); i++)
    {
        if (colliders_[i]->colliderName == name)
        {
            colliders_[i]->colliderBox.x = position.x;
            colliders_[i]->colliderBox.y = position.y;
        }
    }
}
CustomCollider *GameModel::GetPlayerCollider()
{
    return player->playerCollider;
}
void GameModel::SetPlayerCollider(CustomCollider *collider)
{
    player->playerCollider = collider;
}
CustomCollider *GameModel::GetLeftWallCheck()
{
    return leftWallCheck_;
}
void GameModel::SetLeftWallCheck(CustomCollider *leftWallCheck)
{
    leftWallCheck_ = leftWallCheck;
}
void GameModel::SetLeftWallCheckPosition(raylib::Vector2 deltaPosition)
{
    rightWallCheck_->colliderBox.x += deltaPosition.x;
    rightWallCheck_->colliderBox.y += deltaPosition.y;
}
CustomCollider *GameModel::GetRightWallCheck()
{
    return rightWallCheck_;
}
void GameModel::SetRightWallCheck(CustomCollider *rightWallCheck)
{
    rightWallCheck_ = rightWallCheck;
}
void GameModel::SetRightWallCheckPosition(raylib::Vector2 deltaPosition)
{
    rightWallCheck_->colliderBox.x += deltaPosition.x;
    rightWallCheck_->colliderBox.y += deltaPosition.y;
}
CustomCollider *GameModel::GetCeilingCheck()
{
    return ceilingCheck_;
}
void GameModel::SetCeilingCheck(CustomCollider *ceilingCheck)
{
    ceilingCheck_ = ceilingCheck;
}
void GameModel::SetCeilingCheckPosition(raylib::Vector2 deltaPosition)
{
    ceilingCheck_->colliderBox.x += deltaPosition.x;
    ceilingCheck_->colliderBox.y += deltaPosition.y;
}
CustomCollider *GameModel::GetGroundCheck()
{
    return groundCheck_;
}
void GameModel::SetGroundCheck(CustomCollider *groundCheck)
{
    groundCheck_ = groundCheck;
}
void GameModel::SetGroundCheckPosition(raylib::Vector2 deltaPosition)
{
    groundCheck_->colliderBox.x += deltaPosition.x;
    groundCheck_->colliderBox.y += deltaPosition.y;
}
#pragma endregion
