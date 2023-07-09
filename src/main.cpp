#include "raylib-cpp.hpp"
#include "includes/main.h"
#include "includes/map.h"
#include "includes/player.h"
#include "includes/animation.h"
#include <iostream>

int main()
{
    InitWindow(1000, 1000, "test");
    SetTargetFPS(60);
    Map maplist[]={
    {"ground","../assets/sprites/Knight//road3.png",1,40,60,raylib::Vector2(0,880),279,40},
    {"ground","../assets/sprites/Knight//road3.png",1,40,60,raylib::Vector2(279,880),279,40},
    {"ground","../assets/sprites/Knight//road3.png",1,40,60,raylib::Vector2(279*2,880),279,40},
    {"ground","../assets/sprites/Knight//road3.png",1,40,60,raylib::Vector2(279*3,880),279,40},
    {"ground","../assets/sprites/Knight//road3.png",1,40,60,raylib::Vector2(279*4,880),279,40},
    {"ground","../assets/sprites/Knight//road3.png",1,40,60,raylib::Vector2(279*5,880),279,40},
    {"ground","../assets/sprites/Knight//road3.png",1,40,60,raylib::Vector2(279*6,880),279,40},
    {"ground","../assets/sprites/Knight//road3.png",1,40,60,raylib::Vector2(279*7,880),279,40},
    {"ground","../assets/sprites/Knight//road3.png",1,40,60,raylib::Vector2(279*8,880),279,40},
    {"ground","../assets/sprites/Knight//road3.png",1,40,60,raylib::Vector2(279*9,880),279,40},
    {"ground","../assets/sprites/Knight//road3.png",1,40,60,raylib::Vector2(279*10,880),279,40},
    {"ground","../assets/sprites/Knight//road3.png",1,40,60,raylib::Vector2(279*11,880),279,40}
};
    int envItemsLength = sizeof(maplist)/sizeof(maplist[0]);
    AnimationInfo test = AnimationInfo("../assets/sprites/Knight/Idle.png", 9, 0.2f);
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (int i=0;i<envItemsLength;i++){
            maplist[i].DrawMap();
        }
        test.DrawAnimation(raylib::Vector2(0, 0), true, raylib::Vector2(-65, 0));
        test.DrawAnimation(raylib::Vector2(0, 0));
        test.Update();
        EndDrawing();
    }
}   