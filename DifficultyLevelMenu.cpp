#include "DifficultyLevelMenu.h"
#include "Game.h"

namespace SnakeGame {

	void InitDifficultyLevelMenu(DifficultyLevelMenu& difficultyLevelMenu, const Game& game)
	{
		difficultyLevelMenu.difficultyLevelText.setFont(game.font);
		difficultyLevelMenu.difficultyLevelText.setCharacterSize(75);
		difficultyLevelMenu.difficultyLevelText.setFillColor(sf::Color::White);
		std::string difficultyLevelText = u8"Уровень сложности";
		difficultyLevelMenu.difficultyLevelText.setString(sf::String::fromUtf8(difficultyLevelText.begin(), difficultyLevelText.end()));
		difficultyLevelMenu.difficultyLevelText.setPosition(SCREEN_WIDTH / 2 - difficultyLevelMenu.difficultyLevelText.getGlobalBounds().width / 2, 75.f);

		difficultyLevelMenu.difficultyLevel_1Text.setFont(game.font);
		difficultyLevelMenu.difficultyLevel_1Text.setCharacterSize(35);
		difficultyLevelMenu.difficultyLevel_1Text.setFillColor(sf::Color::White);
		std::string difficultyLevel_1Text = u8"Простой";
		difficultyLevelMenu.difficultyLevel_1Text.setString(sf::String::fromUtf8(difficultyLevel_1Text.begin(), difficultyLevel_1Text.end()));
		difficultyLevelMenu.difficultyLevel_1Text.setPosition(400.f, 250.f);

		difficultyLevelMenu.difficultyLevel_2Text.setFont(game.font);
		difficultyLevelMenu.difficultyLevel_2Text.setCharacterSize(35);
		difficultyLevelMenu.difficultyLevel_2Text.setFillColor(sf::Color::White);
		std::string difficultyLevel_2Text = u8"Тяжелее простого";
		difficultyLevelMenu.difficultyLevel_2Text.setString(sf::String::fromUtf8(difficultyLevel_2Text.begin(), difficultyLevel_2Text.end()));
		difficultyLevelMenu.difficultyLevel_2Text.setPosition(400.f, 300.f);

		difficultyLevelMenu.difficultyLevel_3Text.setFont(game.font);
		difficultyLevelMenu.difficultyLevel_3Text.setCharacterSize(35);
		difficultyLevelMenu.difficultyLevel_3Text.setFillColor(sf::Color::White);
		std::string difficultyLevel_3Text = u8"Средний";
		difficultyLevelMenu.difficultyLevel_3Text.setString(sf::String::fromUtf8(difficultyLevel_3Text.begin(), difficultyLevel_3Text.end()));
		difficultyLevelMenu.difficultyLevel_3Text.setPosition(400.f, 350.f);

		difficultyLevelMenu.difficultyLevel_4Text.setFont(game.font);
		difficultyLevelMenu.difficultyLevel_4Text.setCharacterSize(35);
		difficultyLevelMenu.difficultyLevel_4Text.setFillColor(sf::Color::White);
		std::string difficultyLevel_4Text = u8"Легче тяжёлого";
		difficultyLevelMenu.difficultyLevel_4Text.setString(sf::String::fromUtf8(difficultyLevel_4Text.begin(), difficultyLevel_4Text.end()));
		difficultyLevelMenu.difficultyLevel_4Text.setPosition(400.f, 400.f);

		difficultyLevelMenu.difficultyLevel_5Text.setFont(game.font);
		difficultyLevelMenu.difficultyLevel_5Text.setCharacterSize(35);
		difficultyLevelMenu.difficultyLevel_5Text.setFillColor(sf::Color::White);
		std::string difficultyLevel_5Text = u8"Тяжёлый";
		difficultyLevelMenu.difficultyLevel_5Text.setString(sf::String::fromUtf8(difficultyLevel_5Text.begin(), difficultyLevel_5Text.end()));
		difficultyLevelMenu.difficultyLevel_5Text.setPosition(400.f, 450.f);

		difficultyLevelMenu.checkMark.setTexture(game.checkMarkTexture);
		SetSpriteSize(difficultyLevelMenu.checkMark, 35.f, 35.f);
		difficultyLevelMenu.checkMark.setPosition(750.f, difficultyLevelMenu.difficultyLevel_1Text.getPosition().y);

		UpdateDifficultyLevelMenuButtonsColor(difficultyLevelMenu);
	}

	void UpdateCheckMark(DifficultyLevelMenu& difficultyLevelMenu)
	{
		switch (difficultyLevelMenu.currentButton)
		{
		case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_1:
		{
			difficultyLevelMenu.checkMark.setPosition(750.f, difficultyLevelMenu.difficultyLevel_1Text.getPosition().y);
			break;
		}
		case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_2:
		{
			difficultyLevelMenu.checkMark.setPosition(750.f, difficultyLevelMenu.difficultyLevel_2Text.getPosition().y);
			break;
		}
		case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_3:
		{
			difficultyLevelMenu.checkMark.setPosition(750.f, difficultyLevelMenu.difficultyLevel_3Text.getPosition().y);
			break;
		}
		case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_4:
		{
			difficultyLevelMenu.checkMark.setPosition(750.f, difficultyLevelMenu.difficultyLevel_4Text.getPosition().y);
			break;
		}
		case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_5:
		{
			difficultyLevelMenu.checkMark.setPosition(750.f, difficultyLevelMenu.difficultyLevel_5Text.getPosition().y);
			break;
		}
		default:
			break;
		}
	}

	void UpdateDifficultyLevelMenuButtonsColor(DifficultyLevelMenu& difficultyLevelMenu)
	{
		// Set white color to all buttons text
		difficultyLevelMenu.difficultyLevel_1Text.setFillColor(sf::Color::White);
		difficultyLevelMenu.difficultyLevel_2Text.setFillColor(sf::Color::White);
		difficultyLevelMenu.difficultyLevel_3Text.setFillColor(sf::Color::White);
		difficultyLevelMenu.difficultyLevel_4Text.setFillColor(sf::Color::White);
		difficultyLevelMenu.difficultyLevel_5Text.setFillColor(sf::Color::White);

		// Set green color to the current button
		switch (difficultyLevelMenu.currentButton)
		{
		case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_1:
		{
			difficultyLevelMenu.difficultyLevel_1Text.setFillColor(sf::Color::Green);
			break;
		}
		case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_2:
		{
			difficultyLevelMenu.difficultyLevel_2Text.setFillColor(sf::Color::Green);
			break;
		}
		case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_3:
		{
			difficultyLevelMenu.difficultyLevel_3Text.setFillColor(sf::Color::Green);
			break;
		}
		case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_4:
		{
			difficultyLevelMenu.difficultyLevel_4Text.setFillColor(sf::Color::Green);
			break;
		}
		case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_5:
		{
			difficultyLevelMenu.difficultyLevel_5Text.setFillColor(sf::Color::Green);
			break;
		}
		default:
			break;
		}
	}

	void UpdateDifficultyLevelMenu(DifficultyLevelMenu& difficultyLevelMenu, Game& game)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (!difficultyLevelMenu.isControlKeyPressed) {

				// Set current button
				switch (difficultyLevelMenu.currentButton)
				{
				case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_1:
				{
					difficultyLevelMenu.currentButton = DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_2;
					break;
				}
				case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_2:
				{
					difficultyLevelMenu.currentButton = DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_3;
					break;
				}
				case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_3:
				{
					difficultyLevelMenu.currentButton = DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_4;
					break;
				}
				case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_4:
				{
					difficultyLevelMenu.currentButton = DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_5;
					break;
				}
				case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_5:
				{
					difficultyLevelMenu.currentButton = DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_1;
					break;
				}
				default:
					break;
				}
				difficultyLevelMenu.isControlKeyPressed = true;

				UpdateDifficultyLevelMenuButtonsColor(difficultyLevelMenu);
				PlayPressKeySound(game);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (!difficultyLevelMenu.isControlKeyPressed) {

				// Set current button
				switch (difficultyLevelMenu.currentButton)
				{
				case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_1:
				{
					difficultyLevelMenu.currentButton = DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_5;
					break;
				}
				case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_2:
				{
					difficultyLevelMenu.currentButton = DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_1;	
					break;
				}
				case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_3:
				{
					difficultyLevelMenu.currentButton = DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_2;
					break;
				}
				case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_4:
				{
					difficultyLevelMenu.currentButton = DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_3;
					break;
				}
				case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_5:
				{
					difficultyLevelMenu.currentButton = DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_4;
					break;
				}
				default:
					break;
				}
				difficultyLevelMenu.isControlKeyPressed = true;

				UpdateDifficultyLevelMenuButtonsColor(difficultyLevelMenu);
				PlayPressKeySound(game);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (!difficultyLevelMenu.isControlKeyPressed) {

				// Update game difficulty
				switch (difficultyLevelMenu.currentButton)
				{
				case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_1:
				{
					UpdateGameDifficulty(game, DIFFICULTY_LEVEL_1);
					break;
				}
				case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_2:
				{
					UpdateGameDifficulty(game, DIFFICULTY_LEVEL_2);
					break;
				}
				case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_3:
				{
					UpdateGameDifficulty(game, DIFFICULTY_LEVEL_3);
					break;
				}
				case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_4:
				{
					UpdateGameDifficulty(game, DIFFICULTY_LEVEL_4);
					break;
				}
				case DifficultyLevelMenu::SettingsMenuButton::DIFFICULTY_LEVEL_5:
				{
					UpdateGameDifficulty(game, DIFFICULTY_LEVEL_5);
					break;
				}
				default:
					break;
				}
				UpdateCheckMark(difficultyLevelMenu);
				difficultyLevelMenu.isControlKeyPressed = true;
				PlayPressKeySound(game);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
			if (!difficultyLevelMenu.isControlKeyPressed) {
				game.mainMenu.state = MainMenuState::MAIN_MENU;
				difficultyLevelMenu.isControlKeyPressed = true;
				PlayPressKeySound(game);
			}
		}	
		else {
			difficultyLevelMenu.isControlKeyPressed = false;
		}
	}

	void DrawDifficultyLevelMenu(DifficultyLevelMenu& difficultyLevelMenu, sf::RenderWindow& window)
	{
		window.draw(difficultyLevelMenu.difficultyLevelText);
		window.draw(difficultyLevelMenu.checkMark);
		window.draw(difficultyLevelMenu.difficultyLevel_1Text);
		window.draw(difficultyLevelMenu.difficultyLevel_2Text);
		window.draw(difficultyLevelMenu.difficultyLevel_3Text);
		window.draw(difficultyLevelMenu.difficultyLevel_4Text);
		window.draw(difficultyLevelMenu.difficultyLevel_5Text);
	}
	
}