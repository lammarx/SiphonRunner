#ifndef PIPELINE_H
#define PIPELINE_H

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
	RectangleShape pipeTurn;
	float pipeAngle = 90.f;
	const float pipeHeight = 200.f;
	const float pipeWidth = 100.f;
};

#endif 