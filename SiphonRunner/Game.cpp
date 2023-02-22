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

	int moveDirection = 0;

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			switch (event.type) {
			case Event::Closed: window.close();
			case Event::KeyPressed:
				if (event.key.code == Keyboard::Escape) gamePause();
				if (event.key.code == Keyboard::S) moveDirection = 0, player.setDirection(moveDirection);
				if (event.key.code == Keyboard::D) moveDirection = 1, player.setDirection(moveDirection);
				if (event.key.code == Keyboard::A) moveDirection = 2, player.setDirection(moveDirection);
			}
		}
		pipeline.move(moveDirection);
		pipeline.update();
		player.update(pipeline.getPipelineBounds());
		
		window.clear();
		pipeline.draw(window);
		player.draw(window);
		window.display();
	}
	return 0;
}
