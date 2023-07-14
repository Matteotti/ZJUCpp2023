//
// Created by Hjuntao on 2023/7/12.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <memory>

#include "raylib.h"
#include "model/GameModel.h"
#include "view/GameView.h"
#include "viewModel/GameViewModel.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "MVVM Example");

    GameModel model;

    GameView view;
    GameViewModel viewModel;

    model.ClearColliders();

#pragma region InitPlayer
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
    memset(playerAnimationInfo, 0, sizeof(AnimationInfo));
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
    memset(playerCollider, 0, sizeof(CustomCollider));
    model.SetPlayerCollider(playerCollider);
    playerCollider->colliderName = "player";
    model.SetPlayerColliderBox(raylib::Rectangle(model.GetPlayerPosition().x, model.GetPlayerPosition().y, PLAYER_WALLCHECK_WIDTH, PLAYER_WALLCHECK_HEIGHT));
    model.SetPlayerColliderTag(ColliderTag::PLAYER);
    model.SetPlayerColliderType(ColliderType::RECT);
    model.AddCollider(model.GetPlayerCollider());
#pragma endregion

#pragma region InitPlayerWallCheck
    CustomCollider *playerLeftWallCheck = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    memset(playerLeftWallCheck, 0, sizeof(CustomCollider));
    playerLeftWallCheck->colliderName = "playerLeftWallCheck";
    playerLeftWallCheck->colliderBox = raylib::Rectangle(model.GetPlayerPosition().x - PLAYER_WALLCHECK_BIAS_X, model.GetPlayerPosition().y, PLAYER_WALLCHECK_BIAS_X, PLAYER_WALLCHECK_HEIGHT);
    playerLeftWallCheck->colliderTag = ColliderTag::PLAYER_WALLCHECK;
    playerLeftWallCheck->colliderType = ColliderType::RECT;
    model.SetLeftWallCheck(playerLeftWallCheck);
    model.AddCollider(playerLeftWallCheck);

    CustomCollider *playerRightWallCheck = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    memset(playerRightWallCheck, 0, sizeof(CustomCollider));
    playerRightWallCheck->colliderName = "playerRightWallCheck";
    playerRightWallCheck->colliderBox = raylib::Rectangle(model.GetPlayerPosition().x + PLAYER_WALLCHECK_WIDTH, model.GetPlayerPosition().y, PLAYER_WALLCHECK_BIAS_X, PLAYER_WALLCHECK_HEIGHT);
    playerRightWallCheck->colliderTag = ColliderTag::PLAYER_WALLCHECK;
    playerRightWallCheck->colliderType = ColliderType::RECT;
    model.SetRightWallCheck(playerRightWallCheck);
    model.AddCollider(playerRightWallCheck);

    CustomCollider *playerTopWallCheck = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    memset(playerTopWallCheck, 0, sizeof(CustomCollider));
    playerTopWallCheck->colliderName = "playerTopWallCheck";
    playerTopWallCheck->colliderBox = raylib::Rectangle(model.GetPlayerPosition().x, model.GetPlayerPosition().y - PLAYER_WALLCHECK_BIAS_Y, PLAYER_WALLCHECK_WIDTH, PLAYER_WALLCHECK_BIAS_Y);
    playerTopWallCheck->colliderTag = ColliderTag::PLAYER_WALLCHECK;
    playerTopWallCheck->colliderType = ColliderType::RECT;
    model.SetCeilingCheck(playerTopWallCheck);
    model.AddCollider(playerTopWallCheck);

    CustomCollider *playerBottomWallCheck = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    memset(playerBottomWallCheck, 0, sizeof(CustomCollider));
    playerBottomWallCheck->colliderName = "playerBottomWallCheck";
    playerBottomWallCheck->colliderBox = raylib::Rectangle(model.GetPlayerPosition().x, model.GetPlayerPosition().y + PLAYER_WALLCHECK_HEIGHT, PLAYER_WALLCHECK_WIDTH, PLAYER_WALLCHECK_BIAS_Y);
    playerBottomWallCheck->colliderTag = ColliderTag::PLAYER_WALLCHECK;
    playerBottomWallCheck->colliderType = ColliderType::RECT;
    model.SetGroundCheck(playerBottomWallCheck);
    model.AddCollider(playerBottomWallCheck);
#pragma endregion

    viewModel.setModel(&model);
    view.SetCommon(model.GetGameCommonPtr());

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        // view.draw(view.getGameCommonPtr()->getScore(), view.getGameCommonPtr()->getGameOver());

        EndDrawing();
    }

    CloseWindow();

    return 0;
}