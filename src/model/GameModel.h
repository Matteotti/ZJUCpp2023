//
// Created by Hjuntao on 2023/7/12.
//

#ifndef CPPGAMEJAM_GAMEMODEL_H
#define CPPGAMEJAM_GAMEMODEL_H

#include <memory>
#include <string>
#include <vector>
#include <malloc.h>
#include "raylib.h"
#include "../common/GameCommon.h"
#include "../../includes/animation.h"
#include "../../includes/customCollider.h"
#include "../../includes/player.h"
#include "../../includes/animation.h"

class GameModel
{

private:
    std::shared_ptr<GameCommon> gameCommonPtr;
    PlayerInModel *player = static_cast<PlayerInModel *>(malloc(sizeof(PlayerInModel)));
    CustomCollider *leftWallCheck_ = static_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    CustomCollider *rightWallCheck_ = static_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    CustomCollider *ceilingCheck_ = static_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    CustomCollider *groundCheck_ = static_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    std::vector<CustomCollider *> colliders_;
    AnimationInfo *animationInfo;

    // map
    std::shared_ptr<MapCommon> mapCommonPtr;
    std::string mapName;
    std::string path;
    int frameCount = 0;
    int mapWidth;
    int mapHeight;
    AnimationInfo* mapAnimationInfo;
    CustomCollider* mapCollider;
    std::vector<MapCommon> maplist;
    std::vector<int> mapWidthList;
    std::vector<int> mapHeightList;

public:
    GameModel();
    std::shared_ptr<GameCommon> GetGameCommonPtr();

    raylib::Vector2 GetPlayerPosition();
    void SetPlayerPosition(raylib::Vector2 position);
    raylib::Rectangle GetPlayerSourceRec();
    void SetPlayerSourceRec(raylib::Rectangle sourceRec);
    raylib::Vector2 GetPlayerSpeed();
    void SetPlayerSpeed(raylib::Vector2 speed);
    std::string GetPlayerColliderName();
    AnimationInfo *GetPlayerAnimationInfo();
    void SetPlayerAnimationInfo(AnimationInfo *animationInfo);
    CustomCollider *GetPlayerCollider();
    void SetPlayerCollider(CustomCollider *collider);
    void SetPlayerColliderName(std::string name);
    raylib::Rectangle GetPlayerColliderBox();
    void SetPlayerColliderBox(raylib::Rectangle colliderBox);
    void SetPlayerColliderBoxPosition(raylib::Vector2 deltaPosition);
    raylib::Vector2 GetPlayerColliderCenter();
    void SetPlayerColliderCenter(raylib::Vector2 center);
    float GetPlayerColliderRadius();
    void SetPlayerColliderRadius(float radius);
    ColliderTag GetPlayerColliderTag();
    void SetPlayerColliderTag(ColliderTag tag);
    ColliderType GetPlayerColliderType();
    void SetPlayerColliderType(ColliderType type);
    AnimatorState GetPlayerAnimatorState();
    void SetPlayerAnimatorState(AnimatorState state);
    int GetPlayerHP();
    void SetPlayerHP(int hp);
    int GetPlayerMP();
    void SetPlayerMP(int mp);
    int GetPlayerJumpCount();
    void SetPlayerJumpCount(int jumpCount);
    float GetPlayerJumpCounter();
    void SetPlayerJumpCounter(float jumpCounter);
    bool GetPlayerIsGrounded();
    void SetPlayerIsGrounded(bool isGrounded);
    bool GetPlayerIsLeftWalled();
    void SetPlayerIsLeftWalled(bool isLeftWalled);
    bool GetPlayerIsRightWalled();
    void SetPlayerIsRightWalled(bool isRightWalled);
    bool GetPlayerIsCeilinged();
    void SetPlayerIsCeilinged(bool isCeilinged);
    bool GetPlayerIsJumping();
    void SetPlayerIsJumping(bool isJumping);
    bool GetPlayerIsFacingRight();
    void SetPlayerIsFacingRight(bool isFacingRight);
    std::string GetPlayerAnimationPath();
    void SetPlayerAnimationPath(std::string path);
    bool GetPlayerAnimationIsStop();
    void SetPlayerAnimationIsStop(bool stop);
    int GetPlayerAnimationFrameCount();
    void SetPlayerAnimationFrameCount(int frameCount);
    int GetPlayerAnimationCurrentFrame();
    void SetPlayerAnimationCurrentFrame(int currentFrame);
    float GetPlayerAnimationFrameWidth();
    void SetPlayerAnimationFrameWidth(float frameWidth);
    float GetPlayerAnimationFrameHeight();
    void SetPlayerAnimationFrameHeight(float frameHeight);
    float GetPlayerAnimationFrameTime();
    void SetPlayerAnimationFrameTime(float frameTime);
    float GetPlayerAnimationFrameTimeCounter();
    void SetPlayerAnimationFrameTimeCounter(float frameTimeCounter);
    std::vector<CustomCollider *> GetColliders();
    void SetColliders(std::vector<CustomCollider *> colliders);
    void AddCollider(CustomCollider *collider);
    void RemoveCollider(CustomCollider *collider);
    void ClearColliders();
    void UpdateColliderPosition(std::string name, raylib::Vector2 position);
    CustomCollider *GetLeftWallCheck();
    void SetLeftWallCheck(CustomCollider *leftWallCheck);
    void SetLeftWallCheckPosition(raylib::Vector2 deltaPosition);
    CustomCollider *GetRightWallCheck();
    void SetRightWallCheck(CustomCollider *rightWallCheck);
    void SetRightWallCheckPosition(raylib::Vector2 deltaPosition);
    CustomCollider *GetCeilingCheck();
    void SetCeilingCheck(CustomCollider *ceilingCheck);
    void SetCeilingCheckPosition(raylib::Vector2 deltaPosition);
    CustomCollider *GetGroundCheck();
    void SetGroundCheck(CustomCollider *groundCheck);
    void SetGroundCheckPosition(raylib::Vector2 deltaPosition);

    void SetAnimationInfoPath(std::string path);
    void SetAnimationInfoFrameCount(int frameCount);
    // friend class MapModel;

    //map
    void SetMapModel(const std::string mapName, std::string path, int frameCount, raylib::Vector2 positionn);
    std::shared_ptr<MapCommon> GetMapCommonPtr();
    std::string GetMapName();

    void SetMapAnimationInfoPath(std::string path);
    void SetMapAnimationInfoFrameCount(int frameCount);
    void SetAnimationInfoCurrentFrame(int currentFrame);
    void SetAnimationInfoFrameTimeCounter(float frameTimeCounter);
    void SetAnimationInfoFrameTime(float frameTime);
    void SetAnimationInfoStop(bool stop);
    void SetAnimationInfoFrameWidth(float frameWidth);
    void SetAnimationInfoFrameHeight(float frameHeight);

    void SetColliderName(std::string name);
    void SetColliderColliderBox(float x, float y, float width, float height);
    void SetColliderCenter(raylib::Vector2 center);
    void SetColliderRadius(float radius);
    void SetColliderTag(ColliderTag tag);
    void SetColliderType(ColliderType type);
    void SetMapName(std::string mapname);
    void SetMapWidth(float width);
    void SetMapHeight(float height);
    int GetMapWidth(int index);
    int GetMapHeight(int index);


    std::vector<MapCommon> getMaplist() const;
};

#endif // CPPGAMEJAM_GAMEMODEL_H
