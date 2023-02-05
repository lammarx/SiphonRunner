#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Pipeline.h"

using namespace sf;

class Game {
public:
	Game() {

	}
	int pollEvent();
private:
	// SFML Classes
	RenderWindow window;
	Event event;
	VideoMode videoMode;
	Font font;

	// Init
	void initWindow();

	int gamePause();
	int gamePrologue();
	int buttonSettings();
	int buttonAbout();
};