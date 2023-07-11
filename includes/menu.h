//
// Created by Hjuntao on 2023/7/9.
//

#ifndef CPPGAMEJAM_MENU_H
#define CPPGAMEJAM_MENU_H

#include "raylib-cpp.hpp"
#include "button.h"

enum GameState{
    START,
    SCENE0,
    SCENE1,
    SCENE2,
    PAUSE,
    GAME_OVER,
    WIN
};

class Menu{
private:
    std::vector<Button> buttons;
    GameState CurrentState;
    raylib::Texture background;
public:
    Menu();
    void DrawMenu();
    void UpdateMenu();
    void UnloadMenu();
    GameState GetState();
    void SetState(GameState state);
};

Menu::Menu(){}

void Menu::DrawMenu() {
    background.Draw(0, 0);
    for (auto &button : buttons) {
        button.DrawButton();
    }
}

void Menu::UpdateMenu() {

}


#endif //CPPGAMEJAM_MENU_H
