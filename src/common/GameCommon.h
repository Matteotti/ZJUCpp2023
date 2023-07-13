//
// Created by Hjuntao on 2023/7/12.
//

#ifndef CPPGAMEJAM_GAMECOMMON_H
#define CPPGAMEJAM_GAMECOMMON_H

#include <memory>
#include "raylib-cpp.hpp"
#include "raylib.h"

class GameCommon
{
private:
    raylib::Vector2 playerPosition = raylib::Vector2(0, 0);
    raylib::Rectangle playerSourceRect;
    raylib::Texture2DUnmanaged playerTexture;

public:
    GameCommon();
    raylib::Vector2 GetPlayerPosition();
    void SetPlayerPosition(raylib::Vector2 position);
    raylib::Rectangle GetPlayerSourceRect();
    void SetPlayerSourceRect(raylib::Rectangle sourceRect);
    raylib::Texture2DUnmanaged GetPlayerTexture();
    void SetPlayerTexture(raylib::Texture2DUnmanaged texture);
};

#endif // CPPGAMEJAM_GAMECOMMON_H
