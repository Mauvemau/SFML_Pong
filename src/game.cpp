#include "game.h"
#include "settings.h"

#include <iostream>
using namespace std;

// Private

void Game::manageInput(double dt) {
	if (Keyboard::isKeyPressed(Keyboard::Up)){
		player.move(-1, dt);
	}
	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		player.move(1, dt);
	}
}

void Game::draw() {
	window->clear();
	window->draw(player.getShape());
	window->draw(ball.getShape());
	window->display();
}

void Game::update(double dt) {
	Event event;
	while (window->pollEvent(event))
	{
		if (event.type == Event::Closed)
			window->close();
	}

	manageInput(dt);
	ball.update(dt);
}

// Public

Game::Game(int windowWidth, int windowHeight)
:
player({ static_cast<float>(windowWidth * .1f), static_cast<float>(windowHeight * .5f) }, { 25.0f, 100.0f }, 450.0f, Color(255, 0, 0, 255)),
ball({ { static_cast<float>(windowWidth * .5f), static_cast<float>(windowHeight * .5f) }, 15.0f, 200.0f, Color(0, 255, 0, 255) }) {

	window = new RenderWindow(VideoMode(windowWidth, windowHeight), "SFML Pong");

	Settings::setWindowWidth(windowWidth);
	Settings::setWindowHeight(windowHeight);

	player.center();

	points = { 0, 0 };
	cout << "Game object created!\n";
}

Game::~Game() {
	delete window;
	cout << "Game object destroyed!\n";
}

void Game::run() {
	Clock clock;
	while (window->isOpen()) {
		Time elapsed = clock.restart();
		double dt = elapsed.asSeconds();
		update(dt);
		draw();
	}
}