#include "Audioplayer.h"
#include <iostream>

AudioPlayer::AudioPlayer()
{
	std::cout << "Hello" << std::endl;
	createWindow();
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

std::vector<Button>* AudioPlayer::getButtons() {
	return &Buttons;
}

void AudioPlayer::createButton() {
	Button* newButton = new Button(sf::Vector2f(5.0f, 5.0f), sf::Vector2f(5.0f, 5.0f));

}

void AudioPlayer::addButton(Button* clickableDeezNutz) {
	Buttons.push_back(*clickableDeezNutz);
}