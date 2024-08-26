#include <iostream>
#include <raylib.h>
#include "simulation.hpp"

int main()
{
    Color darkGray = Color{29, 29, 29, 255};

    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    const int CELL_SIZE = 25;
    int FPS = 12;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of life");
    SetTargetFPS(FPS);
    Simulation simulation {WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE};

    while (WindowShouldClose() == false)
    {
        simulation.Update();
        BeginDrawing();
        ClearBackground(darkGray);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
}