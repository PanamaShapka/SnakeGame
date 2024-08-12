#pragma once
#include "SFML-2.6.1/include/SFML/Graphics.hpp"

namespace SnakeGame 
{
	struct Leaderboard {
		struct LeaderboardLine {
			std::string name;
			int score = 0;
			int position = 0;
		};

		std::vector<LeaderboardLine> leaderboard;
	};

	void InitLeaderboard(Leaderboard& leaderboard);
	void UpdateLeaderboard(Leaderboard& leaderboard);
	void AddRecordToLeaderboard(Leaderboard& leaderboard, Leaderboard::LeaderboardLine newRecord);
}


