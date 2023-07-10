#ifndef ANIMATION_H
#define ANIMATION_H

#define ANIMATION_FRAME_TIME 0.2f

#include "raylib-cpp.hpp"
#include "raymath.hpp"
class AnimationInfo
{
public:
    std::string path = "";
    raylib::Texture2D texture;
    int frameCount = 0;
    int currentFrame = 0;
    float frameWidth = 0;
    float frameHeight = 0;
    float frameTime = ANIMATION_FRAME_TIME;
    float frameTimeCounter = 0;

    AnimationInfo()
    {
    }

    AnimationInfo(std::string path_, int frameCount_, float frameTime_ = ANIMATION_FRAME_TIME)
    {
        this->path = path_;
        this->frameCount = frameCount_;
        this->frameTime = frameTime_;
        LoadTexture();
        this->frameWidth = texture.width / frameCount_;
        this->frameHeight = texture.height;
    }

    void LoadTexture()
    {
        texture = raylib::Texture2D(path);
    }

    void DrawAnimation(raylib::Vector2 position, bool flipX = false, raylib::Vector2 bias = raylib::Vector2(0, 0))
    {

        if (flipX)
        {
            frameWidth *= -1;
            position += bias;
        }
        raylib::Rectangle sourceRec = raylib::Rectangle(currentFrame * frameWidth, 0.0f, frameWidth, frameHeight);
        texture.Draw(sourceRec, position);
        if (flipX)
        {
            frameWidth *= -1;
        }
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

#endif // ANIMATION_H