#include "Math.h"
#include "Game.h"

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
	
	std::vector<Box> CreateLawnBorder(Grid& grid, sf::Vector2i length, const Game& game)
	{
		std::vector<Box> result;

		for (int x = 0; x < length.x; ++x) {
			Box box;
			InitBox(box, game);
			SetBoxPosition(box, sf::Vector2i(x, 0));
			result.push_back(box);

			GetCell(grid, sf::Vector2i(x, 0)).isCellEmpty = false;
		}

		for (int x = 0; x < length.x; ++x) {
			Box box;
			InitBox(box, game);
			SetBoxPosition(box, sf::Vector2i(x, length.y - 1));
			result.push_back(box);

			GetCell(grid, sf::Vector2i(x, length.y - 1)).isCellEmpty = false;
		}

		for (int y = 1; y < length.y - 1; ++y) {
			Box box;
			InitBox(box, game);
			SetBoxPosition(box, sf::Vector2i(0, y));
			result.push_back(box);

			GetCell(grid, sf::Vector2i(0, y)).isCellEmpty = false;
		}

		for (int y = 1; y < length.y - 1; ++y) {
			Box box;
			InitBox(box, game);
			SetBoxPosition(box, sf::Vector2i(length.x - 1, y));
			result.push_back(box);

			GetCell(grid, sf::Vector2i(length.x - 1, y)).isCellEmpty = false;
		}

		return result;
	}

	sf::Vector2i GetRandomEmptyPositionInLawn(Grid& grid)
	{
		if (grid.emptyCells.size() == 1) {
			return grid.emptyCells.at(0).position;
		}
		else if (grid.emptyCells.size() == 0) {
			return sf::Vector2i(-1, -1);
		}
		else {
			return grid.emptyCells.at(rand() % (grid.emptyCells.size() - 1)).position;
		}
	}

}
