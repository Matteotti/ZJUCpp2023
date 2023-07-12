#ifndef BOSS_H
#define BOSS_H

#include "raylib-cpp.hpp"
#include "includes/animation.h"
#include "includes/customCollider.h"
#include "raymath.hpp"

#define BOSS_FULL_HP 1000
#define BOSS_WIDTH 100.0f
#define BOSS_HEIGHT 100.0f
#define BOSS_ANIMATION_BIAS_X 100.0f

enum SingleBossAnimatorState
{
    BOSS_DISAPPEAR,
    BOSS_ATTACK_TO_RIGHT,
    BOSS_ATTACK_TO_LEFT,
    BOSS_ATTACK_TO_GROUND,
    BOSS_PLACE_PLATE,
};

class Boss
{
public:
    raylib::Vector2 position = raylib::Vector2(0, 0);
    raylib::Vector2 currentSpeed = raylib::Vector2(0, 0);
    SingleBossAnimatorState animatorState = BOSS_DISAPPEAR;
    AnimationInfo bossAnimationInfo;
    CustomCollider bossCollider;
    Boss *boss = nullptr;
    ThreeBosses *threeBosses = nullptr;
    int HP = BOSS_FULL_HP;
    float attackForeTime = 0.5f;
    float attackPostTime = 0.5f;
    bool isDead;

    Boss(std::string path_, int frameCount_, raylib::Vector2 position_, int index_)
    {
        bossAnimationInfo = AnimationInfo(path_, frameCount_);
        position = position_;
        bossCollider = CustomCollider("Boss" + std::to_string(index_), position.x, position.y, BOSS_WIDTH, BOSS_HEIGHT, ColliderTag::ENEMY);
        boss = this;
    }

    void UpdatePosition()
    {
        position += currentSpeed;
        bossCollider.MoveCollider(raylib::Vector2(currentSpeed.x, currentSpeed.y));
    }

    void UpdatePositionTo(raylib::Vector2 position_)
    {
        position = position_;
        bossCollider.MoveColliderTo(position_);
    }

    void UpdateSpeed(raylib::Vector2 deltaSpeed)
    {
        currentSpeed += deltaSpeed;
    }

    void SetSpeed(raylib::Vector2 newSpeed)
    {
        currentSpeed = newSpeed;
    }

    void UpdateBossAttackState()
    {
    }

    void UpdateBossAnimation(std::string path_, int frameCount_, float frameTime_ = ANIMATION_FRAME_TIME, bool stop_ = false)
    {
        if (path_ != bossAnimationInfo.path)
            bossAnimationInfo = AnimationInfo(path_, frameCount_, frameTime_, stop_);
    }

    void Draw()
    {
        bossAnimationInfo.DrawAnimation(position, isFacingRight, raylib::Vector2(BOSS_ANIMATION_BIAS_X, 0));
    }

    void BossHurt(int damage)
    {
        HP -= damage;
        if (HP <= 0)
        {
            HP = 0;
            isDead = true;
            // DEAD
            if (threeBosses != nullptr && threeBosses->boss1->isDead && threeBosses->boss2->isDead && threeBosses->boss3->isDead)
            {
                threeBosses->isBossDead = true;
            }
        }
    }

    void CheckCollisionWithPlayer(Player *player)
    {
        if (bossCollider.CheckCollisionWith(player->playerCollider))
        {
            player->PlayerHurt(1);
        }
    }
};

class ThreeBosses
{
public:
    Boss *boss1 = nullptr;
    Boss *boss2 = nullptr;
    Boss *boss3 = nullptr;
    bool isSecondStage = false;
    bool isCurrentStateFinished = true;
    bool isBossDead = false;

    void UpdateBossesAttackState()
    {
    }

    void ExecuteCurrentState()
    {
    }
};

#endif