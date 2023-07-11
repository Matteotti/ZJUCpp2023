#ifndef ANIMATION_H
#define ANIMATION_H

#define ANIMATION_FRAME_TIME 0.15f

#include "raylib-cpp.hpp"
#include "raymath.hpp"
#include "iostream"
class AnimationInfo
{
public:
    std::string path = "";
    raylib::Texture2DUnmanaged texture;
    bool stop = false;
    int frameCount = 0;
    int currentFrame = 0;
    float frameWidth = 0;
    float frameHeight = 0;
    float frameTime = ANIMATION_FRAME_TIME;
    float frameTimeCounter = 0;

    AnimationInfo()
    {
    }

    AnimationInfo(const AnimationInfo &animationInfo_)
    {
        this->path = animationInfo_.path;
        this->frameCount = animationInfo_.frameCount;
        this->frameTime = animationInfo_.frameTime;
        this->frameWidth = animationInfo_.frameWidth;
        this->frameHeight = animationInfo_.frameHeight;
        this->frameTimeCounter = animationInfo_.frameTimeCounter;
        this->currentFrame = animationInfo_.currentFrame;
        this->texture = animationInfo_.texture;
        this->stop = animationInfo_.stop;
    }

    AnimationInfo &operator=(const AnimationInfo &animationInfo_)
    {
        this->path = animationInfo_.path;
        this->frameCount = animationInfo_.frameCount;
        this->currentFrame = animationInfo_.currentFrame;
        this->frameTime = animationInfo_.frameTime;
        this->frameWidth = animationInfo_.frameWidth;
        this->frameHeight = animationInfo_.frameHeight;
        this->frameTimeCounter = animationInfo_.frameTimeCounter;
        this->texture = animationInfo_.texture;
        this->stop = animationInfo_.stop;
        return *this;
    }

    AnimationInfo(std::string path_, int frameCount_, float frameTime_ = ANIMATION_FRAME_TIME, bool stop_ = false)
    {
        this->path = path_;
        this->frameCount = frameCount_;
        this->currentFrame = 0;
        this->frameTimeCounter = 0;
        this->frameTime = frameTime_;
        this->stop = stop_;
        LoadTexture();
        this->frameWidth = texture.width / frameCount_;
        this->frameHeight = texture.height;
    }

    void LoadTexture()
    {
        texture = raylib::Texture2DUnmanaged(path);
    }

    void DrawAnimation(raylib::Vector2 position, bool flipX = false, raylib::Vector2 bias = raylib::Vector2(0, 0))
    {

        if (flipX)
        {
            frameWidth *= -1;
            position += bias;
            currentFrame = frameCount - currentFrame - 1;
        }
        if (flipX && currentFrame == 0 && stop)
            currentFrame = 1;
        raylib::Rectangle sourceRec = raylib::Rectangle(currentFrame * frameWidth, 0.0f, frameWidth, frameHeight);
        texture.Draw(sourceRec, position);
        if (flipX && currentFrame == 1 && stop)
            currentFrame = 0;
        if (flipX)
        {
            frameWidth *= -1;
            currentFrame = frameCount - currentFrame - 1;
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
                if (!stop)
                    currentFrame = 0;                    
                else if (stop)
                    currentFrame = frameCount - 1;
            }
        }
    }

    void Update()
    {
        UpdateAnimationFramCount();
    }
};

#endif // ANIMATION_H