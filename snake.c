#include "raylib.h"

int main()
{
    InitWindow(800, 450, "My Snake Game");

    // Snake head position
    int snakeX = 310;
    int snakeY = 225;

    // Movement timer
    float moveTimer = 0;
    float moveDelay = 0.12f;

    while (!WindowShouldClose())
    {
        
        moveTimer += GetFrameTime();

        
        if (moveTimer >= moveDelay)
        {
            if (IsKeyDown(KEY_W))
            {
                snakeY -= 10;
            }

            if (IsKeyDown(KEY_S))
            {
                snakeY += 10;
            }

            if (IsKeyDown(KEY_A))
            {
                snakeX -= 10;
            }

            if (IsKeyDown(KEY_D))
            {
                snakeX += 10;
            }

            moveTimer = 0;
        }

        BeginDrawing();

        // Game board
        DrawRectangle(120, 120, 380, 210, RED);
        DrawRectangleLines(120, 120, 380, 210, BLACK);

        // Rules box
        DrawRectangle(560, 25, 190, 120, PINK);
        DrawRectangleLines(560, 25, 190, 120, WHITE);

        DrawText("RULES", 562, 30, 20, BLACK);
        DrawText("Eat the food", 562, 52, 16, BLACK);
        DrawCircle(680, 60, 5, RED);
        DrawText("Don't hit the wall", 562, 75, 16, BLACK);
        DrawText("Don't hit yourself", 562, 95, 16, BLACK);
        DrawText("Good Luck! :)", 562, 112, 14, BLACK);

        // Snake
        DrawCircle(snakeX, snakeY, 5, GREEN);
    

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

