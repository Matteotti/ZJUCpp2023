//
// Created by Hjuntao on 2023/7/12.
//

#ifndef CPPGAMEJAM_GAMEMODEL_H
#define CPPGAMEJAM_GAMEMODEL_H

#include <memory>
#include <string>
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
    PlayerInModel *player;
    AnimationInfo *animationInfo;


public:
    GameModel();
    std::shared_ptr<GameCommon> GetGameCommonPtr();

    raylib::Vector2 GetPlayerPosition();
    void SetPlayerPosition(raylib::Vector2 position);
    raylib::Vector2 GetPlayerSpeed();
    void SetPlayerSpeed(raylib::Vector2 speed);
    AnimatorState GetPlayerAnimatorState();
    void SetPlayerAnimatorState(AnimatorState state);
    int GetPlayerHP();
    void SetPlayerHP(int hp);
    int GetPlayerMP();
    void SetPlayerMP(int mp);
    int GetPlayerJumpCount();
    void SetPlayerJumpCount(int jumpCount);
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


    void SetAnimationInfoPath(std::string path);
    void SetAnimationInfoFrameCount(int frameCount);
};


class MapModel {
private:
    std::shared_ptr<MapCommon> mapCommonPtr;
    std::string mapName;
    std::string path;
    int frameCount = 0;
    int width;
    int height;
    AnimationInfo* mapAnimationInfo;
    CustomCollider* mapCollider;
public:
    MapModel(const std::string &mapName, std::string path, int frameCount, raylib::Vector2 positionn);
    std::shared_ptr<MapCommon> GetMapCommonPtr();
    std::string GetMapName();

    void SetAnimationInfoPath(std::string path);
    void SetAnimationInfoFrameCount(int frameCount);
    void SetAnimationInfoCurrentFrame(int currentFrame);
    void SetAnimationInfoFrameTimeCounter(float frameTimeCounter);
    void SetAnimationInfoFrameTime(float frameTime);
    void SetAnimationInfoStop(bool stop);
    void SetAnimationInfoFrameWidth(float frameWidth);
    void SetAnimationInfoFrameHeight(float frameHeight);

    void SetColliderName(std::string name);
    void SetColliderColliderBox(float x,float y,float width,float height);
    void SetColliderCenter(raylib::Vector2 center);
    void SetColliderRadius(float radius);
    void SetColliderTag(ColliderTag tag);
    void SetColliderType(ColliderType type);

    //void LoadTexture(std::string path);


};
std::vector<MapModel> maplist;

#endif // CPPGAMEJAM_GAMEMODEL_H
