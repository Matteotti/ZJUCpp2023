#ifndef MAP_H
#define MAP_H

#include "raylib-cpp.hpp"
#include "raymath.hpp"
#include "includes/animation.h"
#include "includes/customCollider.h"

class Map;
std::vector<Map> mapList;

class Map
{
public:
    std::string mapName;
    std::string path;
    int frameCount = 0;
    raylib::Vector2 position;
    int width;
    int height;
    AnimationInfo mapAnimationInfo;
    CustomCollider mapCollider;

    Map(const Map &other)
    {
        // Copy the data from other to this object
        mapName = other.mapName;
        path = other.path;
        frameCount = other.frameCount;
        position = other.position;
        mapAnimationInfo = other.mapAnimationInfo;
        width = other.width;
        height = other.height;
        mapCollider = other.mapCollider;
    }

    Map &operator=(const Map &other)
    {
        if (this != &other)
        {
            // Copy the data from other to this object
            mapName = other.mapName;
            path = other.path;
            frameCount = other.frameCount;
            position = other.position;
            mapAnimationInfo = other.mapAnimationInfo;
            width = other.width;
            height = other.height;
            mapCollider = other.mapCollider;
        }
        return *this;
    }

    Map(const std::string &mapName, std::string path, int frameCount, raylib::Vector2 position)
    {
        this->mapName = mapName;
        this->path = path;
        this->frameCount = frameCount;
        this->position = position;
        this->mapAnimationInfo = AnimationInfo(path, frameCount);
        this->width = mapAnimationInfo.texture.width / frameCount;
        this->height = mapAnimationInfo.texture.height;
        raylib::Vector3 min = raylib::Vector3(position.x, position.y - height, 0);
        raylib::Vector3 max = raylib::Vector3(position.x + width, position.y, 0);
        this->mapCollider = CustomCollider(mapName, raylib::BoundingBox(min, max), ColliderTag::ENVIRONMENT);
        mapList.push_back(*this);
    }

    void DeleteMap()
    {
        for (int i = 0; i < mapList.size(); i++)
        {
            if (mapList[i].mapName == mapName)
            {
                mapList.erase(mapList.begin() + i);
            }
        }
    }

    void DrawMap()
    {
        mapAnimationInfo.DrawAnimation(position);
    }

    void Update()
    {
        mapAnimationInfo.Update();
    }
};

#endif // MAP_H