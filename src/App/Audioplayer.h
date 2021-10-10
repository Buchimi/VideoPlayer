#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H
#include "SFML/Graphics//RenderWindow.hpp"

class AudioPlayer
{
public:
	AudioPlayer();
	~AudioPlayer();

	void createWindow();
	
	//get window
	sf::RenderWindow* getWindow();

	//closes app
	void closeApp();
	
	bool isOpened = true;
private:
	// Window pointer
	sf::RenderWindow* window;
	// icons and buttons
	// music array/playlist
	// current music playing

};




#endif // !AUDIOPLAYER_H
