#include "GameBackground.h"

GameBackground::GameBackground() {
	background01Tex.loadFromFile("Resources\\GameBackground01.png");
	background02Tex.loadFromFile("Resources\\GameBackground02.png");
	transitionTex.loadFromFile("Resources\\GameBackgroundTransition.png");

	for (size_t i = 0; i < rand() % 30 + 10; i++) {
		Sprite bg;
		if (i != 0) { bg.setPosition(0.f, backgrounds[backgrounds.size() - 1].getPosition().y); }
		bg.setTexture(background01Tex);
		backgrounds.push_back(bg);
	}
}

void GameBackground::update() {
	for (size_t i = 0; i < backgrounds.size(); i++) {
		backgrounds[i].move(0.f, -5.f);
	}
}

void GameBackground::addBackground() {
	Sprite bg;
	bg.setPosition(0.f, backgrounds[backgrounds.size() - 1].getPosition().y);

	if (rand() % 1 == 0) {
		bg.setTexture(background01Tex);
		backgrounds.push_back(bg);
	}
	else {
		bg.setTexture(background02Tex);
		backgrounds.push_back(bg);
	}
}

void GameBackground::draw(RenderWindow& window) {
	window.draw(transition);
	for (size_t i = 0; i < backgrounds.size(); i++) {
		window.draw(backgrounds[i]);
	}
}