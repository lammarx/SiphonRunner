#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class GameBackground {
public:
	GameBackground();
	void draw(RenderWindow& window);
private:
	Texture transitionTex;
	Texture background01;
	Texture background02;
	std::vector<Sprite> backgrounds;
	Sprite transition;
};

