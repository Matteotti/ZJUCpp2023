#ifndef ANIMATION_H
#define ANIMATION_H

#include "raylib-cpp.hpp"
#include "raymath.hpp"
class AnimationInfo
{
public:
    std::string path = "";
    raylib::Texture2D texture;
    raylib::Vector2 position = raylib::Vector2(0, 0);
    int frameCount = 0;
    float frameWidth = 0;
    float frameHeight = 0;
    float frameTime = GetFrameTime();

    AnimationInfo()
    {
    }

    AnimationInfo(std::string path_, int frameCount_, float frameWidth_, float frameHeight_)
    {
        this->path = path_;
        this->frameCount = frameCount_;
        this->frameWidth = frameWidth_;
        this->frameHeight = frameHeight_;
        LoadTexture();
    }

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