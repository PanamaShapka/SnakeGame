#pragma once
#include "SFML-2.6.1/include/SFML/Graphics.hpp"
#include "Constants.h"
#include "DifficultyLevelMenu.h"
#include "SettingsMenu.h"
#include "LeaderboardMenu.h"

namespace SnakeGame {

	enum class MainMenuState {
		MAIN_MENU = 0,
		DIFFICULTY_LEVEL_MENU,
		LEADERBOARD_MENU,
		SETTINGS_MENU,
	};

	struct MainMenu {
		MainMenuState state = MainMenuState::MAIN_MENU;

		enum class MainMenuButton {
			START_GAME_BUTTON = 0,
			DIFFICULTY_LEVEL_BUTTON,
			LEADERBOARD_BUTTON,
			SETTINGS_BUTTON,
			EXIT_GAME_BUTTON
		};

		MainMenuButton currentButton = MainMenuButton::START_GAME_BUTTON;
		bool isControlKeyPressed = false;

		DifficultyLevelMenu difficultyLevelMenu;
		SettingsMenu settingsMenu;
		LeaderboardMenu leaderboardMenu;

		sf::Text gameNameText;
		sf::Text startGameText;
		sf::Text difficultyLevelText;
		sf::Text leaderboardText;
		sf::Text settingsText;
		sf::Text exitGameText;

	};

	struct Game;

	void InitMainMenu(MainMenu& mainMenu, const Game& game);
	void UpdateMainMenuButtonsColor(MainMenu& mainMenu);
	void UpdateMainMenuButtonsColor(MainMenu& mainMenu, MainMenu::MainMenuButton lastButton);
	void UpdateMainMenu(MainMenu& mainMenu, Game& game, sf::Window& window);
	void DrawMainMenu(MainMenu& mainMenu, const Game& game, sf::RenderWindow& window);
}

