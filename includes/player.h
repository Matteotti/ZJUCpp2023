#ifndef PLAYER_H
#define PLAYER_H

#include "raylib-cpp.hpp"
#include <raymath.h>
#include <iostream>

#define PLAYER_MAX_HP 8
#define PLAYER_MAX_MP 200
#define PLAYER_SPEED 5.0f
#define PLAYER_JUMP_SPEED 10.0f
#define PLAYER_JUMP_TIME 1.5f
#define PLAYER_DOUBLE_JUMP_SPEED 5.0f
#define PLAYER_DOUBLE_JUMP_TIME 1.5f
#define PLAYER_GRAVITY 9.8f
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

enum AnimatorState
{
    IDLE,
    WALKING,
    JUMPING,
    DOUBLE_JUMPING,
    FALLING,
    ATTACKING,
    SHADE_SOUL,
    DESCENDING_DARK,
    ABYSS_SHRIEK,
    DASHING,
    BLACK_DASHING,
    HURT,
    DEAD
};

class Player
{
public:
    raylib::Vector2 position = raylib::Vector2(0, 0);
    raylib::Vector2 currentSpeed = raylib::Vector2(0, 0);
    AnimatorState currentState = AnimatorState::IDLE;
    int HP = PLAYER_MAX_HP;
    int MP = PLAYER_MAX_MP;
    int jumpCount = 0;
    float jumpCounter = 0.0f;
    float nailAttackCounter = 0.0f;
    float blackDashCounter = 0.0f;
    float dashCounter = 0.0f;
    float invincibleCounter = 0.0f;
    bool disableMoveControl = false;
    bool isGrounded = true;
    bool isJumping = false;
    bool isFacingRight = true;

    Player(){};

    void UpdatePosition(raylib::Vector2 speed)
    {
        position += speed;
    }

    void UpdateSpeed(Vector2 deltaSpeed)
    {
        currentSpeed += deltaSpeed;
    }

    void SetSpeed(Vector2 newSpeed)
    {
        currentSpeed = newSpeed;
    }

    void PlayerStartJump()
    {
        if (isGrounded)
        {
            isGrounded = false;
            isJumping = true;
            jumpCounter = PLAYER_JUMP_TIME;
        }
        else if (jumpCount == 0)
        {
            jumpCount++;
            isJumping = true;
            jumpCounter = PLAYER_DOUBLE_JUMP_TIME;
        }
    }

    void PlayerStopJump()
    {
        isJumping = false;
        jumpCounter = 0.0f;
    }

    void PlayerUpdateJump()
    {
        if (isJumping && jumpCounter > 0.0f)
        {
            SetSpeed(raylib::Vector2(currentSpeed.x, PLAYER_JUMP_SPEED));
            jumpCounter -= GetFrameTime();
            if (jumpCounter <= 0.0f)
            {
                PlayerStopJump();
            }
        }
    }

    void PlayerAttack()
    {
    }

    void PlayerShadeSoul()
    {
    }

    void PlayerDescendingDark()
    {
    }

    void PlayerAbyssShriek()
    {
    }

    void PlayerDash()
    {
    }

    void PlayerBlackDash()
    {
    }

    void PlayerHurt()
    {
    }

    void PlayerDie()
    {
    }

    void UpdateAnimator()
    {
        if (currentState == IDLE || currentState == WALKING || currentState == JUMPING || currentState == FALLING)
        {
            if (isGrounded)
            {
                if (currentSpeed.x == 0)
                {
                    currentState = IDLE;
                }
                else
                {
                    currentState = WALKING;
                }
            }
            else
            {
                if (currentSpeed.y > 0)
                {
                    currentState = JUMPING;
                }
                else
                {
                    currentState = FALLING;
                }
            }
        }
        std::cout << "Current State: " << currentState << std::endl;
    }

    void Update()
    {
        UpdatePosition(currentSpeed);
        UpdateAnimator();
        PlayerUpdateJump();
    }
};

#endif