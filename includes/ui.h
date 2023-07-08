//
// Created by Tonyhh on 2023/7/6.
//

#ifndef CPPGAMEJAM_UI_H
#define CPPGAMEJAM_UI_H

#include "raylib-cpp.hpp"

class UI
{
private:
    raylib::Texture2D texture;
    raylib::Vector2 position;
    raylib::Vector2 scale;

public:
    UI(raylib::Texture2D texture, raylib::Vector2 position, raylib::Vector2 scale);
    void UI_DrawBackground();
    void UI_DrawHP();
    void UI_DrawMP();
    void UpdateHP(int hp);
    void UpdateMP(int mp);
};

void UI::UI_DrawBackground()
{
    raylib::Image background = raylib::LoadImage("assets/UI/Background.png");
}

#endif // CPPGAMEJAM_UI_H
