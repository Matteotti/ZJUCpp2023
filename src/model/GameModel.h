//
// Created by Hjuntao on 2023/7/12.
//

#ifndef CPPGAMEJAM_GAMEMODEL_H
#define CPPGAMEJAM_GAMEMODEL_H

#include <memory>
#include "../common/GameCommon.h"

class GameModel {

private:

    std::shared_ptr<GameCommon> gameCommonPtr;

public:
    GameModel();

    GameModel(int score, bool gameOver);

    std::shared_ptr<GameCommon> GetGameCommonPtr();

    void setScore(int score);

    int getScore();

    void setGameOver(bool gameOver);

    bool getGameOver();
};

#endif // CPPGAMEJAM_GAMEMODEL_H
