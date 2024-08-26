#pragma once
#include "grid.hpp"

class Simulation {
    public: 
        Simulation(int width, int height, int cellSize)
        : grid(width, height, cellSize), tempGrid(width, height, cellSize) {};

        void Draw();
        void setCellValue(int row, int column, int value);
        int countLiveNeighbors(int row, int column);
        void update();
    private: 
    Grid grid;
    Grid tempGrid;
    
};