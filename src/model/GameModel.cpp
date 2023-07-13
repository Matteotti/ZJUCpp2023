//
// Created by Hjuntao on 2023/7/12.
//

#include "GameModel.h"

GameModel::GameModel(){
    this->gameCommonPtr = std::make_shared<GameCommon>(0, false);
}

std::shared_ptr<GameCommon> GameModel::getGameCommonPtr() {
    return gameCommonPtr;
}

void GameModel::setScore(int score) {
    this->gameCommonPtr->setScore(score);
}

int GameModel::getScore() {
    return this->gameCommonPtr->getScore();
}

void GameModel::setGameOver(bool gameOver) {
    this->gameCommonPtr->setGameOver(gameOver);
}

bool GameModel::getGameOver() {
    return this->gameCommonPtr->getGameOver();
}