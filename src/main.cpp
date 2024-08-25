#include <raylib.h>
#include "simulation.hpp"

int main()
{
    Color darkGray = Color{29, 29, 29, 255};

    const int WINDOW_WIDTH = 1910;
    const int WINDOW_HEIGHT = 1050;
    const int CELL_SIZE = 25;
    int FPS = 12;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of life");
    SetTargetFPS(FPS);
    Simulation simulation {WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE};
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkGray);
        // grid.Update();
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}