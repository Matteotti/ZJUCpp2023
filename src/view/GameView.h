//
// Created by Hjuntao on 2023/7/12.
//

#ifndef CPPGAMEJAM_GAMEVIEW_H
#define CPPGAMEJAM_GAMEVIEW_H

#include <functional>
#include <iostream>
#include <utility>
#include "raylib.h"
#include "raylib-cpp.hpp"
#include "../common/GameCommon.h"
#include "../../includes/direction.h"
#include "../../includes/animation.h"
#include "../../includes/player.h"

class Button
{
private:
    raylib::Image image;
    raylib::Rectangle src;
    bool isHovered;
    std::function<void()> command;

public:
    Button(std::string path, raylib::Rectangle src, std::function<void()> command)
    {
        image.Load(path);
        this->src = src;
        this->isHovered = false;
        this->command = command;
    }
    void UpdateButton()
    {
        if (CheckCollisionPointRec(GetMousePosition(), src))
        {
            isHovered = true;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                command();
            }
        }
        else
        {
            isHovered = false;
        }
    }
    void DrawButton()
    {
        if (isHovered)
        {
            raylib::Texture texture;
            texture.Load(image);
            texture.Draw(src, src.GetPosition(), WHITE);
            texture.Unload();
        }
    }

    // overload = operator
    Button &operator=(const Button &button)
    {
        this->image = button.image;
        this->src = button.src;
        this->isHovered = button.isHovered;
        this->command = button.command;
        return *this;
    }

    ~Button()
    {
        image.Unload();
    }
};

class Menu
{
private:
    std::vector<Button> buttons;
    raylib::Texture background;

public:
    Menu() {}
    Menu(std::vector<Button> buttons, std::string background_path)
    {
        this->buttons = std::move(buttons);
        background.Load(background_path);
    }
    void DrawMenu()
    {
        background.Draw(0, 0);
        for (auto &button : buttons)
        {
            button.DrawButton();
        }
    }
    void UpdateMenu()
    {
        for (auto &button : buttons)
        {
            button.UpdateButton();
        }
    }
    void SetButtons(std::vector<Button> buttonsList)
    {
        this->buttons = std::move(buttonsList);
    }
    ~Menu()
    {
        background.Unload();
    }
};

class UI
{
private:
    raylib::Image HP_bar_unit;
    raylib::Image HP_bar_unit_empty;
    raylib::Image MP_bar;
    raylib::Image Background;

    raylib::Vector2 HP_bar_position;
    raylib::Vector2 MP_bar_position;
    raylib::Vector2 Background_position;

    float HP_bar_unit_scale;
    float MP_bar_scale;
    float Background_scale;

    //@TODO: add animation
    AnimationInfo MP_bar_animation;

    int HP_count{};
    int MP_count{};

public:
    UI() {}

    UI(const std::string &HP_bar_unit_path, const std::string &MP_bar_path, const std::string &Background_path)
    {
        HP_bar_unit.Load(HP_bar_unit_path);
        MP_bar.Load(MP_bar_path);
        Background.Load(Background_path);
        HP_count = 0;
        MP_count = 0;
    }

    void DrawUI()
    {
        raylib::Texture tBackground;
        tBackground.Load(Background);
        tBackground.Draw(Background_position.x, Background_position.y);
        tBackground.Unload();
        for (int i = 0; i < PLAYER_MAX_HP; ++i)
        {
            raylib::Texture tHP_bar_unit;
            tHP_bar_unit.Load(HP_bar_unit);
            raylib::Texture tHP_bar_unit_empty;
            tHP_bar_unit_empty.Load(HP_bar_unit_empty);
            if (i < HP_count)
            {
                tHP_bar_unit.Draw(raylib::Vector2(HP_bar_position.x + i * HP_bar_unit.GetWidth(),
                                                  HP_bar_position.y),
                                  0,
                                  HP_bar_unit_scale,
                                  WHITE);
            }
            else
            {
                tHP_bar_unit_empty.Draw(raylib::Vector2(HP_bar_position.x + i * HP_bar_unit.GetWidth(),
                                                        HP_bar_position.y),
                                        0,
                                        HP_bar_unit_scale,
                                        WHITE);
            }
            tHP_bar_unit.Unload();
            tHP_bar_unit_empty.Unload();
        }
        raylib::Texture tMP_bar;
        tMP_bar.Load(MP_bar);
        tMP_bar.Draw(raylib::Rectangle(0,
                                       MP_bar.GetHeight() * (PLAYER_MAX_MP - MP_count) / PLAYER_MAX_MP,
                                       MP_bar.GetWidth(),
                                       MP_bar.GetHeight() * MP_count / PLAYER_MAX_MP),
                     MP_bar_position,
                     MP_count < 33 ? WHITE : GRAY);
        tMP_bar.Unload();
    }

    void UpdateUI(const int HP, const int MP)
    {
        HP_count = HP;
        MP_count = MP;
    }

    void SetHP_bar_unit(const std::string &path)
    {
        HP_bar_unit.Load(path);
    }

    void SetHP_bar_unit_empty(const std::string &path)
    {
        HP_bar_unit_empty.Load(path);
    }

    void SetMP_bar(const std::string &path)
    {
        MP_bar.Load(path);
    }

    void SetBackground(const std::string &path)
    {
        Background.Load(path);
    }

    void SetHP_bar_unit_position(const raylib::Vector2 &HP_bar_unit_position)
    {
        HP_bar_position = HP_bar_unit_position;
    }

    void SetMP_bar_position(const raylib::Vector2 &position)
    {
        this->MP_bar_position = position;
    }

    void SetBackground_position(const raylib::Vector2 &position)
    {
        this->Background_position = position;
    }

    void SetHP_bar_unit_scale(float scale)
    {
        this->HP_bar_unit_scale = scale;
    }

    void SetMP_bar_scale(float scale)
    {
        this->MP_bar_scale = scale;
    }

    void SetBackground_scale(float scale)
    {
        this->Background_scale = scale;
    }

    ~UI()
    {
        HP_bar_unit.Unload();
        MP_bar.Unload();
        Background.Unload();
    }
};

class GameView
{
private:
    int HorizontalInput = 0;
    int VerticalInput = 0;

    std::function<void(direction)> playerMoveCommand;
    std::function<void(bool)> playerJumpCommand;
    std::function<void()> playerUpdateJumpSpeedCommand;
    std::function<void()> playerCheckWallCommand;
    std::function<void()> playerAniamtorUpdateCommand;
    std::function<void()> playerAniamtionUpdateCommand;
    std::function<void()> playerUpdatePositionCommand;
    std::function<void()> playerUpdateAnimationFrameCommand;
    std::function<void(raylib::Vector2)> playerUpdateAnimationRectCommand;
    std::function<void(direction)> playerAttackCommand;
    std::function<void()> drawPlayerCommand;

    std::shared_ptr<GameCommon> gameCommonPtr;

public:
    GameView();
    void UpdatePlayerMove();
    void UpdatePlayerJump();
    void UpdatePlayerAttack(bool isFacingRight);
    void Update();

    void Draw(
        std::string path,
        raylib::Vector2 position,
        raylib::Rectangle src);
    void SetPlayerMoveCommand(std::function<void(direction)> command);
    void SetPlayerJumpCommand(std::function<void(bool)> command);
    void SetPlayerUpdateJumpSpeedCommand(std::function<void()> command);
    void SetPlayerCheckWallCommand(std::function<void()> command);
    void SetPlayerAnimatorUpdateCommand(std::function<void()> command);
    void SetPlayerAnimationUpdateCommand(std::function<void()> command);
    void SetPlayerUpdatePositionCommand(std::function<void()> command);
    void SetPlayerUpdateAnimationFrameCommand(std::function<void()> command);
    void SetPlayerUpdateAnimationRectCommand(std::function<void(raylib::Vector2)> command);
    void SetPlayerAttackCommand(std::function<void(direction)> command);
    void SetDrawPlayerCommand(std::function<void()> command);
    std::shared_ptr<GameCommon> getGameCommonPtr()
    {
        return gameCommonPtr;
    }
};

#endif // CPPGAMEJAM_GAMEVIEW_H
