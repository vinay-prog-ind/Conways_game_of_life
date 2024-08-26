#include "grid.hpp"
#include <raylib.h>

void Grid::Draw()
{
    for(int row = 0; row < rows; row++) {
        for(int column = 0; column < columns; column++) {
            Color color = cells[row][column] ? Color{0, 255, 0, 150} : Color{55, 55, 55, 5};
            DrawRectangle(column * cellSize, row * cellSize, cellSize-1, cellSize-1, color);
            // DrawCircle(column * cellSize, row * cellSize, (cellSize/2)-1, color);
        }
    }
}
bool Grid::isWithinBounds(int row, int column)
{
    if(row >= 0 && row < rows && column >= 0 && column < columns)
    {
         return true;
    }
    return false;
}

// void Grid::fillRandom()
// {
//     for(int row = 0; row < rows; row++) {
//         for(int column = 0; column < columns; column++) {
//             int randomValue  = GetRandomValue(0, 1);
//             cells[rows][column] = randomValue;
//         }
//     }
// }

void Grid::setValue(int row, int column, int value)
{
    if(isWithinBounds(row, column))
    {
         cells[row][column] = value;
    }
}

int Grid::getValue(int row, int column)
{
    if(isWithinBounds(row, column))
    {
        return cells[row][column];
    }
}