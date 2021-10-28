#pragma once
//#include "sprite.hpp"
#include "Rect.hpp"
#include "IClickable.h"
#include "Window.hpp"
#include "RectangleShape.hpp"
#include "Texture.hpp"
#include "Vector2.hpp"
//template <typename T>
class Button : public sf::RectangleShape, public IClickable
{
public:
	//click
	
	void clicked();//pass in a callback
	//TODO: Learn to pass functions into functions as arguments
	Button( sf::Vector2f size, sf::Vector2f pos);
	~Button();

private:
	//icon/button texture
	//Sprite icon;
	//bool wasClicked;

}; //class ends

