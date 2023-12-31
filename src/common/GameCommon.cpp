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
std::string GameCommon::GetMapAnimPath()
{
    return mapAnimPath;
}
void GameCommon::SetMapAnimPath(std::string path)
{
    mapAnimPath = path;
}
raylib::Vector2 MapCommon::getPosition() const
{
    return position;
}

std::string MapCommon::getPath() const
{
    return path;
}

int MapCommon::getFrameCount() const
{
    return frameCount;
}

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

void MapCommon::SetMapPosition(raylib::Vector2 position)
{
    this->position = position;
}

void MapCommon::SetMappath(std::string path)
{
    this->path = path;
}

void MapCommon::SetMapFrameCount(int frameCount)
{
    this->frameCount = frameCount;
}

MapCommon::MapCommon(raylib::Vector2 position, std::string path, int frameCount, int mapWidth, int mapHeight) {
    this->position = position;
    this->path = path;
    this->frameCount = frameCount;
    this->mapWidth = mapWidth;
    this->mapHeight = mapHeight;
}

int MapCommon::GetMapWidth() {
    return mapWidth;
}

int MapCommon::GetMapHeight() {
    return mapHeight;
}

std::vector<MapCommon> GameCommon::GetMapList()
{
    return maplist;
}
void GameCommon::MapPushBack(MapCommon mapCommon)
{
    maplist.push_back(mapCommon);
}



