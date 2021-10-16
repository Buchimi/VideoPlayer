#pragma once
#include "sprite.hpp"
#include "Rect.hpp"
#include "IClickable.h"
#include "Window.hpp"

template <typename T>
class Button : sf::Sprite, sf::Rect<T>, IClickable
{
public:
	//click
	//void clicked();//pass in a callback
	//TODO: Learn to pass functions into functions as arguments
	void checkForClicks(sf::Event event) {

	}
	//Button();
	//~Button();
private:
	//icon/button texture
	Sprite icon;
	bool wasClicked;

}; //class ends

