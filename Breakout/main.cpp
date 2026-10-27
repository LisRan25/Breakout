#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include <iostream>
#include "ImageManager.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(1000, 800), "Breakout");
    GameManager gameManager(&window);
    gameManager.initialize();

    ImageManager images;
    images.loadTexture("Images/teehee.jpg");
    sf::Sprite sprite(images.getRandomTexture());

    sf::Clock clock;
    float deltaTime;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        deltaTime = clock.restart().asSeconds();

        gameManager.update(deltaTime);

        window.clear();
        gameManager.render();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
