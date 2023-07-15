//
// Created by Hjuntao on 2023/7/12.
//

#ifndef CPPGAMEJAM_GAMEVIEWMODEL_H
#define CPPGAMEJAM_GAMEVIEWMODEL_H

#include "../model/GameModel.h"
#include "../../includes/direction.h"
#include "raylib-cpp.hpp"
#include "raylib.h"
#include <iostream>
#include <functional>

class GameViewModel
{
private:
    GameModel *model;

public:
    explicit GameViewModel();
    void setModel(GameModel *model);

    std::shared_ptr<MapCommon> GetMapCommonPtr();
    std::vector<MapCommon> GetMapList();

    std::vector<CustomCollider *> CheckCollisionWithAll(CustomCollider *target, ColliderTag targetTag);
    std::vector<CustomCollider *> CheckCollisionWithAll(CustomCollider *target);
    void UpdateAnimationInfo(std::string path, int frameCount, float frameTime_, bool stop_);

    // void setMapModel(MapModel *mapModel);
    std::function<void(direction)> getMovePlayerCommand();
    std::function<void(bool)> getPlayerJumpCommand();
    std::function<void()> getPlayerUpdateJumpSpeed();
    std::function<void()> getPlayerCheckWall();
    std::function<void()> getPlayerAnimatorUpdate();
    std::function<void()> getPlayerAnimationUpdate();
    std::function<void()> getPlayerUpdatePosition();
    std::function<void()> getUpdateAnimationFrame();
    std::function<void()> getUpdatePlayerAnimationRect();
    std::function<void()> getDrawPlayerCommand();

    std::function<void(direction)> getPlayerAttackCommand();
    // void DeleteMap();
};

#endif // CPPGAMEJAM_GAMEVIEWMODEL_H
