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
    return [this]() -> void
    {
        this->updateView();
    };
}

std::function<void()> GameViewModel::getIncreaseScoreCommand()
{
    return [this]() -> void
    {
        this->increaseScore();
    };
}

std::function<void(bool)> GameViewModel::getSetGameOverCommand()
{
    return [this](bool value) -> void
    {
        this->setGameOver(value);
    };
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