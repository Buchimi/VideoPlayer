#pragma once
#include "Rect.hpp"
class IClickable
{
public:
	virtual ~IClickable();
	virtual void clicked() = 0;
	sf::Rect<int> rectangle;
private:

protected:
	
};


