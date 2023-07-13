//
// Created by Hjuntao on 2023/7/12.
//

#ifndef CPPGAMEJAM_GAMEVIEW_H
#define CPPGAMEJAM_GAMEVIEW_H

#include <functional>
#include <iostream>
#include "raylib.h"
#include "../common/GameCommon.h"

class GameView
{
private:
    std::function<void()> updateViewCommand;
    std::function<void()> increaseScoreCommand;
    std::function<void(bool)> setGameOverCommand;

    std::shared_ptr<GameCommon> gameCommonPtr;

public:
    GameView();
    void setCommon(std::shared_ptr<GameCommon> gameCommonPtr);
    void draw(int score, bool gameOver);
    void UpdateScore();
    void GameOver();

    void setIncreaseScoreCommand(std::function<void()> command);
    void setSetGameOverCommand(std::function<void(bool)> command);

    std::shared_ptr<GameCommon> getGameCommonPtr() {
        return gameCommonPtr;
    }
};

#endif // CPPGAMEJAM_GAMEVIEW_H
