//
// Created by Hjuntao on 2023/7/6.
//

#ifndef CPPGAMEJAM_UI_H
#define CPPGAMEJAM_UI_H


#include "raylib-cpp.hpp"

class UI {
private:
    raylib::Image background;
    raylib::Image hp_bar;
    raylib::Image mp_bar;

    raylib::Texture2D background_texture;
    raylib::Texture2D hp_bar_texture;
    raylib::Texture2D mp_bar_texture;

    raylib::Vector2 background_position;
    raylib::Vector2 hp_bar_position;
    raylib::Vector2 mp_bar_position;

    raylib::Vector2 background_size;
    raylib::Vector2 hp_bar_size;
    raylib::Vector2 mp_bar_size;

    //@TODO: Add an animated topping of the mp bar, will finish upon the completion of the animation class
    //animation::AnimationInfo mp_bar_topping;

public:
    UI();

    void DrawUI();

    void UpdateHP(const int &hp);

    void UpdateMP(const int &mp);

    void ClearUI();//wipe the UI from the screen

    void UnloadUI();//unload the UI from memory
};

UI::UI() {
    //@TODO: Decide the exact position and size of the UI elements
    background_position = raylib::Vector2(0, 0);
    hp_bar_position = raylib::Vector2(0, 0);
    mp_bar_position = raylib::Vector2(0, 0);
    background_size = raylib::Vector2(0, 0);
    hp_bar_size = raylib::Vector2(0, 0);
    mp_bar_size = raylib::Vector2(0, 0);

    background = LoadImage("assets/ui/background.png");
    hp_bar = LoadImage("assets/ui/hp_bar.png");
    mp_bar = LoadImage("assets/ui/mp_bar.png");
}

void UI::DrawUI() {
    background_texture = LoadTextureFromImage(background);
    hp_bar_texture = hp_bar.LoadTexture();
    mp_bar_texture = mp_bar.LoadTexture();
    DrawTexture(background_texture, background_position.x, background_position.y, WHITE);
    //@TODO: Change the HP/MP bar from a rectangle to a covered texture
    //@TODO: Should the size of the HP/MP bar be Vector2 or float?
    DrawTexturePro(hp_bar_texture,
                   raylib::Rectangle(0, 0, hp_bar_size.x, hp_bar_size.y),
                   raylib::Rectangle(hp_bar_position.x, hp_bar_position.y, hp_bar_size.x, hp_bar_size.y),
                   raylib::Vector2(0, 0),
                   0,
                   WHITE);
    DrawTexturePro(mp_bar_texture,
                   raylib::Rectangle(0, 0, mp_bar_size.x, mp_bar_size.y),
                   raylib::Rectangle(mp_bar_position.x, mp_bar_position.y, mp_bar_size.x, mp_bar_size.y),
                   raylib::Vector2(0, 0),
                   0,
                   WHITE);
}

void UI::UpdateHP(const int &hp) {
    hp_bar_size.x = hp;
}

void UI::UpdateMP(const int &mp) {
    mp_bar_size.x = mp;
}

void UI::ClearUI() {
    UnloadTexture(background);
    UnloadTexture(hp_bar);
    UnloadTexture(mp_bar);
}

void UI::UnloadUI() {
    UnloadImage(background);
    UnloadImage(hp_bar);
    UnloadImage(mp_bar);
}


#endif //CPPGAMEJAM_UI_H
