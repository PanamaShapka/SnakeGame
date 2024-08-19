#pragma once
#include "SFML-2.6.1/include/SFML/Graphics.hpp"
#include "Constants.h"

namespace SnakeGame {

	struct Game;
	struct Box;
	struct Grid;

	bool IsRectanglesCollide(sf::Vector2f rectangle1Position, sf::Vector2f rectangle1Size, sf::Vector2f rectangle2Position, sf::Vector2f rectangle2Size);
	void SetSpriteSize(sf::Sprite& sprite, float width, float height);
	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY);
	void SetSpriteScale(sf::Sprite& sprite, float scaleX, float scaleY);
	void SetSpritePositionInWindow(sf::Sprite& sprite, sf::Vector2i position);
	std::vector<Box> CreateLawnBorder(Grid& grid, sf::Vector2i length, const Game& game);
	sf::Vector2i GetRandomEmptyPositionInLawn(Grid& grid);
}

