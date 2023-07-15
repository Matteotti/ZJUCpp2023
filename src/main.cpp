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
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "MVVM Example");

    GameModel model;

    GameView view;
    view.SetCommon(model.GetGameCommonPtr());
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

#pragma region InitUI
    view.ui.SetHP_bar_unit("../assets/ui/HP_bar_unit.png");
    view.ui.SetHP_bar_unit_empty("../assets/ui/HP_bar.png");
    view.ui.SetMP_bar("../assets/ui/MP_bar.png");
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