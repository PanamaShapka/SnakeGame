#include "Leaderboard.h"

namespace SnakeGame {

	void InitLeaderboard(Leaderboard& leaderboard)
	{
		leaderboard.leaderboard.insert(leaderboard.leaderboard.begin(), 10, Leaderboard::LeaderboardLine());

		int position = 1;
		for (Leaderboard::LeaderboardLine& currentLine : leaderboard.leaderboard) {
			currentLine.name = "XYZ";
			currentLine.score = 0;
			currentLine.position = position;
			++position;
		}
	}

	void UpdateLeaderboard(Leaderboard& leaderboard)
	{
		std::sort(leaderboard.leaderboard.begin(), leaderboard.leaderboard.end(), [](const Leaderboard::LeaderboardLine& line1, const Leaderboard::LeaderboardLine& line2) {
			return line1.score > line2.score; 
			});

		leaderboard.leaderboard.erase(leaderboard.leaderboard.begin() + 10, leaderboard.leaderboard.end());

		int position = 1;
		for (Leaderboard::LeaderboardLine& currentLine : leaderboard.leaderboard) {
			currentLine.position = position;
			++position;
		}
	}

	void AddRecordToLeaderboard(Leaderboard& leaderboard, Leaderboard::LeaderboardLine newRecord)
	{
		leaderboard.leaderboard.push_back(newRecord);
	}
}
