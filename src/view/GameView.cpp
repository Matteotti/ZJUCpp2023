//
// Created by Hjuntao on 2023/7/12.
//

#include "GameView.h"
#include <stdlib.h>
#include <string>

void GameView::draw(int score, bool gameOver) {
    BeginDrawing();

    //ClearBackground(RAYWHITE);

    DrawText("Game View", 10, 10, 20, BLACK);

    if (gameOver) {
        DrawText("Game Over", 10, 70, 20, RED);
    }

    EndDrawing();
}
