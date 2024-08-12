#pragma once
#include "SFML-2.6.1/include/SFML/Graphics.hpp"
#include <cassert>

#include "MathForSprites.h"

namespace SnakeGame {

	struct Box {
		sf::Sprite sprite;
		sf::Vector2i position;
	};

	struct Game;

	void InitBox(Box& box, const Game& game);
	void SetBoxPosition(Box& box, sf::Vector2i position);
	void DrawBox(Box& box, sf::RenderWindow& window);
}

