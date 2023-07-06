#include "includes/main.h"

void Draw();
void DrawPlayer();

void PlayerMove();

int main()
{
    raylib::Window(1600, 900, "Hollow Knight");
    SetTargetFPS(60);

    Player knight = Player();

    while (!WindowShouldClose())
    {
        // Update Data Here
        PlayerMove(knight);
        knight.Update();
        // End Update

        // Draw Here
        BeginDrawing();
        Draw();
        EndDrawing();
        // End Draw
    }
}

void Draw()
{
    // Clear

    // sorting layer drawing
    // 1.background
    // 2.player
    //...
    // ?.attack
}

void DrawPlayer()
{
}

void PlayerMove(Player &player)
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
    if (player.isFacingRight * horizontalInput < 0)
    {
        player.isFacingRight = !player.isFacingRight;
    }
    player.SetSpeed(raylib::Vector2(horizontalInput * PLAYER_SPEED, player.currentSpeed.y));

    if (IsKeyPressed(KEY_SPACE))
    {
        // JUMP
        player.PlayerStartJump();
    }
    else if (IsKeyReleased(KEY_SPACE))
    {
        // STOPJUMP
        player.PlayerStopJump();
    }
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        // ATTACK
    }
    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
    {
        // DASH
    }
    if (!player.isGrounded)
    {
        player.UpdateSpeed(raylib::Vector2(0, -PLAYER_GRAVITY));
    }
}