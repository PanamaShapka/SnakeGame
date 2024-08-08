#include "Apple.h"
#include "Game.h"

namespace SnakeGame {

	void InitApple(Apple& apple, const Game& game)
	{
		apple.sprite.setTexture(game.appleTexture);
		SetSpriteRelativeOrigin(apple.sprite, 0.5f, 0.5f);
		SetSpriteSize(apple.sprite, BASE_SPRITE_SIZE, BASE_SPRITE_SIZE);
	}

	void SetApplePosition(Apple& apple, sf::Vector2i position)
	{
		apple.position = position;
		SetSpritePositionInWindow(apple.sprite, apple.position);
	}

	void DrawApple(Apple& apple, sf::RenderWindow& window)
	{
		window.draw(apple.sprite);
	}
}

