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

    CustomCollider(const std::string &name_, float x_, float y_, float width_, float height_, ColliderTag colliderTag_)
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
    /* bool check_rect(Rectangle rect_1,Rectangle rect_2)
    {
        if (rect_1.x <= rect_2.x + rect_2.width &&
            rect_1.x + rect_1.width >= rect_2.x &&
            rect_1.y <= rect_2.y + rect_2.height &&
            rect_1.y + rect_1.height >= rect_2.y)
        {
            return true;
        }
        else
        {
            return false;
        }
    } */
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

    void MoveCollider(raylib::Vector2 delta)
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