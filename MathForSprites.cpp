#include "MathForSprites.h"

namespace SnakeGame {

	bool IsRectanglesCollide(sf::Vector2f rectangle1Position, sf::Vector2f rectangle1Size, sf::Vector2f rectangle2Position, sf::Vector2f rectangle2Size)
	{
		float dx = (float)fabs(rectangle1Position.x - rectangle2Position.x);
		float dy = (float)fabs(rectangle1Position.y - rectangle2Position.y);
		return (dx <= (rectangle1Size.x + rectangle2Size.x) / 2.f &&
			dy <= (rectangle1Size.y + rectangle2Size.y) / 2.f);
	}

	 void SetSpriteSize(sf::Sprite& sprite, float width, float height)
	{
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sf::Vector2f scale = { width / spriteRect.width, height / spriteRect.height };
		sprite.setScale(scale);
	}

	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY)
	{
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sprite.setOrigin(originX * spriteRect.width, originY * spriteRect.height);
	}

	void SetSpriteScale(sf::Sprite& sprite, float scaleX, float scaleY)
	{
		sprite.setScale(scaleX, scaleY);
	}

	void SetSpritePositionInWindow(sf::Sprite& sprite, sf::Vector2i position)
	{
		sprite.setPosition(sf::Vector2f(position.x * LAWN_CELL_SIZE + 25.f, position.y * LAWN_CELL_SIZE + 25.f));
	}
	
}
