#pragma once
#include "SFML-2.6.1/include/SFML/Graphics.hpp"
#include "Constants.h"
#include "Difficulty.h"

namespace SnakeGame {

	struct DifficultyLevelMenu {
		enum class SettingsMenuButton {
			DIFFICULTY_LEVEL_1 = 0,
			DIFFICULTY_LEVEL_2,
			DIFFICULTY_LEVEL_3,
			DIFFICULTY_LEVEL_4,
			DIFFICULTY_LEVEL_5
		};

		SettingsMenuButton currentButton = SettingsMenuButton::DIFFICULTY_LEVEL_1;
		bool isControlKeyPressed = false;

		sf::Text difficultyLevelText;
		sf::Sprite checkMark;
		sf::Text difficultyLevel_1Text;
		sf::Text difficultyLevel_2Text;
		sf::Text difficultyLevel_3Text;
		sf::Text difficultyLevel_4Text;
		sf::Text difficultyLevel_5Text;
	};

	struct Game;

	void InitDifficultyLevelMenu(DifficultyLevelMenu& difficultyLevelMenu, const Game& game);
	void UpdateCheckMark(DifficultyLevelMenu& difficultyLevelMenu);
	void UpdateDifficultyLevelMenuButtonsColor(DifficultyLevelMenu& difficultyLevelMenu);
	void UpdateDifficultyLevelMenu(DifficultyLevelMenu& difficultyLevelMenu, Game& game);
	void DrawDifficultyLevelMenu(DifficultyLevelMenu& difficultyLevelMenu, sf::RenderWindow& window);
}

