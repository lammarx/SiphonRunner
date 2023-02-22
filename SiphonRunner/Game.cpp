#include "Game.h"
#include "GameMenu.h"
#include "Player.h"
#include "Dumpling.h"

void Game::initWindow() {
	videoMode.width = 1600;
	videoMode.height = 900;
	window.create(videoMode, "SiphonRunner");
	window.setFramerateLimit(144);
}

int Game::pollEvent() {
	srand(time(0));
	initWindow();
	font.loadFromFile("Resources\\PressStart2P-Regular.ttf");

	gamePause();
	gamePrologue();

	Player player;
	Pipeline pipeline;
	pipeline.create();

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			switch (event.type) {
			case Event::Closed: window.close();
			case Event::KeyPressed:
				if (event.key.code == Keyboard::Escape) gamePause();
				if (event.key.code == Keyboard::S) player.setDirection(0);
				if (event.key.code == Keyboard::D) player.setDirection(1);
				if (event.key.code == Keyboard::A) player.setDirection(2);
			}
		}
		pipeline.update();
		
		window.clear();
		pipeline.draw(window);
		player.draw(window);
		window.display();
	}
	return 0;
}
