#include "Game.h"
#include "GameMenu.h"

int Game::gamePrologue() {
	Texture art_1, art_2, art_3, art_4;
	Sprite sprite_1, sprite_2, sprite_3, sprite_4;
	art_1.loadFromFile("Resources\\prologue_art1.png");
	art_2.loadFromFile("Resources\\prologue_art2.png");
	art_3.loadFromFile("Resources\\prologue_art3.png");
	art_4.loadFromFile("Resources\\prologue_art4.png");
	sprite_1.setTexture(art_1); sprite_1.setPosition(100.f, 50.f);
	sprite_2.setTexture(art_2); sprite_2.setPosition(900.f, 50.f);
	sprite_3.setTexture(art_3); sprite_3.setPosition(100.f, 50.f);
	sprite_4.setTexture(art_4); sprite_4.setPosition(900.f, 50.f);
	bool changePage = false;
		
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (Event::KeyPressed) {
				if (event.key.code == Keyboard::Left) changePage = false;
				if (event.key.code == Keyboard::Enter && changePage) return 0;

				if (event.key.code == Keyboard::Right || event.key.code == Keyboard::Space) changePage = true;
			}
		}
		window.clear();
		if (!changePage) window.draw(sprite_1), window.draw(sprite_2);
		else window.draw(sprite_3), window.draw(sprite_4);
		window.display();
	}
	return 0;
}

int Game::gamePause() {
	String gameMenuStrings[]{ "Play", "Settings", "About", "Quit" };
	GameMenu gameMenu(window, 100, 600, 4, gameMenuStrings, 40, 60);
	gameMenu.setColorTextMenu(Color(237, 147, 0), Color::Red, Color::Black);

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			switch (event.type) {
			case Event::Closed: window.close();
			}
			if (event.type == Event::KeyReleased) {
				if (event.key.code == Keyboard::Up) gameMenu.MoveUp();
				if (event.key.code == Keyboard::Down) gameMenu.MoveDown();
				if (event.key.code == Keyboard::Tilde) return 0;
				if (event.key.code == Keyboard::Return) {
					switch (gameMenu.getSelectedMenuNumber()) {
					case 0: return 0;
					case 1: buttonSettings(); break;
					case 2: buttonAbout(); break;
					case 3: window.close(); break;
					}
				}
			}
		}
		gameMenu.updateBackground();

		window.clear();
		gameMenu.draw();
		window.display();
	}
}

int Game::buttonSettings() {
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) window.close();
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Escape) return 0;
			}
		}
		window.clear();
		window.display();
	}
}

int Game::buttonAbout() {
	Sprite gameTitle;
	Texture gameTitleTexture;
	Text gameInfo;
	Texture backgroundTexture;
	Sprite background;
	backgroundTexture.loadFromFile("Resources\\GameMenuBackground.png");
	background.setTexture(backgroundTexture);
	gameInfo.setFont(font);
	gameInfo.setString(String("This is a game created specially for Stalevi by Begemotto.") + 
					   String("\nYou are playing as Gucci dog nose. You have to drop through siphon") +
					   String("\nto save a dumpling that fall into siphon ways.") +
					   String("\nFor additional help or info, contact to Begemotto#5566"));
	gameInfo.setPosition(800.f, 200.f);
	gameInfo.setOrigin(gameInfo.getGlobalBounds().width / 2.f - 800.f, 0.f);
	//gameInfo.setCharacterSize(12);
	gameTitleTexture.loadFromFile("Resources\\gamelogo.png");
	gameTitle.setTexture(gameTitleTexture);
	gameTitle.setScale(2.2, 2.2);
	gameTitle.setOrigin(226.f, 25.5);
	gameTitle.setPosition(800.f, 100.f);
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) window.close();
			if (event.type == Event::KeyPressed) {
				return 0;
			}
		}
		window.clear();
		window.draw(background);
		window.draw(gameTitle);
		window.draw(gameInfo);
		window.display();
	}
	return 0;
}