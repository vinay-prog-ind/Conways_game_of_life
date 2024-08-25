#include "grid.hpp"
#include <raylib.h>

void Grid::Draw()
{
    for(int row = 0; row < rows; row++) {
        for(int column = 0; column < columns; column++) {
            Color color = cells[row][column] ? Color{0, 255, 0, 150} : Color{55, 55, 55, 5};
            // DrawRectangle(column * cellSize, row * cellSize, cellSize-1, cellSize-1, color);
            DrawCircle(column * cellSize, row * cellSize, cellSize/2-1, color);
        }
    }
}

void Grid::setValue(int row, int column, int value)
{
    if(row >= 0 && row < rows && column >= 0 && column < columns)
    {
         cells[row][column] = value;
    }
}