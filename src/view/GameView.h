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
#include "../../includes/enemy.h"

class Button
{
private:
    std::string hoveredPath;
    std::string unHoveredPath;
    std::string pressedPath;

    raylib::TextureUnmanaged temp;
    raylib::Vector2 position;
    raylib::Vector2 size = raylib::Vector2(400, 71);

    float scale = 1.0f;

    bool isHovered = false;

public:
    Button(){
    }

    Button(std::string hoveredPath_, std::string unHoveredPath_, std::string pressedPath_, float width, float height){
        this->hoveredPath = hoveredPath_;
        this->unHoveredPath = unHoveredPath_;
        this->pressedPath = pressedPath_;
        this->size = raylib::Vector2(width, height);
    }

    void Update(){
        if(CheckCollisionPointRec(GetMousePosition(), raylib::Rectangle(position.x, position.y, size.x, size.y))){
            isHovered = true;
        }
        else{
            isHovered = false;
        }
    }

    bool IsPressed(){
        if(isHovered && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
            return true;
        }
        else{
            return false;
        }
    }

    void Draw(){
        if(isHovered){
            if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
                temp.Load(pressedPath);
            }
            else{
                temp.Load(hoveredPath);
            }
        } else{
            temp.Load(unHoveredPath);
        }
        temp.Draw(position, 0, 1.0f, WHITE);
    }

    void SetPosition(float x_, float y_){
        position.x = x_;
        position.y = y_;
    }

    void SetSize(float x_, float y_){
        size.x = x_;
        size.y = y_;
    }

    void SetScale(float scale_){
        this->scale = scale_;
    }

    void SetHoveredPath(std::string hoveredPath_){
        this->hoveredPath = hoveredPath_;
        this->temp.Load(hoveredPath_);
    }

    void SetUnHoveredPath(std::string unHoveredPath_){
        this->unHoveredPath = unHoveredPath_;
        this->temp.Load(unHoveredPath_);
    }

    void SetPressedPath(std::string pressedPath_){
        this->pressedPath = pressedPath_;
        this->temp.Load(pressedPath_);
    }

    ~Button(){
        temp.Unload();
    }
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

    int HP_count = PLAYER_MAX_HP;
    int MP_count = PLAYER_MAX_MP;

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
            if(i < 0){
                i = 0;
            }
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
        if(MP_count<0){
            MP_count = 0;
        }
        temp.Draw(raylib::Rectangle(0,
                                    temp.GetHeight()*(PLAYER_MAX_MP- MP_count)/PLAYER_MAX_MP,
                                    temp.GetWidth(),
                                    temp.GetHeight()*MP_count/PLAYER_MAX_MP),
                    mpBarPosition+raylib::Vector2(10, temp.GetHeight()*(PLAYER_MAX_MP- MP_count)/PLAYER_MAX_MP),
                    MP_count < 33 ? GRAY : WHITE
                );
    }

    void Update(int Hp, int Mp){
        HP_count = Hp;
        MP_count = Mp;
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

    std::function<void()> updateViewCommand = nullptr;
    std::function<void()> increaseScoreCommand = nullptr;
    std::function<void(bool)> setGameOverCommand = nullptr;

    std::function<void(direction)> playerMoveCommand = nullptr;
    std::function<void(bool)> playerJumpCommand = nullptr;
    std::function<void()> playerUpdateJumpSpeedCommand = nullptr;
    std::function<void()> playerCheckWallCommand = nullptr;
    std::function<void()> playerAniamtorUpdateCommand = nullptr;
    std::function<void()> playerAniamtionUpdateCommand = nullptr;
    std::function<void()> playerUpdatePositionCommand = nullptr;
    std::function<void()> playerUpdateAnimationFrameCommand = nullptr;
    std::function<void(raylib::Vector2)> playerUpdateAnimationRectCommand = nullptr;
    std::function<void(direction)> playerAttackCommand = nullptr;
    std::function<void()> drawPlayerCommand = nullptr;

    std::shared_ptr<GameCommon> gameCommonPtr;

    std::function<void()> attackTopCommand = nullptr;
    std::function<void()> attackDownCommand = nullptr;

    std::function<void()> updateEnemyAnimStateCommand = nullptr;
    std::function<void()> updateEnemySpeedCommand = nullptr;
    std::function<void()> updateEnemySpeedPhysicallyCommand = nullptr;
    std::function<void()> updateEnemyAnimationCommand = nullptr;
    std::function<void()> updateEnemyPositionCommand = nullptr;
    std::function<void()> updateEnemyColliderPositionCommand = nullptr;
    std::function<void()> updateEnemyAnimationFrameCommand = nullptr;
    std::function<void()> updateEnemyAnimationRectCommand = nullptr;
    std::function<void()> checkCollisionWithPlayerCommand = nullptr;
    std::function<void()> updateEnemyWallCheckCommand = nullptr;

    raylib::TextureUnmanaged temp;

public:
    Camera2D camera = {0};
    GameView();
    void SetCommon(std::shared_ptr<GameCommon> gameCommon);
    void DrawExample(int score, bool gameOver);
    void UpdateScore();
    void GameOver();
    void UpdatePlayerMove();
    void UpdatePlayerJump();
    void UpdatePlayerAttack(bool isFacingRight);
    void UpdatePlayer();
    void UpdateEnemy();

    UI ui;

    //initialize buttons with path parameters
    Button resumeButton = Button("../assets/button/resume_button_hovered.png",
                                 "../assets/button/resume_button_unhovered.png",
                                 "../assets/button/resume_button_pressed.png",
                                 400.0f, 72.0f);

    Button startButton = Button("../assets/button/start_button_hovered.png",
                                "../assets/button/start_button_unhovered.png",
                                "../assets/button/start_button_pressed.png",
                                400.0f, 72.0f);

    Button exitButton = Button("../assets/button/exit_button_hovered.png",
                                 "../assets/button/exit_button_unhovered.png",
                                 "../assets/button/exit_button_pressed.png",
                                 400.0f, 72.0f);

    Button pauseButton = Button("../assets/button/pause_button_hovered.png",
                                "../assets/button/pause_button_unhovered.png",
                                "../assets/button/pause_button_pressed.png",
                                400.0f, 72.0f);



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
    void SetUpdateEnemyAnimState(std::function<void()> command);
    void SetUpdateEnemySpeed(std::function<void()> command);
    void SetUpdateEnemySpeedPhysically(std::function<void()> command);
    void SetUpdateEnemyAnimation(std::function<void()> command);
    void SetUpdateEnemyPosition(std::function<void()> command);
    void SetUpdateEnemyColliderPosition(std::function<void()> command);
    void SetUpdateEnemyAnimationFrame(std::function<void()> command);
    void SetUpdateEnemyAnimationRect(std::function<void()> command);
    void SetCheckCollisionWithPlayer(std::function<void()> command);
    void SetUpdateEnemyWallCheck(std::function<void()> command);
    std::shared_ptr<GameCommon> getGameCommonPtr()
    {
        return gameCommonPtr;
    }
    void UpdateCamera(Camera2D *camera, raylib::Vector2 position, int width, int height);
};

#endif // CPPGAMEJAM_GAMEVIEW_H
