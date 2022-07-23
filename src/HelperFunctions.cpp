#include<iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
// #include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>

// using namespace std;

void mover(sf::CircleShape *obj,int x){
    for (int i = 0; i < x; i++)
    {
       (*obj).move(i,i);
    
    }
    
}
