#ifndef INCLUDES_COLLIDER_H
#define INCLUDES_COLLIDER_H

#include "raylib-cpp.hpp"
#include "raymath.hpp"
#include "includes\animation.h"

#define POINT_WIDTH 0.1f

class CustomCollider;
std::vector<CustomCollider> colliderList;

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

class CustomCollider
{
public:
    std::string colliderName;
    raylib::Rectangle colliderBox;
    raylib::Vector2 center;
    float radius;
    ColliderTag colliderTag = NONE;
    ColliderType colliderType = RECT;

    CustomCollider()
    {
    }

    CustomCollider(const CustomCollider &customCollider_)
    {
        this->colliderName = customCollider_.colliderName;
        this->colliderBox = customCollider_.colliderBox;
        this->center = customCollider_.center;
        this->radius = customCollider_.radius;
        this->colliderTag = customCollider_.colliderTag;
        this->colliderType = customCollider_.colliderType;
    }

    CustomCollider &operator=(const CustomCollider &customCollider_)
    {
        this->colliderName = customCollider_.colliderName;
        this->colliderBox = customCollider_.colliderBox;
        this->center = customCollider_.center;
        this->radius = customCollider_.radius;
        this->colliderTag = customCollider_.colliderTag;
        this->colliderType = customCollider_.colliderType;
        return *this;
    }

    CustomCollider(const std::string &name_, float x_, float y_, float height_, float width_, ColliderTag colliderTag_)
    {
        this->colliderName = name_;
        this->colliderBox = raylib::Rectangle(x_, y_, width_, height_);
        this->colliderTag = colliderTag_;
        this->colliderType = RECT;
        colliderList.push_back(*this);
    }

    CustomCollider(const std::string &name_, raylib::Vector2 center_, float radius_, ColliderTag colliderTag_)
    {
        this->colliderName = name_;
        this->center = center_;
        this->radius = radius_;
        this->colliderTag = colliderTag_;
        this->colliderType = CIRCLE;
        colliderList.push_back(*this);
    }

    void DeleteCollider()
    {
        for (int i = 0; i < colliderList.size(); i++)
        {
            if (colliderList[i].colliderName == this->colliderName)
            {
                colliderList.erase(colliderList.begin() + i);
            }
        }
    }

    bool CheckCollision(CustomCollider otherCollider)
    {
        if (this->colliderType == RECT && otherCollider.colliderType == RECT)
        {
            return CheckCollisionRecs(this->colliderBox, otherCollider.colliderBox);
        }
        else if (this->colliderType == CIRCLE && otherCollider.colliderType == CIRCLE)
        {
            return CheckCollisionCircles(this->center, this->radius, otherCollider.center, otherCollider.radius);
        }
        else if (this->colliderType == RECT && otherCollider.colliderType == CIRCLE)
        {
            return CheckCollisionCircleRec(otherCollider.center, otherCollider.radius, this->colliderBox);
        }
        else if (this->colliderType == CIRCLE && otherCollider.colliderType == RECT)
        {
            return CheckCollisionCircleRec(this->center, this->radius, otherCollider.colliderBox);
        }
        return false;
    }

    std::vector<CustomCollider> CheckCollisionWithAll()
    {
        std::vector<CustomCollider> colliders = std::vector<CustomCollider>();
        for (int i = 0; i < colliderList.size(); i++)
        {
            if (colliderList[i].colliderName != this->colliderName)
            {
                if (CheckCollision(colliderList[i]))
                {
                    colliders.push_back(colliderList[i]);
                }
            }
            return colliders;
        }
    }

    std::vector<CustomCollider> CheckCollisionWithAll(ColliderTag targetTag)
    {
        std::vector<CustomCollider> colliders = std::vector<CustomCollider>();
        for (int i = 0; i < colliderList.size(); i++)
        {
            if (colliderList[i].colliderName != this->colliderName && colliderList[i].colliderTag == targetTag)
            {
                if (CheckCollision(colliderList[i]))
                {
                    colliders.push_back(colliderList[i]);
                }
            }
        }
        return colliders;
    }

    void MoveCollider(raylib::Vector2 delta)
    {
        switch (colliderType)
        {
        case RECT:
            colliderBox.x += delta.x;
            colliderBox.y += delta.y;
            break;
        case CIRCLE:
            center += delta;
            break;
        default:
            break;
        }
    }
};

#endif // INCLUDES_COLLIDER_H