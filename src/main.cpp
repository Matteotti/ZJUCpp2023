#include "includes/main.h"

#pragma region Methods Declaration
void GameInit();
void Awake();
void Start();
void Update();
void LateUpdate();
void Draw();
void EndFrame();

void DrawBackground();
void DrawPlayer();
void DrawEnemy();
void DrawMap();
void DrawAttack();
void DrawUI();
void PlayerMove();
#pragma endregion

int main()
{

    GameInit();

    while (!WindowShouldClose())
    {
        Awake();

        Start();

        Update(); // Update most of your data here

        LateUpdate();

        Draw();

        EndFrame();
    }
}

#pragma region Game Management Methods
void GameInit()
{
    raylib::Window(1600, 900, "Hollow Knight");
    SetTargetFPS(60);
}

void Awake()
{
    // knight = Player();
}

void Start()
{
}

void Update()
{
    PlayerMove();
    knight.Update();
}

void LateUpdate()
{
}

void Draw()
{
    BeginDrawing();
    // Clear
    ClearBackground(WHITE);
    // sorting layer drawing
    DrawBackground();
    DrawPlayer();
    DrawEnemy();
    DrawMap();
    DrawAttack();
    DrawUI();
    EndDrawing();
}

void EndFrame()
{
}
#pragma endregion

#pragma region Game Drawing Methods
void DrawBackground()
{
}
void DrawPlayer()
{
}
void DrawEnemy()
{
}
void DrawMap()
{
}
void DrawAttack()
{
}
void DrawUI()
{
}
#pragma endregion

#pragma region Game Logic Methods
void InitPlayer()
{
}

void InitMap()
{
}

void PlayerMove()
{
    int horizontalInput = 0;
    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT))
    {
        horizontalInput -= 1;
    }
    if (IsKeyReleased(KEY_A) || IsKeyReleased(KEY_LEFT))
    {
        horizontalInput += 1;
    }
    if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT))
    {
        horizontalInput += 1;
    }
    if (IsKeyReleased(KEY_D) || IsKeyReleased(KEY_RIGHT))
    {
        horizontalInput -= 1;
    }

    // MOVE
    if (knight.isFacingRight * horizontalInput < 0)
    {
        knight.isFacingRight = !knight.isFacingRight;
    }
    knight.SetSpeed(raylib::Vector2(horizontalInput * PLAYER_SPEED, knight.currentSpeed.y));

    if (IsKeyPressed(KEY_SPACE))
    {
        // JUMP
        knight.PlayerStartJump();
    }
    else if (IsKeyReleased(KEY_SPACE))
    {
        // STOPJUMP
        knight.PlayerStopJump();
    }
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        // ATTACK
    }
    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
    {
        // DASH
    }
    if (!knight.isGrounded)
    {
        knight.UpdateSpeed(raylib::Vector2(0, -PLAYER_GRAVITY));
    }
}
#pragma endregion