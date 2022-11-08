#pragma once

class Settings {
private:
	static int windowWidth;
	static int windowHeight;

public:

	static void setWindowWidth(int _windowWidth);
	static void setWindowHeight(int _windowHeight);

	static int getWindowWidth();
	static int getWindowHeight();
};