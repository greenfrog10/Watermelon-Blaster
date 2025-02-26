#include "raylib/src/raylib.h"
int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int FPS = 60;
    const char* title = "Watermelon Blast !";
    const Color background_color = SKYBLUE;
    const Color player_color = DARKGREEN;
    Vector2 pos = { screenWidth / 2, screenHeight / 2 };
    const int player_size = 30;
    const int max_jump_height = 150;
    int y_before_jump = 0;
    bool is_jumping = false;
    bool fall = true;
    bool is_on_floor = false;
    Rectangle ground = {0, screenHeight - 30, screenWidth, 30};
    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(FPS);              


    while (!WindowShouldClose())    
    {
        if (CheckCollisionCircleRec(pos, player_size, ground))
        {
            is_on_floor = true;
        }
        else
        {
            is_on_floor = false;
        }
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_Z) || IsKeyDown(KEY_W)) 
        {
            if (!is_jumping && is_on_floor)
            {
                fall = false;
                is_jumping = true;
                y_before_jump = pos.y;
            }
        }
        if (is_jumping)
        {
            pos.y -= 10;
            if (pos.y <= y_before_jump - max_jump_height) 
            {
                is_jumping = false;
                fall = true;
            }
        }
        if (fall && !is_on_floor)
        {
            pos.y += 5;
        }
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        {
            pos.x += 10;
        }
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_Q) ||IsKeyDown(KEY_A))
        {
            pos.x -= 10;
        }
        BeginDrawing();
        DrawCircleV(pos,player_size,player_color);
        DrawRectangleRec(ground, RED);
        DrawRectangle(0, screenHeight - 30, screenWidth, 30, RED);        
        ClearBackground(background_color);
        EndDrawing();
        
    }

   
    CloseWindow();        

    return 0;
}