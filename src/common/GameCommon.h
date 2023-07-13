//
// Created by Hjuntao on 2023/7/12.
//

#ifndef CPPGAMEJAM_GAMECOMMON_H
#define CPPGAMEJAM_GAMECOMMON_H

#include <memory>
#include "raylib-cpp.hpp"
#include "raylib.h"

struct Player
{

}

class GameCommon
{
private:
    int score;
    bool gameOver;

public:
    GameCommon();

    GameCommon(int score, bool gameOver);

    int getScore();

    void setScore(int score);

    bool getGameOver();

    void setGameOver(bool gameOver);
};

#endif // CPPGAMEJAM_GAMECOMMON_H
