#include "raylib.h"

#define MAX_SNAKE_LENGTH 100

int main()
{
    InitWindow(800, 450, "My Snake Game");
    SetTargetFPS(60);

    Vector2 snake[MAX_SNAKE_LENGTH];

    int snakeLength = 2;

    snake[0] = (Vector2){310, 220};
    snake[1] = (Vector2){300, 220};

    
    int direction = 0;


    float moveTimer = 0.0f;
    float moveDelay = 0.20f;

    

    Vector2 food;

    food.x = GetRandomValue(13, 49) * 10;
    food.y = GetRandomValue(13, 32) * 10;

    

    bool gameOver = false;



    while (!WindowShouldClose())
    {
       

        if (!gameOver)
        {
           
            if (IsKeyPressed(KEY_W) && direction != 4)
            {
                direction = 1;
            }

            
            if (IsKeyPressed(KEY_A) && direction != 3)
            {
                direction = 2;
            }

        
            if (IsKeyPressed(KEY_S) && direction != 2)
            {
                direction = 3;
            }


            if (IsKeyPressed(KEY_Z) && direction != 1)
            {
                direction = 4;
            }
        }

        

        if (!gameOver && direction != 0)
        {
            moveTimer += GetFrameTime();

            if (moveTimer >= moveDelay)
            {
            
                Vector2 oldTail = snake[snakeLength - 1];

                
                for (int i = snakeLength - 1; i > 0; i--)
                {
                    snake[i] = snake[i - 1];
                }

                
                if (direction == 1)
                {
                    
                    snake[0].y -= 10;
                }
                else if (direction == 2)
                {
                    
                    snake[0].x -= 10;
                }
                else if (direction == 3)
                {
                    
                    snake[0].x += 10;
                }
                else if (direction == 4)
                {
                
                    snake[0].y += 10;
                }

                moveTimer = 0.0f;

                

                if (snake[0].x <= 120 ||
                    snake[0].x >= 500 ||
                    snake[0].y <= 120 ||
                    snake[0].y >= 330)
                {
                    gameOver = true;
                }

               

                if (!gameOver &&
                    snake[0].x == food.x &&
                    snake[0].y == food.y)
                {
                    if (snakeLength < MAX_SNAKE_LENGTH)
                    {
                        snake[snakeLength] = oldTail;
                        snakeLength++;
                    }

                   
                    food.x = GetRandomValue(13, 49) * 10;
                    food.y = GetRandomValue(13, 32) * 10;
                }


                for (int i = 1; i < snakeLength; i++)
                {
                    if (snake[0].x == snake[i].x &&
                        snake[0].y == snake[i].y)
                    {
                        gameOver = true;
                    }
                }
            }
        }

        

        BeginDrawing();

        ClearBackground(PINK);

        

        DrawRectangle(120, 120, 380, 210, RED);
        DrawRectangleLines(120, 120, 380, 210, BLACK);

    

        DrawRectangle(560, 25, 190, 120, PINK);
        DrawRectangleLines(560, 25, 190, 120, WHITE);

        DrawText("RULES", 562, 30, 20, BLACK);

        DrawText("Eat the food", 562, 52, 16, BLACK);
        DrawCircle(680, 60, 5, RED);

        DrawText("Don't hit the wall", 562, 75, 16, BLACK);

        DrawText("Don't hit yourself", 562, 95, 16, BLACK);

        DrawText("Good Luck! :)", 562, 112, 14, BLACK);

     

        DrawText("W = UP", 560, 170, 18, BLACK);
        DrawText("A = LEFT", 560, 195, 18, BLACK);
        DrawText("S = RIGHT", 560, 220, 18, BLACK);
        DrawText("Z = DOWN", 560, 245, 18, BLACK);

      

        if (!gameOver)
        {
            DrawCircle(food.x, food.y, 5, YELLOW);
        }

       

        for (int i = 0; i < snakeLength; i++)
        {
            DrawCircle(snake[i].x, snake[i].y, 5, GREEN);
        }

       

        if (gameOver)
        {
            DrawText("GAME OVER", 230, 190, 40, WHITE);

            DrawText("Press ENTER to restart",
                     220, 240, 20, WHITE);

            if (IsKeyPressed(KEY_ENTER))
            {
                snakeLength = 2;

                snake[0] = (Vector2){310, 220};
                snake[1] = (Vector2){300, 220};

                direction = 0;

                moveTimer = 0.0f;

                food.x = GetRandomValue(13, 49) * 10;
                food.y = GetRandomValue(13, 32) * 10;

                gameOver = false;
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}