#include "raylib.h"

int main()
{
    InitWindow(800, 450, "My Snake Game");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(PINK);
        DrawRectangle(120,120,380,210,PURPLE);
        DrawRectangleLines(120,120,380, 210, BLACK);
        DrawRectangle(560, 25, 190, 120, PINK);
        DrawRectangleLines(560, 25, 190, 120, BLACK);
        DrawText("RULES", 562, 30, 20, BLACK);
        DrawText("Eat the food", 562, 52, 16, BLACK);
        DrawText("Eat the food", 562, 52, 16, BLACK);
        DrawCircle(680, 60, 5, RED);
        DrawText("Don't hit the wall", 562, 75, 16, BLACK);
        DrawText("Don't hit the wall", 562, 75, 16, BLACK);
        DrawText("Don't hit yourself", 562, 95, 16, BLACK);
        DrawText("Don't hit yourself", 562, 95, 16, BLACK);
        DrawText("Good Luck! :)", 562, 112, 14, BLACK);
        DrawText("Good Luck! :)", 562, 112, 14, BLACK);


        EndDrawing();
    }

    CloseWindow();

    return 0;
}

