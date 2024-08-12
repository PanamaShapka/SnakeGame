#pragma once
#include "SFML-2.6.1/include/SFML/Graphics.hpp"
#include "Constants.h"

namespace SnakeGame {

	struct Game;
	struct Leaderboard;

	struct LeaderboardMenu {
		bool isControlKeyPressed = false;

		sf::Text leaderboardText;
		sf::Text leaderboard;
	};

	void InitLeaderboardMenu(LeaderboardMenu& leaderboardMenu, const Game& game);
	void UpdateLeaderboardMenuState(LeaderboardMenu& leaderboardMenu, const Game& game);
	void UpdateLeaderboardMenu(LeaderboardMenu& leaderboardMenu, Game& game);
	void DrawLeaderboardMenu(LeaderboardMenu& leaderboardMenu, sf::RenderWindow& window);
}

