#include "Player.h"

Player::Player() {
	noseTex.loadFromFile("Resources\\nose.png");
	nose.setTexture(noseTex);
	nose.setOrigin(25.f, 25.f);
	nose.setPosition(600.f, 200.f);
	nose.setTexture(noseTex);
}

void Player::update(std::vector<FloatRect> bnds) {
	std::vector<FloatRect> bounds = bnds;
	bool gameOver = false;
	for (size_t i = 0; i < bounds.size(); i++) {
		if (bounds[i].intersects(nose.getLocalBounds())) {
			gameOver = true; break;
		}
	}
	std::cout << gameOver << "\n";
}

void Player::move() {

}

void Player::setDirection(const int moveDirection) {
	direction = moveDirection;
	if (direction == 0) nose.setRotation(0.f);
	if (direction == 1) nose.setRotation(-90.f);
	if (direction == 2) nose.setRotation(90.f);
}

void Player::draw(RenderWindow& window) {
	window.draw(nose);
	for (size_t i = 0; i < baseNose.size(); i++) {
		window.draw(nosePart);
	}
}