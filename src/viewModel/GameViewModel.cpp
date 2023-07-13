//
// Created by Hjuntao on 2023/7/12.
//

#include "GameViewModel.h"
#include <functional>

GameViewModel::GameViewModel() {}

void GameViewModel::setModel(GameModel *model)
{
    this->model = model;
}

// TODO: ReadInDirection
std::function<void(direction)> GameViewModel::getMovePlayerCommand()
{
    return [this](direction command) -> void
    {
        if (model->GetPlayerIsFacingRight() && command == direction::LEFT)
        {
            model->SetPlayerIsFacingRight(false);
        }
        else if (!model->GetPlayerIsFacingRight() && command == direction::RIGHT)
        {
            model->SetPlayerIsFacingRight(true);
        }
        switch (command)
        {
        case LEFT:
            model->SetPlayerSpeed(raylib::Vector2(-PLAYER_SPEED, model->GetPlayerSpeed().y));
            break;
        case RIGHT:
            model->SetPlayerSpeed(raylib::Vector2(PLAYER_SPEED, model->GetPlayerSpeed().y));
            break;
        case STILL:
            model->SetPlayerSpeed(raylib::Vector2(0, model->GetPlayerSpeed().y));
            break;
        default:
            break;
        }
    };
}
// TODO: ExecuteWhenSpaceIsPressed
std::function<void()> GameViewModel::getPlayerStartJump()
{
}
// TODO: ExecuteWhenSpaceIsReleased
std::function<void()> GameViewModel::getPlayerStopJump();
// TODO: ExecuteAlways
std::function<void()> GameViewModel::getPlayerUpdateJumpSpeed();
std::function<void()> GameViewModel::getPlayerCheckWall();
std::function<void()> GameViewModel::getPlayerAniamtorUpdate();