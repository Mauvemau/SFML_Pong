#include "player.h"
#include "game.h"
#include "settings.h"

#include <iostream>
using namespace std;

// Private

void Player::updateShape() {
	shape.setPosition(position);
	shape.setSize(size);
	shape.setFillColor(color);
}

// Public

Player::Player(Vector2f position, Vector2f size, float speed, Color color) {
	this->position = position;
	this->size = size;
	this->speed = speed;
	this->color = color;

	updateShape();

	cout << "Player object created!\n";
}

Player::~Player() {
	cout << "Player object destroyed!\n";
}

RectangleShape Player::getShape() {
	return shape;
}

void Player::center() {
	position.x -= (size.x * .5f);
	position.y -= (size.y * .5f);
	updateShape();
}

void Player::move(float direction, double dt) {
	position.y += static_cast<float>(direction * (speed * dt));
	if (position.y < 0) position.y = 0;
	if (position.y + size.y > Settings::getWindowHeight()) position.y = Settings::getWindowHeight() - size.y;
	updateShape();
}