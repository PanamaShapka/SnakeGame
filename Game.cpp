#include "Game.h"

namespace SnakeGame {

	void InitGame(Game& game)
	{
		assert(game.snakeHeadTexture.loadFromFile(RESOURCES_PATH + "\\SnakeHead.png"));
		assert(game.snakeTailTexture.loadFromFile(RESOURCES_PATH + "\\SnakeTail.png"));
		assert(game.boxTexture.loadFromFile(RESOURCES_PATH + "\\Box.png"));
		assert(game.appleTexture.loadFromFile(RESOURCES_PATH + "\\Apple.png"));
		assert(game.checkMarkTexture.loadFromFile(RESOURCES_PATH + "\\CheckMark.png"));
		assert(game.font.loadFromFile(RESOURCES_PATH + "\\Fonts\\Roboto-Thin.ttf"));

		assert(game.pressKeySoundBuffer.loadFromFile(RESOURCES_PATH + "\\Theevilsocks__menu-hover.wav")); // The original sound doesn't work, so I put another one here
		assert(game.snakeHitSoundBuffer.loadFromFile(RESOURCES_PATH + "\\Owlstorm__Snake_Hit.wav"));
		assert(game.backgroundMusicSoundBuffer.loadFromFile(RESOURCES_PATH + "\\Clinthammer__Background_Music.wav"));
		assert(game.loseSoundBuffer.loadFromFile(RESOURCES_PATH + "\\Maodin204__Lose.wav"));
		assert(game.enterSoundBuffer.loadFromFile(RESOURCES_PATH + "\\Theevilsocks__menu-hover.wav"));

		// Init sounds
		game.pressKeySound.setBuffer(game.pressKeySoundBuffer);
		game.snakeHitSound.setBuffer(game.snakeHitSoundBuffer);
		game.backgroundMusic.setBuffer(game.backgroundMusicSoundBuffer);
		game.loseSound.setBuffer(game.loseSoundBuffer);
		game.enterSound.setBuffer(game.enterSoundBuffer);

		// Init score
		game.scoreText.setFont(game.font);
		game.scoreText.setCharacterSize(40);
		game.scoreText.setFillColor(sf::Color::White);
		game.scoreText.setString("Score:");
		game.scoreText.setPosition(975.f, 0.f);

		game.scoreNumberText.setFont(game.font);
		game.scoreNumberText.setCharacterSize(30);
		game.scoreNumberText.setFillColor(sf::Color::White);
		game.scoreNumberText.setString("0");
		game.scoreNumberText.setPosition(975.f, game.scoreText.getGlobalBounds().height + 15.f);

		// Init background
		game.background.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
		game.background.setFillColor(sf::Color::Black);
		game.background.setPosition(0.f, 0.f);

		InitLeaderboard(game.leaderboard);
		InitGrid(game.grid);
		InitSnake(game.snake, game);
		UpdateGameDifficulty(game, DIFFICULTY_LEVEL_1);
		InitMainMenu(game.mainMenu, game);
		InitGameOverMenu(game.gameOverMenu, game);
		InitPauseMenu(game.pauseMenu, game);

		UpdateLeaderboardMenuState(game.mainMenu.leaderboardMenu, game);

		game.state = GameState::MAIN_MENU;
	}

	void SetStartGameState(Game& game)
	{
		// Clear game
		game.boxes.clear();
		game.apples.clear();
		SetStartGridState(game.grid);
		
		// Create lawn border
		game.boxes = CreateLawnBorder(game.grid, sf::Vector2i(LAWN_LENGHT_X_WITH_BORDER, LAWN_LENGHT_Y_WITH_BORDER), game);

		// Set start snake state
		SetStartSnakeState(game.snake, game);
		for (SnakeTailPart& currentSnakeTailPart : game.snake.tail) {
			GetCell(game.grid, currentSnakeTailPart.position).isCellEmpty = false;
		}

		UpdateGrid(game.grid);
		
		// Set apples
		Apple tempApple;
		InitApple(tempApple, game);
		game.apples.insert(game.apples.begin(), INITIAL_NUM_APPLES, tempApple);

		for (Apple& currentApple : game.apples) {
			SetApplePosition(currentApple, GetRandomEmptyPositionInLawn(game.grid));
			GetCell(game.grid, currentApple.position).isCellEmpty = false;
			UpdateGrid(game.grid);
		}

		// Set score
		game.score = 0;
		game.scoreNumberText.setString(std::to_string(game.score));

		if (game.currentSettings.musicSetting) {
			game.backgroundMusic.play();
			game.backgroundMusic.setLoop(true);
		}

		game.lastPressedSnakeControlKey = SnakeControlKey::D_KEY;
		game.state = GameState::PLAYING;

		game.enterSound.play();
	}

	void PlayPressKeySound(Game& game)
	{
		if (game.currentSettings.sfxSetting) {
			game.pressKeySound.play();
		}
	}

	void UpdateGameDifficulty(Game& game, DifficultyLevel newDifficultyLevel)
	{
		game.difficulty = newDifficultyLevel;
		game.snake.speed = game.difficulty.snakeSpeed;
	}

	void UpdateGame(Game& game, sf::Window& window)
	{
		switch (game.state)
		{
		case GameState::PLAYING:
		{
			// Update handle input
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				game.lastPressedSnakeControlKey = SnakeControlKey::D_KEY;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				game.lastPressedSnakeControlKey = SnakeControlKey::S_KEY;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				game.lastPressedSnakeControlKey = SnakeControlKey::A_KEY;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				game.lastPressedSnakeControlKey = SnakeControlKey::W_KEY;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
				game.state = GameState::PAUSED;
				PlayPressKeySound(game);
				game.backgroundMusic.stop();
				SetStartPauseMenuState(game.pauseMenu);
			}

			// Check snake update
			if (game.gameClock.getElapsedTime().asSeconds() >= game.snake.speed) {
				game.gameClock.restart();
			}
			else {
				return;
			}

			
			// Update snake direction
			switch (game.lastPressedSnakeControlKey)
			{
			case SnakeControlKey::D_KEY:
			{
				UpdateSnakeDirection(game.snake, SnakeDirection::Right);
				break;
			}
			case SnakeControlKey::S_KEY:
			{
				UpdateSnakeDirection(game.snake, SnakeDirection::Down);
				break;
			}
			case SnakeControlKey::A_KEY:
			{
				UpdateSnakeDirection(game.snake, SnakeDirection::Left);
				break;
			}
			case SnakeControlKey::W_KEY:
			{
				UpdateSnakeDirection(game.snake, SnakeDirection::Up);
				break;
			}
			default:
				break;
			}

			// Update snake position
			sf::Vector2i newSnakeHeadPosition;
			switch (game.snake.direction)
			{
			case SnakeDirection::Right:
			{
				newSnakeHeadPosition = sf::Vector2i(GetSnakeHead(game.snake).position.x + 1, GetSnakeHead(game.snake).position.y);
				break;
			}
			case SnakeDirection::Down:
			{
				newSnakeHeadPosition = sf::Vector2i(GetSnakeHead(game.snake).position.x, GetSnakeHead(game.snake).position.y + 1);
				break;
			}
			case SnakeDirection::Left:
			{
				newSnakeHeadPosition = sf::Vector2i(GetSnakeHead(game.snake).position.x - 1, GetSnakeHead(game.snake).position.y);
				break;
			}
			case SnakeDirection::Up:
			{
				newSnakeHeadPosition = sf::Vector2i(GetSnakeHead(game.snake).position.x, GetSnakeHead(game.snake).position.y - 1);
				break;
			}
			default:
				break;
			}

			// Find snake collision with boxes
			if (std::find_if(game.boxes.begin(), game.boxes.end(), [newSnakeHeadPosition](const Box& currentBox) {
				return newSnakeHeadPosition == currentBox.position; }) != game.boxes.end())
			{
				if (game.currentSettings.sfxSetting) {
					game.snakeHitSound.play();
				}

				game.backgroundMusic.stop();

				// Set GAME_OVER state
				game.state = GameState::GAME_OVER;

				UpdateGameOverMenuStates(game.gameOverMenu, game);
				game.gameClock.restart();
				return;
			}

			// Find snake collision with snake tail
			if (std::find_if(game.snake.tail.begin() + 1, game.snake.tail.end() - 1, [newSnakeHeadPosition](const SnakeTailPart& currentSnakeTailPart) {
				return newSnakeHeadPosition == currentSnakeTailPart.position; }) != game.snake.tail.end() - 1)
			{
				if (game.currentSettings.sfxSetting) {
					game.snakeHitSound.play();
				}

				game.backgroundMusic.stop();

				// Set GAME_OVER state
				game.state = GameState::GAME_OVER;

				UpdateGameOverMenuStates(game.gameOverMenu, game);
				game.gameClock.restart();
				return;
			}

			// Update cells to new snake position
			GetCell(game.grid, newSnakeHeadPosition).isCellEmpty = false;

			// Find snake collision with apples
			std::vector<Apple>::iterator currentApple = std::find_if(game.apples.begin(), game.apples.end(), [newSnakeHeadPosition](const Apple& currentApple) {
				return newSnakeHeadPosition == currentApple.position; });
			if (currentApple != game.apples.end()) // if apple was eaten
			{
				// Update score
				game.score += game.difficulty.pointPerApple;
				if (game.score > game.bestScore) {
					game.bestScore = game.score;
				}
				game.scoreNumberText.setString(std::to_string(game.score));

				// Update grid and apples
				sf::Vector2i newApplePosition = GetRandomEmptyPositionInLawn(game.grid);
				if (newApplePosition == sf::Vector2i(-1, -1)) {
					game.apples.erase(currentApple);
					UpdateGrid(game.grid);
				}
				else {
					GetCell(game.grid, newApplePosition).isCellEmpty = false;
					UpdateGrid(game.grid);

					// Set new apple position
					SetApplePosition(*currentApple, newApplePosition);
				}

				// Add new part to snake tail
				AddSnakeTailPart(game.snake, game, true);
			}
			else { // if apple was not eaten
				GetCell(game.grid, game.snake.tail.at(game.snake.tail.size() - 1).position).isCellEmpty = true;
				UpdateGrid(game.grid);
			}

			// Update snake
			UpdateSnakePosition(game.snake, newSnakeHeadPosition);

			break;

		}
		case GameState::GAME_OVER:
		{
			UpdateGameOverMenu(game.gameOverMenu, game);
			break;
		}
		case GameState::PAUSED:
		{
			UpdatePauseMenu(game.pauseMenu, game);
			break;
		}
		case GameState::MAIN_MENU:
		{
			UpdateMainMenu(game.mainMenu, game, window);
			break;
		}
		default:
			break;
		}
	}

	void DrawGame(Game& game, sf::RenderWindow& window)
	{
		window.draw(game.background);

		if (game.state == GameState::PLAYING || game.state == GameState::GAME_OVER || game.state == GameState::PAUSED) {
			DrawSnake(game.snake, window);

			for (Box& currentBox : game.boxes) {
				DrawBox(currentBox, window);
			}

			for (Apple& currentApple : game.apples) {
				DrawApple(currentApple, window);
			}

			window.draw(game.scoreText);
			window.draw(game.scoreNumberText);

			if (game.state == GameState::PAUSED) {
				DrawPauseMenu(game.pauseMenu, window);
			}
			else if (game.state == GameState::GAME_OVER) {
				DrawGameOverMenu(game.gameOverMenu, window);
			}
		}
		else if (game.state == GameState::MAIN_MENU) {
			DrawMainMenu(game.mainMenu, game, window);
		}
	}

	void ExitGame(sf::Window& window)
	{
		window.close();
	}
}