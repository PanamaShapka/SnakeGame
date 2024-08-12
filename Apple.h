#pragma once
#include "SFML-2.6.1/include/SFML/Graphics.hpp"
#include <cassert>

#include "MathForSprites.h"

namespace SnakeGame {

	struct Apple {
		sf::Sprite sprite;
		sf::Vector2i position;
	};

	struct Game;

	void InitApple(Apple& apple, const Game& game);
	void SetApplePosition(Apple& apple, sf::Vector2i position);
	void DrawApple(Apple& apple, sf::RenderWindow& window);
}