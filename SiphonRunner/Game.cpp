#include "Game.h"
#include "GameMenu.h"

void Game::initWindow() {
	videoMode.width = 1600;
	videoMode.height = 900;
	window.create(videoMode, "SiphonRunner");
	window.getSettings();
}

int Game::pollEvent() {
	srand(time(0));
	initWindow();
	font.loadFromFile("Resources\\PressStart2P-Regular.ttf");

	gamePause();
	gamePrologue();

	Pipeline pipeline;
	pipeline.create();

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			switch (event.type) {
			case Event::Closed: window.close();
			case Event::KeyPressed:
				if (event.key.code == Keyboard::Escape) gamePause();
				if (event.key.code == Keyboard::A) pipeline.addPipe();
			}
		}
		window.clear();
		pipeline.draw(window);
		window.display();
	}
	return 0;
}