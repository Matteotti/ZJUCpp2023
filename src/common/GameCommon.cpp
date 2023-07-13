//
// Created by Hjuntao on 2023/7/12.
//

#include "GameCommon.h"

GameCommon::GameCommon() {}

GameCommon::GameCommon(int score, bool gameOver) : score(0), gameOver(false) {}

int GameCommon::getScore()
{
    return score;
}

void GameCommon::setScore(int score)
{
    this->score = score;
}

bool GameCommon::getGameOver()
{
    return gameOver;
}

void GameCommon::setGameOver(bool gameOver)
{
    this->gameOver = gameOver;
}
