
#include "SFML/Graphics.hpp"
#include <iostream>
#include "SFML/System/Vector2.hpp"
#include "SFML/Audio/Music.hpp"
#include "Audioplayer.h"

using namespace std;
int dosum(int a = 3, int b = 3) {
    return a + b;
}


int main()
{
    sf::Music file; 

    if (!file.openFromFile("C:/Users/sting/Downloads/Nightcore - Replay.wav")) {
        cerr << "music not opened";
    }
    file.play();
    AudioPlayer audioplayer;
    while (audioplayer.getWindow()->isOpen()) {
        sf::Event event;
        
        while (audioplayer.getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                std::cerr << "window closed";
                audioplayer.getWindow()->close();
            }
        }
    }
    /*
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::Vector2f speed{ 1.0f, 1.0f };

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                
                if (event.key.code == sf::Keyboard::W) {
                    shape.setPosition(shape.getPosition() + speed);
                }
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    */
    return 0;
}

