#pragma once
#include "SFML-2.6.1/include/SFML/Graphics.hpp"
#include "Constants.h"

namespace SnakeGame {

	bool IsRectanglesCollide(sf::Vector2f rectangle1Position, sf::Vector2f rectangle1Size, sf::Vector2f rectangle2Position, sf::Vector2f rectangle2Size);
	void SetSpriteSize(sf::Sprite& sprite, float width, float height);
	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY);
	void SetSpriteScale(sf::Sprite& sprite, float scaleX, float scaleY);
	void SetSpritePositionInWindow(sf::Sprite& sprite, sf::Vector2i position);
}

