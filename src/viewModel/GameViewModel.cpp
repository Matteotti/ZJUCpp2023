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
void GameViewModel::setMapModel(MapModel *mapModel)
{
    this->mapModel = mapModel;
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
std::function<void()> GameViewModel::getPlayerStopJump()
{
}
// TODO: ExecuteAlways
std::function<void()> GameViewModel::getPlayerUpdateJumpSpeed()
{

}
std::function<void()> GameViewModel::getPlayerCheckWall()
{

}
std::function<void()> GameViewModel::getPlayerAniamtorUpdate()
{
    
}



std::function<void(AnimatorState)> GameViewModel::getAttackTopCommand()
{
    return [this](AnimatorState currentstate) -> void
    {
        if (currentstate != ATTACKING_TOP)
        {
            model->SetPlayerAnimatorState(ATTACKING_TOP);
        }
    };
}
std::function<void(AnimatorState)> GameViewModel::getAttackDownCommand()
{
    return [this](AnimatorState currentstate) -> void
    {
        if (currentstate != ATTACKING_BOTTOM)
        {
            model->SetPlayerAnimatorState(ATTACKING_BOTTOM);
        }
    };
}


void GameViewModel::DeleteMap()
{
    for (int i = 0; i < maplist.size(); i++)
    {
        if (maplist[i].GetMapName() == mapModel->GetMapName())
        {
            maplist.erase(maplist.begin() + i);
        }
    }
}