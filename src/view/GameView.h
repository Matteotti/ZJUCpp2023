//
// Created by Hjuntao on 2023/7/12.
//

#ifndef CPPGAMEJAM_GAMEVIEW_H
#define CPPGAMEJAM_GAMEVIEW_H

#include <functional>
#include <iostream>
#include "raylib.h"

class GameView
{
public:
    void draw(int score, bool gameOver);
    void UpdateScore();
    void GameOver();
    std::function<void()> setUpdateViewCommand(std::function<void()> command);
    std::function<void()> setIncreaseScoreCommand(std::function<void()> command);
    std::function<void(bool)> setSetGameOverCommand(std::function<void(bool)> command);

private:
    std::function<void()> updateViewCommand;
    std::function<void()> increaseScoreCommand;
    std::function<void(bool)> setGameOverCommand;
};

#endif // CPPGAMEJAM_GAMEVIEW_H
