#include "Pipeline.h"

void Pipeline::create() {
	pipe.setFillColor(Color(255, 255, 255, 100));
	pipe.setSize(Vector2f(pipeSize, pipeSize));
	pipe.setPosition(800.f, 0.f);
	pipeline.push_back(pipe);

	pipeTurn.setSize(Vector2f(pipeSize, pipeSize));
	//for (int i = 0; i < 10; i++) {
	//	addPipe();
	//}
}

// SUPER GOVNOCODE RIGHT THERE:
void Pipeline::addPipe() {
	index = rand() % 10;
	
	if (direction == 0) {
		pipe.setPosition(pipeline[pipeline.size() - 1].getPosition().x, pipeline[pipeline.size() - 1].getPosition().y + pipeSize);
	}
	else if (direction == 1) {
		pipe.setPosition(pipeline[pipeline.size() - 1].getPosition().x + pipeSize, pipeline[pipeline.size() - 1].getPosition().y);
	}
	else if (direction == 2) {
		pipe.setPosition(pipeline[pipeline.size() - 1].getPosition().x - pipeSize, pipeline[pipeline.size() - 1].getPosition().y);
	}
	if (index > 5) {
		direction = rand() % 2;
	}
	pipeline.push_back(pipe);
}

void Pipeline::update() {
	for (int i = 0; i < pipeline.size(); i++) {
		if (Keyboard::isKeyPressed(Keyboard::W)) { pipeline[i].move(0.f, 2.f); }
		else if (Keyboard::isKeyPressed(Keyboard::A)) { pipeline[i].move(2.f, 0.f); }
		else if (Keyboard::isKeyPressed(Keyboard::S)) { pipeline[i].move(0.f, -2.f); }
		else if (Keyboard::isKeyPressed(Keyboard::D)) { pipeline[i].move(-2.f, 0.f); }
	}
	if (pipeline.size() == 3) {
		pipeline.erase(pipeline.begin());
		addPipe();
		std::cout << pipeline.size() << "\n";
	}
	if (Keyboard::isKeyPressed(Keyboard::E)) addPipe();
}

void Pipeline::draw(RenderWindow& window) {
	for (int i = 0; i < pipeline.size(); i++) {
		window.draw(pipeline[i]);
	}
}