
#include "SFML/Graphics.hpp"
#include <iostream>
#include "SFML/Audio/Music.hpp"
#include "Audioplayer.h"
#include "Mouse.hpp"
#include "Vector2.hpp"
using namespace std;

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
            }/*
            if (event.type == sf::Event::MouseButtonPressed) 
            {
                sf::Vector2i mousepos = sf::Mouse::getPosition();
                for (int i = 0; i < audioplayer.getClicables()->size(); ++i) {
                    IClickable* objectref = &(audioplayer.getClicables()-.at(i));
                    if (objectref->rectangle.contains(mousepos)) {//objectref->rectangle.contain(sf::Mouse.getPosition())

                    }
                }
            }*/
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

