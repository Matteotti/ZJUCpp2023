//
// Created by Hjuntao on 2023/7/12.
//

#include "GameViewModel.h"
#include <iostream>
#include <functional>

GameViewModel::GameViewModel() {}

void GameViewModel::setModel(GameModel *model)
{
    this->model = model;
}
/* void GameViewModel::setMapModel(MapModel *mapModel)
{
    this->mapModel = mapModel;
} */

// TOOL METHOD: Check Collision using tag
std::vector<CustomCollider *> GameViewModel::CheckCollisionWithAll(CustomCollider *target, ColliderTag targetTag)
{
    std::vector<CustomCollider *> result = std::vector<CustomCollider *>();
    for (int i = 0; i < model->GetColliders().size(); i++)
    {
        if (model->GetColliders()[i]->colliderTag == targetTag && model->GetColliders()[i]->colliderName != target->colliderName)
        {
            if (CheckCollisionRecs(model->GetColliders()[i]->colliderBox, target->colliderBox))
            {
                result.push_back(model->GetColliders()[i]);
            }
        }
    }
    return result;
}

// TOOL METHOD: Check Collision with all
std::vector<CustomCollider *> GameViewModel::CheckCollisionWithAll(CustomCollider *target)
{
    std::vector<CustomCollider *> result = std::vector<CustomCollider *>();
    for (int i = 0; i < model->GetColliders().size(); i++)
    {
        if (model->GetColliders()[i]->colliderName != target->colliderName)
        {
            if (CheckCollisionRecs(model->GetColliders()[i]->colliderBox, target->colliderBox))
            {
                result.push_back(model->GetColliders()[i]);
            }
        }
    }
    return result;
}

// TOOL METHOD: Update Animation With Path & FrameCount
void GameViewModel::UpdateAnimationInfo(std::string path, int frameCount, float frameTime_ = ANIMATION_FRAME_TIME, bool stop_ = false)
{
    if (path != model->GetPlayerAnimationPath())
    {
        model->SetPlayerAnimationPath(path);
        raylib::Texture2DUnmanaged texture = LoadTexture(path.c_str());
        model->SetPlayerAnimationCurrentFrame(0);
        model->SetPlayerAnimationFrameTimeCounter(0);
        model->SetPlayerAnimationFrameWidth(texture.width / frameCount);
        model->SetPlayerAnimationFrameHeight(texture.height);
        model->SetPlayerAnimationFrameTime(frameTime_);
        model->SetPlayerAnimationIsStop(stop_);
        UnloadTexture(texture);
    }
}

// TOOL METHOD: Update Animation With Path & FrameCount
void GameViewModel::UpdateEnemyAnimationInfo(std::string path, int frameCount, float frameTime_ = ANIMATION_FRAME_TIME, bool stop_ = false)
{
    if (path != model->GetEnemyAnimationPath())
    {
        model->SetEnemyAnimationPath(path);
        raylib::Texture2DUnmanaged texture = LoadTexture(path.c_str());
        model->SetEnemyAnimationCurrentFrame(0);
        model->SetEnemyAnimationFrameTimeCounter(0);
        model->SetEnemyAnimationFrameWidth(texture.width / frameCount);
        model->SetEnemyAnimationFrameHeight(texture.height);
        model->SetEnemyAnimationFrameTimeCounter(frameTime_);
        UnloadTexture(texture);
    }
}

// STD::FUNCTIONS Execute when wasd is pressed, need a parameter of direction
std::function<void(direction)> GameViewModel::getMovePlayerCommand()
{
    return [this](direction command) -> void
    {
        // std::cout << "PLAYER POS 1" << model->GetPlayerPosition().x << " " << model->GetPlayerPosition().y << std::endl;
        if (model->GetGameCommonPtr()->GetPlayerIsFacingRight() && command == direction::LEFT)
        {
            model->GetGameCommonPtr()->SetPlayerIsFacingRight(false);
        }
        else if (!model->GetGameCommonPtr()->GetPlayerIsFacingRight() && command == direction::RIGHT)
        {
            model->GetGameCommonPtr()->SetPlayerIsFacingRight(true);
        }
        switch (command)
        {
        case LEFT:
            model->SetPlayerSpeed(raylib::Vector2(-PLAYER_SPEED, model->GetPlayerSpeed().y));
            // std::cout << "LEFT, SPEED = " << model->GetPlayerSpeed().x << " " << model->GetPlayerSpeed().y << std::endl;
            break;
        case RIGHT:
            model->SetPlayerSpeed(raylib::Vector2(PLAYER_SPEED, model->GetPlayerSpeed().y));
            // std::cout << "RIGHT, SPEED = " << model->GetPlayerSpeed().x << " " << model->GetPlayerSpeed().y << std::endl;
            break;
        case STILL:
            model->SetPlayerSpeed(raylib::Vector2(0, model->GetPlayerSpeed().y));
            // std::cout << "STILL, SPEED = " << model->GetPlayerSpeed().x << " " << model->GetPlayerSpeed().y << std::endl;
            break;
        default:
            break;
        }
        // std::cout << "PLAYER POS 2" << model->GetPlayerPosition().x << " " << model->GetPlayerPosition().y << std::endl;
    };
}

// STD::FUNCTIONS Execute when space is pressed
std::function<void(bool)> GameViewModel::getPlayerJumpCommand()
{
    return [this](bool isPressed) -> void
    {
        // std::cout << "PLAYER POS 3" << model->GetPlayerPosition().x << " " << model->GetPlayerPosition().y << std::endl;
        if (isPressed)
        {
            // std::cout << "JUMP" << std::endl;
            if (model->GetPlayerIsGrounded())
            {
                model->SetPlayerIsGrounded(false);
                model->SetPlayerIsJumping(true);
                model->SetPlayerJumpCounter(PLAYER_JUMP_TIME);
            }
            else if (model->GetPlayerJumpCount() == 0)
            {
                model->SetPlayerJumpCount(model->GetPlayerJumpCount() + 1);
                model->SetPlayerIsJumping(true);
                model->SetPlayerJumpCounter(PLAYER_DOUBLE_JUMP_TIME);
            }
        }
        else
        {
            // std::cout << "STOP JUMP" << std::endl;
            model->SetPlayerIsJumping(false);
            model->SetPlayerJumpCounter(0);
        }
        // std::cout << "PLAYER POS 4" << model->GetPlayerPosition().x << " " << model->GetPlayerPosition().y << std::endl;
    };
}

// STD::FUNCTIONS Execute every frame
std::function<void()> GameViewModel::getPlayerUpdateJumpSpeed()
{
    return [this]() -> void
    {
        // std::cout << "PLAYER POS 5" << model->GetPlayerPosition().x << " " << model->GetPlayerPosition().y << std::endl;
        if (model->GetPlayerIsJumping() && model->GetPlayerJumpCounter() > 0.0f)
        {
            model->SetPlayerSpeed(raylib::Vector2(model->GetPlayerSpeed().x, PLAYER_JUMP_SPEED));
            model->SetPlayerJumpCounter(model->GetPlayerJumpCounter() - GetFrameTime());
        }
        else if (model->GetPlayerJumpCounter() <= 0.0f)
        {
            model->SetPlayerIsJumping(false);
            model->SetPlayerJumpCounter(0);
        }
        // std::cout << "PLAYER POS 6" << model->GetPlayerPosition().x << " " << model->GetPlayerPosition().y << std::endl;
    };
}

// STD::FUNCTIONS Execute every frame
std::function<void()> GameViewModel::getPlayerCheckWall()
{
    return [this]() -> void
    {
        // std::cout << "PLAYER POS 7" << model->GetPlayerPosition().x << " " << model->GetPlayerPosition().y << std::endl;
        std::vector<CustomCollider *> left = CheckCollisionWithAll(model->GetLeftWallCheck(), ColliderTag::ENVIRONMENT);
        std::vector<CustomCollider *> right = CheckCollisionWithAll(model->GetRightWallCheck(), ColliderTag::ENVIRONMENT);
        std::vector<CustomCollider *> ceiling = CheckCollisionWithAll(model->GetCeilingCheck(), ColliderTag::ENVIRONMENT);
        std::vector<CustomCollider *> ground = CheckCollisionWithAll(model->GetGroundCheck(), ColliderTag::ENVIRONMENT);
        model->SetPlayerIsLeftWalled(left.size() > 0);
        model->SetPlayerIsRightWalled(right.size() > 0);
        model->SetPlayerIsCeilinged(ceiling.size() > 0);
        model->SetPlayerIsGrounded(ground.size() > 0);

        if (model->GetPlayerIsGrounded())
        {
            model->SetPlayerJumpCount(0);
        }
        else if (!model->GetPlayerIsGrounded())
        {
            model->SetPlayerSpeed(raylib::Vector2(model->GetPlayerSpeed().x, model->GetPlayerSpeed().y + PLAYER_GRAVITY * GetFrameTime()));
        }
        if (model->GetPlayerIsGrounded() && model->GetPlayerSpeed().y > 0)
        {
            model->SetPlayerSpeed(raylib::Vector2(model->GetPlayerSpeed().x, 0));
        }
        if (model->GetPlayerIsLeftWalled() && model->GetPlayerSpeed().x < 0)
        {
            model->SetPlayerSpeed(raylib::Vector2(0, model->GetPlayerSpeed().y));
        }
        if (model->GetPlayerIsRightWalled() && model->GetPlayerSpeed().x > 0)
        {
            model->SetPlayerSpeed(raylib::Vector2(0, model->GetPlayerSpeed().y));
        }
        if (model->GetPlayerIsCeilinged() && model->GetPlayerSpeed().y < 0)
        {
            model->SetPlayerSpeed(raylib::Vector2(model->GetPlayerSpeed().x, 0));
        }

        // std::cout << "PLAYER POS 8" << model->GetPlayerPosition().x << " " << model->GetPlayerPosition().y << std::endl;
    };
}

// STD::FUNCTIONS Execute every frame
std::function<void()> GameViewModel::getPlayerAnimatorUpdate()
{
    return [this]() -> void
    {
        // std::cout << "PLAYER POS 9" << model->GetPlayerPosition().x << " " << model->GetPlayerPosition().y << std::endl;
        if (model->GetPlayerAnimatorState() == IDLE || model->GetPlayerAnimatorState() == WALKING || model->GetPlayerAnimatorState() == JUMPING || model->GetPlayerAnimatorState() == FALLING)
        {
            if (model->GetPlayerIsGrounded())
            {
                if (model->GetPlayerSpeed().x == 0)
                {
                    model->SetPlayerAnimatorState(IDLE);
                }
                else
                {
                    model->SetPlayerAnimatorState(WALKING);
                }
            }
            else
            {
                if (model->GetPlayerSpeed().y < 0)
                {
                    model->SetPlayerAnimatorState(JUMPING);
                }
                else
                {
                    model->SetPlayerAnimatorState(FALLING);
                }
            }
        }

        // std::cout << "PLAYER POS 10" << model->GetPlayerPosition().x << " " << model->GetPlayerPosition().y << std::endl;
    };
}
std::function<void()> GameViewModel::getPlayerAnimationUpdate()
{
    return [this]() -> void
    {
        // std::cout << "PLAYER POS 11" << model->GetPlayerPosition().x << " " << model->GetPlayerPosition().y << std::endl;
        switch (model->GetPlayerAnimatorState())
        {
        case IDLE:
            UpdateAnimationInfo("../assets/sprites/Knight/Idle.png", 9);
            // std::cout << "IDLE" << std::endl;
            break;
        case WALKING:
            UpdateAnimationInfo("../assets/sprites/Knight/Walk.png", 5);
            // std::cout << "WALKING" << std::endl;
            break;
        case JUMPING:
            UpdateAnimationInfo("../assets/sprites/Knight/Jump.png", 9, ANIMATION_FRAME_TIME, true);
            // std::cout << "JUMPING" << std::endl;
            break;
        case DOUBLE_JUMPING:
            UpdateAnimationInfo("../assets/sprites/Knight/KnightDoubleJump.png", 9);
            // std::cout << "DOUBLE_JUMPING" << std::endl;
            break;
        case FALLING:
            UpdateAnimationInfo("../assets/sprites/Knight/Fall.png", 3);
            // std::cout << "FALLING" << std::endl;
            break;
        case ATTACKING_TOP:
            UpdateAnimationInfo("../assets/sprites/Attack/attacktop.png", 5);
            break;
        case ATTACKING_BOTTOM:
            UpdateAnimationInfo("../assets/sprites/Attack/attackdown.png", 5);
            break;
        case ATTACKING_LEFT:
            UpdateAnimationInfo("../assets/sprites/Attack/attackleft.png", 5);
            break;
        case ATTACKING_RIGHT:
            UpdateAnimationInfo("../assets/sprites/Attack/attackright.png", 5);
            break;
        }

        // std::cout << "PLAYER POS 12" << model->GetPlayerPosition().x << " " << model->GetPlayerPosition().y << std::endl;
    };
}

// STD::FUNCTIONS Execute every frame
std::function<void()> GameViewModel::getPlayerUpdatePosition()
{
    return [this]() -> void
    {
        // std::cout << "PLAYER POS 13" << model->GetPlayerPosition().x << " " << model->GetPlayerPosition().y << std::endl;
        //  std::cout << "PLAYER SPEED " << model->GetPlayerSpeed().x << " " << model->GetPlayerSpeed().y << std::endl;
        //  std::cout << "PLAYER POSITION1 " << model->GetPlayerPosition().x << " " << model->GetPlayerPosition().y << std::endl;
        model->SetPlayerPosition(raylib::Vector2(model->GetPlayerPosition().x + model->GetPlayerSpeed().x, model->GetPlayerPosition().y + model->GetPlayerSpeed().y));
        // std::cout << "PLAYER POSITION2 " << model->GetPlayerPosition().x << " " << model->GetPlayerPosition().y << std::endl;
        model->SetPlayerColliderBoxPosition(model->GetPlayerSpeed());
        model->SetLeftWallCheckPosition(model->GetPlayerSpeed());
        model->SetRightWallCheckPosition(model->GetPlayerSpeed());
        model->SetCeilingCheckPosition(model->GetPlayerSpeed());
        model->SetGroundCheckPosition(model->GetPlayerSpeed());
        // std::cout << "PLAYER POS 14" << model->GetPlayerPosition().x << " " << model->GetPlayerPosition().y << std::endl;
    };
}

// STD::FUNCTIONS Execute every frame
std::function<void()> GameViewModel::getUpdateAnimationFrame()
{
    return [this]() -> void
    {
        // std::cout << "PLAYER POS 15" << model->GetPlayerPosition().x << " " << model->GetPlayerPosition().y << std::endl;
        model->SetPlayerAnimationFrameTimeCounter(model->GetPlayerAnimationFrameTimeCounter() + GetFrameTime());
        if (model->GetPlayerAnimationFrameTimeCounter() >= model->GetPlayerAnimationFrameTime())
        {
            model->SetPlayerAnimationFrameTimeCounter(0);
            model->SetPlayerAnimationCurrentFrame(model->GetPlayerAnimationCurrentFrame() + 1);
            if (model->GetPlayerAnimationCurrentFrame() >= model->GetPlayerAnimationFrameCount())
            {
                if (!model->GetPlayerAnimationIsStop())
                    model->SetPlayerAnimationCurrentFrame(0);
                else if (model->GetPlayerAnimationIsStop())
                    model->SetPlayerAnimationCurrentFrame(model->GetPlayerAnimationFrameCount() - 1);
            }
        }

        // std::cout << "PLAYER POS 16" << model->GetPlayerPosition().x << " " << model->GetPlayerPosition().y << std::endl;
    };
}

// STD::FUNCTIONS Execute every frame
std::function<void(raylib::Vector2)> GameViewModel::getUpdatePlayerAnimationRect()
{
    return [this](raylib::Vector2 bias) -> void
    {
        // std::cout << "PLAYER POS 17" << model->GetPlayerPosition().x << " " << model->GetPlayerPosition().y << std::endl;
        if (model->GetGameCommonPtr()->GetPlayerIsFacingRight())
        {
            model->SetPlayerAnimationFrameWidth(-1 * model->GetPlayerAnimationFrameWidth());
            model->SetPlayerPosition(raylib::Vector2(model->GetPlayerPosition().x + bias.x, model->GetPlayerPosition().y + bias.y));
            model->SetPlayerAnimationCurrentFrame(model->GetPlayerAnimationFrameCount() - model->GetPlayerAnimationCurrentFrame() - 1);
        }
        if (model->GetGameCommonPtr()->GetPlayerIsFacingRight() && model->GetPlayerAnimationCurrentFrame() == 0 && model->GetPlayerAnimationIsStop())
            model->SetPlayerAnimationCurrentFrame(1);
        raylib::Rectangle sourceRec = raylib::Rectangle(model->GetPlayerAnimationCurrentFrame() * model->GetPlayerAnimationFrameWidth(), 0.0f, model->GetPlayerAnimationFrameWidth(), model->GetPlayerAnimationFrameHeight());
        model->SetPlayerSourceRec(sourceRec);
        temp = LoadTexture(model->GetPlayerAnimationPath().c_str());
        temp.Draw(model->GetPlayerSourceRec(), model->GetPlayerPosition());
        if (model->GetGameCommonPtr()->GetPlayerIsFacingRight() && model->GetPlayerAnimationCurrentFrame() == 1 && model->GetPlayerAnimationIsStop())
            model->SetPlayerAnimationCurrentFrame(0);
        if (model->GetGameCommonPtr()->GetPlayerIsFacingRight())
        {
            model->SetPlayerAnimationFrameWidth(-1 * model->GetPlayerAnimationFrameWidth());
            model->SetPlayerPosition(raylib::Vector2(model->GetPlayerPosition().x - bias.x, model->GetPlayerPosition().y - bias.y));
            model->SetPlayerAnimationCurrentFrame(model->GetPlayerAnimationFrameCount() - model->GetPlayerAnimationCurrentFrame() - 1);
        }

        // std::cout << "PLAYER POS 18" << model->GetPlayerPosition().x << " " << model->GetPlayerPosition().y << std::endl;
    };
}

std::function<void(raylib::Vector2)> GameViewModel::getDrawPlayerWithBias()
{
    return [this](raylib::Vector2 bias) -> void
    {
        raylib::Texture2DUnmanaged texture = LoadTexture(model->GetPlayerAnimationPath().c_str());
        if (model->GetGameCommonPtr()->GetPlayerIsFacingRight())
            texture.Draw(model->GetPlayerSourceRec(), model->GetPlayerPosition() + bias, WHITE);
        else
            texture.Draw(model->GetPlayerSourceRec(), model->GetPlayerPosition(), WHITE);
        texture.Unload();
    };
}

// STD::FUNCTIONS Execute every frame
std::function<void()> GameViewModel::getDrawPlayerCommand()
{
    return [this]() -> void
    {
        raylib::Texture2DUnmanaged texture = LoadTexture(model->GetPlayerAnimationPath().c_str());
        texture.Draw(model->GetPlayerSourceRec(), model->GetPlayerPosition(), WHITE);
        texture.Unload();
    };
}

std::function<void(AnimatorState)> GameViewModel::getAttackTopCommand()
{
    return [this](AnimatorState currentstate) -> void
    {
        if (currentstate != ATTACKING_TOP)
        {
            model->SetPlayerAnimatorState(ATTACKING_TOP);
        }
    };
}
std::function<void(AnimatorState)> GameViewModel::getAttackDownCommand()
{
    return [this](AnimatorState currentstate) -> void
    {
        if (currentstate != ATTACKING_BOTTOM)
        {
            model->SetPlayerAnimatorState(ATTACKING_BOTTOM);
        }
    };
}

std::function<void()> GameViewModel::getUpdateEnemyAnimState()
{
    return [this]() -> void
    {
        if (model->GetEnemyJumpCounter() >= ENEMY_MIN_JUMP_GAP)
        {
            model->SetEnemyCurrentSpeed(raylib::Vector2(model->GetEnemyCurrentSpeed().x, ENEMY_JUMP_SPEED));
            model->SetEnemyJumpCounter(0);
        }
        else
        {
            model->SetEnemyJumpCounter(model->GetEnemyJumpCounter() + GetFrameTime());
        }
    };
}

std::function<void()> GameViewModel::getUpdateEnemySpeed()
{
    return [this]() -> void
    {
        bool isPlayerRight = model->GetPlayerPosition().x > model->GetEnemyPosition().x;
        if (isPlayerRight)
        {
            model->SetEnemyCurrentSpeed(raylib::Vector2(ENEMY_SPEED, model->GetEnemyCurrentSpeed().y));
        }
        else
        {
            model->SetEnemyCurrentSpeed(raylib::Vector2(-ENEMY_SPEED, model->GetEnemyCurrentSpeed().y));
        }
    };
}

std::function<void()> GameViewModel::getUpdateEnemyWallCheck()
{
    return [this]() -> void
    {
        std::vector<CustomCollider *> left = CheckCollisionWithAll(model->GetEnemyLeftWallCheck(), ColliderTag::ENVIRONMENT);
        std::vector<CustomCollider *> right = CheckCollisionWithAll(model->GetEnemyRightWallCheck(), ColliderTag::ENVIRONMENT);
        std::vector<CustomCollider *> ceiling = CheckCollisionWithAll(model->GetEnemyCeilingCheck(), ColliderTag::ENVIRONMENT);
        std::vector<CustomCollider *> ground = CheckCollisionWithAll(model->GetEnemyGroundCheck(), ColliderTag::ENVIRONMENT);
        model->SetEnemyIsLeftWalled(left.size() > 0);
        model->SetEnemyIsRightWalled(right.size() > 0);
        model->SetEnemyIsCeilinged(ceiling.size() > 0);
        model->SetEnemyIsGrounded(ground.size() > 0);
    };
}

std::function<void()> GameViewModel::getUpdateEnemySpeedPhysically()
{
    return [this]() -> void
    {
        if (!model->GetEnemyIsGrounded())
        {
            model->SetEnemyCurrentSpeed(raylib::Vector2(model->GetEnemyCurrentSpeed().x, model->GetEnemyCurrentSpeed().y + ENEMY_GRAVITY * GetFrameTime()));
        }
        if (model->GetEnemyIsGrounded() && model->GetEnemyCurrentSpeed().y > 0)
        {
            model->SetEnemyCurrentSpeed(raylib::Vector2(model->GetEnemyCurrentSpeed().x, 0));
        }
        if (model->GetEnemyIsLeftWalled() && model->GetEnemyCurrentSpeed().x < 0)
        {
            model->SetEnemyCurrentSpeed(raylib::Vector2(0, model->GetEnemyCurrentSpeed().y));
        }
        if (model->GetEnemyIsRightWalled() && model->GetEnemyCurrentSpeed().x > 0)
        {
            model->SetEnemyCurrentSpeed(raylib::Vector2(0, model->GetEnemyCurrentSpeed().y));
        }
        if (model->GetEnemyIsCeilinged() && model->GetEnemyCurrentSpeed().y < 0)
        {
            model->SetEnemyCurrentSpeed(raylib::Vector2(model->GetEnemyCurrentSpeed().x, 0));
        }
    };
}

std::function<void()> GameViewModel::getUpdateEnemyAnimation()
{
    return [this]() -> void
    {
        switch (model->GetEnemyAnimState())
        {
        case ENEMY_WALK:
            UpdateEnemyAnimationInfo("../assets/sprites/Enemy/ZombieRunnerIdle.png", 4);
            break;
        case ENEMY_DEAD:
            UpdateEnemyAnimationInfo("../assets/sprites/Enemy/ZombieRunnerDead.png", 9, ANIMATION_FRAME_TIME, true);
            break;
        }
    };
}

std::function<void()> GameViewModel::getUpdateEnemyPosition()
{
    return [this]() -> void
    {
        model->SetEnemyPosition(raylib::Vector2(model->GetEnemyPosition().x + model->GetEnemyCurrentSpeed().x, model->GetEnemyPosition().y + model->GetEnemyCurrentSpeed().y));
    };
}

std::function<void()> GameViewModel::getUpdateEnemyColliderPosition()
{
    return [this]() -> void
    {
        model->SetEnemyColliderBoxPosition(model->GetEnemyCurrentSpeed());
        model->SetEnemyLeftWallCheckPosition(model->GetEnemyCurrentSpeed());
        model->SetEnemyRightWallCheckPosition(model->GetEnemyCurrentSpeed());
        model->SetEnemyCeilingCheckPosition(model->GetEnemyCurrentSpeed());
        model->SetEnemyGroundCheckPosition(model->GetEnemyCurrentSpeed());
    };
}

std::function<void()> GameViewModel::getUpdateEnemyAnimationFrame()
{
    return [this]() -> void
    {
        model->SetEnemyAnimationFrameTimeCounter(model->GetEnemyAnimationFrameTimeCounter() + GetFrameTime());
        if (model->GetEnemyAnimationFrameTimeCounter() >= model->GetEnemyAnimationFrameTime())
        {
            model->SetEnemyAnimationFrameTimeCounter(0);
            model->SetEnemyAnimationCurrentFrame(model->GetEnemyAnimationCurrentFrame() + 1);
            if (model->GetEnemyAnimationCurrentFrame() >= model->GetEnemyAnimationFrameCount())
            {
                if (!model->GetEnemyAnimationIsStop())
                    model->SetEnemyAnimationCurrentFrame(0);
                else if (model->GetEnemyAnimationIsStop())
                    model->SetEnemyAnimationCurrentFrame(model->GetEnemyAnimationFrameCount() - 1);
            }
        }
    };
}

std::function<void()> GameViewModel::getUpdateEnemyAnimationRect()
{
    return [this]() -> void
    {
        if (model->GetEnemyIsFacingRight())
        {
            model->SetEnemyAnimationFrameWidth(-1 * model->GetEnemyAnimationFrameWidth());
            model->SetEnemyPosition(raylib::Vector2(model->GetEnemyPosition().x + ENEMY_BIAS, model->GetEnemyPosition().y));
            model->SetEnemyAnimationCurrentFrame(model->GetEnemyAnimationFrameCount() - model->GetEnemyAnimationCurrentFrame() - 1);
        }
        if (model->GetEnemyIsFacingRight() && model->GetEnemyAnimationCurrentFrame() == 0 && model->GetEnemyAnimationIsStop())
            model->SetEnemyAnimationCurrentFrame(1);
        raylib::Rectangle sourceRec = raylib::Rectangle(model->GetEnemyAnimationCurrentFrame() * model->GetEnemyAnimationFrameWidth(), 0.0f, model->GetEnemyAnimationFrameWidth(), model->GetEnemyAnimationFrameHeight());
        model->SetEnemySourceRec(sourceRec);
        temp = LoadTexture(model->GetEnemyAnimationPath().c_str());
        temp.Draw(model->GetEnemySourceRec(), model->GetEnemyPosition());
        if (model->GetEnemyIsFacingRight() && model->GetEnemyAnimationCurrentFrame() == 1 && model->GetEnemyAnimationIsStop())
            model->SetEnemyAnimationCurrentFrame(0);
        if (model->GetEnemyIsFacingRight())
        {
            model->SetEnemyAnimationFrameWidth(-1 * model->GetEnemyAnimationFrameWidth());
            model->SetEnemyPosition(raylib::Vector2(model->GetEnemyPosition().x - ENEMY_BIAS, model->GetEnemyPosition().y));
            model->SetEnemyAnimationCurrentFrame(model->GetEnemyAnimationFrameCount() - model->GetEnemyAnimationCurrentFrame() - 1);
        }
    };
}

std::function<void()> GameViewModel::getCheckCollisionWithPlayer()
{
    return [this]() -> void
    {
        std::vector<CustomCollider *> player = CheckCollisionWithAll(model->GetEnemyCollider(), ColliderTag::PLAYER);
        if (player.size() > 0)
        {
            std::cout << "HIT!" << std::endl;
            model->SetPlayerHP(model->GetPlayerHP() - 1);
        }
    };
}