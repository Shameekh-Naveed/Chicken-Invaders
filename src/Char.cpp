#include <iostream>
#include<SFML\Graphics\Sprite.hpp>
#include "E:/Semester 2/END SEMESTER PROJECT/headers/Char.hpp"

// using namespace std;

Char::Char()
{
    // std::cout<<"Default char constructor called\n";
    //  setOrigin(position);
    // setSize(size);
    
}
Char::Char(sf::Vector2f p)
{
    // std::cout<<"Parameter char constructor called\n";

    setPosition(p);
    // position = p;
    // size=s;
    // // setOrigin(position);
    // setPosition(position);
    // setSize(size);
    //size=s;
    //// setOrigin(position);
    //setPosition(position);
    //setSize(size);

}

//sf::Vector2f Char::getPosition(){
//    return position;
//}

//void Char::setPosition(sf::Vector2f p) {
//    position.x = p.x;
//    position.y = p.y;
//}

void Char::decreaseHealth(){
    health-=20;
}

Char::~Char()
{
    std::cout<<"Char has been destroyed\n";
}
