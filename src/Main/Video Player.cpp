
#include "SFML/Graphics.hpp"
#include <iostream>
#include "SFML/Audio/Music.hpp"
#include "Audioplayer.h"
#include "Mouse.hpp"
#include "Vector2.hpp"
using namespace std;


void manageClicks();




int main()
{
    sf::Music file; 

    if (!file.openFromFile("C:/Users/sting/Downloads/Nightcore - Replay.wav")) {
        cerr << "music not opened";
    }
    file.play();
    //makes an audio player
    AudioPlayer audioplayer;
    
    //makes a button and loads it with texture
    Button* button = new Button(sf::Vector2f(50.0f, 50.0f), sf::Vector2f(500.0f, 500.0f));
    audioplayer.addButton(button);//button is a pointer
    sf::Image image;
    sf::Texture texture;
    image.loadFromFile("C:/Users/sting/OneDrive/Documents/racist.png");
    texture.loadFromImage(image, sf::Rect<int>(50,50,50,50));

    button->setTexture(&texture, false);

    //app loop
    while (audioplayer.getWindow()->isOpen()) {
        sf::Event event;
        
        while (audioplayer.getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                std::cerr << "window closed";
                audioplayer.getWindow()->close();
            }
            //if we got a click
            if (event.type == sf::Event::MouseButtonPressed) 
            {
                sf::Vector2i mousepos = sf::Mouse::getPosition((*audioplayer.getWindow()));
                std::cout << "Clicked" << endl;
                for (int i = 0; i < audioplayer.getButtons()->size(); ++i) {
                    //IClickable* objectref = &(audioplayer.getClicables()->at(i));
                    auto& objectref = audioplayer.getButtons()->at(i);
                    cout << "x: "<< mousepos.x << ", y: " << mousepos.y << endl;
                    cout << "rectangleleft: " << objectref.rectangle.left << " to " << objectref.rectangle.width;
                        //+ objectref->rectangle.left;
                    if (objectref.rectangle.contains(mousepos)) {//objectref->rectangle.contain(sf::Mouse.getPosition())
                        std::cout << mousepos.x << ", " << mousepos.y << endl;
                        objectref.clicked();
                    }
                }
            }
        }
        //cleanup code
        audioplayer.getWindow()->clear();
        audioplayer.getWindow()->draw(*button);
        audioplayer.getWindow()->display();
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

void manageClicks()
{
    
}