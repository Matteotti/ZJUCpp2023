#ifndef PLAYER_H
#define PLAYER_H

#include "raylib-cpp.hpp"
#include "includes/animation.h"
#include "includes/customCollider.h"
#include "raymath.hpp"
#include <iostream>

#define PLAYER_MAX_HP 8
#define PLAYER_MAX_MP 200
#define PLAYER_SPEED 5.0f
#define PLAYER_JUMP_SPEED -10.0f
#define PLAYER_JUMP_TIME 1.5f
#define PLAYER_DOUBLE_JUMP_SPEED 5.0f
#define PLAYER_DOUBLE_JUMP_TIME 1.5f
#define PLAYER_GRAVITY 9.0f
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

#define PLAYER_WALLCHECK_RADIUS 0.5f
#define PLAYER_WALLCHECK_BIAS_X 10.0f
#define PLAYER_WALLCHECK_BIAS_Y 10.0f
#define PLAYER_WALLCHECK_WIDTH 60.0f
#define PLAYER_WALLCHECK_HEIGHT 100.0f

enum AnimatorState
{
    IDLE,
    WALKING,
    JUMPING,
    DOUBLE_JUMPING,
    FALLING,
    ATTACKING_TOP,
    ATTACKING_BOTTOM,
    ATTACKING_LEFT,
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
    AnimationInfo playerAnimationInfo;
    CustomCollider playerCollider;
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
    bool isLeftWalled = false;
    bool isRightWalled = false;
    bool isCeilinged = false;
    bool isJumping = false;
    bool isFacingRight = false;

    Player()
    {
    }

    Player(std::string path_, int frameCount_, raylib::Vector2 position_)
    {
        this->playerAnimationInfo = AnimationInfo(path_, frameCount_);
        this->position = position_;
        /* raylib::Vector3 min = raylib::Vector3(position.x, position.y - PLAYER_WALLCHECK_HEIGHT, 0);
        raylib::Vector3 max = raylib::Vector3(position.x + PLAYER_WALLCHECK_WIDTH, position.y, 0); */
        raylib::Rectangle rectangle(position.x,position.y,PLAYER_WALLCHECK_WIDTH,PLAYER_WALLCHECK_HEIGHT);
        this->playerCollider = CustomCollider("player", rectangle, ColliderTag::PLAYER);
    };

    void UpdatePosition()
    {
        position += currentSpeed;
        playerCollider.MoveCollider(raylib::Vector2(currentSpeed.x, currentSpeed.y));
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
        }
        else if (jumpCounter <= 0.0f)
        {
            PlayerStopJump();
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
        // std::cout << "Current State: " << currentState << std::endl;
    }

    void UpdatePlayerAnimation(std::string path_, int count_)
    {
        playerAnimationInfo = AnimationInfo(path_, count_);
    }

    void UpdateSpeedWithWallCheck()
    {
        if (isLeftWalled && currentSpeed.x < 0)
        {
            SetSpeed(raylib::Vector2(0, currentSpeed.y));
        }
        if (isRightWalled && currentSpeed.x > 0)
        {
            SetSpeed(raylib::Vector2(0, currentSpeed.y));
        }
        if (isCeilinged && currentSpeed.y > 0)
        {
            SetSpeed(raylib::Vector2(currentSpeed.x, 0));
        }
        if (isGrounded && currentSpeed.y < 0)
        {
            SetSpeed(raylib::Vector2(currentSpeed.x, 0));
        }
    }

    void Update()
    {
        UpdateAnimator();
        UpdatePosition();
    }

    void Draw()
    {
        playerAnimationInfo.DrawAnimation(position, isFacingRight);
    }

    void AttackTop_draw()
    {
        playerAnimationInfo=AnimationInfo("F:/ZJUCpp2023/assets/Attack/AttackTop/hebing.png", 5,0.3f);
        playerAnimationInfo.DrawAnimation(position);
    }
    void AttackDown_draw()
    {
        playerAnimationInfo=AnimationInfo("F:/Resources/Sprites/The Knight/Attack/向下攻击/hebing.png",5,0.3f);
        playerAnimationInfo.DrawAnimation(position);
    }
};

Player knight;

class PlayerWallCheck
{
public:
    CustomCollider leftCollider;
    CustomCollider rightCollider;
    CustomCollider topCollider;
    CustomCollider bottomCollider;

    PlayerWallCheck()
    {
        raylib::Vector2 leftColliderPos;
        raylib::Vector2 rightColliderPos;
        raylib::Vector2 topColliderPos;
        raylib::Vector2 bottomColliderPos;
        leftColliderPos = raylib::Vector2(
            knight.position.x - PLAYER_WALLCHECK_BIAS_X,
            knight.position.y + PLAYER_WALLCHECK_HEIGHT / 2);
        rightColliderPos = raylib::Vector2(
            knight.position.x + PLAYER_WALLCHECK_BIAS_X + PLAYER_WALLCHECK_WIDTH,
            knight.position.y + PLAYER_WALLCHECK_HEIGHT / 2);
        topColliderPos = raylib::Vector2(
            knight.position.x + PLAYER_WALLCHECK_WIDTH / 2,
            knight.position.y - PLAYER_WALLCHECK_BIAS_Y);
        bottomColliderPos = raylib::Vector2(
            knight.position.x + PLAYER_WALLCHECK_WIDTH / 2,
            knight.position.y + PLAYER_WALLCHECK_BIAS_Y + PLAYER_WALLCHECK_HEIGHT);
        leftCollider = CustomCollider("playerLeftWallCheck", leftColliderPos, PLAYER_WALLCHECK_RADIUS, ColliderTag::PLAYER_WALLCHECK);
        rightCollider = CustomCollider("playerRightWallCheck", rightColliderPos, PLAYER_WALLCHECK_RADIUS, ColliderTag::PLAYER_WALLCHECK);
        topCollider = CustomCollider("playerTopWallCheck", topColliderPos, PLAYER_WALLCHECK_RADIUS, ColliderTag::PLAYER_WALLCHECK);
        bottomCollider = CustomCollider("playerBottomWallCheck", bottomColliderPos, PLAYER_WALLCHECK_RADIUS, ColliderTag::PLAYER_WALLCHECK);
    }

    void UpdatePosition(raylib::Vector2 delta_)
    {
        leftCollider.MoveCollider(delta_);
        rightCollider.MoveCollider(delta_);
        topCollider.MoveCollider(delta_);
        bottomCollider.MoveCollider(delta_);
    }

    void UpdatePlayerWallCollisionInfo()
    {
        std::vector<CustomCollider> left = leftCollider.CheckCollisionWithAll(ColliderTag::ENVIRONMENT);
        std::vector<CustomCollider> right = rightCollider.CheckCollisionWithAll(ColliderTag::ENVIRONMENT);
        std::vector<CustomCollider> top = topCollider.CheckCollisionWithAll(ColliderTag::ENVIRONMENT);
        std::vector<CustomCollider> bottom = bottomCollider.CheckCollisionWithAll(ColliderTag::ENVIRONMENT);
        knight.isLeftWalled = left.size() > 0;
        knight.isRightWalled = right.size() > 0;
        knight.isCeilinged = top.size() > 0;
        knight.isGrounded = bottom.size() > 0;
        if (knight.isLeftWalled || knight.isRightWalled || knight.isCeilinged || knight.isGrounded)
        {
            std::cout << "Touched Wall" << std::endl;
        }
    }

    void Update()
    {
        UpdatePlayerWallCollisionInfo();
        knight.UpdateSpeedWithWallCheck();
        UpdatePosition(raylib::Vector2(knight.currentSpeed.x, knight.currentSpeed.y));
    }
};

PlayerWallCheck knightWallCheck;

#endif