#include "raylib.h"

int main()
{
  // window Properties:

    int width{800};
    int height{450};
    InitWindow(width, height, "MyWindow");

    // circle coordinates

    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};
    //circle edgews:
    int l_circle_x{circle_x-circle_radius};     //left edge
    int r_circle_x{circle_x+circle_radius};     //right edge
    int u_circle_y{circle_y-circle_radius};     //upper edge
    int b_circle_y{circle_y+circle_radius};     //lower edge

    // axe coordinates
    int axe_x{400};
    int axe_y{0};
    int axe_length{50};
    //axe edges:
    int l_axe_x{axe_x};     //left edge
    int r_axe_x{axe_x+axe_length};     //right edge
    int u_axe_y{axe_y};     //upper edge
    int b_axe_y{axe_y+axe_length};     //lower edge

    int direction{10};

    SetTargetFPS(60);

    while (WindowShouldClose() == false)
        // Game logic starts:
    {
        BeginDrawing();
        ClearBackground(WHITE);


        DrawCircle(circle_x, circle_y, circle_radius, BLUE);
        DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

        // move the axe
        axe_y += direction;

        if(axe_y>height || axe_y<0){
            direction = -direction;
        }

        //check for collision:


        if (IsKeyDown(KEY_D) && circle_x < width)
        {
            circle_x += 10;
        }
        if (IsKeyDown(KEY_A) && circle_x > 0)
        {
            circle_x -= 10;
        }
        // Game logic ends
        EndDrawing();
    }

}