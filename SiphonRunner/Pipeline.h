#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class Pipeline {
public:
	Pipeline(){};
	void create();
	void addPipe();
	void draw(RenderWindow& gameWindow);
private:
	std::vector<RectangleShape> pipeline;
	RectangleShape pipe;
	float pipeAngle = 90.f;
	float pipeHeight = 100.f;
	const float pipeWidth = 20.f;
};
