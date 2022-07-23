#pragma once
#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Audio.hpp>
#include "char.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "NPC.hpp"
#include "Projectile.hpp"

class Game
{
private:
    /* data */
    void processEvents();
    void update();
    void render();
    /*   void updateBackground();
       void renderingBackground();*/

    void handleKeyboardInput(sf::Keyboard::Key, bool); // tester
    void shootProjectile(sf::Vector2f);                //  tester
    sf::Vector2f mouseCoord;
    int frame;

    bool initialized;
    float increment = 50.f / 60.f;


public:
    // sf::Music musicbg;
    
    float y_for_pos = 0;

    sf::RenderWindow *screenPtr;
    sf::Sprite *BackgroundPtr;
    sf::Sprite *BackgroundPtr2;
    sf::Texture bgTexture;
    sf::Texture bgTexture2;

    Char *heroPtr;
    sf::Texture Texture;
    sf::Texture enemy1;
    sf::Texture bullet;
    const sf::Vector2f heroDefaultPos;
    sf::Texture Texture2;
    std::vector<std::vector<NPC *>> NPCs; // One sub vector represents a row of goons
    const sf::Vector2f goonSize;
    std::vector<NPC *> populateGoons(int); // tester
    void sendGoons(std::vector<NPC *>);    // tester
    float x_for_pos = 0;

    std::vector<std::vector<Projectile *>> projectiles; // one sub vector represents a colums of projectiles
    void drawProjectile();
    void projectileMaker(bool);
    void moveProjectile();
    // void projectileShooter(bool);

    void collisionDetection(int);
    void collisionHappened(int, int);
    void collisionHappened(int, int, int, int);

    sf::Clock clock;
    sf::Time passedTime;

private:
    sf::Time TimePerFrame;
    bool diskIsMovingUp, diskIsMovingDown, diskIsMovingLeft, diskIsMovingRight; // tester

public:
    Game();
    void run();
    ~Game();
};
