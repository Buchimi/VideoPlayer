#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H
#include "RenderWindow.hpp"
#include "IClickable.h"
#include <vector>
#include "Button.h"
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
	
	bool isOpened = true;

	std::vector<Button>* getButtons();
	void addButton(Button* clickableDeezNutz);
	void createButton();
private:
	// Window pointer
	sf::RenderWindow* window;
	
	// icons and buttons
	// music array/playlist
	// current music playing
	std::vector<Button> Buttons;
};




#endif // !AUDIOPLAYER_H
