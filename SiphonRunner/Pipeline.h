#ifndef PIPELINE_H
#define PIPELINE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "GameBackground.h"

using namespace sf;

class Pipeline {
public:
	Pipeline(){};
	void create();
	void addPipe();
	void update(GameBackground& gameBackground);
	std::vector<FloatRect> getPipelineBounds();
	void move(const int moveDirection);
	void draw(RenderWindow& gameWindow);
private:
	std::vector<Sprite> pipeline;
	std::vector<int> indexList;
	Clock clock;
	Time time;
	Texture pipe01aTex;
	Texture pipe02aTex;
	Texture pipe01bTex;
	Texture pipe02bTex;
	Texture pipe02cTex;
	Texture pipe02dTex;
	Sprite pipe;
	const float pipeSize = 200.f;
	int direction = 0;
	const float pipeHeight = 200.f;
	const float pipeWidth = 100.f;
};

#endif 
