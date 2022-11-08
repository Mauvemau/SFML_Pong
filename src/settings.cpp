#include "settings.h"

int Settings::windowWidth = 0;
int Settings::windowHeight = 0;

void Settings::setWindowWidth(int _windowWidth) {
	windowWidth = _windowWidth;
}

void Settings::setWindowHeight(int _windowHeight) {
	windowHeight = _windowHeight;
}

int Settings::getWindowWidth() {
	return windowWidth;
}

int Settings::getWindowHeight() {
	return windowHeight;
}