#include <iostream>
#include "E:\Semester 2\END SEMESTER PROJECT\headers\Projectile.hpp"

// using namespace std;

Projectile::Projectile(sf::Vector2f p)
{
    // std::cout << "Projectile constructor called\n";
    setPosition(p);
    // std::cout << "Position is: " << p.x << " , " << p.y << std::endl;
}

bool Projectile::collisionDetection(sf::Sprite *obj)
{
    pos = getPosition();
    sf::Vector2f objPos = obj->getPosition();
    if ((pos.x == objPos.x) && (pos.y == objPos.y))
    {
        return true;
    }
    return false;
}
Projectile::~Projectile()
{
    std::cout << "Projectile destroyed br.....\n";
}
