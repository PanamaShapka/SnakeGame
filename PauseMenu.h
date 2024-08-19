#pragma once
#include "SFML-2.6.1/include/SFML/Graphics.hpp"

namespace SnakeGame {

	struct Game;

	struct PauseMenu {
		enum class PauseMenuButton {
			CONTINUE_BUTTON = 1,
			EXIT_TO_MENU_BUTTON
		};

		PauseMenuButton currentButton;
		bool isKeyPressed;

		sf::RectangleShape background;
		sf::Text pauseText;
		sf::Text continueText;
		sf::Text exitToMenuText;
	};

	void InitPauseMenu(PauseMenu& pauseMenu, const Game& game);
	void SetStartPauseMenuState(PauseMenu& pauseMenu);
	void UpdatePauseMenuButtonsColor(PauseMenu& pauseMenu);
	void UpdatePauseMenu(PauseMenu& pauseMenu, Game& game);
	void DrawPauseMenu(PauseMenu& pauseMenu, sf::RenderWindow& window);
}

