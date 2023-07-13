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

class GameModel
{

private:
    std::shared_ptr<GameCommon> gameCommonPtr;
    PlayerInModel *player;
    CustomCollider *leftWallCheck_;
    CustomCollider *rightWallCheck_;
    CustomCollider *ceilingCheck_;
    CustomCollider *groundCheck_;
    std::vector<CustomCollider *> colliders_;

public:
    GameModel();
    std::shared_ptr<GameCommon> GetGameCommonPtr();

    raylib::Vector2 GetPlayerPosition();
    void SetPlayerPosition(raylib::Vector2 position);
    raylib::Rectangle GetPlayerSourceRec();
    void SetPlayerSourceRec(raylib::Rectangle sourceRec);
    raylib::Texture2DUnmanaged GetPlayerTexture();
    void SetPlayerTexture(raylib::Texture2DUnmanaged texture);
    raylib::Vector2 GetPlayerSpeed();
    void SetPlayerSpeed(raylib::Vector2 speed);
    std::string GetPlayerColliderName();
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
};

#endif // CPPGAMEJAM_GAMEMODEL_H
