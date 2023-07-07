#ifndef ANIMATION_H
#define ANIMATION_H

#include "raylib-cpp.hpp"
#include "raymath.hpp"
class AnimationInfo
{
public:
    std::string path;
    raylib::Texture2D texture;
    raylib::Vector2 position;
    int frameCount;
    float frameWidth;
    float frameHeight;
    float frameTime = GetFrameTime();

    void LoadTexture()
    {
        texture = raylib::Texture2D(path);
    }

    void DrawAnimation(raylib::Vector2 position, int currentFrame)
    {
        raylib::Rectangle currentFrameRec = raylib::Rectangle(currentFrame * frameWidth, 0, frameWidth, frameHeight);
        DrawTextureRec(texture, currentFrameRec, position, WHITE);
    }
};

#endif // ANIMATION_H