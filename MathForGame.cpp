#include "MathForGame.h"
#include "Game.h"

namespace SnakeGame {

	std::vector<Box> CreateLawnBorder(Grid& grid, sf::Vector2i length, const Game& game)
	{
		std::vector<Box> result;

		for (int x = 0; x < length.x; ++x) {
			Box box;
			InitBox(box, game);
			SetBoxPosition(box, sf::Vector2i(x, 0));
			result.push_back(box);

			GetCell(grid, sf::Vector2i(x, 0)).isCellEmpty = false;
		}

		for (int x = 0; x < length.x; ++x) {
			Box box;
			InitBox(box, game);
			SetBoxPosition(box, sf::Vector2i(x, length.y - 1));
			result.push_back(box);

			GetCell(grid, sf::Vector2i(x, length.y - 1)).isCellEmpty = false;
		}

		for (int y = 1; y < length.y - 1; ++y) {
			Box box;
			InitBox(box, game);
			SetBoxPosition(box, sf::Vector2i(0, y));
			result.push_back(box);

			GetCell(grid, sf::Vector2i(0, y)).isCellEmpty = false;
		}

		for (int y = 1; y < length.y - 1; ++y) {
			Box box;
			InitBox(box, game);
			SetBoxPosition(box, sf::Vector2i(length.x - 1, y));
			result.push_back(box);

			GetCell(grid, sf::Vector2i(length.x - 1, y)).isCellEmpty = false;
		}

		return result;
	}

	sf::Vector2i GetRandomEmptyPositionInLawn(Grid& grid)
	{
		if (grid.emptyCells.size() == 1) {
			return grid.emptyCells.at(0).position;
		}
		else if (grid.emptyCells.size() == 0) {
			return sf::Vector2i(-1, - 1);
		}
		else {
			return grid.emptyCells.at(rand() % (grid.emptyCells.size() - 1)).position;
		}
	}
}
