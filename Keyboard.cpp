#include "Keyboard.h"

namespace SnakeGame {

	void UpdateKeyboardInput(Keyboard& keyboard)
	{	
		// Check input


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Backspace)) {
			if (!keyboard.isKeyPressed) {
				if (keyboard.keyboardInput.length() != 0) {
					keyboard.keyboardInput.pop_back();
				}
				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {
		
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('A');
				}
				else {
					keyboard.keyboardInput.push_back('a');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('B');
				}
				else {
					keyboard.keyboardInput.push_back('b');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('C');
				}
				else {
					keyboard.keyboardInput.push_back('c');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('D');
				}
				else {
					keyboard.keyboardInput.push_back('d');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('E');
				}
				else {
					keyboard.keyboardInput.push_back('e');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('F');
				}
				else {
					keyboard.keyboardInput.push_back('f');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('G');
				}
				else {
					keyboard.keyboardInput.push_back('g');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('H');
				}
				else {
					keyboard.keyboardInput.push_back('h');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('I');
				}
				else {
					keyboard.keyboardInput.push_back('i');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('J');
				}
				else {
					keyboard.keyboardInput.push_back('j');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('K');
				}
				else {
					keyboard.keyboardInput.push_back('k');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('L');
				}
				else {
					keyboard.keyboardInput.push_back('l');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('M');
				}
				else {
					keyboard.keyboardInput.push_back('m');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('N');
				}
				else {
					keyboard.keyboardInput.push_back('n');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('O');
				}
				else {
					keyboard.keyboardInput.push_back('o');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('P');
				}
				else {
					keyboard.keyboardInput.push_back('p');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('R');
				}
				else {
					keyboard.keyboardInput.push_back('r');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('S');
				}
				else {
					keyboard.keyboardInput.push_back('s');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('T');
				}
				else {
					keyboard.keyboardInput.push_back('t');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('U');
				}
				else {
					keyboard.keyboardInput.push_back('u');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('V');
				}
				else {
					keyboard.keyboardInput.push_back('v');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('W');
				}
				else {
					keyboard.keyboardInput.push_back('w');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('X');
				}
				else {
					keyboard.keyboardInput.push_back('x');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('Y');
				}
				else {
					keyboard.keyboardInput.push_back('y');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					keyboard.keyboardInput.push_back('Z');
				}
				else {
					keyboard.keyboardInput.push_back('z');
				}

				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {
				keyboard.keyboardInput.push_back('0');
				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {
				keyboard.keyboardInput.push_back('1');
				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {
				keyboard.keyboardInput.push_back('2');
				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {
				keyboard.keyboardInput.push_back('3');
				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {
				keyboard.keyboardInput.push_back('4');
				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {
				keyboard.keyboardInput.push_back('5');
				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {
				keyboard.keyboardInput.push_back('6');
				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {
				keyboard.keyboardInput.push_back('7');
				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {
				keyboard.keyboardInput.push_back('8');
				keyboard.isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
			if (!keyboard.isKeyPressed && keyboard.keyboardInput.length() != keyboard.maxInputLength) {
				keyboard.keyboardInput.push_back('9');
				keyboard.isKeyPressed = true;
			}
		}
		else {
			keyboard.isKeyPressed = false;
		}
	}
}
