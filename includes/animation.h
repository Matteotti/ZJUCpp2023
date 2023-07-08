#ifndef ANIMATION_H
#define ANIMATION_H

#define ANIMATION_FRAME_TIME 0.1f

#include "raylib-cpp.hpp"
#include "raymath.hpp"
class AnimationInfo
{
public:
    std::string path = "";
    raylib::Texture2D texture;
    raylib::Vector2 position = raylib::Vector2(0, 0);
    int frameCount = 0;
    int currentFrame = 0;
    float frameWidth = 0;
    float frameHeight = 0;
    float frameTime = ANIMATION_FRAME_TIME;
    float frameTimeCounter = 0;

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

    void DrawAnimation(raylib::Vector2 position, bool flipX = false)
    {
        raylib::Rectangle sourceRec = raylib::Rectangle(currentFrame * frameWidth, 0.0f, frameWidth, frameHeight);
        raylib::Rectangle destRec = raylib::Rectangle(position.x, position.y, frameWidth, frameHeight);
        raylib::Vector2 origin = raylib::Vector2(frameCount * frameWidth / 2, frameHeight / 2);
        float rotation = flipX ? 180.0f : 0.0f;
        Color tint = WHITE;
        texture.Draw(sourceRec, destRec, origin, rotation, tint);
    }

    void UpdateAnimationFramCount()
    {
        frameTimeCounter += GetFrameTime();
        if (frameTimeCounter >= frameTime)
        {
            frameTimeCounter = 0;
            currentFrame++;
            if (currentFrame >= frameCount)
            {
                currentFrame = 0;
            }
        }
    }

    void Update()
    {
        UpdateAnimationFramCount();
    }
};

#endif //ANIMATION_H