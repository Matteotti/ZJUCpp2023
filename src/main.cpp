
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
void DrawAttackTop();
void DrawAttackDown();
void DrawAttack(AnimatorState currentState);
void DrawUI();
void DrawDebug();
void PlayerMove();
void InitLists();
void InitMapData();
#pragma endregion

//@TODO: Add some game running logic to switch between scenes/menus
//@TODO: thoughts - add a variable to keep track of the current game state

#pragma region Global Variables
int horizontalInput = 0;
int mapListSize;
std::vector<Map> mapList;
#pragma endregion
//mapList = std::vector<Map>();
int main()
{
    SetTraceLogLevel(LOG_NONE);

    raylib::Window window(1600, 900, "Hollow Knight");
    SetTargetFPS(60);
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
    InitLists();
    knight = Player("../assets/sprites/Knight/Idle.png", 9, raylib::Vector2(0, 0));
    knightWallCheck = PlayerWallCheck();

    InitMapData();
}

void Awake()
{
}

void Start()
{
}

void Update()
{
    // read in keyboard input and update player speed
    PlayerMove();
    // Update Jump Speed
    knight.PlayerUpdateJump();
    // use 4 colliders to check 4 directions of the player
    knightWallCheck.Update();
    // update player position, speed, test
    knight.Update();
    // update player test
    knight.playerAnimationInfo.Update();
    // update all map animation
    for (int i = 0; i < mapList.size(); i++)
    {
        mapList[i].Update();
    }
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
    DrawAttack(knight.currentState);
    DrawUI();
    DrawDebug();
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
    knight.Draw();
}
void DrawEnemy()
{
}
void DrawMap()
{
    for (int i = 0; i < mapList.size(); i++)
    {
        mapList[i].DrawMap();
    }
}

void DrawAttackTop()
{
    knight.AttackTop_draw();
}

void DrawAttackDown()
{
    knight.AttackDown_draw();
}

void DrawAttack(AnimatorState currentState)
{
    if (currentState == ATTACKING_TOP)
    {
        DrawAttackTop();
    }
    else if (currentState == ATTACKING_BOTTOM)
    {
        DrawAttackDown();
    }
}

void DrawUI()
{
}
void DrawDebug()
{
    for (int i = 0; i < colliderList.size(); i++)
    {
        DrawRectangleLines(colliderList[i].colliderBox.x, colliderList[i].colliderBox.y, colliderList[i].colliderBox.width, colliderList[i].colliderBox.height, RED);
    }
    DrawRectangle(knightWallCheck.bottomCollider.colliderBox.x, knightWallCheck.bottomCollider.colliderBox.y, knightWallCheck.bottomCollider.colliderBox.width, knightWallCheck.bottomCollider.colliderBox.height, RED);
}
#pragma endregion

#pragma region Game Logic Methods
void InitPlayer()
{
}

void PlayerMove()
{
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
    if (knight.isFacingRight && horizontalInput < 0)
    {
        knight.isFacingRight = false;
    }
    else if (!knight.isFacingRight && horizontalInput > 0)
    {
        knight.isFacingRight = true;
    }
    knight.SetSpeed(raylib::Vector2(horizontalInput * PLAYER_SPEED, knight.currentSpeed.y));

    if (knight.isGrounded)
    {
        knight.jumpCount = 0;
    }

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
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && IsKeyPressed(KEY_W))
    {
        // ATTACK_TOP
        knight.currentState = ATTACKING_TOP;
    }
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && IsKeyPressed(KEY_S))
    {
        // ATTACK_BOTTOM
        knight.currentState = ATTACKING_BOTTOM;
    }
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && IsKeyPressed(KEY_A))
    {
        // ATTACK_LEFT
        knight.currentState = ATTACKING_LEFT;
    }
    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
    {
        // DASH
    }
    if (!knight.isGrounded)
    {
        knight.UpdateSpeed(raylib::Vector2(0, PLAYER_GRAVITY * GetFrameTime()));
    }
}

void InitLists()
{
    //mapList = std::vector<Map>();
    colliderList = std::vector<CustomCollider>();
}

void InitMapData()
{
    Map("ground_1", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(0, 700));
    Map("ground_2", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279, 700));
    Map("ground_3", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279, 600));
    Map("ground_4", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279, 300));
}
#pragma endregion