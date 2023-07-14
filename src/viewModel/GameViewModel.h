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
    MapModel *mapModel;

public:
    explicit GameViewModel();
    void setModel(GameModel *model);
    void setMapModel(MapModel *mapModel);
    std::function<void(direction)> getMovePlayerCommand();
    std::function<void()> getPlayerStartJump();
    std::function<void()> getPlayerStopJump();
    std::function<void()> getPlayerUpdateJumpSpeed();
    std::function<void()> getPlayerCheckWall();
    std::function<void()> getPlayerAniamtorUpdate();


    std::function<void(AnimatorState)> getAttackTopCommand();
    std::function<void(AnimatorState)> getAttackDownCommand();
    void DeleteMap();

};

#endif // CPPGAMEJAM_GAMEVIEWMODEL_H
