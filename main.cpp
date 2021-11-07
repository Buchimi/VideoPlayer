#include "Audioplayer.h"

#include "SFML/Graphics.hpp"
#include <iostream>

#include "Mouse.hpp"
#include "Vector2.hpp"
#include <functional>


using namespace std;

void initializeButtons(AudioPlayer&);

void manageClicks(sf::Event, AudioPlayer&);


void togglePause(AudioPlayer& aud) {
    aud.togglePause();
}
int main()
{

    //makes an audio player
    AudioPlayer audioplayer;

    //Button* playButton = new Button(sf::Vector2f(50.0f, 50.0f), sf::Vector2f(550.0f, 1000.0f), std::bind(&AudioPlayer::togglePause, &audioplayer));
    //makes a button and loads it with texture
    initializeButtons(audioplayer);

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
                manageClicks(event, audioplayer);
            }
        }
        //cleanup code
        audioplayer.getWindow()->clear();
        audioplayer.draw();
        audioplayer.getWindow()->display();
    }

    return 0;
}


void foo() {}

void manageClicks(sf::Event event, AudioPlayer& audioplayer)
{
    sf::Vector2i mousepos = sf::Mouse::getPosition(*audioplayer.getWindow());
    std::cout << "mouse was clicked" << endl;
    for (int i = 0; i < audioplayer.getButtons()->size(); ++i) {
        //get button
        Button& objectref = audioplayer.getButtons()->at(i);

        cout << "x: " << mousepos.x << ", y: " << mousepos.y << endl;
        cout << "rectangle co-ordinates, x: " << objectref.rectangle.left << "y: " << objectref.rectangle.top << endl;
        cout << "rect size, width: " << objectref.rectangle.width + objectref.rectangle.left << " height: " << objectref.rectangle.top + objectref.rectangle.height << endl;
        //cout << "rectangleleft: " << objectref.rectangle.left << " to " << objectref.rectangle.width + objectref.rectangle.left  << endl;
        //+ objectref->rectangle.left;

        //check to see if a button was clicked
        if (objectref.rectangle.contains(mousepos)) {//objectref->rectangle.contain(sf::Mouse.getPosition())
            std::cout << mousepos.x << ", " << mousepos.y << endl;
            objectref.clicked();
        }
    }
}

void initializeButtons(AudioPlayer& audioplayer) {
    sf::Vector2f buttonpos;
    sf::Vector2f buttonsize;
    sf::Image image;
    sf::Texture texture;
    //Play Button
    //std::function<void(AudioPlayer&)> funcToPass{ togglePause};
    //std::function<void()> funcToPass{ AudioPlayer::togglePause };
    Button* playButton = new Button(sf::Vector2f(50.0f, 50.0f), sf::Vector2f(550.0f, 1000.0f), std::bind(&AudioPlayer::togglePause, &audioplayer));
    //Button* playButton = new Button(sf::Vector2f(50.0f, 50.0f), sf::Vector2f(550.0f, 1000.0f));

    buttonpos = playButton->getPosition();
    buttonsize = playButton->getSize();
    audioplayer.addButton(playButton);//button is a pointer
    image.loadFromFile("C:/Users/sting/OneDrive/Documents/racist.png");
    texture.loadFromImage(image, sf::Rect<int>(buttonpos.x, buttonpos.y, buttonsize.x, buttonsize.y));
    playButton->setTexture(&texture, false);

    /*
    //Pause button
    Button* pauseButton = new Button(sf::Vector2f(50.0f, 50.0f), sf::Vector2f(200.0f, 200.0f));
    buttonpos = pauseButton->getPosition();
    buttonsize = pauseButton->getSize();
    audioplayer.addButton(pauseButton);//button is a pointer

    image.loadFromFile("C:/Users/sting/OneDrive/Documents/racist.png");
    texture.loadFromImage(image, sf::Rect<int>(buttonpos.x, buttonpos.y, buttonsize.x, buttonsize.y));
    playButton->setTexture(&texture, false);*/
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
