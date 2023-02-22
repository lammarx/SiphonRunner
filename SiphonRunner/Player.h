#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace sf;

class Player {
public:
	Player();
	void update(std::vector<FloatRect> bnds);
	void move();
	void setDirection(const int moveDirection);
	void draw(RenderWindow& window);
private:
	RectangleShape nosePart;
	std::vector<RectangleShape> baseNose;
	Sprite nose;
	Texture noseTex;
	int direction = 0;
};

