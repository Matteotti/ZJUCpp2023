//
// Created by Hjuntao on 2023/7/11.
//

#ifndef CPPGAMEJAM_BUTTON_H
#define CPPGAMEJAM_BUTTON_H

#include "raylib-cpp.hpp"
#include <string>

#define FRAME_WIDTH 50

class Button {
private:
    std::string path;
    raylib::Vector2 position;
    raylib::Texture2DUnmanaged texture;
    raylib::Text text;

    int ButtonState;//0:released 1:mouse hover 2:pressed
    bool ButtonAction;
public:
    Button();

    Button(raylib::Vector2 position, raylib::Texture2DUnmanaged texture, raylib::Text text);

    void DrawButton();

    bool UpdateButton();

    void UnloadButton();

    ~Button() {
        this->texture.Unload();
    }

    Button operator=(Button &other);
};

Button::Button() {
    this->position = raylib::Vector2(0, 0);
    this->ButtonState = 0;
    this->ButtonAction = false;
}

Button::Button(raylib::Vector2 position, raylib::TextureUnmanaged texture, raylib::Text text) {
    this->position = position;
    this->texture = texture;
    this->text = text;
    this->ButtonState = 0;
    this->ButtonAction = false;
}

void Button::DrawButton() {
    text.Draw(position);
    if (ButtonState == 0) {
        texture.Draw(
                raylib::Rectangle(position.x, position.y, texture.width, texture.height),
                raylib::Rectangle(position.x, position.y, FRAME_WIDTH, texture.height),
                raylib::Vector2(0, 0),
                0,
                raylib::WHITE);
    } else if(ButtonState == 1){
        texture.Draw(
                raylib::Rectangle(position.x, position.y, texture.width, texture.height),
                raylib::Rectangle(position.x+FRAME_WIDTH, position.y, FRAME_WIDTH, texture.height),
                raylib::Vector2(0, 0),
                0,
                raylib::WHITE);
    } else{
        texture.Draw(
                raylib::Rectangle(position.x, position.y, texture.width, texture.height),
                raylib::Rectangle(position.x+2*FRAME_WIDTH, position.y, FRAME_WIDTH, texture.height),
                raylib::Vector2(0, 0),
                0,
                raylib::WHITE);
    }
}

bool Button::UpdateButton() {
    if (raylib::Rectangle(position.x, position.y, texture.width, texture.height).CheckCollision(
            GetMousePosition())) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            ButtonState = 2;
            ButtonAction = true;
        } else {
            ButtonState = 1;
            ButtonAction = false;
        }
    } else {
        ButtonState = 0;
        ButtonAction = false;
    }
    return ButtonAction;
}


void Button::UnloadButton() {
    delete this;
}

//overload operator= to copy button
Button Button::operator=(Button &other) {
    this->position = other.position;
    this->texture = other.texture;
    this->text = other.text;
    this->ButtonState = other.ButtonState;
    this->ButtonAction = other.ButtonAction;
    return *this;
}

#endif //CPPGAMEJAM_BUTTON_H
