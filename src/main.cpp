//
// Created by Hjuntao on 2023/7/12.
//

#include <iostream>
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
    GameViewModel viewModel;

    model.ClearColliders();

#pragma region InitPlayer
    model.SetPlayerPosition(raylib::Vector2(0, 0));
    model.SetPlayerSpeed(raylib::Vector2(0, 0));
    model.SetPlayerAnimatorState(AnimatorState::Idle);
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
    model.SetPlayerAnimationPath("../../assets/sprites/Knight/Idle.png");
    model.SetPlayerAnimationFrameCount(9);
    model.SetPlayerAnimationCurrentFrame(0);
    model.SetPlayerAnimationFrameTimeCounter(0.0f);
    model.SetPlayerAnimationFrameTime(ANIMATION_FRAME_TIME);
    model.SetPlayerAnimationStop(false);
    raylib::Texture2DUnmanaged texture = LoadTexture(model.GetPlayerAnimationPath().c_str());
    model.SetPlayerAnimationFrameWidth(texture.width / model.GetPlayerAnimationFrameCount());
    model.SetPlayerAnimationFrameHeight(texture.height);
    texture.Unload();
    model.SetPlayerColliderName("player");
    model.SetPlayerColliderBox(raylib::Rectangle(model.GetPlayerPosition().x, model.GetPlayerPosition().y, PLAYER_WALLCHECK_WIDTH, PLAYER_WALLCHECK_HEIGHT));
    model.SetPlayerColliderTag(ColliderTag::PLAYER);
    model.SetPlayerColliderType(ColliderType::RECT);
    model.AddCollider(model.GetPlayerCollider());
#pragma endregion

#pragma region InitPlayerWallCheck
    model.SetPlayerLeftWallCheckColliderName("playerLeftWallCheck");
    model.SetPlayerLeftWallCheckColliderBox(raylib::Rectangle(model.GetPlayerPosition().x - PLAYER_WALLCHECK_BIAS_X, model.GetPlayerPosition().y, PLAYER_WALLCHECK_BIAS_X, PLAYER_WALLCHECK_HEIGHT));
    model.SetPlayerLeftWallCheckColliderTag(ColliderTag::PLAYER_WALLCHECK);
    model.SetPlayerLeftWallCheckColliderType(ColliderType::RECT);
    model.AddCollider(model.GetPlayerLeftWallCheckCollider());

    model.SetPlayerRightWallCheckColliderName("playerRightWallCheck");
    model.SetPlayerRightWallCheckColliderBox(raylib::Rectangle(model.GetPlayerPosition().x + PLAYER_WALLCHECK_WIDTH, model.GetPlayerPosition().y, PLAYER_WALLCHECK_BIAS_X, PLAYER_WALLCHECK_HEIGHT));
    model.SetPlayerRightWallCheckColliderTag(ColliderTag::PLAYER_WALLCHECK);
    model.SetPlayerRightWallCheckColliderType(ColliderType::RECT);
    model.AddCollider(model.GetPlayerRightWallCheckCollider());

    model.SetPlayerTopWallCheckColliderName("playerTopWallCheck");
    model.SetPlayerTopWallCheckColliderBox(raylib::Rectangle(model.GetPlayerPosition().x, model.GetPlayerPosition().y - PLAYER_WALLCHECK_BIAS_Y, PLAYER_WALLCHECK_WIDTH, PLAYER_WALLCHECK_BIAS_Y));
    model.SetPlayerTopWallCheckColliderTag(ColliderTag::PLAYER_WALLCHECK);
    model.SetPlayerTopWallCheckColliderType(ColliderType::RECT);
    model.AddCollider(model.GetPlayerTopWallCheckCollider());

    model.SetPlayerBottomWallCheckColliderName("playerBottomWallCheck");
    model.SetPlayerBottomWallCheckColliderBox(raylib::Rectangle(model.GetPlayerPosition().x, model.GetPlayerPosition().y + PLAYER_WALLCHECK_HEIGHT, PLAYER_WALLCHECK_WIDTH, PLAYER_WALLCHECK_BIAS_Y));
    model.SetPlayerBottomWallCheckColliderTag(ColliderTag::PLAYER_WALLCHECK);
    model.SetPlayerBottomWallCheckColliderType(ColliderType::RECT);
    model.AddCollider(model.GetPlayerBottomWallCheckCollider());
#pragma endregion

    viewModel.setModel(&model);
    view.setCommon(model.GetGameCommonPtr());

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