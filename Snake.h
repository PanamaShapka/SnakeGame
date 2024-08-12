#pragma once
#include "SFML-2.6.1/include/SFML/Graphics.hpp"
#include <cassert>

#include "MathForSprites.h"

namespace SnakeGame {

	enum class SnakeDirection {
		Right = 0,
		Down,
		Left,
		Up
	};

	struct SnakeTailPart {
		sf::Sprite sprite;
		sf::Vector2i position;
		SnakeTailPart* nextSnakePart = nullptr;
	};

	struct Snake {
		std::vector<SnakeTailPart> tail;
		SnakeDirection direction = SnakeDirection::Right;
		float speed;
	};

	struct Game;

	void InitSnake(Snake& snake, const Game& game);
	void SetStartSnakeState(Snake& snake, const Game& game);
	SnakeTailPart& GetSnakeHead(Snake& snake);
	void SetSnakePointers(Snake& snake);
	void UpdateSnakeDirection(Snake& snake, SnakeDirection newSnakeDirection);
	void UpdateSnakePosition(Snake& snake, sf::Vector2i newSnakeHeadPosition);
	void AddSnakeTailPart(Snake& snake, const Game& game, bool shouldUpdatePointers);
	void AddSnakeTailPart(Snake& snake, const Game& game, sf::Vector2i position, bool shouldUpdatePointers);
	void AddSnakeHead(Snake& snake, const Game& game, sf::Vector2i position, bool shouldUpdatePointers);
	void DrawSnake(Snake& snake, sf::RenderWindow& window);
}