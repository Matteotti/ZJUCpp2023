//
// Created by Hjuntao on 2023/7/12.
//

#include "GameViewModel.h"

GameViewModel::GameViewModel(GameModel* model, GameView* view) : model(model), view(view) {}

void GameViewModel::updateView() {
    view->draw(model->score, model->gameOver);
}

void GameViewModel::increaseScore() {
    model->increaseScore();
    updateView();
}

void GameViewModel::setGameOver(bool value) {
    model->setGameOver(value);
    updateView();
}
