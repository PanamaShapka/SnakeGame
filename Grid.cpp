#include "Grid.h"

namespace SnakeGame {

	void InitGrid(Grid& grid)
	{
		for (int y = 0; y < LAWN_LENGHT_Y_WITH_BORDER; ++y) {
			for (int x = 0; x < LAWN_LENGHT_X_WITH_BORDER; ++x) {
				grid.cells.push_back(Grid::Cell());
				grid.cells.at(grid.cells.size() - 1).position = sf::Vector2i(x, y);
			}
		}

		grid.emptyCells.reserve(grid.cells.size());
	}
	Grid::Cell& GetCell(Grid& grid, sf::Vector2i position)
	{
		return *(std::find_if(grid.cells.begin(), grid.cells.end(), [position](const Grid::Cell& currentCell) {
			return currentCell.position == position; }));
	}

	void UpdateGrid(Grid& grid)
	{
		grid.emptyCells.clear();
		for (Grid::Cell& currentCell : grid.cells) {
			if (currentCell.isCellEmpty) {
				grid.emptyCells.push_back(currentCell);
			}
		}
	}
	void SetStartGridState(Grid& grid)
	{
		for (Grid::Cell& currentCell : grid.cells) {
			currentCell.isCellEmpty = true;
		}
		grid.emptyCells.clear();
	}
}
