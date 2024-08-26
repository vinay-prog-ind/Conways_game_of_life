#include <vector>
#include <utility>

#include "simulation.hpp"

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::setCellValue(int row, int column, int value)
{
    grid.setValue(row, column, value);
}

int Simulation::countLiveNeighbors(int row, int column)
{
    int liveNeighbours = 0;
    std::vector<std::pair<int, int>> neighborOffset = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1}
    };

    for(const auto& offset : neighborOffset) {
        int neighborRow = (row + offset.first + grid.getRows()) % grid.getRows();
        int neighborColumn = (column +offset.second + grid.getColumns()) % grid.getColumns();
        liveNeighbours += grid.getValue(neighborRow, neighborColumn);
    }
    return liveNeighbours;
}

void Simulation::Update()
{
    for(int row = 0; row < grid.getRows(); row++) {
        for(int column = 0; column < grid.getColumns(); column++) {
            int liveNeighbors = countLiveNeighbors(row, column);
            int cellValue = grid.getValue(row, column);

            if(cellValue == 1) {
                if(liveNeighbors > 3 || liveNeighbors < 2)
                {
                    tempGrid.setValue(row, column, 0);
                }
                else {
                    tempGrid.setValue(row, column, 1);
                }
            }
            else {
                if(liveNeighbors == 3) {
                    tempGrid.setValue(row, column, 1);
                }
                else {
                    tempGrid.setValue(row, column, 0);
                }
            }
        }
    }
    grid = tempGrid;
}

