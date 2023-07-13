//
// Created by Hjuntao on 2023/7/12.
//

#ifndef CPPGAMEJAM_GAMEVIEWMODEL_H
#define CPPGAMEJAM_GAMEVIEWMODEL_H

#include "../model/GameModel.h"
#include <functional>

class GameViewModel
{
private:
    GameModel *model;

public:
    explicit GameViewModel();
    void setModel(GameModel *model);
    std::function<void()> getIncreaseScoreCommand();
    std::function<void(bool)> getSetGameOverCommand();
};

#endif // CPPGAMEJAM_GAMEVIEWMODEL_H
