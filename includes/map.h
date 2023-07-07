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
    AnimationInfo mapAnimationInfo;
    CustomCollider mapCollider;
};

#endif // MAP_H