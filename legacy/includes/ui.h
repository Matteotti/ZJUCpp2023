//
// Created by Hjuntao on 2023/7/6.
//

#ifndef CPPGAMEJAM_UI_H
#define CPPGAMEJAM_UI_H

#define HP_UNIT_WIDTH 0.5f
#define MP_UNIT_HEIGHT 0.5f

#define HP_BAR_POSITION_X 0
#define HP_BAR_POSITION_Y 0
#define MP_BAR_POSITION_X 0
#define MP_BAR_POSITION_Y 0
#define BACKGROUND_POSITION_X 0
#define BACKGROUND_POSITION_Y 0


#include "raylib-cpp.hpp"
#include "animation.h"

class UI{
private:
    raylib::Texture HP_bar;
    raylib::Texture MP_bar;
    raylib::Texture Background;

    int HP_count;
    int MP_count;

    AnimationInfo MP_bar_topping;

public:
    UI();
    void DrawUI();
    void UpdateUI(const int HP, const int MP);
    void UnloadUI();
};

UI::UI() {
    HP_bar = raylib::Texture("../assets/UI/HP_bar_full.png");
    MP_bar = raylib::Texture("../assets/UI/MP_bar_full.png");
    Background = raylib::Texture("../assets/UI/Background.png");
    HP_count = 8;
    MP_count = 100;
}

void UI::DrawUI() {
    Background.Draw(BACKGROUND_POSITION_X, BACKGROUND_POSITION_Y);
    HP_bar.Draw(
            raylib::Rectangle(HP_BAR_POSITION_X, HP_BAR_POSITION_Y, HP_bar.width, HP_bar.height),
            raylib::Rectangle(HP_BAR_POSITION_X, HP_BAR_POSITION_Y, HP_bar.width * HP_count, HP_bar.height),
            raylib::Vector2(0, 0),
            0,
            raylib::Color(255, 255, 255, 255)
            );
    MP_bar.Draw(
            raylib::Rectangle(MP_BAR_POSITION_X, MP_BAR_POSITION_Y, MP_bar.width, MP_bar.height),
            raylib::Rectangle(MP_BAR_POSITION_X, MP_BAR_POSITION_Y, MP_bar.width, MP_bar.height * MP_count),
            raylib::Vector2(0, 0),
            0,
            raylib::Color(255, 255, 255, 255)
            );
}

void UI::UpdateUI(const int HP, const int MP) {
    HP_count = HP;
    MP_count = MP;
}

void UI::UnloadUI() {
    HP_bar.Unload();
    MP_bar.Unload();
    Background.Unload();
}

#endif //CPPGAMEJAM_UI_H
