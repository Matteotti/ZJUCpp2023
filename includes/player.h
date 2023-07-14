#ifndef PLAYER_H
#define PLAYER_H

#include "raylib-cpp.hpp"
#include "raymath.hpp"
#include "animation.h"
#include "customCollider.h"
#include <iostream>

/* #define PLAYER_MAX_HP 8
#define PLAYER_MAX_MP 200 */
#define PLAYER_SPEED 5.0f
#define PLAYER_JUMP_SPEED -5.0f
#define PLAYER_JUMP_TIME 1.5f
#define PLAYER_DOUBLE_JUMP_SPEED 5.0f
#define PLAYER_DOUBLE_JUMP_TIME 1.5f
#define PLAYER_GRAVITY 10.0f
#define PLAYER_DASH_SPEED 20.0f
#define PLAYER_BLACK_DASH_SPEED 30.0f
#define PLAYER_DASH_TIME 0.2f
#define PLAYER_BLACK_DASH_TIME 0.1f
#define PLAYER_DASH_COOLDOWN 0.5f
#define PLAYER_BLACK_DASH_COOLDOWN 2f
#define PLAYER_ATTACK_COOLDOWN 0.5f
#define PLAYER_SHADE_SOUL_COST 33
#define PLAYER_DESCENDING_DARK_COST 33
#define PLAYER_ABYSS_SHRIEK_COST 33
#define PLAYER_HURT_TIME 0.5f
#define PLAYER_INVINCIBLE_TIME 1.0f

#define PLAYER_WALLCHECK_BIAS_X 10.0f
#define PLAYER_WALLCHECK_BIAS_Y 10.0f
#define PLAYER_WALLCHECK_WIDTH 60.0f
#define PLAYER_WALLCHECK_HEIGHT 120.0f

#define PLAYER_ANIMATION_BIAS_X -60.0f

enum AnimatorState
{
    IDLE,
    WALKING,
    JUMPING,
    DOUBLE_JUMPING,
    FALLING,
    ATTACKING_LEFT,
    ATTACKING_RIGHT,
    ATTACKING_TOP,
    ATTACKING_BOTTOM,
    SHADE_SOUL,
    DESCENDING_DARK,
    ABYSS_SHRIEK,
    DASHING,
    BLACK_DASHING,
    HURT,
    DEAD
};

typedef struct PlayerStructInModel
{
    raylib::Vector2 currentSpeed = raylib::Vector2(0, 0);
    AnimatorState currentState = AnimatorState::IDLE;
    AnimationInfo *playerAnimationInfo = NULL;
    CustomCollider *playerCollider = NULL;
/*     int HP = PLAYER_MAX_HP;
    int MP = PLAYER_MAX_MP; */
    int jumpCount = 0;
    float jumpCounter = 0.0f;
    float nailAttackCounter = 0.0f;
    float blackDashCounter = 0.0f;
    float dashCounter = 0.0f;
    float invincibleCounter = 0.0f;
    bool disableMoveControl = false;
    bool isGrounded = true;
    bool isLeftWalled = false;
    bool isRightWalled = false;
    bool isCeilinged = false;
    bool isJumping = false;
    //bool isFacingRight = false;
    bool isDead = false;
} PlayerInModel;

typedef struct PlayerWallCheckStruct
{
    CustomCollider *leftCollider;
    CustomCollider *rightCollider;
    CustomCollider *topCollider;
    CustomCollider *bottomCollider;
} PlayerWallCheck;

#endif