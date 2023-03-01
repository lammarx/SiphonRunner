#include "Pipeline.h"

void Pipeline::create() {
	pipe01aTex.loadFromFile("Resources\\pipe_01a.png");
	pipe02aTex.loadFromFile("Resources\\pipe_02a.png");
	pipe01bTex.loadFromFile("Resources\\pipe_01b.png");
	pipe02bTex.loadFromFile("Resources\\pipe_02b.png");
	pipe02cTex.loadFromFile("Resources\\pipe_02c.png");
	pipe02dTex.loadFromFile("Resources\\pipe_02d.png");
	pipe.setPosition(800.f, 0.f);
	pipeline.push_back(pipe);
	pipe.setOrigin(100.f, 100.f);
	for (int i = 0; i < 10; i++) {
		pipeline.push_back(pipe);
	}
}

void Pipeline::addPipe() {
	int index = rand() % 10;
	
	if (direction == 0) {
		pipe.setPosition(pipeline[pipeline.size() - 1].getPosition().x, pipeline[pipeline.size() - 1].getPosition().y + pipeSize);
		pipe.setTexture(pipe01bTex);
	}
	else if (direction == 1) {
		pipe.setPosition(pipeline[pipeline.size() - 1].getPosition().x + pipeSize, pipeline[pipeline.size() - 1].getPosition().y);
		pipe.setTexture(pipe01aTex);
	}
	else if (direction == 2) {
		pipe.setPosition(pipeline[pipeline.size() - 1].getPosition().x - pipeSize, pipeline[pipeline.size() - 1].getPosition().y);
		pipe.setTexture(pipe01aTex);
	}
	
	if (index > 5) {
		int temp = direction;
		do { direction = rand() % 3; } while ((temp == 1 && direction == 2) || (temp == 2 && direction == 1) || direction == temp);
		if (temp == 0 && direction == 1) { pipe.setTexture(pipe02aTex); }
		else if (temp == 0 && direction == 2) { pipe.setTexture(pipe02bTex); }
		else if (temp == 1 && direction == 0) { pipe.setTexture(pipe02cTex); }
		else if (temp == 2 && direction == 0) { pipe.setTexture(pipe02dTex); }
	}
	pipeline.push_back(pipe);
}

void Pipeline::update() {
	if (pipeline[0].getPosition().y < -100.f || pipeline[0].getPosition().x < -100.f || pipeline[0].getPosition().x > 1700.f) {
		pipeline.erase(pipeline.begin());
		addPipe();
	}
}

std::vector<FloatRect> Pipeline::getPipelineBounds() {
	std::vector<FloatRect> bounds;
	for (size_t i = 0; i < pipeline.size(); i++) {
		bounds.push_back(pipeline[i].getGlobalBounds());
	} return bounds;
}

void Pipeline::move(const int moveDirection) {
	for (int i = 0; i < pipeline.size(); i++) {
		if (moveDirection == 0) pipeline[i].move(0.f, -5.f);
		else if (moveDirection == 1) pipeline[i].move(-5.f, 0.f);
		else if (moveDirection == 2) pipeline[i].move(5.f, 0.f);
	}
}

void Pipeline::draw(RenderWindow& window) {
	for (int i = 0; i < pipeline.size(); i++) {
		window.draw(pipeline[i]);
	}
}