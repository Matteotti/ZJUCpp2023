//
// Created by Hjuntao on 2023/7/12.
//

#include "GameModel.h"

GameModel::GameModel()
{
    this->gameCommonPtr = std::make_shared<GameCommon>();
    this->animationInfo = new AnimationInfo();
    this->mapAnimationInfo = new AnimationInfo();
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
AnimationInfo *GameModel::GetPlayerAnimationInfo()
{
    return player->playerAnimationInfo;
}
void GameModel::SetPlayerAnimationInfo(AnimationInfo *animationInfo)
{
    player->playerAnimationInfo = animationInfo;
}
CustomCollider *GameModel::GetPlayerCollider()
{
    return player->playerCollider;
}
void GameModel::SetPlayerCollider(CustomCollider *collider)
{
    player->playerCollider = collider;
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
    return gameCommonPtr->GetPlayerHP();
}
void GameModel::SetPlayerHP(int hp)
{
    gameCommonPtr->SetPlayerHP(hp);
}
int GameModel::GetPlayerMP()
{
    return gameCommonPtr->GetPlayerMP();
}
void GameModel::SetPlayerMP(int mp)
{
    gameCommonPtr->SetPlayerMP(mp);
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
    return gameCommonPtr->GetPlayerIsFacingRight();
}
void GameModel::SetPlayerIsFacingRight(bool isFacingRight)
{
    gameCommonPtr->SetPlayerIsFacingRight(isFacingRight);
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
    leftWallCheck_->colliderBox.x += deltaPosition.x;
    leftWallCheck_->colliderBox.y += deltaPosition.y;
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

/* void GameModel::SetAnimationInfoPath(std::string path)
{
    animationInfo->path = path;
}

void GameModel::SetAnimationInfoFrameCount(int frameCount)
{
    animationInfo->frameCount = frameCount;
}
 */

void GameModel::SetMapAnimationInfoPath(std::string path)
{
    this->path = path;
}

void GameModel::SetMapAnimationInfoFrameCount(int frameCount)
{
    this->frameCount = frameCount;
}

/* void GameModel::LoadTexture(std::string path)
{
    mapCommonPtr->SetPlayerTexture(raylib::Texture2DUnmanaged(path));
} */

void GameModel::SetColliderName(std::string name)
{
    mapCollider->colliderName = name;
}

void GameModel::SetColliderColliderBox(float x, float y, float width, float height)
{
    mapCollider->colliderBox = raylib::Rectangle(x, y, width, height);
}

void GameModel::SetColliderType(ColliderType type)
{
    mapCollider->colliderType = type;
}

void GameModel::SetColliderTag(ColliderTag tag)
{
    mapCollider->colliderTag = tag;
}

void GameModel::SetColliderCenter(raylib::Vector2 center)
{
    mapCollider->center = center;
}

void GameModel::SetColliderRadius(float radius)
{
    mapCollider->radius = radius;
}

void GameModel::SetMapName(std::string mapname)
{
    this->mapName = mapname;
}

void GameModel::SetMapWidth(float width)
{
    this->mapWidth = width;
}

void GameModel::SetMapHeight(float height)
{
    this->mapHeight = height;
}

void GameModel::SetMapModel(const std::string mapName, std::string path, int frameCount, raylib::Vector2 position)
{
    this->mapCollider = new CustomCollider();
    this->mapName = mapName;
    this->mapCommonPtr = std::make_shared<MapCommon>(position, path, frameCount);
    // this->mapCommonPtr = std::make_shared<MapCommon>(position, path, frameCount);
    this->SetMapAnimationInfoPath(path);
    this->SetMapAnimationInfoFrameCount(frameCount);
    raylib::Texture2DUnmanaged texture = raylib::Texture2DUnmanaged(path);
    // this->mapCommonPtr->SetMapTexture(raylib::Texture2DUnmanaged(path));
    this->mapWidth = texture.width / frameCount;
    this->mapHeight = texture.height;
    this->mapWidthList.push_back(mapWidth);
    this->mapHeightList.push_back(mapHeight);
    this->SetColliderName(mapName);
    this->SetColliderColliderBox(position.x, position.y, mapWidth, mapHeight);
    this->SetColliderTag(ColliderTag::ENVIRONMENT);
    colliders_.push_back(this->mapCollider);
    maplist.push_back(*this->mapCommonPtr);
}

std::shared_ptr<MapCommon> GameModel::GetMapCommonPtr()
{
    return mapCommonPtr;
}

std::string GameModel::GetMapName()
{
    return mapName;
}

std::vector<MapCommon> GameModel::getMaplist() const
{
    return maplist;
}

int GameModel::GetMapWidth(int index)
{
    return mapWidthList[index];
}

int GameModel::GetMapHeight(int index)
{
    return mapHeightList[index];
}

#pragma endregion
