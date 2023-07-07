#ifndef INCLUDES_COLLIDER_H
#define INCLUDES_COLLIDER_H

#include "raylib-cpp.hpp"
#include "raymath.hpp"
#include "includes\animation.h"

#define POINT_WIDTH 0.1f

class CustomCollider;
std::vector<CustomCollider *> colliderList;

enum ColliderTag
{
    PLAYER,
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

    CustomCollider(std::string name_, raylib::BoundingBox colliderBox_, ColliderTag colliderTag_)
    {
        this->colliderName = name_;
        this->colliderBox = colliderBox_;
        this->colliderTag = colliderTag_;
        this->colliderType = BOX;
        colliderList.push_back(this);
    }

    CustomCollider(std::string name_, raylib::Ray ray_, ColliderTag colliderTag_)
    {
        this->colliderName = name_;
        this->ray = ray_;
        this->colliderTag = colliderTag_;
        this->colliderType = RAY;
        colliderList.push_back(this);
    }

    CustomCollider(std::string name_, raylib::Vector3 center_, float radius_, ColliderTag colliderTag_)
    {
        this->colliderName = name_;
        this->center = center_;
        this->radius = radius_;
        this->colliderTag = colliderTag_;
        this->colliderType = CIRCLE;
        colliderList.push_back(this);
    }

    CustomCollider(std::string name_, raylib::Vector3 center_, ColliderTag colliderTag_)
    {
        this->colliderName = name_;
        this->center = center_;
        this->colliderTag = colliderTag_;
        this->colliderType = POINT;
        colliderList.push_back(this);
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

    std::vector<CustomCollider *> CheckCollisionWithAll()
    {
        std::vector<CustomCollider *> colliders = std::vector<CustomCollider *>();
        for (int i = 0; i < colliderList.size(); i++)
        {
            if (colliderList[i] != this)
            {
                switch (colliderList[i]->colliderType)
                {
                case BOX:
                    if (CheckCollision(colliderList[i]->colliderBox))
                    {
                        colliders.push_back(colliderList[i]);
                    }
                    break;
                case CIRCLE:
                    if (CheckCollision(colliderList[i]->center, colliderList[i]->radius))
                    {
                        colliders.push_back(colliderList[i]);
                    }
                    break;
                case RAY:
                    if (CheckCollision(colliderList[i]->ray))
                    {
                        colliders.push_back(colliderList[i]);
                    }
                    break;
                case POINT:
                    if (CheckCollision(colliderList[i]->center, POINT_WIDTH))
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

    std::vector<CustomCollider *> CheckCollisionWithAll(ColliderTag targetTag)
    {
        std::vector<CustomCollider *> colliders = std::vector<CustomCollider *>();
        for (int i = 0; i < colliderList.size(); i++)
        {
            if (colliderList[i] != this && colliderList[i]->colliderTag == targetTag)
            {
                switch (colliderList[i]->colliderType)
                {
                case BOX:
                    if (CheckCollision(colliderList[i]->colliderBox))
                    {
                        colliders.push_back(colliderList[i]);
                    }
                    break;
                case CIRCLE:
                    if (CheckCollision(colliderList[i]->center, colliderList[i]->radius))
                    {
                        colliders.push_back(colliderList[i]);
                    }
                    break;
                case RAY:
                    if (CheckCollision(colliderList[i]->ray))
                    {
                        colliders.push_back(colliderList[i]);
                    }
                    break;
                case POINT:
                    if (CheckCollision(colliderList[i]->center, POINT_WIDTH))
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
};

#endif // INCLUDES_COLLIDER_H