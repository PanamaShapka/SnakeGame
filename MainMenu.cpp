#include "MainMenu.h"
#include "Game.h"

namespace SnakeGame {

	void InitMainMenu(MainMenu& mainMenu, const Game& game)
	{
		mainMenu.gameNameText.setFont(game.font);
		mainMenu.gameNameText.setCharacterSize(100);
		mainMenu.gameNameText.setFillColor(sf::Color::White);
		std::string gameNameText = u8"Змейка";
		mainMenu.gameNameText.setString(sf::String::fromUtf8(gameNameText.begin(), gameNameText.end()));
		mainMenu.gameNameText.setPosition(SCREEN_WIDTH / 2 - mainMenu.gameNameText.getGlobalBounds().width / 2, 75.f);

		mainMenu.startGameText.setFont(game.font);
		mainMenu.startGameText.setCharacterSize(35);
		mainMenu.startGameText.setFillColor(sf::Color::White);
		std::string startGameText = u8"Начать игру";
		mainMenu.startGameText.setString(sf::String::fromUtf8(startGameText.begin(), startGameText.end()));
		mainMenu.startGameText.setPosition(SCREEN_WIDTH / 2 - mainMenu.startGameText.getGlobalBounds().width / 2, 250.f);

		mainMenu.difficultyLevelText.setFont(game.font);
		mainMenu.difficultyLevelText.setCharacterSize(35);
		mainMenu.difficultyLevelText.setFillColor(sf::Color::White);
		std::string difficultyLevelText = u8"Уровень сложности";
		mainMenu.difficultyLevelText.setString(sf::String::fromUtf8(difficultyLevelText.begin(), difficultyLevelText.end()));
		mainMenu.difficultyLevelText.setPosition(SCREEN_WIDTH / 2 - mainMenu.difficultyLevelText.getGlobalBounds().width / 2, 300.f);

		mainMenu.leaderboardText.setFont(game.font);
		mainMenu.leaderboardText.setCharacterSize(35);
		mainMenu.leaderboardText.setFillColor(sf::Color::White);
		std::string leaderboardText = u8"Таблица лидеров";
		mainMenu.leaderboardText.setString(sf::String::fromUtf8(leaderboardText.begin(), leaderboardText.end()));
		mainMenu.leaderboardText.setPosition(SCREEN_WIDTH / 2 - mainMenu.leaderboardText.getGlobalBounds().width / 2, 350.f);

		mainMenu.settingsText.setFont(game.font);
		mainMenu.settingsText.setCharacterSize(35);
		mainMenu.settingsText.setFillColor(sf::Color::White);
		std::string settingsText = u8"Настройки";
		mainMenu.settingsText.setString(sf::String::fromUtf8(settingsText.begin(), settingsText.end()));
		mainMenu.settingsText.setPosition(SCREEN_WIDTH / 2 - mainMenu.settingsText.getGlobalBounds().width / 2, 400.f);

		mainMenu.exitGameText.setFont(game.font);
		mainMenu.exitGameText.setCharacterSize(35);
		mainMenu.exitGameText.setFillColor(sf::Color::White);
		std::string exitGameText = u8"Выход";
		mainMenu.exitGameText.setString(sf::String::fromUtf8(exitGameText.begin(), exitGameText.end()));
		mainMenu.exitGameText.setPosition(SCREEN_WIDTH / 2 - mainMenu.exitGameText.getGlobalBounds().width / 2, 450.f);

		UpdateMainMenuButtonsColor(mainMenu);

		InitDifficultyLevelMenu(mainMenu.difficultyLevelMenu, game);
		InitSettingsMenu(mainMenu.settingsMenu, game);
		InitLeaderboardMenu(mainMenu.leaderboardMenu, game);
	}

	void UpdateMainMenuButtonsColor(MainMenu& mainMenu)
	{
		switch (mainMenu.currentButton)
		{
		case MainMenu::MainMenuButton::START_GAME_BUTTON:
		{
			mainMenu.startGameText.setFillColor(sf::Color::Green);

			break;
		}
		case MainMenu::MainMenuButton::DIFFICULTY_LEVEL_BUTTON:
		{
			mainMenu.difficultyLevelText.setFillColor(sf::Color::Green);
			break;
		}
		case MainMenu::MainMenuButton::LEADERBOARD_BUTTON:
		{
			mainMenu.leaderboardText.setFillColor(sf::Color::Green);
			break;
		}
		case MainMenu::MainMenuButton::SETTINGS_BUTTON:
		{
			mainMenu.settingsText.setFillColor(sf::Color::Green);
			break;
		}
		case MainMenu::MainMenuButton::EXIT_GAME_BUTTON:
		{
			mainMenu.exitGameText.setFillColor(sf::Color::Green);
			break;
		}
		default:
			break;
		}
	}

	void UpdateMainMenuButtonsColor(MainMenu& mainMenu, MainMenu::MainMenuButton lastButton)
	{
		switch (mainMenu.currentButton)
		{
		case MainMenu::MainMenuButton::START_GAME_BUTTON:
		{
			mainMenu.startGameText.setFillColor(sf::Color::Green);
			break;
		}
		case MainMenu::MainMenuButton::DIFFICULTY_LEVEL_BUTTON:
		{
			mainMenu.difficultyLevelText.setFillColor(sf::Color::Green);
			break;
		}
		case MainMenu::MainMenuButton::LEADERBOARD_BUTTON:
		{
			mainMenu.leaderboardText.setFillColor(sf::Color::Green);
			break;
		}
		case MainMenu::MainMenuButton::SETTINGS_BUTTON:
		{
			mainMenu.settingsText.setFillColor(sf::Color::Green);
			break;
		}
		case MainMenu::MainMenuButton::EXIT_GAME_BUTTON:
		{
			mainMenu.exitGameText.setFillColor(sf::Color::Green);
			break;
		}
		default:
			break;
		}

		switch (lastButton)
		{
		case MainMenu::MainMenuButton::START_GAME_BUTTON:
		{
			mainMenu.startGameText.setFillColor(sf::Color::White);
			break;
		}
		case MainMenu::MainMenuButton::DIFFICULTY_LEVEL_BUTTON:
		{
			mainMenu.difficultyLevelText.setFillColor(sf::Color::White);
			break;
		}
		case MainMenu::MainMenuButton::LEADERBOARD_BUTTON:
		{
			mainMenu.leaderboardText.setFillColor(sf::Color::White);
			break;
		}
		case MainMenu::MainMenuButton::SETTINGS_BUTTON:
		{
			mainMenu.settingsText.setFillColor(sf::Color::White);
			break;
		}
		case MainMenu::MainMenuButton::EXIT_GAME_BUTTON:
		{
			mainMenu.exitGameText.setFillColor(sf::Color::White);
			break;
		}
		default:
			break;
		}
	}

	void UpdateMainMenu(MainMenu& mainMenu, Game& game, sf::Window& window)
	{
		switch (mainMenu.state) {
		case MainMenuState::MAIN_MENU:
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				if (!mainMenu.isControlKeyPressed) {
					switch (mainMenu.currentButton)
					{
					case MainMenu::MainMenuButton::START_GAME_BUTTON:
					{
						mainMenu.currentButton = MainMenu::MainMenuButton::DIFFICULTY_LEVEL_BUTTON;
						UpdateMainMenuButtonsColor(mainMenu, MainMenu::MainMenuButton::START_GAME_BUTTON);
						break;
					}
					case MainMenu::MainMenuButton::DIFFICULTY_LEVEL_BUTTON:
					{
						mainMenu.currentButton = MainMenu::MainMenuButton::LEADERBOARD_BUTTON;
						UpdateMainMenuButtonsColor(mainMenu, MainMenu::MainMenuButton::DIFFICULTY_LEVEL_BUTTON);
						break;
					}
					case MainMenu::MainMenuButton::LEADERBOARD_BUTTON:
					{
						mainMenu.currentButton = MainMenu::MainMenuButton::SETTINGS_BUTTON;
						UpdateMainMenuButtonsColor(mainMenu, MainMenu::MainMenuButton::LEADERBOARD_BUTTON);
						break;
					}
					case MainMenu::MainMenuButton::SETTINGS_BUTTON:
					{
						mainMenu.currentButton = MainMenu::MainMenuButton::EXIT_GAME_BUTTON;
						UpdateMainMenuButtonsColor(mainMenu, MainMenu::MainMenuButton::SETTINGS_BUTTON);
						break;
					}
					case MainMenu::MainMenuButton::EXIT_GAME_BUTTON:
					{
						mainMenu.currentButton = MainMenu::MainMenuButton::START_GAME_BUTTON;
						UpdateMainMenuButtonsColor(mainMenu, MainMenu::MainMenuButton::EXIT_GAME_BUTTON);
						break;
					}
					default:
						break;
					}
					mainMenu.isControlKeyPressed = true;
					PlayPressKeySound(game);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				if (!mainMenu.isControlKeyPressed) {
					switch (mainMenu.currentButton)
					{
					case MainMenu::MainMenuButton::START_GAME_BUTTON:
					{
						mainMenu.currentButton = MainMenu::MainMenuButton::EXIT_GAME_BUTTON;
						UpdateMainMenuButtonsColor(mainMenu, MainMenu::MainMenuButton::START_GAME_BUTTON);
						break;
					}
					case MainMenu::MainMenuButton::DIFFICULTY_LEVEL_BUTTON:
					{
						mainMenu.currentButton = MainMenu::MainMenuButton::START_GAME_BUTTON;
						UpdateMainMenuButtonsColor(mainMenu, MainMenu::MainMenuButton::DIFFICULTY_LEVEL_BUTTON);
						break;
					}
					case MainMenu::MainMenuButton::LEADERBOARD_BUTTON:
					{
						mainMenu.currentButton = MainMenu::MainMenuButton::DIFFICULTY_LEVEL_BUTTON;
						UpdateMainMenuButtonsColor(mainMenu, MainMenu::MainMenuButton::LEADERBOARD_BUTTON);
						break;
					}
					case MainMenu::MainMenuButton::SETTINGS_BUTTON:
					{
						mainMenu.currentButton = MainMenu::MainMenuButton::LEADERBOARD_BUTTON;
						UpdateMainMenuButtonsColor(mainMenu, MainMenu::MainMenuButton::SETTINGS_BUTTON);
						break;
					}
					case MainMenu::MainMenuButton::EXIT_GAME_BUTTON:
					{
						mainMenu.currentButton = MainMenu::MainMenuButton::SETTINGS_BUTTON;
						UpdateMainMenuButtonsColor(mainMenu, MainMenu::MainMenuButton::EXIT_GAME_BUTTON);
						break;
					}
					default:
						break;
					}
					mainMenu.isControlKeyPressed = true;
					PlayPressKeySound(game);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				if (!mainMenu.isControlKeyPressed) {
					switch (mainMenu.currentButton)
					{
					case MainMenu::MainMenuButton::START_GAME_BUTTON:
					{
						SetStartGameState(game);
						break;
					}
					case MainMenu::MainMenuButton::DIFFICULTY_LEVEL_BUTTON:
					{
						mainMenu.state = MainMenuState::DIFFICULTY_LEVEL_MENU;
						mainMenu.difficultyLevelMenu.isControlKeyPressed = true;
						break;
					}
					case MainMenu::MainMenuButton::LEADERBOARD_BUTTON:
					{
						mainMenu.state = MainMenuState::LEADERBOARD_MENU;
						mainMenu.leaderboardMenu.isControlKeyPressed = true;
						break;
					}
					case MainMenu::MainMenuButton::SETTINGS_BUTTON:
					{
						mainMenu.state = MainMenuState::SETTINGS_MENU;
						mainMenu.settingsMenu.isControlKeyPressed = true;
						break;
					}
					case MainMenu::MainMenuButton::EXIT_GAME_BUTTON:
					{
						ExitGame(window);
						break;
					}
					default:
						break;
					}
					mainMenu.isControlKeyPressed = true;
					PlayPressKeySound(game);
				}
			}
			else {
				mainMenu.isControlKeyPressed = false;
			}
			break;
		}
		case MainMenuState::DIFFICULTY_LEVEL_MENU:
		{
			UpdateDifficultyLevelMenu(mainMenu.difficultyLevelMenu, game);
			break;
		}
		case MainMenuState::SETTINGS_MENU:
		{
			UpdateSettingsMenu(mainMenu.settingsMenu, game);
			break;
		}
		case MainMenuState::LEADERBOARD_MENU:
		{
			UpdateLeaderboardMenu(mainMenu.leaderboardMenu, game);
			break;
		}
		}
	}

	void DrawMainMenu(MainMenu& mainMenu, const Game& game, sf::RenderWindow& window)
	{
		switch (mainMenu.state)
		{
		case MainMenuState::MAIN_MENU:
		{
			window.draw(mainMenu.gameNameText);
			window.draw(mainMenu.startGameText);
			window.draw(mainMenu.difficultyLevelText);
			window.draw(mainMenu.leaderboardText);
			window.draw(mainMenu.settingsText);
			window.draw(mainMenu.exitGameText);
			break;
		}
		case MainMenuState::DIFFICULTY_LEVEL_MENU:
		{
			DrawDifficultyLevelMenu(mainMenu.difficultyLevelMenu, window);
			break;
		}
		case MainMenuState::SETTINGS_MENU:
		{
			DrawSettingsMenu(mainMenu.settingsMenu, game, window);
			break;
		}
		case MainMenuState::LEADERBOARD_MENU:
		{
			DrawLeaderboardMenu(mainMenu.leaderboardMenu, window);
			break;

		}
		default:
			break;
		}
		

	}
}
