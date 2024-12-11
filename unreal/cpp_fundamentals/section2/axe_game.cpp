#include "raylib.h"

int main()
{
    int width{640};
    int height{640};

    InitWindow(width, height, "Init");

    // circle coords
    int x{width / 2};
    int y{height / 2};
    int circle_rad{25};
    int axe_direction{1};
    int axe_x{500};
    int axe_y{0};
    int axe_len{50};
    bool isAxeCollidingWithCircle{false};
    // circle edges
    int l_circle_x{x - circle_rad};
    int r_circle_x{x + circle_rad};
    int u_circle_y{y - circle_rad};
    int b_circle_y{y + circle_rad};
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_len};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_len};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        if (isAxeCollidingWithCircle)
        {
            DrawText("Game Over!", width / 2, height / 2, 20, RED);
        }
        else
        {

            // updates
            l_circle_x = x - circle_rad;
            r_circle_x = x + circle_rad;
            u_circle_y = y - circle_rad;
            b_circle_y = y + circle_rad;

            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_len;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_len;

            isAxeCollidingWithCircle = (b_axe_y >= u_circle_y) &&
                                       (u_axe_y <= b_circle_y) &&
                                       (r_axe_x >= l_circle_x) &&
                                       (l_axe_x <= r_circle_x);

            if (IsKeyDown(KEY_W) && y > 0)
                y -= 25;
            if (IsKeyDown(KEY_A) && x > 0)
                x -= 25;
            if (IsKeyDown(KEY_S) && y < height)
                y += 25;
            if (IsKeyDown(KEY_D) && x < width)
                x += 25;

            DrawCircle(x, y, circle_rad, BLUE);

            // Axe
            if (axe_y < 0 || axe_y > height)
                axe_direction *= -1;
            axe_y += 10 * axe_direction;
            DrawRectangle(axe_x, axe_y, 20, axe_len, RED);

        }
        EndDrawing();
    }

    return 0;
}