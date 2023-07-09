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
    void UpdatePlayer(Player& player);
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

void Map::UpdatePlayer(Player& player)
{
    if (player.playerCollider.CheckCollision(mapCollider))
    {
        if (mapName == "wall")
        {
            player.currentSpeed.x = 0.0f;
            player.position.x = mapCollider.colliderBox.min.x;
        }
        if (mapName == "ground" || mapName == "platform")
        {
            player.currentSpeed.y = 0.0f;
            player.isGrounded = true;
            player.position.y = mapCollider.colliderBox.max.y;
            player.jumpCount = 0;
        }
    }
}

std::vector<Map> mapList;

#endif // MAP_H