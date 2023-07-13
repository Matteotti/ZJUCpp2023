//
// Created by Hjuntao on 2023/7/12.
//

#ifndef CPPGAMEJAM_GAMEMODEL_H
#define CPPGAMEJAM_GAMEMODEL_H

#include <memory>
#include "../common/GameCommon.h"
#include "../../includes/animation.h"
#include "../../includes/customCollider.h"
#include "../../includes/player.h"

class GameModel
{

private:
    std::shared_ptr<GameCommon> gameCommonPtr;
    PlayerInModel *player;

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
};

#endif // CPPGAMEJAM_GAMEMODEL_H
