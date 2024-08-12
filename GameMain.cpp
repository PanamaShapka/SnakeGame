#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Constants.h"
#include "Game.h"

using namespace SnakeGame;

int main() {

	setlocale(LC_ALL, "ru");
	srand((int)time(NULL));

	// Init window
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SnakeSnakeSnake");

	// Init game
	Game game;
	InitGame(game);

	// Main loop
	while (window.isOpen()) {
	
		// Reduce framerate to not spam CPU and GPU
		sf::sleep(sf::milliseconds(16));

		// Read events
		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				window.close();
				break;
			}
		}
				
		// Update game
		UpdateGame(game, window);

		// Draw game
		DrawGame(game, window);
		window.display();
	}

		return 0;
}