#include "Pipeline.h"

void Pipeline::create() {
	pipe.setFillColor(Color(255, 255, 255, 100));
	pipe.setSize(Vector2f(pipeWidth, pipeHeight));
	pipe.setPosition(800.f, 0.f);
	//pipe.setOrigin(pipe.getSize().x / 2.f, 0.f);
	pipeline.push_back(pipe);

	pipeTurn.setSize(Vector2f(pipeWidth, pipeWidth));
	//pipeTurn.setOrigin(pipeWidth / 2.f, 0.f);
	for (int i = 0; i < 10; i++) {
		addPipe();
	}
}

// SUPER GOVNOCODE RIGHT THERE:
void Pipeline::addPipe() {
	int lastIndex = index;
	index = rand() % 3;
	if (index == 0) { pipeAngle = 0.f; if (index == lastIndex) { index = rand() % 2 + 1; } }
	else if (index == 1) { pipeAngle = 90.f; if (lastIndex == 2) { index = 2; } }
	else if (index == 2) { pipeAngle = -90.f; if (lastIndex == 1) { index = 1; } }
	else if (index == 3) { pipeAngle = 0.f; if (lastIndex != 0) { index = 0; if (index == lastIndex) { index = rand() % 2 + 1; } } }

	if (index == 0) {
		pipeTurn.setPosition(pipeline[pipeline.size() - 1].getPosition().x, pipeline[pipeline.size() - 1].getPosition().y + pipeline[pipeline.size() - 1].getSize().y);
		pipeline.push_back(pipeTurn);
	}
	else {
		pipe.setSize(Vector2f(pipe.getSize().y, pipe.getSize().x));
		if (index == 1) {
			pipe.setPosition(pipeline[pipeline.size() - 1].getPosition().x + pipeline[pipeline.size() - 1].getSize().x, pipeline[pipeline.size() - 1].getPosition().y);
		}
		else if (index == 2) {
			pipe.setPosition(pipeline[pipeline.size() - 1].getPosition().x - pipe.getSize().x, pipeline[pipeline.size() - 1].getPosition().y);
		}
		else if (index == 3) {
			pipe.setPosition(pipeline[pipeline.size() - 1].getPosition().x, pipeline[pipeline.size() - 1].getPosition().y);
		}
		pipeline.push_back(pipe);
	}
}

void Pipeline::update() {
	for (int i = 0; i < pipeline.size(); i++) {
		if (Keyboard::isKeyPressed(Keyboard::A)) { pipeline[i].move(0.1, 0.f); }
		else if (Keyboard::isKeyPressed(Keyboard::S)) { pipeline[i].move(0.f, -0.1); }
		else if (Keyboard::isKeyPressed(Keyboard::D)) { pipeline[i].move(-0.1, 0.f); }
	}
	if (pipeline[0].getPosition().y < -500.f) {
		pipeline.erase(pipeline.begin());
		addPipe();
		std::cout << pipeline.size() << "\n";
	}
}

void Pipeline::draw(RenderWindow& window) {
	for (int i = 0; i < pipeline.size(); i++) {
		window.draw(pipeline[i]);
	}
}
