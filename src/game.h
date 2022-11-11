#pragma once

#include "player.h"
#include "ball.h"

using namespace sf;

class Game {
private:
	Player player;
	Player playerTwo;
	Ball ball;
	Vector2i points;

	RenderWindow* window;

	void manageInput(double dt);
	void draw();
	void update(double dt);

public:

	Game(int windowWidth, int windowHeigh);
	~Game();

	void run();
};