//
// Created by Hjuntao on 2023/7/12.
//

#include "GameModel.h"

GameModel::GameModel(){
    this->gameCommonPtr = std::make_shared<GameCommon>(0, false);
}

GameModel::GameModel(int score, bool gameOver) {
    this->gameCommonPtr = std::make_shared<GameCommon>(score, gameOver);
}

std::shared_ptr<GameCommon> GameModel::GetGameCommonPtr() {
    return gameCommonPtr;
}