#pragma once

namespace SnakeGame {

	struct DifficultyLevel {
		float snakeSpeed;
		int pointPerApple;
	};

	const DifficultyLevel DIFFICULTY_LEVEL_1 = { 0.5f, 2 };
	const DifficultyLevel DIFFICULTY_LEVEL_2 = { 0.25f, 4 };
	const DifficultyLevel DIFFICULTY_LEVEL_3 = { 0.125f, 6 };
	const DifficultyLevel DIFFICULTY_LEVEL_4 = { 0.0625f, 8 };
	const DifficultyLevel DIFFICULTY_LEVEL_5 = { 0.03125f, 10 };
}

