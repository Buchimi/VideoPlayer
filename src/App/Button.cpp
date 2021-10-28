#include "Button.h"
#include "Window.hpp"
#include <iostream>
#include <IClickable.h>

//template<typename T>
Button::Button(sf::Vector2f size, sf::Vector2f pos) : sf::RectangleShape(size)
{
	setPosition(pos);
	rectangle.left = pos.x;
	rectangle.top = pos.y;
	rectangle.width = size.x;
	rectangle.height = size.y;
}
//template<typename T>
Button::~Button() {

}

void Button::clicked() {
	std::cout << "button was clicked" << std::endl;
}
//void IClickable::clicked() {
	//std::cout << "clickable was clicked" << std::endl;
//}
