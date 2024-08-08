#include "Box.h"
#include "Game.h"

namespace SnakeGame {

	void InitBox(Box& box, const Game& game)
	{
		box.sprite.setTexture(game.boxTexture);
		SetSpriteRelativeOrigin(box.sprite, 0.5f, 0.5f);
		SetSpriteSize(box.sprite, BASE_SPRITE_SIZE, BASE_SPRITE_SIZE);
	}

	void SetBoxPosition(Box& box, sf::Vector2i position)
	{
		box.position = position;
		SetSpritePositionInWindow(box.sprite, box.position);
	}

	void DrawBox(Box& box, sf::RenderWindow& window)
	{
		window.draw(box.sprite);
	}
}