//
// Created by Hjuntao on 2023/7/12.
//

#include "GameViewModel.h"
#include <iostream>
#include <functional>

GameViewModel::GameViewModel(){}

void GameViewModel::setModel(GameModel *model)
{
    this->model = model;
}

std::function<void()> GameViewModel::getIncreaseScoreCommand()
{
    return [this]() -> void
    {
        std::cout << "increase score" << std::endl;
        model->GetGameCommonPtr()->setScore(model->GetGameCommonPtr()->getScore() + 1);
    };
}

std::function<void(bool)> GameViewModel::getSetGameOverCommand()
{
    return [this](bool value) -> void
    {
        std::cout << "set game over" << std::endl;
        model->GetGameCommonPtr()->setGameOver(value);
    };
}