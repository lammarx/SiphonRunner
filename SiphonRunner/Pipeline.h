#ifndef PIPELINE_H
#define PIPELINE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace sf;

class Pipeline {
public:
	Pipeline(){};
	void create();
	void addPipe();
	void update();
	void draw(RenderWindow& gameWindow);
private:
	std::vector<Sprite> pipeline;
	Texture pipe01aTex;
	Texture pipe02aTex;
	Texture pipe01bTex;
	Texture pipe02bTex;
	Sprite pipe;
	const float pipeSize = 200.f;
	int direction = 0;
	int index = 0;
	float pipeAngle = 90.f;
	const float pipeHeight = 200.f;
	const float pipeWidth = 100.f;
};

#endif 
