//
// Created by Hjuntao on 2023/7/12.
//

#ifndef CPPGAMEJAM_GAMEMODEL_H
#define CPPGAMEJAM_GAMEMODEL_H

class GameModel {
public:
    int score;
    bool gameOver;

    GameModel();
    void increaseScore();
    void setGameOver(bool value);
};

#endif //CPPGAMEJAM_GAMEMODEL_H
