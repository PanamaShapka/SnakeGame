#include "PauseMenu.h"
#include "Game.h"

namespace SnakeGame {

	void InitPauseMenu(PauseMenu& pauseMenu, const Game& game)
	{
		pauseMenu.background.setSize(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
		pauseMenu.background.setFillColor(sf::Color(0, 0, 0, 127.5f));
		pauseMenu.background.setPosition(212.5f, 187.5f);
		pauseMenu.background.setOutlineColor(sf::Color::White);
		pauseMenu.background.setOutlineThickness(5.f);

		pauseMenu.pauseText.setFont(game.font);
		pauseMenu.pauseText.setCharacterSize(50);
		pauseMenu.pauseText.setFillColor(sf::Color::White);
		std::string pauseText = u8"Пауза";
		pauseMenu.pauseText.setString(sf::String::fromUtf8(pauseText.begin(), pauseText.end()));
		pauseMenu.pauseText.setPosition(game.gameOverMenu.background.getPosition().x + game.gameOverMenu.background.getGlobalBounds().width / 2 - pauseMenu.pauseText.getGlobalBounds().width / 2, game.gameOverMenu.background.getPosition().y);

		pauseMenu.continueText.setFont(game.font);
		pauseMenu.continueText.setCharacterSize(35);
		pauseMenu.continueText.setFillColor(sf::Color::White);
		std::string continueText = u8"Продолжить";
		pauseMenu.continueText.setString(sf::String::fromUtf8(continueText.begin(), continueText.end()));
		pauseMenu.continueText.setPosition(game.gameOverMenu.background.getPosition().x + game.gameOverMenu.background.getGlobalBounds().width / 2 - pauseMenu.continueText.getGlobalBounds().width / 2, game.gameOverMenu.background.getPosition().y + game.gameOverMenu.background.getGlobalBounds().height / 2 - pauseMenu.continueText.getGlobalBounds().height / 2 - 15.f);

		pauseMenu.exitToMenuText.setFont(game.font);
		pauseMenu.exitToMenuText.setCharacterSize(35);
		pauseMenu.exitToMenuText.setFillColor(sf::Color::White);
		std::string exitToMenuText = u8"Выйти в меню";
		pauseMenu.exitToMenuText.setString(sf::String::fromUtf8(exitToMenuText.begin(), exitToMenuText.end()));
		pauseMenu.exitToMenuText.setPosition(game.gameOverMenu.background.getPosition().x + game.gameOverMenu.background.getGlobalBounds().width / 2 - pauseMenu.exitToMenuText.getGlobalBounds().width / 2, pauseMenu.continueText.getPosition().y + pauseMenu.continueText.getGlobalBounds().height + 30.f);

		SetStartPauseMenuState(pauseMenu);
	}

	void SetStartPauseMenuState(PauseMenu& pauseMenu)
	{
		pauseMenu.currentButton = PauseMenu::PauseMenuButton::CONTINUE_BUTTON;
		UpdatePauseMenuButtonsColor(pauseMenu);
	}

	void UpdatePauseMenuButtonsColor(PauseMenu& pauseMenu)
	{
		switch (pauseMenu.currentButton)
		{
		case PauseMenu::PauseMenuButton::CONTINUE_BUTTON:
		{
			pauseMenu.continueText.setFillColor(sf::Color::Green);
			pauseMenu.exitToMenuText.setFillColor(sf::Color::White);
			break;
		}
		case PauseMenu::PauseMenuButton::EXIT_TO_MENU_BUTTON:
		{
			pauseMenu.exitToMenuText.setFillColor(sf::Color::Green);
			pauseMenu.continueText.setFillColor(sf::Color::White);
			break;
		}
		default:
			break;
		}
	}

	void UpdatePauseMenuButtonsColor(PauseMenu& pauseMenu, PauseMenu::PauseMenuButton lastButton)
	{
		switch (pauseMenu.currentButton)
		{
		case PauseMenu::PauseMenuButton::CONTINUE_BUTTON:
		{
			pauseMenu.continueText.setFillColor(sf::Color::Green);
			break;
		}
		case PauseMenu::PauseMenuButton::EXIT_TO_MENU_BUTTON:
		{
			pauseMenu.exitToMenuText.setFillColor(sf::Color::Green);
			break;
		}
		default:
			break;
		}

		switch (lastButton)
		{
		case PauseMenu::PauseMenuButton::CONTINUE_BUTTON:
		{
			pauseMenu.continueText.setFillColor(sf::Color::White);
			break;
		}
		case PauseMenu::PauseMenuButton::EXIT_TO_MENU_BUTTON:
		{
			pauseMenu.exitToMenuText.setFillColor(sf::Color::White);
			break;
		}
		default:
			break;
		}
	}

	void UpdatePauseMenu(PauseMenu& pauseMenu, Game& game)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (!pauseMenu.isKeyPressed) {
				switch (pauseMenu.currentButton)
				{
				case  PauseMenu::PauseMenuButton::CONTINUE_BUTTON:
				{
					pauseMenu.currentButton = PauseMenu::PauseMenuButton::EXIT_TO_MENU_BUTTON;
					UpdatePauseMenuButtonsColor(pauseMenu, PauseMenu::PauseMenuButton::CONTINUE_BUTTON);
					break;
				}
				case  PauseMenu::PauseMenuButton::EXIT_TO_MENU_BUTTON:
				{
					pauseMenu.currentButton = PauseMenu::PauseMenuButton::CONTINUE_BUTTON;
					UpdatePauseMenuButtonsColor(pauseMenu, PauseMenu::PauseMenuButton::EXIT_TO_MENU_BUTTON);
					break;
				}
				default:
					break;
				}
				pauseMenu.isKeyPressed = true;
				PlayPressKeySound(game);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (!pauseMenu.isKeyPressed) {
				switch (pauseMenu.currentButton)
				{
				case  PauseMenu::PauseMenuButton::CONTINUE_BUTTON:
				{
					pauseMenu.currentButton = PauseMenu::PauseMenuButton::EXIT_TO_MENU_BUTTON;
					UpdatePauseMenuButtonsColor(pauseMenu, PauseMenu::PauseMenuButton::CONTINUE_BUTTON);
					break;
				}
				case  PauseMenu::PauseMenuButton::EXIT_TO_MENU_BUTTON:
				{
					pauseMenu.currentButton = PauseMenu::PauseMenuButton::CONTINUE_BUTTON;
					UpdatePauseMenuButtonsColor(pauseMenu, PauseMenu::PauseMenuButton::EXIT_TO_MENU_BUTTON);
					break;
				}
				default:
					break;
				}
				pauseMenu.isKeyPressed = true;
				PlayPressKeySound(game);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (!pauseMenu.isKeyPressed) {
				switch (pauseMenu.currentButton)
				{
				case  PauseMenu::PauseMenuButton::CONTINUE_BUTTON:
				{
					game.state = GameState::PLAYING;
					PlayPressKeySound(game);

					sf::sleep(sf::seconds(DELAY_AFTER_PAUSE));

					if (game.currentSettings.musicSetting) {
						game.backgroundMusic.play();
						game.backgroundMusic.setLoop(true);
					}
					break;
				}
				case  PauseMenu::PauseMenuButton::EXIT_TO_MENU_BUTTON:
				{
					game.state = GameState::MAIN_MENU;
					game.mainMenu.isControlKeyPressed = true;
					PlayPressKeySound(game);
					game.loseSound.play();
					UpdateLeaderboardMenuState(game.mainMenu.leaderboardMenu, game);
					break;
				}
				default:
					break;
				}
				pauseMenu.isKeyPressed = true;
			}
		}
		else {
			pauseMenu.isKeyPressed = false;
		}
	}

	void DrawPauseMenu(PauseMenu& pauseMenu, sf::RenderWindow& window)
	{
		window.draw(pauseMenu.background);
		window.draw(pauseMenu.pauseText);
		window.draw(pauseMenu.continueText);
		window.draw(pauseMenu.exitToMenuText);
	}

}
