//
// Created by Hjuntao on 2023/7/12.
//

#ifndef CPPGAMEJAM_GAMEVIEWMODEL_H
#define CPPGAMEJAM_GAMEVIEWMODEL_H

#include "../model/GameModel.h"
#include "../view/GameView.h"

class GameViewModel {
private:
    GameModel* model;
    GameView* view;

public:
    GameViewModel(GameModel* model, GameView* view);

    void updateView();
    void increaseScore();
    void setGameOver(bool value);
};

#endif //CPPGAMEJAM_GAMEVIEWMODEL_H
