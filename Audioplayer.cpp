#include "AudioPlayer.h"

#include <iostream>

AudioPlayer::AudioPlayer()
{
	std::cout << "Hello" << std::endl;
	createWindow();
	if (!file.openFromFile("C:/Users/sting/Downloads/Nightcore - Replay.wav")) {
		std::cerr << "music not opened";
	}
	file.play();
	playing = true;
}

AudioPlayer::~AudioPlayer()
{
}

sf::RenderWindow* AudioPlayer::getWindow() {

	return window;
}

void AudioPlayer::createWindow() {
	//sf::RenderWindow newWindow(sf::VideoMode(1200, 1200), "Hello world");

	window = new sf::RenderWindow(sf::VideoMode(1200, 1200), "Hello window");
	isOpened = true;
}
void AudioPlayer::closeApp() {
	window->clear();
	isOpened = false;
}


void AudioPlayer::togglePause() {
	if (playing) 
	{
		file.pause();
		playing = false;
	}
	else {

		file.play();
		playing = true;
	}
}

std::vector<Button>* AudioPlayer::getButtons() {
	return &Buttons;
}

void AudioPlayer::createButton() {
	Button* newButton = new Button(sf::Vector2f(5.0f, 5.0f), sf::Vector2f(5.0f, 5.0f));

}

void AudioPlayer::addButton(Button* clickableDeezNutz) {
	Buttons.push_back(*clickableDeezNutz);
}

void AudioPlayer::draw() {
	for (auto& obj : *getButtons() ) {
		getWindow()->draw(obj);
	}
}
