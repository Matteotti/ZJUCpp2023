//
// Created by Hjuntao on 2023/7/12.
//

#ifndef CPPGAMEJAM_GAMECOMMON_H
#define CPPGAMEJAM_GAMECOMMON_H

#include <memory>
#include "raylib-cpp.hpp"
#include "raylib.h"
#define PLAYER_MAX_HP 8
#define PLAYER_MAX_MP 200


class MapCommon
{
private:
    raylib::Vector2 position;
    std::string path;
    int frameCount = 0;
    raylib::Texture2DUnmanaged mapTexture;
    int mapWidth;
    int mapHeight;
public:
    MapCommon(raylib::Vector2 position, std::string path, int frameCount ,int mapWidth, int mapHeight);
    raylib::Vector2 getPosition() const;
    std::string getPath() const;
    int getFrameCount() const;
    void SetMapPosition(raylib::Vector2 position);
    void SetMappath(std::string path);
    void SetMapFrameCount(int frameCount);
    int GetMapWidth();
    int GetMapHeight();


};

class GameCommon
{
private:
    raylib::Vector2 playerPosition = raylib::Vector2(0, 0);
    raylib::Rectangle playerSourceRect;
    std::string playerAnimPath;
    std::string mapAnimPath;
    bool isFacingRight = false;
    int HP = PLAYER_MAX_HP;
    int MP = PLAYER_MAX_MP;
    std::vector<MapCommon> maplist;

public:
    GameCommon();
    raylib::Vector2 GetPlayerPosition();
    void SetPlayerPosition(raylib::Vector2 position);
    raylib::Rectangle GetPlayerSourceRect();
    void SetPlayerSourceRect(raylib::Rectangle sourceRect);
    std::string GetPlayerAnimPath();
    void SetPlayerAnimPath(std::string path);
    std::string GetMapAnimPath();
    void SetMapAnimPath(std::string path);
    bool GetPlayerIsFacingRight();
    void SetPlayerIsFacingRight(bool isFacingRight);
    int GetPlayerHP();
    void SetPlayerHP(int hp);
    int GetPlayerMP();
    void SetPlayerMP(int mp);
    std::vector<MapCommon> GetMapList();
    void MapPushBack(MapCommon mapCommon);
};



#endif // CPPGAMEJAM_GAMECOMMON_H
