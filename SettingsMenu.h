#pragma once
#include "SFML-2.6.1/include/SFML/Graphics.hpp"
#include "Constants.h"

namespace SnakeGame {

	struct SettingsMenu {
		enum class SettingsMenuButton {
			MUSIC_BUTTON = 0,
			SFX_BUTTON
		};

		SettingsMenuButton currentButton = SettingsMenuButton::MUSIC_BUTTON;
		bool isControlKeyPressed = false;

		sf::Text settingsText;
		sf::Sprite checkMarkMusicButton;
		sf::Sprite checkMarkSfxButton;
		sf::Text musicText;
		sf::Text sfxText;
	};

	struct Game;

	void InitSettingsMenu(SettingsMenu& settingsMenu, const Game& game);
	void UpdateSettingsMenuButtonsColor(SettingsMenu& settingsMenu);
	void UpdateSettingsMenuButtonsColor(SettingsMenu& settingsMenu, SettingsMenu::SettingsMenuButton lastButton);
	void UpdateSettingsMenu(SettingsMenu& settingsMenu, Game& game);
	void DrawSettingsMenu(SettingsMenu& settingsMenu, const Game& game, sf::RenderWindow& window);
}

