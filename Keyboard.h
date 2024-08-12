#pragma once
#include "SFML-2.6.1/include/SFML/Graphics.hpp"

namespace SnakeGame {

	struct Keyboard
	{
		std::string keyboardInput;
		bool isKeyPressed = false;
		int maxInputLength = 0;
	};

	void UpdateKeyboardInput(Keyboard& keyboard);

}

