//
// Created by Hjuntao on 2023/7/12.
//

#ifndef CPPGAMEJAM_GAMEVIEW_H
#define CPPGAMEJAM_GAMEVIEW_H

#include <functional>
#include <iostream>
#include "raylib.h"
#include "raylib-cpp.hpp"
#include "../common/GameCommon.h"
#include "../../includes/direction.h"

class GameView
{
private:
    int HorizontalInput = 0;
    int VerticalInput = 0;

    std::function<void()> updateViewCommand;
    std::function<void()> increaseScoreCommand;
    std::function<void(bool)> setGameOverCommand;

    std::function<void(direction)> playerMoveCommand;
    std::function<void()> playerJumpCommand;
    std::function<void(int)> playerAttackCommand;

    std::shared_ptr<GameCommon> gameCommonPtr;
    

    std::function<void()> attackTopCommand;
    std::function<void()> attackDownCommand;

public:
    GameView();
    void setCommon(std::shared_ptr<GameCommon> gameCommon);
    void drawExample(int score, bool gameOver);
    void UpdateScore();
    void GameOver();
    void UpdatePlayerMove();
    void UpdatePlayerJump();
    void UpdatePlayerAttack();

    void drawTexture(
            raylib::TextureUnmanaged texture,
            raylib::Vector2 position,
            raylib::Rectangle src
    );

    void setIncreaseScoreCommand(std::function<void()> command);
    void setSetGameOverCommand(std::function<void(bool)> command);
    void setPlayerMoveCommand(std::function<void(direction)> command);
    void setPlayerJumpCommand(std::function<void()> command);
    void setPlayerAttackCommand(std::function<void(int)> command);

    std::shared_ptr<GameCommon> getGameCommonPtr() {
        return gameCommonPtr;
    }
    

    void Attack();
    void setAttackTopCommand(std::function<void()> command);
    void setAttackDownCommand(std::function<void()> command);

};

#endif // CPPGAMEJAM_GAMEVIEW_H
