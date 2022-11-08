#pragma once

#include "SFML/Graphics.hpp"

using namespace sf;

class Player {
private:
	Vector2f position;
	Vector2f size;
	float speed;
	Color color;

	RectangleShape shape;

	void updateShape();

public:

	Player(Vector2f position, Vector2f size, float speed, Color color);
	~Player();

	RectangleShape getShape();

	void center();
	void move(float direction, double dt);
};