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
    SetTraceLogLevel(LOG_NONE);

    const int screenWidth = 1600;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "MVVM Example");

    GameModel *model = new GameModel();

    GameView *view = new GameView();
    GameViewModel *viewModel = new GameViewModel();

    // Init map

    model->SetMapModel("ground_1", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(0, 700));
    model->SetMapModel("ground_2", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279, 700));
    //model->SetMapModel("ground_3", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279, 600));
    model->SetMapModel("ground_4", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 1, 700));
    model->SetMapModel("ground_5", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 2, 700));
    model->SetMapModel("ground_6", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 3, 700));
    model->SetMapModel("ground_7", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 4, 700));
    model->SetMapModel("ground_8", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 5, 700));
    model->SetMapModel("ground_9", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 6, 700));
    model->SetMapModel("ground_10", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 7, 700));
    model->SetMapModel("ground_11", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 8, 500));
    model->SetMapModel("ground_12", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 9, 700));
    model->SetMapModel("ground_13", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 10, 700));
    model->SetMapModel("ground_14", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 11, 700));
    model->SetMapModel("ground_15", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 12, 300));
    model->SetMapModel("ground_16", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 13, 700));
    model->SetMapModel("ground_17", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279, 300));
    //model->SetMapModel("ground_3", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279, 600));
    model->SetMapModel("ground_6", "../assets/sprites/Map/road7-.png", 1, raylib::Vector2(279 * 3, 100));
    model->SetMapModel("ground_7", "../assets/sprites/Map/road7-.png", 1, raylib::Vector2(279 * 4, 100));
    model->SetMapModel("ground_8", "../assets/sprites/Map/road7-.png", 1, raylib::Vector2(279 * 5, 100));
    model->SetMapModel("ground_9", "../assets/sprites/Map/road7-.png", 1, raylib::Vector2(279 * 6, 100));




#pragma region InitPlayer
    model->SetPlayerPosition(raylib::Vector2(400, 0));
    model->SetPlayerSpeed(raylib::Vector2(0, 0));
    model->SetPlayerAnimatorState(AnimatorState::IDLE);
    model->SetPlayerHP(PLAYER_MAX_HP);
    model->SetPlayerMP(PLAYER_MAX_MP);
    model->SetPlayerJumpCount(0);
    model->SetPlayerJumpCounter(0.0f);
    model->SetPlayerIsGrounded(true);
    model->SetPlayerIsLeftWalled(false);
    model->SetPlayerIsRightWalled(false);
    model->SetPlayerIsCeilinged(false);
    model->SetPlayerIsJumping(false);
    model->SetPlayerIsFacingRight(false);
    AnimationInfo *playerAnimationInfo = reinterpret_cast<AnimationInfo *>(malloc(sizeof(AnimationInfo)));
    memset(playerAnimationInfo, 0, sizeof(AnimationInfo));
    model->SetPlayerAnimationInfo(playerAnimationInfo);
    model->SetPlayerAnimationPath("../assets/sprites/Knight/Idle.png");
    model->SetPlayerAnimationFrameCount(9);
    model->SetPlayerAnimationCurrentFrame(0);
    model->SetPlayerAnimationFrameTimeCounter(0.0f);
    model->SetPlayerAnimationFrameTime(ANIMATION_FRAME_TIME);
    model->SetPlayerAnimationIsStop(false);
    raylib::Texture2DUnmanaged texture = LoadTexture(model->GetPlayerAnimationPath().c_str());
    model->SetPlayerAnimationFrameWidth(texture.width / model->GetPlayerAnimationFrameCount());
    model->SetPlayerAnimationFrameHeight(texture.height);
    model->SetPlayerSourceRec(raylib::Rectangle(0.0f, 0.0f, model->GetPlayerAnimationFrameWidth(), model->GetPlayerAnimationFrameHeight()));
    texture.Unload();
    CustomCollider *playerCollider = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    memset(playerCollider, 0, sizeof(CustomCollider));
    model->SetPlayerCollider(playerCollider);
    playerCollider->colliderName = "player";
    model->SetPlayerColliderBox(raylib::Rectangle(model->GetPlayerPosition().x, model->GetPlayerPosition().y, PLAYER_WALLCHECK_WIDTH, PLAYER_WALLCHECK_HEIGHT));
    model->SetPlayerColliderTag(ColliderTag::PLAYER);
    model->SetPlayerColliderType(ColliderType::RECT);
    model->AddCollider(model->GetPlayerCollider());
#pragma endregion

#pragma region InitPlayerWallCheck
    CustomCollider *playerLeftWallCheck = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    memset(playerLeftWallCheck, 0, sizeof(CustomCollider));
    playerLeftWallCheck->colliderName = "playerLeftWallCheck";
    playerLeftWallCheck->colliderBox = raylib::Rectangle(model->GetPlayerPosition().x - PLAYER_WALLCHECK_BIAS_X, model->GetPlayerPosition().y, PLAYER_WALLCHECK_BIAS_X, PLAYER_WALLCHECK_HEIGHT);
    playerLeftWallCheck->colliderTag = ColliderTag::PLAYER_WALLCHECK;
    playerLeftWallCheck->colliderType = ColliderType::RECT;
    model->SetLeftWallCheck(playerLeftWallCheck);
    model->AddCollider(playerLeftWallCheck);

    CustomCollider *playerRightWallCheck = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    memset(playerRightWallCheck, 0, sizeof(CustomCollider));
    playerRightWallCheck->colliderName = "playerRightWallCheck";
    playerRightWallCheck->colliderBox = raylib::Rectangle(model->GetPlayerPosition().x + PLAYER_WALLCHECK_WIDTH, model->GetPlayerPosition().y, PLAYER_WALLCHECK_BIAS_X, PLAYER_WALLCHECK_HEIGHT);
    playerRightWallCheck->colliderTag = ColliderTag::PLAYER_WALLCHECK;
    playerRightWallCheck->colliderType = ColliderType::RECT;
    model->SetRightWallCheck(playerRightWallCheck);
    model->AddCollider(playerRightWallCheck);

    CustomCollider *playerTopWallCheck = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    memset(playerTopWallCheck, 0, sizeof(CustomCollider));
    playerTopWallCheck->colliderName = "playerTopWallCheck";
    playerTopWallCheck->colliderBox = raylib::Rectangle(model->GetPlayerPosition().x, model->GetPlayerPosition().y - PLAYER_WALLCHECK_BIAS_Y, PLAYER_WALLCHECK_WIDTH, PLAYER_WALLCHECK_BIAS_Y);
    playerTopWallCheck->colliderTag = ColliderTag::PLAYER_WALLCHECK;
    playerTopWallCheck->colliderType = ColliderType::RECT;
    model->SetCeilingCheck(playerTopWallCheck);
    model->AddCollider(playerTopWallCheck);

    CustomCollider *playerBottomWallCheck = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    memset(playerBottomWallCheck, 0, sizeof(CustomCollider));
    playerBottomWallCheck->colliderName = "playerBottomWallCheck";
    playerBottomWallCheck->colliderBox = raylib::Rectangle(model->GetPlayerPosition().x, model->GetPlayerPosition().y + PLAYER_WALLCHECK_HEIGHT, PLAYER_WALLCHECK_WIDTH, PLAYER_WALLCHECK_BIAS_Y);
    playerBottomWallCheck->colliderTag = ColliderTag::PLAYER_WALLCHECK;
    playerBottomWallCheck->colliderType = ColliderType::RECT;
    model->SetGroundCheck(playerBottomWallCheck);
    model->AddCollider(playerBottomWallCheck);
#pragma endregion

#pragma region Bind Command
    view->SetPlayerMoveCommand(viewModel->getMovePlayerCommand());
    view->SetPlayerJumpCommand(viewModel->getPlayerJumpCommand());
    view->SetPlayerUpdateJumpSpeedCommand(viewModel->getPlayerUpdateJumpSpeed());
    view->SetPlayerCheckWallCommand(viewModel->getPlayerCheckWall());
    view->SetPlayerAnimatorUpdateCommand(viewModel->getPlayerAnimatorUpdate());
    view->SetPlayerAnimationUpdateCommand(viewModel->getPlayerAnimationUpdate());
    view->SetPlayerUpdatePositionCommand(viewModel->getPlayerUpdatePosition());
    view->SetPlayerUpdateAnimationFrameCommand(viewModel->getUpdateAnimationFrame());
    view->SetPlayerUpdateAnimationRectCommand(viewModel->getUpdatePlayerAnimationRect());
    view->SetPlayerAttackCommand(viewModel->getPlayerAttackCommand());

#pragma endregion

    viewModel->setModel(model);
    view->SetCommon(model->GetGameCommonPtr());
    // view.SetCommon(model.GetGameCommonPtr());

    SetTargetFPS(144);

    view->camera.target = view->getGameCommonPtr()->GetPlayerPosition();
    view->camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    view->camera.rotation = 0.0f;
    view->camera.zoom = 1.0f;
    while (!WindowShouldClose())
    {

        BeginDrawing();
        BeginMode2D(view->camera);

        ClearBackground(GRAY);
        for (int i = 0; i < view->getGameCommonPtr()->GetMapList().size(); i++)
        {
            view->Draw(view->getGameCommonPtr()->GetMapList()[i].getPath(), view->getGameCommonPtr()->GetMapList()[i].getPosition(), raylib::Rectangle(0.0f, 0.0f, view->getGameCommonPtr()->GetMapList()[i].GetMapWidth(), view->getGameCommonPtr()->GetMapList()[i].GetMapHeight()));
        }

        view->UpdatePlayerMove();
        view->UpdatePlayerAttack(view->getGameCommonPtr()->GetPlayerIsFacingRight());
        view->UpdatePlayerJump(); 
        view->Update();

        EndMode2D();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}