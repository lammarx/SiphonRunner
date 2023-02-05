#include "Pipeline.h"

void Pipeline::create() {
	pipe.setFillColor(Color(255, 255, 255, 100));
	pipe.setSize(Vector2f(pipeWidth, pipeHeight));
	pipe.setPosition(800.f, pipe.getSize().x / 2.f);
	pipe.setOrigin(pipe.getSize().x / 2.f, pipe.getSize().x / 2.f);
	pipeline.push_back(pipe);
}

void Pipeline::addPipe() {
	int index = rand() % 3;
	if (index == 0) pipeAngle = 0.f;
	else if (index == 1) pipeAngle = 90.f;
	else if (index == 2) pipeAngle = -90.f;
	else if (index == 3 && pipeAngle != 0.f) pipeAngle = 180.f;

	
	
	pipeline.push_back(pipe);
}

void Pipeline::draw(RenderWindow& window) {
	for (int i = 0; i < pipeline.size(); i++) {
		window.draw(pipeline[i]);
	}
}