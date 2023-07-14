#ifndef INCLUDES_COLLIDER_H
#define INCLUDES_COLLIDER_H

#include "raylib-cpp.hpp"
#include "raymath.hpp"

#define POINT_WIDTH 0.1f

enum ColliderTag
{
    PLAYER,
    PLAYER_WALLCHECK,
    ENEMY,
    PLAYERATTACK,
    ENEMYATTACK,
    TRAP,
    ENVIRONMENT,
    BACKGROUND,
    NONE
};

enum ColliderType
{
    RECT,
    CIRCLE,
};

typedef struct customColliderStruct
{
    std::string colliderName;
    raylib::Rectangle colliderBox;
    raylib::Vector2 center;
    float radius;
    ColliderTag colliderTag = NONE;
    ColliderType colliderType = RECT;
} CustomCollider;


#endif // INCLUDES_COLLIDER_H