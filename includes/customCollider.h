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
    BOX,
    CIRCLE,
    RAY,
    POINT
};

class CustomCollider
{
public:
    std::string colliderName;
    raylib::BoundingBox colliderBox;
    raylib::Ray ray;
    raylib::Vector3 center;
    float radius;
    ColliderTag colliderTag = NONE;
    ColliderType colliderType = BOX;

    CustomCollider()
    {
    }

    CustomCollider(const CustomCollider &customCollider_)
    {
        this->colliderName = customCollider_.colliderName;
        this->colliderBox = customCollider_.colliderBox;
        this->ray = customCollider_.ray;
        this->center = customCollider_.center;
        this->radius = customCollider_.radius;
        this->colliderTag = customCollider_.colliderTag;
        this->colliderType = customCollider_.colliderType;
    }

    CustomCollider &operator=(const CustomCollider &customCollider_)
    {
        this->colliderName = customCollider_.colliderName;
        this->colliderBox = customCollider_.colliderBox;
        this->ray = customCollider_.ray;
        this->center = customCollider_.center;
        this->radius = customCollider_.radius;
        this->colliderTag = customCollider_.colliderTag;
        this->colliderType = customCollider_.colliderType;
        return *this;
    }

    CustomCollider(const std::string &name_, raylib::BoundingBox colliderBox_, ColliderTag colliderTag_)
    {
        this->colliderName = name_;
        this->colliderBox = colliderBox_;
        this->colliderTag = colliderTag_;
        this->colliderType = BOX;
        colliderList.push_back(*this);
    }

    CustomCollider(const std::string &name_, raylib::Ray ray_, ColliderTag colliderTag_)
    {
        this->colliderName = name_;
        this->ray = ray_;
        this->colliderTag = colliderTag_;
        this->colliderType = RAY;
        colliderList.push_back(*this);
    }

    CustomCollider(const std::string &name_, raylib::Vector3 center_, float radius_, ColliderTag colliderTag_)
    {
        this->colliderName = name_;
        this->center = center_;
        this->radius = radius_;
        this->colliderTag = colliderTag_;
        this->colliderType = CIRCLE;
        colliderList.push_back(*this);
    }

    CustomCollider(const std::string &name_, raylib::Vector3 center_, ColliderTag colliderTag_)
    {
        this->colliderName = name_;
        this->center = center_;
        this->colliderTag = colliderTag_;
        this->colliderType = POINT;
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
        return colliderBox.CheckCollision(otherCollider.colliderBox);
    }

    bool CheckCollision(raylib::BoundingBox otherCollider)
    {
        return colliderBox.CheckCollision(otherCollider);
    }

    bool CheckCollision(raylib::Ray targetRay)
    {
        return colliderBox.CheckCollision(targetRay);
    }

    bool CheckCollision(raylib::Vector3 targetCenter, float targetRadius)
    {
        return colliderBox.CheckCollision(targetCenter, targetRadius);
    }

    std::vector<CustomCollider> CheckCollisionWithAll()
    {
        std::vector<CustomCollider> colliders = std::vector<CustomCollider>();
        for (int i = 0; i < colliderList.size(); i++)
        {
            if (colliderList[i].colliderName != this->colliderName)
            {
                switch (colliderList[i].colliderType)
                {
                case BOX:
                    if (CheckCollision(colliderList[i].colliderBox))
                    {
                        colliders.push_back(colliderList[i]);
                    }
                    break;
                case CIRCLE:
                    if (CheckCollision(colliderList[i].center, colliderList[i].radius))
                    {
                        colliders.push_back(colliderList[i]);
                    }
                    break;
                case RAY:
                    if (CheckCollision(colliderList[i].ray))
                    {
                        colliders.push_back(colliderList[i]);
                    }
                    break;
                case POINT:
                    if (CheckCollision(colliderList[i].center, POINT_WIDTH))
                    {
                        colliders.push_back(colliderList[i]);
                    }
                    break;
                default:
                    break;
                }
            }
        }
        return colliders;
    }

    std::vector<CustomCollider> CheckCollisionWithAll(ColliderTag targetTag)
    {
        std::vector<CustomCollider> colliders = std::vector<CustomCollider>();
        for (int i = 0; i < colliderList.size(); i++)
        {
            if (colliderList[i].colliderName != this->colliderName && colliderList[i].colliderTag == targetTag)
            {
                switch (colliderList[i].colliderType)
                {
                case BOX:
                    if (CheckCollision(colliderList[i].colliderBox))
                    {
                        colliders.push_back(colliderList[i]);
                    }
                    break;
                case CIRCLE:
                    if (CheckCollision(colliderList[i].center, colliderList[i].radius))
                    {
                        colliders.push_back(colliderList[i]);
                    }
                    break;
                case RAY:
                    if (CheckCollision(colliderList[i].ray))
                    {
                        colliders.push_back(colliderList[i]);
                    }
                    break;
                case POINT:
                    if (CheckCollision(colliderList[i].center, POINT_WIDTH))
                    {
                        colliders.push_back(colliderList[i]);
                    }
                    break;
                default:
                    break;
                }
            }
        }
        return colliders;
    }

    void MoveCollider(raylib::Vector3 delta)
    {
        switch (colliderType)
        {
        case BOX:
            colliderBox.min = Vector3Add(colliderBox.min, delta);
            colliderBox.max = Vector3Add(colliderBox.min, delta);
            break;
        case CIRCLE:
            center += delta;
            break;
        case RAY:
            ray.position = Vector3Add(colliderBox.min, delta);
            break;
        case POINT:
            center += delta;
            break;
        default:
            break;
        }
    }
};

#endif // INCLUDES_COLLIDER_H