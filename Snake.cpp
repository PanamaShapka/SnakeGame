#include "Snake.h"
#include "Game.h"

namespace SnakeGame {

	void InitSnake(Snake& snake, const Game& game)
	{
		SetStartSnakeState(snake, game);
	}

	void SetStartSnakeState(Snake& snake, const Game& game)
	{
		snake.direction = SnakeDirection::Right;
		snake.tail.clear();

		AddSnakeHead(snake, game, sf::Vector2i(9, 7), false);
		AddSnakeTailPart(snake, game, sf::Vector2i(8 ,7), false);
		AddSnakeTailPart(snake, game, sf::Vector2i(7, 7), true);
	}

	SnakeTailPart& GetSnakeHead(Snake& snake)
	{
		return snake.tail.at(0);
	}

	void UpdateSnakePointers(Snake& snake) 
	{
		for (std::vector<SnakeTailPart>::reverse_iterator currentSnakeTailPart = snake.tail.rbegin(); currentSnakeTailPart != snake.tail.rend(); ++currentSnakeTailPart) {
			if (currentSnakeTailPart != snake.tail.rend() - 1) {
				currentSnakeTailPart->nextSnakePart = &(*(currentSnakeTailPart + 1));
			}
			else {
				currentSnakeTailPart->nextSnakePart = nullptr;
			}
		}
	}

	void UpdateSnakeDirection(Snake& snake, SnakeDirection newSnakeDirection)
	{
		if (not(snake.direction == SnakeDirection::Right && newSnakeDirection == SnakeDirection::Left ||
			snake.direction == SnakeDirection::Left && newSnakeDirection == SnakeDirection::Right ||
			snake.direction == SnakeDirection::Up && newSnakeDirection == SnakeDirection::Down ||
			snake.direction == SnakeDirection::Down && newSnakeDirection == SnakeDirection::Up)) {
			snake.direction = newSnakeDirection;
			GetSnakeHead(snake).sprite.setRotation(static_cast<int>(snake.direction) * 90.f);
		}
	}

	void UpdateSnakePosition(Snake& snake, sf::Vector2i newSnakeHeadPosition)
	{
		for (std::vector<SnakeTailPart>::reverse_iterator currentSnakeTailPart = snake.tail.rbegin(); currentSnakeTailPart != snake.tail.rend(); currentSnakeTailPart++) {
			if (currentSnakeTailPart->nextSnakePart != nullptr) {
				currentSnakeTailPart->position = currentSnakeTailPart->nextSnakePart->position;
				SetSpritePositionInWindow(currentSnakeTailPart->sprite, currentSnakeTailPart->position);
			}
		}

		GetSnakeHead(snake).position = newSnakeHeadPosition;
		SetSpritePositionInWindow(GetSnakeHead(snake).sprite, GetSnakeHead(snake).position);
	}

	void AddSnakeTailPart(Snake& snake, const Game& game, bool shouldUpdatePointers)
	{
		snake.tail.push_back(SnakeTailPart());
		SnakeTailPart& newSnakeTailPart = snake.tail.at(snake.tail.size() - 1);

		newSnakeTailPart.sprite.setTexture(game.snakeTailTexture);
		SetSpriteRelativeOrigin(newSnakeTailPart.sprite, 0.5f, 0.5f);
		SetSpriteSize(newSnakeTailPart.sprite, BASE_SPRITE_SIZE, BASE_SPRITE_SIZE);
		newSnakeTailPart.position = snake.tail.at(snake.tail.size() - 2).position;
		SetSpritePositionInWindow(newSnakeTailPart.sprite, newSnakeTailPart.position);

		newSnakeTailPart.sprite.setRotation(rand() % 3 * 90.f);

		if (shouldUpdatePointers) {
			UpdateSnakePointers(snake);
		}
	}

	void AddSnakeTailPart(Snake& snake, const Game& game, sf::Vector2i position, bool shouldUpdatePointers)
	{
		snake.tail.push_back(SnakeTailPart());
		SnakeTailPart& newSnakeTailPart = snake.tail.at(snake.tail.size() - 1);

		newSnakeTailPart.sprite.setTexture(game.snakeTailTexture);
		SetSpriteRelativeOrigin(newSnakeTailPart.sprite, 0.5f, 0.5f);
		SetSpriteSize(newSnakeTailPart.sprite, BASE_SPRITE_SIZE, BASE_SPRITE_SIZE);
		newSnakeTailPart.position = position;
		SetSpritePositionInWindow(newSnakeTailPart.sprite, newSnakeTailPart.position);

		newSnakeTailPart.sprite.setRotation(rand() % 3 * 90.f);

		if (shouldUpdatePointers) {
			UpdateSnakePointers(snake);
		}
	}

	void AddSnakeHead(Snake& snake, const Game& game, sf::Vector2i position, bool shouldUpdatePointers)
	{
		snake.tail.push_back(SnakeTailPart());
		SnakeTailPart& newSnakeTailPart = snake.tail.at(snake.tail.size() - 1);

		newSnakeTailPart.sprite.setTexture(game.snakeHeadTexture);
		SetSpriteRelativeOrigin(newSnakeTailPart.sprite, 0.5f, 0.5f);
		SetSpriteSize(newSnakeTailPart.sprite, BASE_SPRITE_SIZE, BASE_SPRITE_SIZE);
		newSnakeTailPart.position = position;
		SetSpritePositionInWindow(newSnakeTailPart.sprite, newSnakeTailPart.position);

		if (shouldUpdatePointers) {
			UpdateSnakePointers(snake);
		}
	}

	void DrawSnake(Snake& snake, sf::RenderWindow& window)
	{
		for (SnakeTailPart& currentSnakeTailPart : snake.tail) {
			window.draw(currentSnakeTailPart.sprite);
		}
	}

	
}