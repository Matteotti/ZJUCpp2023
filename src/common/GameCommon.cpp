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

/* raylib::Texture2DUnmanaged MapCommon::GetMapTexture() {
    return mapTexture;
} */

/* void MapCommon::SetMapTexture(raylib::Texture2DUnmanaged texture) {
    mapTexture = texture;
} */

bool GameCommon::GetPlayerIsFacingRight()
{
    return isFacingRight;
}
void GameCommon::SetPlayerIsFacingRight(bool isFacingRight)
{
    this->isFacingRight = isFacingRight;
}

int GameCommon::GetPlayerHP()
{
    return HP;
}
void GameCommon::SetPlayerHP(int hp)
{
    HP = hp;
}
int GameCommon::GetPlayerMP()
{
    return MP;
}
void GameCommon::SetPlayerMP(int mp)
{
    MP = mp;
}

void MapCommon::SetMapPosition(raylib::Vector2 position) {
    this->position = position;
}

void MapCommon::SetMappath(std::string path) {
    this->path = path;
}

void MapCommon::SetMapFrameCount(int frameCount) {
    this->frameCount = frameCount;
}

MapCommon::MapCommon(raylib::Vector2 position, std::string path, int frameCount) {
    this->position = position;
    this->path = path;
    this->frameCount = frameCount;
}

/* void MapCommon::SetFrameWidth(float width)
{
    this->width = width;
}
void MapCommon::SetFrameHeight(float height)
{
    this->height = height;
}
float MapCommon::GetFrameWidth()
{
    return width;
}
float MapCommon::GetFrameHeight()
{
    return height;
} */


