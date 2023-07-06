#include "raylib-cpp.hpp"
#include <raymath.h>

#define PLAYER_MAX_HP 8
#define PLAYER_MAX_MP 200
#define PLAYER_SPEED 5.0f
#define PLAYER_JUMP_SPEED 10.0f
#define PLAYER_DOUBLE_JUMP_SPEED 5.0f
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
#define PLAYER_ATTACK_DAMAGE 1
#define PLAYER_SHADE_SOUL_DAMAGE 2
#define PLAYER_DESCENDING_DARK_DAMAGE 3
#define PLAYER_ABYSS_SHRIEK_DAMAGE 4
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
    Vector2 position = Vector2{0, 0};
    Vector2 currentSpeed = Vector2{0, 0};
    AnimatorState currentState = AnimatorState::IDLE;
    int HP = PLAYER_MAX_HP;
    int MP = PLAYER_MAX_MP;
    float nailAttackCounter = 0.0f;
    float blackDashCounter = 0.0f;
    float dashCounter = 0.0f;
    float invincibleCounter = 0.0f;
    bool isGrounded = true;

    Player(){};

    Vector2 PlayerMove(Vector2 delta)
    {
        position = Vector2Add(position, delta);
    }

    void PlayerJump()
    {
        currentSpeed.y = -PLAYER_JUMP_SPEED;
    }

    bool GroundCheck()
    {
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
    }
};