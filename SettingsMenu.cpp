#include "SettingsMenu.h"
#include "Game.h"

namespace SnakeGame {

	void InitSettingsMenu(SettingsMenu& settingsMenu, const Game& game)
	{
		settingsMenu.settingsText.setFont(game.font);
		settingsMenu.settingsText.setCharacterSize(75);
		settingsMenu.settingsText.setFillColor(sf::Color::White);
		std::string settingsText = u8"Настройки";
		settingsMenu.settingsText.setString(sf::String::fromUtf8(settingsText.begin(), settingsText.end()));
		settingsMenu.settingsText.setPosition(SCREEN_WIDTH / 2 - settingsMenu.settingsText.getGlobalBounds().width / 2, 75.f);

		settingsMenu.musicText.setFont(game.font);
		settingsMenu.musicText.setCharacterSize(35);
		settingsMenu.musicText.setFillColor(sf::Color::White);
		std::string musicText = u8"Музыка";
		settingsMenu.musicText.setString(sf::String::fromUtf8(musicText.begin(), musicText.end()));
		settingsMenu.musicText.setPosition(400.f, 250.f);

		settingsMenu.sfxText.setFont(game.font);
		settingsMenu.sfxText.setCharacterSize(35);
		settingsMenu.sfxText.setFillColor(sf::Color::White);
		std::string sfxText = u8"Звуки";
		settingsMenu.sfxText.setString(sf::String::fromUtf8(sfxText.begin(), sfxText.end()));
		settingsMenu.sfxText.setPosition(400.f, 300.f);

		settingsMenu.checkMarkMusicButton.setTexture(game.checkMarkTexture);
		SetSpriteSize(settingsMenu.checkMarkMusicButton, 35.f, 35.f);
		settingsMenu.checkMarkMusicButton.setPosition(750.f, settingsMenu.musicText.getPosition().y);

		settingsMenu.checkMarkSfxButton.setTexture(game.checkMarkTexture);
		SetSpriteSize(settingsMenu.checkMarkSfxButton, 35.f, 35.f);
		settingsMenu.checkMarkSfxButton.setPosition(750.f, settingsMenu.sfxText.getPosition().y);

		UpdateSettingsMenuButtonsColor(settingsMenu);
	}

	void UpdateSettingsMenuButtonsColor(SettingsMenu& settingsMenu)
	{
		// Set white color to all buttons text
		settingsMenu.musicText.setFillColor(sf::Color::White);
		settingsMenu.sfxText.setFillColor(sf::Color::White);

		// Set green color to the current button
		switch (settingsMenu.currentButton)
		{
		case SettingsMenu::SettingsMenuButton::MUSIC_BUTTON:
		{
			settingsMenu.musicText.setFillColor(sf::Color::Green);
			break;
		}
		case SettingsMenu::SettingsMenuButton::SFX_BUTTON:
		{
			settingsMenu.sfxText.setFillColor(sf::Color::Green);
			break;
		}
		default:
			break;
		}
	}

	void UpdateSettingsMenu(SettingsMenu& settingsMenu, Game& game)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (!settingsMenu.isControlKeyPressed) {

				// Set current button
				switch (settingsMenu.currentButton)
				{
				case SettingsMenu::SettingsMenuButton::MUSIC_BUTTON:
				{
					settingsMenu.currentButton = SettingsMenu::SettingsMenuButton::SFX_BUTTON;
					break;
				}
				case SettingsMenu::SettingsMenuButton::SFX_BUTTON:
				{
					settingsMenu.currentButton = SettingsMenu::SettingsMenuButton::MUSIC_BUTTON;
					break;
				}
				default:
					break;
				}
				settingsMenu.isControlKeyPressed = true;

				UpdateSettingsMenuButtonsColor(settingsMenu);
				PlayPressKeySound(game);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (!settingsMenu.isControlKeyPressed) {

				// Set current button
				switch (settingsMenu.currentButton)
				{
				case SettingsMenu::SettingsMenuButton::MUSIC_BUTTON:
				{
					settingsMenu.currentButton = SettingsMenu::SettingsMenuButton::SFX_BUTTON;
					break;
				}
				case SettingsMenu::SettingsMenuButton::SFX_BUTTON:
				{
					settingsMenu.currentButton = SettingsMenu::SettingsMenuButton::MUSIC_BUTTON;
					break;
				}
				default:
					break;
				}
				settingsMenu.isControlKeyPressed = true;

				UpdateSettingsMenuButtonsColor(settingsMenu);
				PlayPressKeySound(game);
			}       
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (!settingsMenu.isControlKeyPressed) {
				switch (settingsMenu.currentButton)
				{
				case SettingsMenu::SettingsMenuButton::MUSIC_BUTTON:
				{
					if (game.currentSettings.musicSetting) {
						game.currentSettings.musicSetting = false;
					}
					else {
					game.currentSettings.musicSetting = true;
					}
					break;
				}
				case SettingsMenu::SettingsMenuButton::SFX_BUTTON:
				{
					if (game.currentSettings.sfxSetting) {
						game.currentSettings.sfxSetting = false;
					}
					else {
						game.currentSettings.sfxSetting = true;
					}
					break;
				}
				default:
					break;
				}
				settingsMenu.isControlKeyPressed = true;
				PlayPressKeySound(game);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
			if (!settingsMenu.isControlKeyPressed) {
				game.mainMenu.state = MainMenuState::MAIN_MENU;
				settingsMenu.isControlKeyPressed = true;
				PlayPressKeySound(game);
			}
		}
		else {
			settingsMenu.isControlKeyPressed = false;
		}
	}

	void DrawSettingsMenu(SettingsMenu& settingsMenu, const Game& game, sf::RenderWindow& window) 
	{
		window.draw(settingsMenu.settingsText);
		window.draw(settingsMenu.musicText);
		window.draw(settingsMenu.sfxText);

		if (game.currentSettings.musicSetting) {
			window.draw(settingsMenu.checkMarkMusicButton);
		}
		if (game.currentSettings.sfxSetting) {
			window.draw(settingsMenu.checkMarkSfxButton);
		}
	}
}
