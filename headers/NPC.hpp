#pragma once
#include<cmath>
#include<SFML\Graphics\RectangleShape.hpp>
#include "Char.hpp"
class NPC : public Char
{
private:
    float level;
    int num;
    // sf::Vector2f pos;
    float pos_x;
    float pos_y;
public:
    NPC(int,int); // uniquely for enemies
    void adjustPosition(float);
    void tookHit();
    int getHealth();
    ~NPC();
};

