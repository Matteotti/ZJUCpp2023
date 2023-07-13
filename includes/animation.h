#ifndef ANIMATION_H
#define ANIMATION_H

#define ANIMATION_FRAME_TIME 0.15f

#include "raylib-cpp.hpp"
#include "raymath.hpp"
#include "iostream"
typedef struct AnimationInfoInModelStruct
{
    std::string path = "";
    bool stop = false;
    int frameCount = 0;
    int currentFrame = 0;
    float frameWidth = 0;
    float frameHeight = 0;
    float frameTime = ANIMATION_FRAME_TIME;
    float frameTimeCounter = 0;
} AnimationInfo;

#endif // ANIMATION_H