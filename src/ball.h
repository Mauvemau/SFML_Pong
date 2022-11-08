#pragma once

#include "SFML/Graphics.hpp"

using namespace sf;

class Ball {
private:
	Vector2f position;
	float radius;
	Vector2f direction;
	float speed;
	Color color;

	CircleShape shape;

	void updateShape();

public:

	Ball(Vector2f position, float radius, float speed, Color color);
	~Ball();

	CircleShape getShape();

	void update(double dt);
};