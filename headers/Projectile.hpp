#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Projectile : public sf::Sprite
{
private:
    sf::Vector2f pos;
    const sf::Vector2f size;
public:
    Projectile(sf::Vector2f);
    bool collisionDetection(sf::Sprite*);
    ~Projectile();
};

