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
    raylib::Rectangle colliderRectangle;
    raylib::Ray ray;
    raylib::Vector2 center;
    float radius;
    ColliderTag colliderTag = NONE;
    ColliderType colliderType = BOX;

    CustomCollider()
    {
    }

    CustomCollider(CustomCollider& otherCollider)
    {
        this->colliderName=otherCollider.colliderName;
        this->colliderRectangle=otherCollider.colliderRectangle;
        this->ray=otherCollider.ray;
        this->center=otherCollider.center;
        this->radius=otherCollider.radius;
        this->colliderTag=otherCollider.colliderTag;
        this->colliderType=otherCollider.colliderType;
    }

    CustomCollider(const std::string &name_, raylib::Rectangle colliderRectangle_, ColliderTag colliderTag_)
    {
        this->colliderName = name_;
        this->colliderRectangle = colliderRectangle_;
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

    CustomCollider(const std::string &name_, raylib::Vector2 center_, float radius_, ColliderTag colliderTag_)
    {
        this->colliderName = name_;
        this->center = center_;
        this->radius = radius_;
        this->colliderTag = colliderTag_;
        this->colliderType = CIRCLE;
        colliderList.push_back(*this);
    }

    CustomCollider(const std::string &name_, raylib::Vector2 center_, ColliderTag colliderTag_)
    {
        this->colliderName = name_;
        this->center = center_;
        this->colliderTag = colliderTag_;
        this->colliderType = POINT;
        colliderList.push_back(*this);
    }

    CustomCollider& operator=(CustomCollider* otherCollider)
    {
        if (this==otherCollider)
        {
            return *this;
        }
        else
        {
            this->colliderName=otherCollider->colliderName;
            this->colliderRectangle=otherCollider->colliderRectangle;
            this->ray=otherCollider->ray;
            this->center=otherCollider->center;
            this->radius=otherCollider->radius;
            this->colliderTag=otherCollider->colliderTag;
            this->colliderType=otherCollider->colliderType;
        }
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
        return colliderRectangle.CheckCollision(otherCollider.colliderRectangle);
    }

    bool CheckCollision(raylib::Rectangle targetRectangle)
    {
        return colliderRectangle.CheckCollision(targetRectangle);
    }

    /* bool CheckCollision(raylib::Ray targetRay)
    {
        return colliderBox.CheckCollision(targetRay);
    } */

    bool CheckCollision(raylib::Vector2 targetCenter, float targetRadius)
    {
        return colliderRectangle.CheckCollision(targetCenter, targetRadius);
    }

    bool CheckCollision(raylib::Vector2 Point)
    {
        return colliderRectangle.CheckCollision(Point);
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
                    if (CheckCollision(colliderList[i].colliderRectangle))
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
                /*case RAY:
                    if (CheckCollision(colliderList[i].ray))
                    {
                        colliders.push_back(colliderList[i]);
                    }
                    break; */
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
                    if (CheckCollision(colliderList[i].colliderRectangle))
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
                /* case RAY:
                    if (CheckCollision(colliderList[i].ray))
                    {
                        colliders.push_back(colliderList[i]);
                    }
                    break; */
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
            colliderRectangle.SetPosition(delta.Add(colliderRectangle.GetPosition()));
            break;
        case CIRCLE:
            center=Vector2Add(center,delta);
            break;
        /* case RAY:
            ray.position = Vector3Add(colliderBox.min, delta);
            break; */
        case POINT:
            center=Vector2Add(center,delta);
            break;
        default:
            break;
        }
    }
};

#endif // INCLUDES_COLLIDER_H