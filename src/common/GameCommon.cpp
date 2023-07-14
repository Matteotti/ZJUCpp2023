//
// Created by Hjuntao on 2023/7/12.
//

#include "GameCommon.h"

GameCommon::GameCommon() {}

raylib::Vector2 GameCommon::GetPlayerPosition()
{
    return playerPosition;
}
void GameCommon::SetPlayerPosition(raylib::Vector2 position)
{
    playerPosition = position;
}
raylib::Rectangle GameCommon::GetPlayerSourceRect()
{
    return playerSourceRect;
}
void GameCommon::SetPlayerSourceRect(raylib::Rectangle sourceRect)
{
    playerSourceRect = sourceRect;
}
std::string GameCommon::GetPlayerAnimPath()
{
    return playerAnimPath;
}
void GameCommon::SetPlayerAnimPath(std::string path)
{
    playerAnimPath = path;
}