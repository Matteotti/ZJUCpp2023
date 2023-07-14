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
    std::string playerAnimPath;

public:
    GameCommon();
    raylib::Vector2 GetPlayerPosition();
    void SetPlayerPosition(raylib::Vector2 position);
    raylib::Rectangle GetPlayerSourceRect();
    void SetPlayerSourceRect(raylib::Rectangle sourceRect);
    std::string GetPlayerAnimPath();
    void SetPlayerAnimPath(std::string path);
};

#endif // CPPGAMEJAM_GAMECOMMON_H
