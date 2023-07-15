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
    std::string text;
    std::string texturePath;
    bool isHovered;
    // FIXME: Possibly be unable to work as expected via passing and using a std::function
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
    Button &operator=(const Button &other) = default;

    ~Button()
    {
        image.Unload();
    }
};

class Menu
{
private:
    std::vector<Button> buttons;

public:
    Menu() = default;
    Menu(std::vector<Button> buttons)
    {
        this->buttons = std::move(buttons);
    }
    void DrawMenu()
    {
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
    ~Menu() = default;
};

class UI
{
private:
    std::string hpBarUnitPath;
    std::string hpBarUnitEmptyPath;
    std::string mpBarPath;
    std::string backgroundPath;

    raylib::TextureUnmanaged temp;

    raylib::Vector2 hpBarUnitPosition;
    raylib::Vector2 mpBarPosition;
    raylib::Vector2 backgroundPosition;

    float hpBarUnitScale;
    float mpBarScale;
    float backgroundScale;

    int HP_count = 3;
    int MP_count = 100;

public:
    UI(){}
    UI(std::string hpBarUnitPath,
       std::string hpBarUnitEmptyPath,
       std::string mpBarPath,
       std::string backgroundPath)
    {
        this->hpBarUnitPath = std::move(hpBarUnitPath);
        this->hpBarUnitEmptyPath = std::move(hpBarUnitEmptyPath);
        this->mpBarPath = std::move(mpBarPath);
        this->backgroundPath = std::move(backgroundPath);

        hpBarUnitPosition = raylib::Vector2(120, 0);
        mpBarPosition = raylib::Vector2(0, 10);
        backgroundPosition = raylib::Vector2(5, 0);

        hpBarUnitScale = 1.0f;
        mpBarScale = 1.0f;
        backgroundScale = 1.0f;
    }

    void Draw(){
        //draw full hp units
        temp.Load(hpBarUnitPath);
        for(int i = 0; i < HP_count; i++){
            temp.Draw(raylib::Vector2(hpBarUnitPosition.x + i * temp.GetWidth() * hpBarUnitScale, hpBarUnitPosition.y),
                      0,
                      hpBarUnitScale,
                      WHITE);
        }
        //draw empty hp units
        temp.Load(hpBarUnitEmptyPath);
        for(int i = HP_count; i < PLAYER_MAX_HP; i++){
            temp.Draw(raylib::Vector2(hpBarUnitPosition.x + i * temp.GetWidth() * hpBarUnitScale, hpBarUnitPosition.y),
                      0,
                      hpBarUnitScale,
                      WHITE);
        }
        //draw background
        temp.Load(backgroundPath);
        temp.Draw(backgroundPosition, 0, backgroundScale, WHITE);
        //draw mp bar
        temp.Load(mpBarPath);
        temp.Draw(raylib::Rectangle(0,
                                    temp.GetHeight()*(PLAYER_MAX_MP- MP_count)/PLAYER_MAX_MP,
                                    temp.GetWidth(),
                                    temp.GetHeight()*MP_count/PLAYER_MAX_MP),
                    mpBarPosition+raylib::Vector2(10, temp.GetHeight()*(PLAYER_MAX_MP- MP_count)/PLAYER_MAX_MP),
                    MP_count < 33 ? GRAY : WHITE
                );
    }



    void SetHpBarUnitPath(std::string path)
    {
        this->hpBarUnitPath = std::move(path);
    }

    void SetHpBarUnitEmptyPath(std::string path)
    {
        this->hpBarUnitEmptyPath = std::move(path);
    }

    void SetMpBarPath(std::string path)
    {
        this->mpBarPath = std::move(path);
    }

    void SetBackgroundPath(std::string path)
    {
        this->backgroundPath = std::move(path);
    }

    ~UI() = default;
};

class GameView
{
private:
    int HorizontalInput = 0;
    int VerticalInput = 0;

    std::function<void()> updateViewCommand;
    std::function<void()> increaseScoreCommand;
    std::function<void(bool)> setGameOverCommand;

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

    std::function<void()> attackTopCommand;
    std::function<void()> attackDownCommand;

    raylib::TextureUnmanaged temp;

public:
    GameView();
    void SetCommon(std::shared_ptr<GameCommon> gameCommon);
    void DrawExample(int score, bool gameOver);
    void UpdateScore();
    void GameOver();
    void UpdatePlayerMove();
    void UpdatePlayerJump();
    void UpdatePlayerAttack(bool isFacingRight);
    void Update();

    UI ui;
    Menu menu;

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

    void Attack();
    void setAttackTopCommand(std::function<void()> command);
    void setAttackDownCommand(std::function<void()> command);

    ~GameView() = default;
};

#endif // CPPGAMEJAM_GAMEVIEW_H
