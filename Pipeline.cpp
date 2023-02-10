#include "Pipeline.h"

void Pipeline::create() {
	pipe.setFillColor(Color(255, 255, 255, 100));
	pipe.setSize(Vector2f(pipeWidth, pipeHeight));
	pipe.setPosition(800.f, 0.f);
	pipe.setOrigin(pipe.getSize().x / 2.f, 0.f);
	pipeline.push_back(pipe);

	pipeTurn.setSize(Vector2f(pipeWidth, pipeWidth));
}

void Pipeline::addPipe() {
	int index = rand() % 2;
	if (index == 0) pipeAngle = 0.f;
	else if (index == 1) pipeAngle = 90.f;
	else if (index == 2) pipeAngle = -90.f;
	
	if (index == 0) {
		if (pipeline[pipeline.size() - 1].getPosition().x == pipeWidth) { // if pipeline[last] is looking down
			pipe.setPosition(pipeline[pipeline.size() - 1].getPosition().x + pipeHeight, pipeline[pipeline.size() - 1].getPosition().y);
		}
		else if (pipeline[pipeline.size() - 1].getPosition().x == pipeHeight) {

		}
	}
	else {

	}
	
	pipeline.push_back(pipe);
}

void Pipeline::draw(RenderWindow& window) {
	for (int i = 0; i < pipeline.size(); i++) {
		window.draw(pipeline[i]);
	}
}