#pragma once
// #include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
class Char : public sf::Sprite
{
protected:
    float health;

public:
    // sf::Vector2f position;
    Char();
    Char(sf::Vector2f);

    void decreaseHealth();

    // void addProjectile();
    // void shootProjectile();
    // sf::Vector2f getPosition();
    // void setPosition(sf::Vector2f);
    ~Char();
};
