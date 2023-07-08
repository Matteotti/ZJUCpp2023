#ifndef MAP_H
#define MAP_H

#include "raylib-cpp.hpp"
#include "raymath.hpp"
#include "includes/animation.h"
#include "includes/customCollider.h"

class Map
{
public:
    std::string mapName;
    std::string path;
    int frameCount = 0;
    int frameWidth = 0;
    int frameHeight = 0;
    raylib::Vector2 position;
    int width;
    int height;
    AnimationInfo mapAnimationInfo;
    CustomCollider mapCollider;

    Map(std::string mapName, std::string path, int frameCount, int frameWidth, int frameHeight)
    {
        this->mapName = mapName;
        this->path = path;
        this->frameCount = frameCount;
        this->frameWidth = frameWidth;
        this->frameHeight = frameHeight;
        this->mapAnimationInfo = AnimationInfo(path, frameCount, frameWidth, frameHeight);
        raylib::Vector3 min = raylib::Vector3(position.x, position.y - height, 0);
        raylib::Vector3 max = raylib::Vector3(position.x + width, position.y, 0);
        this->mapCollider = CustomCollider(mapName, raylib::BoundingBox(min, max), ColliderTag::ENVIRONMENT);
    }

    void DrawMap()
    {
        mapAnimationInfo.DrawAnimation(position);
    }
};

std::vector<Map> mapList;

#endif // MAP_H