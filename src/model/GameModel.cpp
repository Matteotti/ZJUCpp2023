//
// Created by Hjuntao on 2023/7/12.
//

#include "GameModel.h"

GameModel::GameModel() : score(0), gameOver(false) {}

int GameModel::GetScore()
{
    return score;
}

void GameModel::SetScore(int value)
{
    score = value;
}

bool GameModel::GetGameOver()
{
    return gameOver;
}

void GameModel::SetGameOver(bool value)
{
    gameOver = value;
}
