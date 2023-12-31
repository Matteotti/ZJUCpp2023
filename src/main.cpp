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

enum gameState {
    START,
    RUNNING,
    PAUSE,
    GAME_OVER,
    WIN
};

int main() {
    SetTraceLogLevel(LOG_NONE);

    const int screenWidth = 1600;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "MVVM Example");

    GameModel *model = new GameModel();

    GameView *view = new GameView();
    GameViewModel *viewModel = new GameViewModel();

#pragma region InitUI
    view->ui.SetHpBarUnitPath("../assets/ui/HP_bar_unit.png");
    view->ui.SetHpBarUnitEmptyPath("../assets/ui/HP_bar_unit_empty.png");
    view->ui.SetMpBarPath("../assets/ui/MP_bar.png");
    view->ui.SetBackgroundPath("../assets/ui/Background.png");
#pragma endregion
    // Init map

#pragma region map init
    model->SetMapModel("ground_1", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(0, 700));
    model->SetMapModel("ground_2", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279, 700));
    // model->SetMapModel("ground_3", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279, 600));
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
    // model->SetMapModel("ground_3", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279, 600));
    model->SetMapModel("ground_6", "../assets/sprites/Map/road7-.png", 1, raylib::Vector2(279 * 3, 100));
    model->SetMapModel("ground_7", "../assets/sprites/Map/road7-.png", 1, raylib::Vector2(279 * 4, 100));
    model->SetMapModel("ground_8", "../assets/sprites/Map/road7-.png", 1, raylib::Vector2(279 * 5, 100));
    model->SetMapModel("ground_9", "../assets/sprites/Map/road7-.png", 1, raylib::Vector2(279 * 6, 100));

#pragma endregion

    //Init Buttons

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
    model->SetPlayerSourceRec(raylib::Rectangle(0.0f, 0.0f, model->GetPlayerAnimationFrameWidth(),
                                                model->GetPlayerAnimationFrameHeight()));
    texture.Unload();
    CustomCollider *playerCollider = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    memset(playerCollider, 0, sizeof(CustomCollider));
    model->SetPlayerCollider(playerCollider);
    playerCollider->colliderName = "player";
    model->SetPlayerColliderBox(
            raylib::Rectangle(model->GetPlayerPosition().x, model->GetPlayerPosition().y, PLAYER_WALLCHECK_WIDTH,
                              PLAYER_WALLCHECK_HEIGHT));
    model->SetPlayerColliderTag(ColliderTag::PLAYER);
    model->SetPlayerColliderType(ColliderType::RECT);
    model->AddCollider(model->GetPlayerCollider());
#pragma endregion

#pragma region InitButtons
    view->resumeButton.SetPosition(600.0f,400.0f);
    view->exitButton.SetPosition(600.0f,600.0f);
#pragma endregion

#pragma region InitPlayerWallCheck
    CustomCollider *playerLeftWallCheck = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    memset(playerLeftWallCheck, 0, sizeof(CustomCollider));
    playerLeftWallCheck->colliderName = "playerLeftWallCheck";
    playerLeftWallCheck->colliderBox = raylib::Rectangle(model->GetPlayerPosition().x - PLAYER_WALLCHECK_BIAS_X,
                                                         model->GetPlayerPosition().y, PLAYER_WALLCHECK_BIAS_X,
                                                         PLAYER_WALLCHECK_HEIGHT);
    playerLeftWallCheck->colliderTag = ColliderTag::PLAYER_WALLCHECK;
    playerLeftWallCheck->colliderType = ColliderType::RECT;
    model->SetLeftWallCheck(playerLeftWallCheck);
    model->AddCollider(playerLeftWallCheck);

    CustomCollider *playerRightWallCheck = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    memset(playerRightWallCheck, 0, sizeof(CustomCollider));
    playerRightWallCheck->colliderName = "playerRightWallCheck";
    playerRightWallCheck->colliderBox = raylib::Rectangle(model->GetPlayerPosition().x + PLAYER_WALLCHECK_WIDTH,
                                                          model->GetPlayerPosition().y, PLAYER_WALLCHECK_BIAS_X,
                                                          PLAYER_WALLCHECK_HEIGHT);
    playerRightWallCheck->colliderTag = ColliderTag::PLAYER_WALLCHECK;
    playerRightWallCheck->colliderType = ColliderType::RECT;
    model->SetRightWallCheck(playerRightWallCheck);
    model->AddCollider(playerRightWallCheck);

    CustomCollider *playerTopWallCheck = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    memset(playerTopWallCheck, 0, sizeof(CustomCollider));
    playerTopWallCheck->colliderName = "playerTopWallCheck";
    playerTopWallCheck->colliderBox = raylib::Rectangle(model->GetPlayerPosition().x,
                                                        model->GetPlayerPosition().y - PLAYER_WALLCHECK_BIAS_Y,
                                                        PLAYER_WALLCHECK_WIDTH, PLAYER_WALLCHECK_BIAS_Y);
    playerTopWallCheck->colliderTag = ColliderTag::PLAYER_WALLCHECK;
    playerTopWallCheck->colliderType = ColliderType::RECT;
    model->SetCeilingCheck(playerTopWallCheck);
    model->AddCollider(playerTopWallCheck);

    CustomCollider *playerBottomWallCheck = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    memset(playerBottomWallCheck, 0, sizeof(CustomCollider));
    playerBottomWallCheck->colliderName = "playerBottomWallCheck";
    playerBottomWallCheck->colliderBox = raylib::Rectangle(model->GetPlayerPosition().x,
                                                           model->GetPlayerPosition().y + PLAYER_WALLCHECK_HEIGHT,
                                                           PLAYER_WALLCHECK_WIDTH, PLAYER_WALLCHECK_BIAS_Y);
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

    view->SetUpdateEnemyAnimState(viewModel->getUpdateEnemyAnimState());
    view->SetUpdateEnemySpeed(viewModel->getUpdateEnemySpeed());
    view->SetUpdateEnemySpeedPhysically(viewModel->getUpdateEnemySpeedPhysically());
    view->SetUpdateEnemyAnimation(viewModel->getUpdateEnemyAnimation());
    view->SetUpdateEnemyPosition(viewModel->getUpdateEnemyPosition());
    view->SetUpdateEnemyColliderPosition(viewModel->getUpdateEnemyColliderPosition());
    view->SetUpdateEnemyAnimationFrame(viewModel->getUpdateEnemyAnimationFrame());
    view->SetUpdateEnemyAnimationRect(viewModel->getUpdateEnemyAnimationRect());
    view->SetCheckCollisionWithPlayer(viewModel->getCheckCollisionWithPlayer());
    view->SetUpdateEnemyWallCheck(viewModel->getUpdateEnemyWallCheck());

#pragma endregion

#pragma region InitEnemy
    EnemyInModel *enemy = reinterpret_cast<EnemyInModel *>(malloc(sizeof(EnemyInModel)));
    memset(enemy, 0, sizeof(EnemyInModel));
    model->SetEnemy(enemy);
    model->SetEnemyPosition(raylib::Vector2(100, 0));
    model->SetEnemyCurrentSpeed(raylib::Vector2(0, 0));
    model->SetEnemyAnimState(EnemyAnimState::ENEMY_WALK);
    model->SetEnemySourceRec(raylib::Rectangle(0, 0, 108, 132));
    AnimationInfo *enemyAnimationInfo = reinterpret_cast<AnimationInfo *>(malloc(sizeof(AnimationInfo)));
    memset(enemyAnimationInfo, 0, sizeof(AnimationInfo));
    model->SetEnemyAnimationInfo(enemyAnimationInfo);
    model->SetEnemyAnimationIsStop(false);
    model->SetEnemyAnimationFrameCount(3);
    model->SetEnemyAnimationCurrentFrame(0);
    model->SetEnemyAnimationPath("../assets/sprites/Enemy/ZombieRunnerWalk.png");
    model->SetEnemyAnimationFrameTimeCounter(0.0f);
    model->SetEnemyAnimationFrameTime(ANIMATION_FRAME_TIME);
    raylib::Texture2DUnmanaged enemyTexture = LoadTexture(model->GetEnemyAnimationPath().c_str());
    model->SetEnemyAnimationFrameWidth(enemyTexture.width / model->GetEnemyAnimationFrameCount());
    model->SetEnemyAnimationFrameHeight(enemyTexture.height);
    enemyTexture.Unload();
    CustomCollider *enemyCollider = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    memset(enemyCollider, 0, sizeof(CustomCollider));
    model->SetEnemyCollider(enemyCollider);
    model->SetEnemyColliderName("enemy");
    model->SetEnemyColliderBox(
            raylib::Rectangle(model->GetEnemyPosition().x, model->GetEnemyPosition().y, ENEMY_COLLIDER_SIZE_X,
                              ENEMY_COLLIDER_SIZE_Y));
    model->SetEnemyColliderTag(ColliderTag::ENEMY);
    model->AddCollider(model->GetEnemyCollider());
    model->SetEnemyIsFacingRight(true);
    model->SetEnemyIsGrounded(false);
    model->SetEnemyIsLeftWalled(false);
    model->SetEnemyIsRightWalled(false);
    model->SetEnemyIsCeilinged(false);
    model->SetEnemyJumpCounter(0.0f);
    model->SetEnemyHP(ENEMY_MAX_HP);
#pragma endregion

#pragma region InitEnemyWallCheck
    CustomCollider *enemyLeftCheck = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    memset(enemyLeftCheck, 0, sizeof(CustomCollider));
    enemyLeftCheck->colliderName = "enemyLeftCheck";
    enemyLeftCheck->colliderBox = raylib::Rectangle(model->GetEnemyPosition().x - ENEMY_COLLIDER_BIAS_X,
                                                    model->GetEnemyPosition().y, ENEMY_COLLIDER_BIAS_X,
                                                    ENEMY_COLLIDER_SIZE_Y);
    enemyLeftCheck->colliderTag = ColliderTag::NONE;
    enemyLeftCheck->colliderType = ColliderType::RECT;
    model->SetEnemyLeftWallCheck(enemyLeftCheck);
    model->AddCollider(enemyLeftCheck);

    CustomCollider *enemyRightCheck = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    memset(enemyRightCheck, 0, sizeof(CustomCollider));
    enemyRightCheck->colliderName = "enemyRightCheck";
    enemyRightCheck->colliderBox = raylib::Rectangle(model->GetEnemyPosition().x + ENEMY_COLLIDER_SIZE_X,
                                                     model->GetEnemyPosition().y, ENEMY_COLLIDER_BIAS_X,
                                                     ENEMY_COLLIDER_SIZE_Y);
    enemyRightCheck->colliderTag = ColliderTag::NONE;
    enemyRightCheck->colliderType = ColliderType::RECT;
    model->SetEnemyRightWallCheck(enemyRightCheck);
    model->AddCollider(enemyRightCheck);

    CustomCollider *enemyTopCheck = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    memset(enemyTopCheck, 0, sizeof(CustomCollider));
    enemyTopCheck->colliderName = "enemyTopCheck";
    enemyTopCheck->colliderBox = raylib::Rectangle(model->GetEnemyPosition().x,
                                                   model->GetEnemyPosition().y - ENEMY_COLLIDER_BIAS_Y,
                                                   ENEMY_COLLIDER_SIZE_X, ENEMY_COLLIDER_BIAS_Y);
    enemyTopCheck->colliderTag = ColliderTag::NONE;
    enemyTopCheck->colliderType = ColliderType::RECT;
    model->SetEnemyCeilingCheck(enemyTopCheck);
    model->AddCollider(enemyTopCheck);

    CustomCollider *enemyBottomCheck = reinterpret_cast<CustomCollider *>(malloc(sizeof(CustomCollider)));
    memset(enemyBottomCheck, 0, sizeof(CustomCollider));
    enemyBottomCheck->colliderName = "enemyBottomCheck";
    enemyBottomCheck->colliderBox = raylib::Rectangle(model->GetEnemyPosition().x,
                                                      model->GetEnemyPosition().y + ENEMY_COLLIDER_SIZE_Y,
                                                      ENEMY_COLLIDER_SIZE_X, ENEMY_COLLIDER_BIAS_Y);
    enemyBottomCheck->colliderTag = ColliderTag::NONE;
    enemyBottomCheck->colliderType = ColliderType::RECT;
    model->SetEnemyGroundCheck(enemyBottomCheck);
    model->AddCollider(enemyBottomCheck);
#pragma endregion

    gameState currentGameState = gameState::START;

    viewModel->setModel(model);
    view->SetCommon(model->GetGameCommonPtr());
    // view.SetCommon(model.GetGameCommonPtr());

    SetTargetFPS(30);

    view->camera.target = view->getGameCommonPtr()->GetPlayerPosition();
    view->camera.offset = raylib::Vector2(screenWidth / 2.0f, screenHeight / 2.0f);
    view->camera.rotation = 0.0f;
    view->camera.zoom = 1.0f;
    while (!WindowShouldClose()) {

        BeginDrawing();
        if (currentGameState == gameState::START) {
            view->Draw("../assets/start_menu.png", raylib::Vector2(0.0f, 0.0f),
                       raylib::Rectangle(0.0f, 0.0f, screenWidth, screenHeight));
            view->Draw("../assets/title.png", raylib::Vector2(535.0f, 200.0f),
                       raylib::Rectangle(535.0f, 310.0f, 530.0f, 280.0f));
            view->startButton.SetPosition(600, 500);
            view->startButton.Update();
            view->startButton.Draw();
            if (view->startButton.IsPressed()) {
                currentGameState = gameState::RUNNING;
            }
        } else if (currentGameState == gameState::RUNNING) {
            BeginMode2D(view->camera);

            ClearBackground(BLACK);


            for (int i = 0; i < view->getGameCommonPtr()->GetMapList().size(); i++) {
                view->Draw(view->getGameCommonPtr()->GetMapList()[i].getPath(),
                           view->getGameCommonPtr()->GetMapList()[i].getPosition(),
                           raylib::Rectangle(0.0f, 0.0f, view->getGameCommonPtr()->GetMapList()[i].GetMapWidth(),
                                             view->getGameCommonPtr()->GetMapList()[i].GetMapHeight()));
            }

            view->UpdatePlayerMove();
            view->UpdatePlayerJump();
            view->UpdatePlayer();
            view->UpdateEnemy();

            if(view->getGameCommonPtr()->GetPlayerHP() <= 0){
                currentGameState = gameState::GAME_OVER;
            }

            EndMode2D();

            view->pauseButton.SetPosition(696, 0);
            view->pauseButton.Update();
            view->pauseButton.Draw();
            if(view->pauseButton.IsPressed()){
                currentGameState = gameState::PAUSE;
            }
#pragma region
            if(model->GetEnemyHP()<=0){
                currentGameState = WIN;
            }
#pragma endregion
            view->ui.Update(view->getGameCommonPtr()->GetPlayerHP(), view->getGameCommonPtr()->GetPlayerMP());
            view->ui.Draw();

        } else if(currentGameState == PAUSE){
            view->Draw("../assets/start_menu.png", raylib::Vector2(0.0f, 0.0f),
                       raylib::Rectangle(0.0f, 0.0f, screenWidth, screenHeight));
            view->Draw("../assets/game_paused.png",raylib::Vector2(700.0f,30.0f),
                       raylib::Rectangle(0.0f,0.0f,208.0f,72.0f));
            view->resumeButton.Update();
            view->resumeButton.Draw();
            if(view->resumeButton.IsPressed()){
                currentGameState = gameState::RUNNING;
            }
        }else if(currentGameState == GAME_OVER){
            view->Draw("../assets/start_menu.png", raylib::Vector2(0.0f, 0.0f),
                       raylib::Rectangle(0.0f, 0.0f, screenWidth, screenHeight));
            view->Draw("../assets/game_over.png",raylib::Vector2(500.0f,30.0f),
                       raylib::Rectangle(0.0f,0.0f,500.0f,500.0f));

            view->exitButton.Update();
            view->exitButton.Draw();
            if(view->exitButton.IsPressed()){
                CloseWindow();
            }
        }else if(currentGameState == WIN){
            view->Draw("../assets/start_menu.png", raylib::Vector2(0.0f, 0.0f),
                       raylib::Rectangle(0.0f, 0.0f, screenWidth, screenHeight));
            view->Draw("../assets/game_win.png",raylib::Vector2(500.0f,30.0f),
                       raylib::Rectangle(0.0f,0.0f,500.0f,500.0f));

            view->exitButton.Update();
            view->exitButton.Draw();
            if(view->exitButton.IsPressed()){
                CloseWindow();
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}