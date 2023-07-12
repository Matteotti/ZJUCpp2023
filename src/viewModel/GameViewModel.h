//
// Created by Hjuntao on 2023/7/12.
//

#ifndef CPPGAMEJAM_GAMEVIEWMODEL_H
#define CPPGAMEJAM_GAMEVIEWMODEL_H

#include "../model/GameModel.h"
#include "../view/GameView.h"

class GameViewModel
{
private:
    GameModel *model;
    GameView *view;

public:
    GameViewModel(GameModel *model, GameView *view);
    void Bind();
    std::function<void()> getUpdateViewCommand();
    std::function<void()> getIncreaseScoreCommand();
    std::function<void(bool)> getSetGameOverCommand();

    void updateView();
    void increaseScore();
    void setGameOver(bool value);
};

#endif // CPPGAMEJAM_GAMEVIEWMODEL_H
