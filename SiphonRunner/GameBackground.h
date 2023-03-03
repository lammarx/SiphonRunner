#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class GameBackground {
public:
	GameBackground();
	void update();
	void addBackground();
	void draw(RenderWindow& window);
private:
	Texture background01Tex;
	Texture background02Tex;
	Texture transitionTex;
	std::vector<Sprite> backgrounds;
	Sprite transition;
	Clock clock;
};

