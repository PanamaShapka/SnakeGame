#pragma once
#include "SFML-2.6.1/include/SFML/Graphics.hpp"
#include "SFML-2.6.1/include/SFML/Audio/Sound.hpp"
#include "SFML-2.6.1/include/SFML/Audio/SoundBuffer.hpp"

#include "Math.h"
#include "Snake.h"
#include "Box.h"
#include "Apple.h"
#include "Grid.h"
#include "MainMenu.h"
#include "GameOverMenu.h"
#include "Leaderboard.h"
#include "PauseMenu.h"


namespace SnakeGame {

	enum class GameState {
		PLAYING = 0,
		GAME_OVER,
		PAUSED,
		MAIN_MENU
	};

	enum class SnakeControlKey {
		D_KEY = 0,
		S_KEY,
		A_KEY,
		W_KEY
	};

	struct GameSettings {
		bool musicSetting = true;
		bool sfxSetting = true;
	};

	struct Game
	{
		Grid grid;
		std::vector<Apple> apples;
		std::vector<Box> boxes;
		Snake snake;
		sf::Clock gameClock;
		sf::RectangleShape background;
		GameState state;

		sf::Texture snakeTailTexture;
		sf::Texture snakeHeadTexture;
		sf::Texture boxTexture;
		sf::Texture appleTexture;
		sf::Texture checkMarkTexture;

		sf::Sound pressKeySound;
		sf::SoundBuffer pressKeySoundBuffer;
		
		sf::Sound snakeHitSound;
		sf::SoundBuffer snakeHitSoundBuffer;

		sf::Sound backgroundMusic;
		sf::SoundBuffer backgroundMusicSoundBuffer;

		sf::Sound loseSound;
		sf::SoundBuffer loseSoundBuffer;

		sf::Sound enterSound;
		sf::SoundBuffer enterSoundBuffer;

		sf::Font font;
		sf::Text scoreText;
		sf::Text scoreNumberText;
		int score = 0;
		int bestScore = 0;

		Leaderboard leaderboard;
		GameOverMenu gameOverMenu;
		PauseMenu pauseMenu;

		MainMenu mainMenu;

		SnakeControlKey lastPressedSnakeControlKey;
		DifficultyLevel difficulty = DIFFICULTY_LEVEL_1;
		GameSettings currentSettings;

	};

	void InitGame(Game& game);
	void SetStartGameState(Game& game);
	void PlayPressKeySound(Game& game);
	void UpdateGameDifficulty(Game& game, DifficultyLevel newDifficultyLevel);
	void UpdateGame(Game& game, sf::Window& win);
	void DrawGame(Game& game, sf::RenderWindow& window);
	void ExitGame(sf::Window& window);
}
