#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H
#include "RenderWindow.hpp"
#include "IClickable.h"
#include <vector>
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

	std::vector<IClickable>* getClicables();
private:
	// Window pointer
	sf::RenderWindow* window;
	
	// icons and buttons
	// music array/playlist
	// current music playing
	std::vector<IClickable> clickables;
};




#endif // !AUDIOPLAYER_H
