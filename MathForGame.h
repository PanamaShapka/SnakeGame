#pragma once
#include "Snake.h"
#include "Box.h"
#include "Apple.h"
#include "Grid.h"

namespace SnakeGame {

	struct Game;

	std::vector<Box> CreateLawnBorder(Grid& grid, sf::Vector2i length, const Game& game);
	sf::Vector2i GetRandomEmptyPositionInLawn(Grid& grid);
}

