#pragma once
#include "SFML-2.6.1/include/SFML/Graphics.hpp"
#include "Constants.h"

namespace SnakeGame {

	struct Grid
	{
		struct Cell {
			sf::Vector2i position;
			bool isCellEmpty = true;
		};

		std::vector<Cell> cells;
		std::vector<Cell> emptyCells;
	};

	void InitGrid(Grid& grid);
	Grid::Cell& GetCell(Grid& grid, sf::Vector2i position);
	void UpdateGrid(Grid& grid);
	void SetStartGridState(Grid& grid);
}

