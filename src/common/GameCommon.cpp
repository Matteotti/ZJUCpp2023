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
raylib::Texture2DUnmanaged GameCommon::GetPlayerTexture()
{
    return playerTexture;
}
void GameCommon::SetPlayerTexture(raylib::Texture2DUnmanaged texture)
{
    playerTexture = texture;
}


raylib::Vector2 MapCommon::getPosition() const {
    return position;
}

std::string MapCommon::getPath() const {
    return path;
}

int MapCommon::getFrameCount() const {
    return frameCount;
}

raylib::Texture2DUnmanaged MapCommon::GetPlayerTexture() {
    return mapTexture;
}

void MapCommon::SetPlayerTexture(raylib::Texture2DUnmanaged texture) {
    mapTexture = texture;
}


