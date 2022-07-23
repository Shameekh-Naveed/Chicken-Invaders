#include <iostream>
#include <cstdlib>
#include "E:\Semester 2\END SEMESTER PROJECT\headers\NPC.hpp"
// using namespace std;

NPC::NPC(int l, int n)
{
    // std::cout << "NPC Constructor\n";
    // size = s;
    health = 100*(l);
    level = (float)l;
    num = n;
    pos_x = 0.f;
    pos_y = (float)level;

    setPosition(pos_x, pos_y);
    setOrigin(pos_x, pos_y);
    // position.x = 0;
    // position.y = level;
    // setSize(size);
    // setPosition(position);
    // std::cout<<"Npc constructor end\n";
}

void NPC::adjustPosition(float x)
{

    pos_x = x + (200 * num);

    // float x_in_rad = x * 3.14159/180;
    if (x < 77.809)
    {
        pos_y = 500 - (80 * level) - ((1.f / 20.f) * (x * x)); // n is floor level
        if (pos_y < (20 * level))
            pos_y = 20 * level;
    }
    else if (x >= 77.809 && x <= 1820) // 400 window width
    {
        // pos_y = (float)(15.f * (fabs(sin((0.05f * pos_x)) + (float)(5.f * level)))); // num is the villain number
        pos_y = (15.f * (fabs(sin((0.05f * pos_x)) + (8.5f * level)))); // num is the villain number
    }
    else
    {
        // x = 571;
        // pos_x = pos_x = 570 + (50 * num);
        // pos_y = (float)(15.f * (fabs(sin((0.05f * 571)) + (float)(5.f * level)))) * sin(x / 33);
        // pos_y *= sin(x);
        // if (pos_y >=  100)
        // {
        //     pos_y -= 0.7f;
        // }
        // else
        // {
        //     pos_y += 0.7f;
        // }
        // pos_y = (float)(15.f * (fabs(sin((x)) + (float)(4.f * level)))); // num is the villain number
        // position.y = abs(sin(x)) + level;  // n is the level
        // position.y = 0; // n is the level
    }
    // std::cout << "x & y for " << level << "  &  " << num << " ==  " << pos_x << "  " << pos_y << std::endl;
    setPosition(pos_x, pos_y);
    // return position;
}

void NPC::tookHit()
{
    decreaseHealth();
    // if (health <= 0)
    // {
    //     NPC::~NPC();
    // }
}

int NPC::getHealth(){
    return health;
}

NPC::~NPC()
{
    std::cout << "NPC Destroyed buhahahahha...\n";
}
