//
// Created by Hjuntao on 2023/7/12.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <memory>

#include "raylib.h"
#include "model/GameModel.h"
#include "view/GameView.h"
#include "viewModel/GameViewModel.h"

void InitPlayer();
void InitPlayerWallCheck();

int main()
{
    const int screenWidth = 1600;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "MVVM Example");

    GameModel model;

    GameView view;
    GameViewModel viewModel;

    //Init map

    model.SetMapModel("ground_1", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(0, 700));
    model.SetMapModel("ground_2", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279, 700));
    model.SetMapModel("ground_3", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279, 600));
    model.SetMapModel("ground_4", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279*1, 700));
    model.SetMapModel("ground_5", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279*2, 700));
    model.SetMapModel("ground_6", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279*3, 700));
    model.SetMapModel("ground_7", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279*4, 700));
    model.SetMapModel("ground_8", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279*5, 700));
    model.SetMapModel("ground_9", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279*6, 700));
    model.SetMapModel("ground_10", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279*7, 700));
    model.SetMapModel("ground_11", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279*8, 700));
    model.SetMapModel("ground_12", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279, 300));

    
    



    model.ClearColliders();

/* #pragma region InitPlayer
    model.SetPlayerPosition(raylib::Vector2(0, 0));
    model.SetPlayerSpeed(raylib::Vector2(0, 0));
    model.SetPlayerAnimatorState(AnimatorState::IDLE);
    model.SetPlayerHP(PLAYER_MAX_HP);
    model.SetPlayerMP(PLAYER_MAX_MP);
    model.SetPlayerJumpCount(0);
    model.SetPlayerJumpCounter(0.0f);
    model.SetPlayerIsGrounded(true);
    model.SetPlayerIsLeftWalled(false);
    model.SetPlayerIsRightWalled(false);
    model.SetPlayerIsCeilinged(false);
    model.SetPlayerIsJumping(false);
    model.SetPlayerIsFacingRight(false);
    AnimationInfo *playerAnimationInfo = reinterpret_cast<AnimationInfo *>(malloc(sizeof(AnimationInfo)));
    model.SetPlayerAnimationInfo(playerAnimationInfo);
    model.SetPlayerAnimationPath("../assets/sprites/Knight/Idle.png");
    model.SetPlayerAnimationFrameCount(9);
    model.SetPlayerAnimationCurrentFrame(0);
    model.SetPlayerAnimationFrameTimeCounter(0.0f);
    model.SetPlayerAnimationFrameTime(ANIMATION_FRAME_TIME);
    model.SetPlayerAnimationIsStop(false);
    raylib::Texture2DUnmanaged texture = LoadTexture(model.GetPlayerAnimationPath().c_str());
    model.SetPlayerAnimationFrameWidth(texture.width / model.GetPlayerAnimationFrameCount());
    model.SetPlayerAnimationFrameHeight(texture.height);
    texture.Unload();
    CustomCollider *playerCollider = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    model.SetPlayerCollider(playerCollider);
    playerCollider->colliderName = std::string("player");
    model.SetPlayerColliderBox(raylib::Rectangle(model.GetPlayerPosition().x, model.GetPlayerPosition().y, PLAYER_WALLCHECK_WIDTH, PLAYER_WALLCHECK_HEIGHT));
    model.SetPlayerColliderTag(ColliderTag::PLAYER);
    model.SetPlayerColliderType(ColliderType::RECT);
    model.AddCollider(model.GetPlayerCollider());
#pragma endregion

#pragma region InitPlayerWallCheck
    CustomCollider *playerLeftWallCheck = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    playerLeftWallCheck->colliderName = "playerLeftWallCheck";
    playerLeftWallCheck->colliderBox = raylib::Rectangle(model.GetPlayerPosition().x - PLAYER_WALLCHECK_BIAS_X, model.GetPlayerPosition().y, PLAYER_WALLCHECK_BIAS_X, PLAYER_WALLCHECK_HEIGHT);
    playerLeftWallCheck->colliderTag = ColliderTag::PLAYER_WALLCHECK;
    playerLeftWallCheck->colliderType = ColliderType::RECT;
    model.SetLeftWallCheck(playerLeftWallCheck);
    model.AddCollider(playerLeftWallCheck);

    CustomCollider *playerRightWallCheck = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    playerRightWallCheck->colliderName = "playerRightWallCheck";
    playerRightWallCheck->colliderBox = raylib::Rectangle(model.GetPlayerPosition().x + PLAYER_WALLCHECK_WIDTH, model.GetPlayerPosition().y, PLAYER_WALLCHECK_BIAS_X, PLAYER_WALLCHECK_HEIGHT);
    playerRightWallCheck->colliderTag = ColliderTag::PLAYER_WALLCHECK;
    playerRightWallCheck->colliderType = ColliderType::RECT;
    model.SetRightWallCheck(playerRightWallCheck);
    model.AddCollider(playerRightWallCheck);

    CustomCollider *playerTopWallCheck = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    playerTopWallCheck->colliderName = "playerTopWallCheck";
    playerTopWallCheck->colliderBox = raylib::Rectangle(model.GetPlayerPosition().x, model.GetPlayerPosition().y - PLAYER_WALLCHECK_BIAS_Y, PLAYER_WALLCHECK_WIDTH, PLAYER_WALLCHECK_BIAS_Y);
    playerTopWallCheck->colliderTag = ColliderTag::PLAYER_WALLCHECK;
    playerTopWallCheck->colliderType = ColliderType::RECT;
    model.SetCeilingCheck(playerTopWallCheck);
    model.AddCollider(playerTopWallCheck);

    CustomCollider *playerBottomWallCheck = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    playerBottomWallCheck->colliderName = "playerBottomWallCheck";
    playerBottomWallCheck->colliderBox = raylib::Rectangle(model.GetPlayerPosition().x, model.GetPlayerPosition().y + PLAYER_WALLCHECK_HEIGHT, PLAYER_WALLCHECK_WIDTH, PLAYER_WALLCHECK_BIAS_Y);
    playerBottomWallCheck->colliderTag = ColliderTag::PLAYER_WALLCHECK;
    playerBottomWallCheck->colliderType = ColliderType::RECT;
    model.SetGroundCheck(playerBottomWallCheck);
    model.AddCollider(playerBottomWallCheck);
#pragma endregion
 */
    viewModel.setModel(&model);
    //view.SetCommon(model.GetGameCommonPtr());

    SetTargetFPS(30);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);
        
        for(int i = 0; i < model.getMaplist().size();i++)
        {
            view.Draw(model.getMaplist()[i].getPath(), model.getMaplist()[i].getPosition(), raylib::Rectangle(0.0f, 0.0f,model.GetMapWidth(i) , model.GetMapHeight(i)));
        }
        // view.draw(view.getGameCommonPtr()->getScore(), view.getGameCommonPtr()->getGameOver());

        EndDrawing();
    }

    CloseWindow();

    return 0;
}