#include "Button.h"
//#include "Window.hpp"
#include <iostream>
//#include <IClickable.h>

//template<typename T>

Button::Button(sf::Vector2f size, sf::Vector2f pos) : sf::RectangleShape(size)
{
	setPosition(pos);
	setupRectangle(size, pos);

}

Button::Button(sf::Vector2f size, sf::Vector2f pos, std::function<void()> funcptr) : sf::RectangleShape(size)
{
	setPosition(pos);
	setupRectangle(size, pos);
	clickFunction = funcptr;
	//clickFunction = funcptr;
	
	//clickFunction = std::bind(funcptr);
}

//template<typename T>
Button::~Button() {

}


void Button::setupRectangle(sf::Vector2f size, sf::Vector2f pos) {
	rectangle.left = pos.x; //candidate for deletion
	rectangle.top = pos.y; //candidate for deletion
	rectangle.width = size.x;
	rectangle.height = size.y;
}

void Button::clicked() {
	std::cout << "button was clicked" << std::endl;
	clickFunction();
}
