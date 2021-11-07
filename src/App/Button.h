#pragma once
//#include "sprite.hpp"
#include "Rect.hpp"
#include "IClickable.h"
#include "Window.hpp"
#include "RectangleShape.hpp"
#include "Texture.hpp"
#include "Vector2.hpp"
#include <functional>


//template <typename T>
class Button : public sf::RectangleShape, public IClickable
{

	
public:
	//click
	Button(){}
	void clicked();//pass in a callback
	//TODO: Learn to pass functions into functions as arguments
	Button( sf::Vector2f size, sf::Vector2f pos);
	~Button();
	Button(sf::Vector2f size, sf::Vector2f pos, std::function<void()>);
	void setupRectangle(sf::Vector2f size, sf::Vector2f pos);
private:

	std::function<void()> clickFunction; 
	
	//this is what will be called when the user clicks a buttoon
	//icon/button texture
	//Sprite icon;
	//bool wasClicked;
}; //class ends

