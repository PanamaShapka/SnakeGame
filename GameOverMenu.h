#pragma once
#include "SFML-2.6.1/include/SFML/Graphics.hpp"
#include "Keyboard.h"

namespace SnakeGame {

	struct Game;
	struct Leaderboard;

	enum class GameOverMenuState {
		GAME_OVER_MENU = 0,
		NEW_RECORD_MENU,
		NAME_INPUT
	};

	struct NameInputMenu {
		Keyboard keyboard;
		bool isKeyPressed;

		sf::Text input;
		sf::Text inputNameText;
	};

	struct NewRecordMenu {
		enum NewRecordMenuButton {
			YES = 0,
			NO
		};

		NewRecordMenuButton currentButton = NewRecordMenuButton::YES;
		bool isControlKeyPressed = false;

		sf::Text yesText;
		sf::Text noText;
		sf::Text newRecordText;
	};

	struct GameOverMenu
	{
		enum GameOverMenuButton{
			EXIT_BUTTON = 0,
			RESTART_BUTTON
		};

		GameOverMenuState state;

		GameOverMenuButton currentButton = GameOverMenuButton::RESTART_BUTTON;
		bool isControlKeyPressed = false;

		sf::RectangleShape background;
		sf::Text finalScoreText;
		sf::Text finalScoreNumberText;
		sf::Text leaderboard;
		sf::Text exitText;
		sf::Text restartText;
		sf::Text leaderboardText;

		NewRecordMenu newRecordMenu;
		NameInputMenu nameInputMenu;
	};

	void InitGameOverMenu(GameOverMenu& gameOverMenu, const Game& game);
	void UpdateGameOverMenuLeaderboard(GameOverMenu& gameOverMenu, const Game& game);
	void UpdateGameOverMenuStates(GameOverMenu& gameOverMenu, const Game& game);
	void UpdateGameOverMenuButtonsColor(GameOverMenu& gameOverMenu);
	void UpdateGameOverMenuButtonsColor(GameOverMenu& gameOverMenu, GameOverMenu::GameOverMenuButton lastButton);
	void UpdateGameOverMenu(GameOverMenu& gameOverMenu, Game& game);
	void DrawGameOverMenu(GameOverMenu& gameOverMenu, sf::RenderWindow& window);

	void InitNewRecordMenu(NewRecordMenu& newRecordMenu, const Game& game);
	void SetStartNewRecordMenuState(NewRecordMenu& newRecordMenu, const Game& game);
	void UpdateNewRecordMenuButtonsColor(NewRecordMenu& newRecordMenu);
	void UpdateNewRecordMenuButtonsColor(NewRecordMenu& newRecordMenu, NewRecordMenu::NewRecordMenuButton lastButton);
	void UpdateNewRecordMenu(NewRecordMenu& newRecordMenu, Game& game);
	void DrawNewRecordMenu(GameOverMenu& gameOverMenu, sf::RenderWindow& window);

	void InitNameInputMenu(NameInputMenu& nameInputMenu, const Game& game);
	void SetStartNameInputMenuState(NameInputMenu& nameInputMenu, const Game& game);
	void UpdateNameInputMenu(NameInputMenu& nameInputMenu, Game& game);
	void DrawNameInputMenu(GameOverMenu& gameOverMenu, sf::RenderWindow& window);
}

