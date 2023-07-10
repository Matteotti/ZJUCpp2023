
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
void DrawDebug();
void PlayerMove();
void InitLists();
void InitMapData();
#pragma endregion

//@TODO: Add some game running logic to switch between scenes/menus
//@TODO: thoughts - add a variable to keep track of the current game state

#pragma region Global Variables
int horizontalInput = 0;
#pragma endregion

int main()
{

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
    knight.PlayerUpdateJump();
    // use 4 colliders to check 4 directions of the player
    knightWallCheck.Update();
    // update player position, speed, test
    knight.Update();
    // update player test
    knight.playerAnimationInfo.Update();
    // FIXME map can't be stored in a std::vector
    //  update all map animation
    //  for (int i = 0; i < mapList.size(); i++)
    //  {
    //      mapList[i].Update();
    //  }
    Map("ground_1", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(0, 880)).Update();
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
    // FIXME map can't be stored in a std::vector
    // for (int i = 0; i < mapList.size(); i++)
    // {
    //     mapList[i].DrawMap();
    // }
}
void DrawAttack()
{
}
void DrawUI()
{
}
void DrawDebug()
{
    Image img = GenImageColor(10, 10, RED);
    Texture2D tex = LoadTextureFromImage(img);
    DrawTexture(tex, knightWallCheck.leftCollider.center.x, knightWallCheck.leftCollider.center.y, WHITE);
    DrawTexture(tex, knightWallCheck.rightCollider.center.x, knightWallCheck.rightCollider.center.y, WHITE);
    DrawTexture(tex, knightWallCheck.topCollider.center.x, knightWallCheck.topCollider.center.y, WHITE);
    DrawTexture(tex, knightWallCheck.bottomCollider.center.x, knightWallCheck.bottomCollider.center.y, WHITE);
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
    if (knight.isFacingRight * horizontalInput < 0)
    {
        knight.isFacingRight = !knight.isFacingRight;
    }
    std::cout << "Horizontal Input: " << horizontalInput << std::endl;
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
        knight.UpdateSpeed(raylib::Vector2(0, PLAYER_GRAVITY * GetFrameTime()));
    }
}

void InitLists()
{
    mapList = std::vector<Map>();
    colliderList = std::vector<CustomCollider>();
}

void InitMapData()
{
    // FIXME map can't be stored in a std::vector
    // mapList = std::vector<Map>();
    // mapList.push_back(Map("ground_1", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(0, 880)));
    // mapList.push_back(Map("ground_2", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279, 880)));
    // mapList.push_back(Map("ground_3", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 2, 880)));
    // mapList.push_back(Map("ground_4", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 3, 880)));
    // mapList.push_back(Map("ground_5", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 4, 880)));
    // mapList.push_back(Map("ground_6", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 5, 880)));
    // mapList.push_back(Map("ground_7", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 6, 880)));
    // mapList.push_back(Map("ground_8", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 7, 880)));
    // mapList.push_back(Map("ground_9", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 8, 880)));
    // mapList.push_back(Map("ground_10", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 9, 880)));
    // mapList.push_back(Map("ground_11", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 10, 880)));
    // mapList.push_back(Map("ground_12", "../assets/sprites/Map/road3.png", 1, raylib::Vector2(279 * 11, 880)));

    // the parameter min and max of raylib::BoundingBox is not specific, we dont know the position of the collider
    CustomCollider ground = CustomCollider("ground", raylib::BoundingBox(raylib::Vector3(0, 200, 0), raylib::Vector3(1600, 300, 0)), ColliderTag::ENVIRONMENT);
}
#pragma endregion * /