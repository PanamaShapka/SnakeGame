#include "GameOverMenu.h"
#include "Game.h"

namespace SnakeGame {

	void InitGameOverMenu(GameOverMenu& gameOverMenu, const Game& game)
	{
		gameOverMenu.background.setSize(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
		gameOverMenu.background.setFillColor(sf::Color(0, 0, 0, 127.5f));
		gameOverMenu.background.setPosition(212.5f, 187.5f);
		gameOverMenu.background.setOutlineColor(sf::Color::White);
		gameOverMenu.background.setOutlineThickness(5.f);

		gameOverMenu.finalScoreText.setFont(game.font);
		gameOverMenu.finalScoreText.setCharacterSize(50);
		gameOverMenu.finalScoreText.setFillColor(sf::Color::White);
		std::string finalScoreText = u8"Количество очков:";
		gameOverMenu.finalScoreText.setString(sf::String::fromUtf8(finalScoreText.begin(), finalScoreText.end()));
		gameOverMenu.finalScoreText.setPosition(gameOverMenu.background.getPosition().x + gameOverMenu.background.getGlobalBounds().width / 2 - gameOverMenu.finalScoreText.getGlobalBounds().width / 2, gameOverMenu.background.getPosition().y);

		gameOverMenu.finalScoreNumberText.setFont(game.font);
		gameOverMenu.finalScoreNumberText.setCharacterSize(50);
		gameOverMenu.finalScoreNumberText.setFillColor(sf::Color::White);
		gameOverMenu.finalScoreNumberText.setString("*");
		gameOverMenu.finalScoreNumberText.setPosition(gameOverMenu.background.getPosition().x + gameOverMenu.background.getGlobalBounds().width / 2 - gameOverMenu.finalScoreNumberText.getGlobalBounds().width, gameOverMenu.finalScoreText.getPosition().y + gameOverMenu.finalScoreText.getGlobalBounds().height + 10.f);

		gameOverMenu.restartText.setFont(game.font);
		gameOverMenu.restartText.setCharacterSize(35);
		gameOverMenu.restartText.setFillColor(sf::Color::White);
		std::string restartText = u8"Продолжить игру";
		gameOverMenu.restartText.setString(sf::String::fromUtf8(restartText.begin(), restartText.end()));
		gameOverMenu.restartText.setPosition(gameOverMenu.background.getPosition().x + gameOverMenu.background.getGlobalBounds().width / 2 - gameOverMenu.restartText.getGlobalBounds().width / 2, gameOverMenu.background.getPosition().y + gameOverMenu.background.getGlobalBounds().height - 120.f);
		
		gameOverMenu.exitText.setFont(game.font);
		gameOverMenu.exitText.setCharacterSize(35);
		gameOverMenu.exitText.setFillColor(sf::Color::White);
		std::string exitText = u8"Выйти в меню";
		gameOverMenu.exitText.setString(sf::String::fromUtf8(exitText.begin(), exitText.end()));
		gameOverMenu.exitText.setPosition(gameOverMenu.background.getPosition().x + gameOverMenu.background.getGlobalBounds().width / 2 - gameOverMenu.exitText.getGlobalBounds().width / 2, gameOverMenu.background.getPosition().y + gameOverMenu.background.getGlobalBounds().height - 70.f);

		gameOverMenu.leaderboardText.setFont(game.font);
		gameOverMenu.leaderboardText.setCharacterSize(20);
		gameOverMenu.leaderboardText.setFillColor(sf::Color::White);
		std::string leaderboardText = u8"Таблица лидеров";
		gameOverMenu.leaderboardText.setString(sf::String::fromUtf8(leaderboardText.begin(), leaderboardText.end()));
		gameOverMenu.leaderboardText.setPosition(gameOverMenu.background.getPosition().x + gameOverMenu.background.getGlobalBounds().width / 2 - gameOverMenu.leaderboardText.getGlobalBounds().width / 2, gameOverMenu.finalScoreNumberText.getPosition().y + gameOverMenu.finalScoreNumberText.getGlobalBounds().height + 40.f);

		gameOverMenu.leaderboard.setFont(game.font);
		gameOverMenu.leaderboard.setCharacterSize(20);
		gameOverMenu.leaderboard.setFillColor(sf::Color::White);
		gameOverMenu.leaderboard.setString("*");
		gameOverMenu.leaderboard.setPosition(gameOverMenu.background.getPosition().x + gameOverMenu.background.getGlobalBounds().width / 2 - gameOverMenu.leaderboard.getGlobalBounds().width, gameOverMenu.leaderboardText.getPosition().y + gameOverMenu.leaderboardText.getGlobalBounds().height + 10.f);

		InitNewRecordMenu(gameOverMenu.newRecordMenu, game);
		InitNameInputMenu(gameOverMenu.nameInputMenu, game);
		UpdateGameOverMenuButtonsColor(gameOverMenu);
	}

	void UpdateGameOverMenuLeaderboard(GameOverMenu& gameOverMenu, const Game& game)
	{
		std::string leaderboardText;
		for (Leaderboard::LeaderboardLine currentLine : game.leaderboard.leaderboard) {
			if (currentLine.position > 5) {
				break;
			}

			leaderboardText += (std::to_string(currentLine.position) + ". " + currentLine.name + " : " + std::to_string(currentLine.score) + "\n");
		}
		gameOverMenu.leaderboard.setString(leaderboardText);
		gameOverMenu.leaderboard.setPosition(gameOverMenu.background.getPosition().x + gameOverMenu.background.getGlobalBounds().width / 2 - gameOverMenu.leaderboard.getGlobalBounds().width / 2, gameOverMenu.leaderboard.getPosition().y);

	}

	void UpdateGameOverMenuStates(GameOverMenu& gameOverMenu, const Game& game)
	{
		gameOverMenu.finalScoreNumberText.setString(std::to_string(game.score));
		gameOverMenu.finalScoreNumberText.setPosition(gameOverMenu.background.getPosition().x + gameOverMenu.background.getGlobalBounds().width / 2 - gameOverMenu.finalScoreNumberText.getGlobalBounds().width / 2, gameOverMenu.finalScoreNumberText.getPosition().y);

		gameOverMenu.currentButton = GameOverMenu::GameOverMenuButton::RESTART_BUTTON;
		gameOverMenu.isControlKeyPressed = true;
		UpdateGameOverMenuButtonsColor(gameOverMenu);

		gameOverMenu.state = GameOverMenuState::NEW_RECORD_MENU;
		SetStartNewRecordMenuState(gameOverMenu.newRecordMenu, game);
		SetStartNameInputMenuState(gameOverMenu.nameInputMenu, game);
	}

	void UpdateGameOverMenuButtonsColor(GameOverMenu& gameOverMenu)
	{
		// Set white color to all buttons text
		gameOverMenu.restartText.setFillColor(sf::Color::White);
		gameOverMenu.exitText.setFillColor(sf::Color::White);

		// Set green color to the current button
		switch (gameOverMenu.currentButton)
		{
		case GameOverMenu::GameOverMenuButton::RESTART_BUTTON:
		{
			gameOverMenu.restartText.setFillColor(sf::Color::Green);
			break;
		}
		case GameOverMenu::GameOverMenuButton::EXIT_BUTTON:
		{
			gameOverMenu.exitText.setFillColor(sf::Color::Green);
			break;
		}
		default:
			break;
		}
	}

	void UpdateGameOverMenu(GameOverMenu& gameOverMenu, Game& game)
	{
		switch (gameOverMenu.state)
		{
		case GameOverMenuState::GAME_OVER_MENU:
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				if (!gameOverMenu.isControlKeyPressed) {

					// Set current button
					switch (gameOverMenu.currentButton)
					{
					case GameOverMenu::GameOverMenuButton::RESTART_BUTTON:
					{
						gameOverMenu.currentButton = GameOverMenu::GameOverMenuButton::EXIT_BUTTON;
						break;
					}
					case GameOverMenu::GameOverMenuButton::EXIT_BUTTON:
					{
						gameOverMenu.currentButton = GameOverMenu::GameOverMenuButton::RESTART_BUTTON;
						break;
					}
					default:
						break;
					}
					gameOverMenu.isControlKeyPressed = true;

					UpdateGameOverMenuButtonsColor(gameOverMenu);
					PlayPressKeySound(game);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				if (!gameOverMenu.isControlKeyPressed) {

					// Set current button
					switch (gameOverMenu.currentButton)
					{
					case GameOverMenu::GameOverMenuButton::RESTART_BUTTON:
					{
						gameOverMenu.currentButton = GameOverMenu::GameOverMenuButton::EXIT_BUTTON;
						break;
					}
					case GameOverMenu::GameOverMenuButton::EXIT_BUTTON:
					{
						gameOverMenu.currentButton = GameOverMenu::GameOverMenuButton::RESTART_BUTTON;
						break;
					}
					default:
						break;
					}
					gameOverMenu.isControlKeyPressed = true;

					UpdateGameOverMenuButtonsColor(gameOverMenu);
					PlayPressKeySound(game);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				if (!gameOverMenu.isControlKeyPressed) {
					switch (gameOverMenu.currentButton)
					{
					case GameOverMenu::GameOverMenuButton::RESTART_BUTTON:
					{
						SetStartGameState(game);
						break;
					}
					case GameOverMenu::GameOverMenuButton::EXIT_BUTTON:
					{
						game.state = GameState::MAIN_MENU;
						game.mainMenu.isControlKeyPressed = true;
						UpdateLeaderboardMenuState(game.mainMenu.leaderboardMenu, game);
						game.loseSound.play();
						break;
					}
					default:
						break;
					}
					gameOverMenu.isControlKeyPressed = true;
					PlayPressKeySound(game);
				}
			}
			else {
				gameOverMenu.isControlKeyPressed = false;
			}
			break;
		}
		case GameOverMenuState::NEW_RECORD_MENU:
		{
			UpdateNewRecordMenu(gameOverMenu.newRecordMenu, game);
			break;
		}
		case GameOverMenuState::NAME_INPUT:
		{
			UpdateNameInputMenu(gameOverMenu.nameInputMenu, game);
			break;
		}
		default:
			break;
		}
	}

	void DrawGameOverMenu(GameOverMenu& gameOverMenu, sf::RenderWindow& window)
	{
		switch (gameOverMenu.state) {
		case GameOverMenuState::GAME_OVER_MENU:
		{
			window.draw(gameOverMenu.background);
			window.draw(gameOverMenu.exitText);
			window.draw(gameOverMenu.finalScoreNumberText);
			window.draw(gameOverMenu.finalScoreText);
			window.draw(gameOverMenu.leaderboard);
			window.draw(gameOverMenu.restartText);
			window.draw(gameOverMenu.leaderboardText);
			break;
		}
		case GameOverMenuState::NEW_RECORD_MENU:
		{
			DrawNewRecordMenu(gameOverMenu, window);
			break;
		}
		case GameOverMenuState::NAME_INPUT:
		{
			DrawNameInputMenu(gameOverMenu, window);
			break;
		}
		}
	}


	void InitNewRecordMenu(NewRecordMenu& newRecordMenu, const Game& game)
	{
		newRecordMenu.newRecordText.setFont(game.font);
		newRecordMenu.newRecordText.setCharacterSize(50);
		newRecordMenu.newRecordText.setFillColor(sf::Color::White);
		std::string newRecordText = u8"Ввести имя";
		newRecordMenu.newRecordText.setString(sf::String::fromUtf8(newRecordText.begin(), newRecordText.end()));
		newRecordMenu.newRecordText.setPosition(game.gameOverMenu.background.getPosition().x + game.gameOverMenu.background.getGlobalBounds().width / 2 - newRecordMenu.newRecordText.getGlobalBounds().width / 2, game.gameOverMenu.background.getPosition().y);

		newRecordMenu.yesText.setFont(game.font);
		newRecordMenu.yesText.setCharacterSize(35);
		newRecordMenu.yesText.setFillColor(sf::Color::White);
		std::string yesText = u8"Да";
		newRecordMenu.yesText.setString(sf::String::fromUtf8(yesText.begin(), yesText.end()));
		newRecordMenu.yesText.setPosition(game.gameOverMenu.background.getPosition().x + game.gameOverMenu.background.getGlobalBounds().width / 2 - newRecordMenu.yesText.getGlobalBounds().width / 2, game.gameOverMenu.background.getPosition().y + game.gameOverMenu.background.getGlobalBounds().height / 2 - newRecordMenu.yesText.getGlobalBounds().height / 2 - 15.f);

		newRecordMenu.noText.setFont(game.font);
		newRecordMenu.noText.setCharacterSize(35);
		newRecordMenu.noText.setFillColor(sf::Color::White);
		std::string noText = u8"Нет";
		newRecordMenu.noText.setString(sf::String::fromUtf8(noText.begin(), noText.end()));
		newRecordMenu.noText.setPosition(game.gameOverMenu.background.getPosition().x + game.gameOverMenu.background.getGlobalBounds().width / 2 - newRecordMenu.noText.getGlobalBounds().width / 2, newRecordMenu.yesText.getPosition().y + newRecordMenu.yesText.getGlobalBounds().height + 30.f);

		SetStartNewRecordMenuState(newRecordMenu, game);
	}

	void SetStartNewRecordMenuState(NewRecordMenu& newRecordMenu, const Game& game)
	{
		newRecordMenu.currentButton = NewRecordMenu::NewRecordMenuButton::YES;
		newRecordMenu.isControlKeyPressed = true;
		UpdateNewRecordMenuButtonsColor(newRecordMenu);
	}

	void UpdateNewRecordMenuButtonsColor(NewRecordMenu& newRecordMenu)
	{
		// Set white color to all buttons text
		newRecordMenu.yesText.setFillColor(sf::Color::White);
		newRecordMenu.noText.setFillColor(sf::Color::White);

		// Set green color to the current button
		switch (newRecordMenu.currentButton)
		{
		case NewRecordMenu::NewRecordMenuButton::YES:
		{
			newRecordMenu.yesText.setFillColor(sf::Color::Green);
			break;
		}
		case NewRecordMenu::NewRecordMenuButton::NO:
		{
			newRecordMenu.noText.setFillColor(sf::Color::Green);
			break;
		}
		default:
			break;
		}
	}

	void UpdateNewRecordMenu(NewRecordMenu& newRecordMenu, Game& game)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (!newRecordMenu.isControlKeyPressed) {

				// Set current button
				switch (newRecordMenu.currentButton)
				{
				case NewRecordMenu::NewRecordMenuButton::YES:
				{
					newRecordMenu.currentButton = NewRecordMenu::NewRecordMenuButton::NO;
					break;
				}
				case NewRecordMenu::NewRecordMenuButton::NO:
				{
					newRecordMenu.currentButton = NewRecordMenu::NewRecordMenuButton::YES;
					break;
				}
				default:
					break;
				}
				newRecordMenu.isControlKeyPressed = true;

				UpdateNewRecordMenuButtonsColor(newRecordMenu);
				PlayPressKeySound(game);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (!newRecordMenu.isControlKeyPressed) {

				// Set current button
				switch (newRecordMenu.currentButton)
				{
				case NewRecordMenu::NewRecordMenuButton::YES:
				{
					newRecordMenu.currentButton = NewRecordMenu::NewRecordMenuButton::NO;
					break;
				}
				case NewRecordMenu::NewRecordMenuButton::NO:
				{
					newRecordMenu.currentButton = NewRecordMenu::NewRecordMenuButton::YES;
					break;
				}
				default:
					break;
				}
				newRecordMenu.isControlKeyPressed = true;

				UpdateNewRecordMenuButtonsColor(newRecordMenu);
				PlayPressKeySound(game);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (!newRecordMenu.isControlKeyPressed) {
				switch (newRecordMenu.currentButton)
				{
				case NewRecordMenu::NewRecordMenuButton::YES:
				{
					game.gameOverMenu.state = GameOverMenuState::NAME_INPUT;
					break;
				}
				case NewRecordMenu::NewRecordMenuButton::NO:
				{
					game.gameOverMenu.state = GameOverMenuState::GAME_OVER_MENU;
					UpdateGameOverMenuLeaderboard(game.gameOverMenu, game);
					break;
				}
				default:
					break;
				}
				newRecordMenu.isControlKeyPressed = true;
				PlayPressKeySound(game);
			}
		}
		else {
			newRecordMenu.isControlKeyPressed = false;
		}
	}

	void DrawNewRecordMenu(GameOverMenu& gameOverMenu, sf::RenderWindow& window)
	{
		window.draw(gameOverMenu.background);
		window.draw(gameOverMenu.newRecordMenu.noText);
		window.draw(gameOverMenu.newRecordMenu.yesText);
		window.draw(gameOverMenu.newRecordMenu.newRecordText);
	}


	void InitNameInputMenu(NameInputMenu& nameInputMenu, const Game& game)
	{
		nameInputMenu.inputNameText.setFont(game.font);
		nameInputMenu.inputNameText.setCharacterSize(50);
		nameInputMenu.inputNameText.setFillColor(sf::Color::White);
		std::string inputNameText = u8"Вводите имя";
		nameInputMenu.inputNameText.setString(sf::String::fromUtf8(inputNameText.begin(), inputNameText.end()));
		nameInputMenu.inputNameText.setPosition(game.gameOverMenu.background.getPosition().x + game.gameOverMenu.background.getGlobalBounds().width / 2 - nameInputMenu.inputNameText.getGlobalBounds().width / 2, game.gameOverMenu.background.getPosition().y);

		nameInputMenu.input.setFont(game.font);
		nameInputMenu.input.setCharacterSize(35);
		nameInputMenu.input.setFillColor(sf::Color::White);
		nameInputMenu.input.setString("*");
		nameInputMenu.input.setPosition(game.gameOverMenu.background.getPosition().x + game.gameOverMenu.background.getGlobalBounds().width / 2 - nameInputMenu.inputNameText.getGlobalBounds().width / 2, game.gameOverMenu.background.getPosition().y + game.gameOverMenu.background.getGlobalBounds().height / 2 - nameInputMenu.inputNameText.getGlobalBounds().height / 2);

		nameInputMenu.keyboard.maxInputLength = 24;
	}

	void SetStartNameInputMenuState(NameInputMenu& nameInputMenu, const Game& game)
	{
		nameInputMenu.keyboard.keyboardInput = "";
		nameInputMenu.input.setString(nameInputMenu.keyboard.keyboardInput);
		nameInputMenu.input.setPosition(game.gameOverMenu.background.getPosition().x + game.gameOverMenu.background.getGlobalBounds().width / 2 - nameInputMenu.inputNameText.getGlobalBounds().width / 2, nameInputMenu.input.getPosition().y);
	}

	void UpdateNameInputMenu(NameInputMenu& nameInputMenu, Game& game)
	{
		UpdateKeyboardInput(nameInputMenu.keyboard);

		nameInputMenu.input.setString(nameInputMenu.keyboard.keyboardInput);
		nameInputMenu.input.setPosition(game.gameOverMenu.background.getPosition().x + game.gameOverMenu.background.getGlobalBounds().width / 2 - nameInputMenu.input.getGlobalBounds().width / 2, nameInputMenu.input.getPosition().y);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (!nameInputMenu.isKeyPressed) {
				if (nameInputMenu.keyboard.keyboardInput.length() != 0) {
					game.gameOverMenu.state = GameOverMenuState::GAME_OVER_MENU;

					Leaderboard::LeaderboardLine newRecord;
					newRecord.name = nameInputMenu.keyboard.keyboardInput;
					newRecord.score = game.score;

					AddRecordToLeaderboard(game.leaderboard, newRecord);
					UpdateLeaderboard(game.leaderboard);
					UpdateGameOverMenuLeaderboard(game.gameOverMenu, game);
				}

				nameInputMenu.isKeyPressed = true;
				PlayPressKeySound(game);
			}
		}
		else {
			nameInputMenu.isKeyPressed = false;
		}
	}

	void DrawNameInputMenu(GameOverMenu& gameOverMenu, sf::RenderWindow& window)
	{
		window.draw(gameOverMenu.background);
		window.draw(gameOverMenu.nameInputMenu.inputNameText);
		window.draw(gameOverMenu.nameInputMenu.input);
	}
}
