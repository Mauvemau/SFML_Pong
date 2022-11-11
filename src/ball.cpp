#include "ball.h"
#include "settings.h"

#include <iostream>
using namespace std;

// Private

void Ball::updateShape() {
	shape.setPosition(position);
	shape.setRadius(radius);
	shape.setFillColor(color);
}

// Public

Ball::Ball(Vector2f position, float radius, float speed, Color color) {
	this->position = position;
	this->radius = radius;
	this->speed = speed;
	this->color = color;

	direction = { 1, 1 };

	updateShape();
	cout << "Ball object created!\n";
}

Ball::~Ball() {
	cout << "Ball object destroyed!\n";
}

CircleShape Ball::getShape() {
	return shape;
}

void Ball::update(double dt) {
	position.x += static_cast<float>(direction.x * (speed * dt));
	position.y += static_cast<float>(direction.y * (speed * dt));

	if (position.x < 0) { 
		direction.x = 1;
	}
	if (position.x + (radius * 2.0f) > Settings::getWindowWidth()) {
		direction.x = -1;
	}
	if (position.y < 0) {
		direction.y = 1;
	}
	if (position.y + (radius * 2.0f) > Settings::getWindowHeight()) {
		direction.y = -1;
	}

	updateShape();
}