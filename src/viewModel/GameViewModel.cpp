//
// Created by Hjuntao on 2023/7/12.
//

#include "GameViewModel.h"
#include <iostream>
#include <functional>

GameViewModel::GameViewModel(GameModel *model, GameView *view) : model(model), view(view)
{
}

void GameViewModel::Bind()
{
    view->setUpdateViewCommand(getUpdateViewCommand());
    view->setIncreaseScoreCommand(getIncreaseScoreCommand());
    view->setSetGameOverCommand(getSetGameOverCommand());
}

std::function<void()> GameViewModel::getUpdateViewCommand()
{
    return std::bind(&GameViewModel::updateView, this);
}

std::function<void()> GameViewModel::getIncreaseScoreCommand()
{
    return std::bind(&GameViewModel::increaseScore, this);
}

std::function<void(bool)> GameViewModel::getSetGameOverCommand()
{
    return std::bind(&GameViewModel::setGameOver, this, std::placeholders::_1);
}

void GameViewModel::updateView()
{
    view->draw(model->score, model->gameOver);
}

void GameViewModel::increaseScore()
{
    std::cout << "increase score" << std::endl;
    model->SetScore(model->GetScore() + 1);
}

void GameViewModel::setGameOver(bool value)
{
    std::cout << "set game over" << std::endl;
    model->SetGameOver(value);
}