#include <iostream>
#include "Game.cpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/SoundSource.hpp>
#include <SFML/Audio/SoundStream.hpp>
int main()
{
    sf::RenderWindow *screenNew = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Game Run", sf::Style::Default);
    sf::Sprite *mainScreenPtr = new sf::Sprite();
    sf::Texture mainScreen;
    // sf::Music musicfg;
    // if (!musicfg.openFromFile("E:/Semester 2/END SEMESTER PROJECT/musicfg.ogg"))
    // {
    //     std::cout << "Music Load Failed!" << std::endl;
    // }
    if (!mainScreen.loadFromFile("E:/Semester 2/END SEMESTER PROJECT/mainScreen2.png"))
    {
        std::cout << "Main Screen Load Failed!" << std::endl;
    }
    mainScreenPtr->setTexture(mainScreen);
    mainScreenPtr->setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    // musicfg.play();
    while (screenNew->isOpen())
    {
        sf::Event event;
        while (screenNew->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                screenNew->close();
                // musicfg.stop();
                break;

            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    screenNew->close();
                    // musicfg.stop();
                }
                break;
            }
        }
        screenNew->clear();
        screenNew->draw(*mainScreenPtr);
        screenNew->display();
    }

    Game mainGame;
    mainGame.run();

    // return 0;
}