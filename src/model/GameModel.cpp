//
// Created by Hjuntao on 2023/7/12.
//

#include "GameModel.h"

GameModel::GameModel() : score(0), gameOver(false) {}

void GameModel::increaseScore() {
    score++;
}

void GameModel::setGameOver(bool value) {
    gameOver = value;
}
