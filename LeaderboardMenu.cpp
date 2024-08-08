#include "LeaderboardMenu.h"
#include "Game.h"

namespace SnakeGame {

	void InitLeaderboardMenu(LeaderboardMenu& leaderboardMenu, const Game& game)
	{
		leaderboardMenu.leaderboardText.setFont(game.font);
		leaderboardMenu.leaderboardText.setCharacterSize(75);
		leaderboardMenu.leaderboardText.setFillColor(sf::Color::White);
		std::string leaderboardText = u8"Таблица лидеров";
		leaderboardMenu.leaderboardText.setString(sf::String::fromUtf8(leaderboardText.begin(), leaderboardText.end()));
		leaderboardMenu.leaderboardText.setPosition(SCREEN_WIDTH / 2 - leaderboardMenu.leaderboardText.getGlobalBounds().width / 2, 75.f);

		leaderboardMenu.leaderboard.setFont(game.font);
		leaderboardMenu.leaderboard.setCharacterSize(35);
		leaderboardMenu.leaderboard.setFillColor(sf::Color::White);
		leaderboardMenu.leaderboard.setString("*");
		leaderboardMenu.leaderboard.setPosition((float)SCREEN_WIDTH / 2 - leaderboardMenu.leaderboard.getGlobalBounds().width / 2, leaderboardMenu.leaderboardText.getPosition().y + leaderboardMenu.leaderboardText.getGlobalBounds().height + 30.f);
	}

	void UpdateLeaderboardMenuState(LeaderboardMenu& leaderboardMenu, const Game& game)
	{
		std::string leaderboardText;
		for (Leaderboard::LeaderboardLine currentLine : game.leaderboard.leaderboard) {
			leaderboardText += (std::to_string(currentLine.position) + ". " + currentLine.name + " : " + std::to_string(currentLine.score) + "\n");
		}

		leaderboardMenu.leaderboard.setString(leaderboardText);
		leaderboardMenu.leaderboard.setPosition((float)SCREEN_WIDTH / 2 - leaderboardMenu.leaderboard.getGlobalBounds().width / 2, leaderboardMenu.leaderboard.getPosition().y);
	}

	void UpdateLeaderboardMenu(LeaderboardMenu& leaderboardMenu, Game& game)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
			if (!leaderboardMenu.isControlKeyPressed) {
				game.mainMenu.state = MainMenuState::MAIN_MENU;
				leaderboardMenu.isControlKeyPressed = true;
				PlayPressKeySound(game);
			}
		}
		else {
			leaderboardMenu.isControlKeyPressed = false;
		}
	}

	void DrawLeaderboardMenu(LeaderboardMenu& leaderboardMenu, sf::RenderWindow& window)
	{
		window.draw(leaderboardMenu.leaderboard);
		window.draw(leaderboardMenu.leaderboardText);
	}

}
