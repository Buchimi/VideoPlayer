#pragma once


#include "Button.h"
#include "RenderWindow.hpp"
#include "IClickable.h"
#include <vector>

#include "SFML/Audio/Music.hpp"

class AudioPlayer
{
public:
	AudioPlayer();
	~AudioPlayer();

	//get window
	sf::RenderWindow* getWindow();

	void createWindow();
	//closes app
	void closeApp();
	Button but;
	bool isOpened = true;
	std::vector<Button>* getButtons();
	
	void addButton(Button* clickableDeezNutz);
	void createButton();
	
	void draw();

	void togglePause();
private:
	// Window pointer
	sf::RenderWindow* window;
	// icons and buttons
	std::vector<Button> Buttons;
	bool playing;
	// current music playing
	sf::Music file;
	// music array/playlist
};