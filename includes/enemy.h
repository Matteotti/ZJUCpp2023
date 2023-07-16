#ifndef ENEMY_H
#define ENEMY_H

#include "raylib-cpp.hpp"
#include "raymath.hpp"
#include "animation.h"
#include "customCollider.h"

#define ENEMY_MAX_HP 8
#define ENEMY_COLLIDER_SIZE_X 106.0f
#define ENEMY_COLLIDER_SIZE_Y 125.0f
#define ENEMY_COLLIDER_BIAS_X 5.0f
#define ENEMY_COLLIDER_BIAS_Y 20.0f
#define ENEMY_MIN_JUMP_GAP 5.0f
#define ENEMY_MIN_IDLE_GAP 1.5f
#define ENEMY_JUMP_SPEED -25.0f
#define ENEMY_SPEED 2.5f
#define IDLE_TIME 1.0f
#define ENEMY_GRAVITY 15.0f
#define ENEMY_BIAS 0.0f

enum EnemyAnimState
{
    ENEMY_WALK,
    ENEMY_DEAD
};

typedef struct EnemyStructInModel
{
    raylib::Vector2 position = raylib::Vector2(0, 0);
    raylib::Vector2 currentSpeed = raylib::Vector2(0, 0);
    EnemyAnimState animState = ENEMY_WALK;
    raylib::Rectangle sourceRec = raylib::Rectangle(0, 0, 0, 0);
    AnimationInfo *enemyAnimationInfo = static_cast<AnimationInfo *>(malloc(sizeof(AnimationInfo)));
    CustomCollider *enemyCollider = static_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    std::string path;
    bool isFacingRight = true;
    bool isGrounded = false;
    bool isLeftWalled = false;
    bool isRightWalled = false;
    bool isCeilinged = false;
    float minJumpGap = ENEMY_MIN_JUMP_GAP;
    float jumpCounter = 0.0f;
    float jumpSpeed = ENEMY_JUMP_SPEED;
} EnemyInModel;

#endif