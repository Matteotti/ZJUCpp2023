// #include "includes/main.h"

// #pragma region DEFINES
// #define PLAYER_ANIMATION_IDLE_PATH "assets/players/knight.png"
// #define PLAYER_ANIMATION_IDLE_FRAMECOUNT 5
// #define PLAYER_ANIMATION_HEIGHT 64.0f
// #define PLAYER_ANIMATION_WIDTH 64.0f
// #pragma endregion

// #pragma region Methods Declaration
// void GameInit();
// void Awake();
// void Start();
// void Update();
// void LateUpdate();
// void Draw();
// void EndFrame();

// void DrawBackground();
// void DrawPlayer();
// void DrawEnemy();
// void DrawMap();
// void DrawAttack();
// void DrawUI();
// void PlayerMove();
// void InitMapData();
// #pragma endregion

//@TODO: Add some game running logic to switch between scenes/menus
//@TODO: thoughts - add a variable to keep track of the current game state

// int main()
// {

//     GameInit();

//     while (!WindowShouldClose())
//     {
//         Awake();

//         Start();

//         Update(); // Update most of your data here

//         LateUpdate();

//         Draw();

//         EndFrame();
//     }
// }

// #pragma region Game Management Methods
// void GameInit()
// {
//     raylib::Window(1600, 900, "Hollow Knight");
//     SetTargetFPS(60);

//     knight = Player(PLAYER_ANIMATION_IDLE_PATH, PLAYER_ANIMATION_IDLE_FRAMECOUNT, PLAYER_ANIMATION_WIDTH, PLAYER_ANIMATION_HEIGHT, raylib::Vector2(0, 0));
//     knightWallCheck = PlayerWallCheck();

//     InitMapData();
// }

// void Awake()
// {
// }

// void Start()
// {
// }

// void Update()
// {
//     // use 4 colliders to check 4 directions of the player
//     knightWallCheck.Update();
//     // read in keyboard input and update player speed
//     PlayerMove();
//     // update player position, speed, test
//     knight.Update();
//     // update player test
//     knight.playerAnimationInfo.Update();
// }

// void LateUpdate()
// {
// }

// void Draw()
// {
//     BeginDrawing();
//     // Clear
//     ClearBackground(WHITE);
//     // sorting layer drawing
//     DrawBackground();
//     DrawPlayer();
//     DrawEnemy();
//     DrawMap();
//     DrawAttack();
//     DrawUI();
//     EndDrawing();
// }

// void EndFrame()
// {
// }
// #pragma endregion

// #pragma region Game Drawing Methods
// void DrawBackground()
// {
// }
// void DrawPlayer() // TODO:
// {
//     knight.Draw();
// }
// void DrawEnemy()
// {
// }
// void DrawMap() // TODO:
// {
// }
// void DrawAttack()
// {
// }
// void DrawUI()
// {
// }
// #pragma endregion

// #pragma region Game Logic Methods
// void InitPlayer()
// {
// }

// void InitMap()
// {
// }

// void PlayerMove()
// {
//     int horizontalInput = 0;
//     if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT))
//     {
//         horizontalInput -= 1;
//     }
//     if (IsKeyReleased(KEY_A) || IsKeyReleased(KEY_LEFT))
//     {
//         horizontalInput += 1;
//     }
//     if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT))
//     {
//         horizontalInput += 1;
//     }
//     if (IsKeyReleased(KEY_D) || IsKeyReleased(KEY_RIGHT))
//     {
//         horizontalInput -= 1;
//     }

//     // MOVE
//     if (knight.isFacingRight * horizontalInput < 0)
//     {
//         knight.isFacingRight = !knight.isFacingRight;
//     }
//     knight.SetSpeed(raylib::Vector2(horizontalInput * PLAYER_SPEED, knight.currentSpeed.y));

//     if (IsKeyPressed(KEY_SPACE))
//     {
//         // JUMP
//         knight.PlayerStartJump();
//     }
//     else if (IsKeyReleased(KEY_SPACE))
//     {
//         // STOPJUMP
//         knight.PlayerStopJump();
//     }
//     if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
//     {
//         // ATTACK
//     }
//     if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
//     {
//         // DASH
//     }
//     if (!knight.isGrounded)
//     {
//         knight.UpdateSpeed(raylib::Vector2(0, -PLAYER_GRAVITY));
//     }
// }

// void InitMapData() // TODO:
// {
//     mapList = std::vector<Map>();
// }
// #pragma endregion

#include "raylib-cpp.hpp"
#include "includes/main.h"
#include <iostream>

int main()
{
    InitWindow(1000, 1000, "test");
    SetTargetFPS(60);

    AnimationInfo test = AnimationInfo("../assets/sprites/Knight/Idle.png", 9, 0.2f);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        test.DrawAnimation(raylib::Vector2(0, 0), true, raylib::Vector2(-65, 0));
        test.DrawAnimation(raylib::Vector2(0, 0));
        test.Update();
        EndDrawing();
    }
}