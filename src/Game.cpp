#include <iostream>
#include "E:\Semester 2\END SEMESTER PROJECT\headers\Game.hpp"
#include "char.cpp"
#include "NPC.cpp"
#include "Projectile.cpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <Windows.h>
#include<SFML/Audio.hpp>
// using namespace std;

Game::Game() : heroDefaultPos(sf::Vector2f(247, 200)), goonSize(sf::Vector2f(20, 20))
{
    frame = 1;
    BackgroundPtr = new sf::Sprite();
    BackgroundPtr2 = new sf::Sprite();
    screenPtr = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Game Run", sf::Style::Default),
    TimePerFrame = sf::seconds(1.f / 60.f);
    /* sf::View View (sf::FloatRect(0.f, 0.f, 1000.f, 600.f));
     screenPtr->setView(View);*/
    // disk1 = play.generate();
    diskIsMovingUp = diskIsMovingDown = diskIsMovingLeft = diskIsMovingRight = false;
    // projectilePtr = nullptr;
    // projectiles.push_back(nullptr);

    // HERO DISPLAY
    heroPtr = new Char(heroDefaultPos);
    NPCs.push_back(populateGoons(1));
    NPCs.push_back(populateGoons(2));
    NPCs.push_back(populateGoons(3));
    NPCs.push_back(populateGoons(4));
    // std::cout << "GAME UPDAYTEED\n";
    if (!Texture.loadFromFile("E:/Semester 2/END SEMESTER PROJECT/SpaceShip.png"))
    {
        std::cout << "Image Load Failed!" << std::endl;
    }
    // std::cout << "GAME UPDAYTEED 3\n";
    enemy1.loadFromFile("E:/Semester 2/END SEMESTER PROJECT/enemy1-100.png");
    // bullet.loadFromFile("E:/Semester 2/END SEMESTER PROJECT/smokebullet-50.png");
    if (!bullet.loadFromFile("E:/Semester 2/END SEMESTER PROJECT/bullet4.png"))
    {
        std::cout << "Image Load Failed buuletttt!" << std::endl;
    }
    // SpritePtr->setTexture(*TexturePtr);
    heroPtr->setTexture(Texture);
    heroPtr->setOrigin(heroDefaultPos);

    // BACKGROUND DISPLAY
    // BackgroundPtr = new Char();
    // std::cout << "BackgroundPtr Char upDated" << std::endl;
    if (!bgTexture.loadFromFile("E:/Semester 2/END SEMESTER PROJECT/Backgroundnew4.jpg"))
    {
        std::cout << "Background Image Load Failed!" << std::endl;
    }
    if (!bgTexture2.loadFromFile("E:/Semester 2/END SEMESTER PROJECT/Backgroundnew4v2.jpg"))
    {
        std::cout << "Background Image Load Failed!" << std::endl;
    }
    // if (!musicbg.openFromFile("E:/Semester 2/END SEMESTER PROJECT/driftingTrimmed.ogg"))
    // {
    //     std::cout << "Music Load Failed!" << std::endl;
    // }
    BackgroundPtr->setTexture(bgTexture);
    BackgroundPtr2->setTexture(bgTexture2);

    BackgroundPtr->setOrigin(0, 0);
    BackgroundPtr2->setOrigin(0, 0);

    BackgroundPtr->setPosition(0, 1);
    BackgroundPtr2->setPosition(0, -1079);
    // std::cout << BackgroundPtr->getPosition().x << std::endl
    //           << BackgroundPtr->getPosition().y << std::endl;
    // std::cout << "GAME UPDAYTEED 6\n";
    // Texture2.setRepeated(true);
    // BACKGROUND DISPLAY 2
    // BackgroundPtr2 = new Char();
    // BackgroundPtr2->setTexture(Texture2);
    // std::cout << "BackgroundPtr Char2 upDated" << std::endl;

    // Projectile Setup
    projectiles.push_back(std::vector<Projectile *>());
    projectiles.push_back(std::vector<Projectile *>());
    initialized = false;
    // frame = 0;
    // Background->setPosition(sf::Vector2f(0, 0));
}

void Game::run()
{
    // musicbg.play();
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (screenPtr->isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update();
        }
        render();

        // std::cout << "changes made3";
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (screenPtr->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            screenPtr->close();
            break;
        case sf::Event::KeyPressed:
            handleKeyboardInput(event.key.code, true);
            // std::cout<<"Key pressed "<<event.key.code<<std::endl;
            break;
        case sf::Event::KeyReleased:
            handleKeyboardInput(event.key.code, false);
            // std::cout<<"Key pressed "<<event.key.code<<std::endl;
            break;
        case sf::Event::MouseMoved:
            mouseCoord.x = event.mouseMove.x;
            mouseCoord.y = event.mouseMove.y;
            // std::cout<<"This occured\n";
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                mouseCoord.x = event.mouseButton.x;
                mouseCoord.y = event.mouseButton.y;
                initialized = true;
                // std::cout << "X and Y : " << mouseCoord.x << "   " << mouseCoord.y << std::endl;

                // if (projectilePtr == nullptr)
                // {
                //     projectilePtr = new Projectile;
                // }
            }
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                // if (projectilePtr != nullptr)
                // {
                //     delete projectilePtr;
                //     projectilePtr = nullptr;
                //     std::cout << "right\n";
                // }
            }
            break;

        default:
            break;
        }
    }
}

void Game::update()
{

    // y_for_pos += 0.6f;
    BackgroundPtr->move(0, 1.0f);
    BackgroundPtr2->move(0, 1.0f);
    int bg1;
    (int(BackgroundPtr->getPosition().y) % 1080) == 0 ? bg1 = 1 : bg1 = 0;
    int bg2;
    (int(BackgroundPtr2->getPosition().y) % 1080) == 0 ? bg2 = 1 : bg2 = 0;

    if (bg1)
    {
        BackgroundPtr->setPosition(0, -1079);
    }
    if (bg2)
    {
        BackgroundPtr2->setPosition(0, 1);
    }
    heroPtr->setPosition(mouseCoord);

    if (frame % 1000 == 0)
    {
        increment *= -1;
    }
    x_for_pos += increment;

    // x_for_pos > 570 ? x_for_pos = 570 - x_for_pos : true;
    for (int l = 0; l < NPCs.size(); l++)
    {
        for (int i = 0; i < NPCs[l].size(); i++)
        {
            NPCs[l][i]->adjustPosition(x_for_pos);
        }
    }
    if (frame % 20 == 0)
    {
        projectileMaker(initialized);
    }
    if (initialized && projectiles[0].size() >= 1)
    {
        moveProjectile(); // Move the previous projectile up before making new ones
        for (int c = 0; c < projectiles.size(); c++)
        {
            collisionDetection(c);
        }
    }

    frame++;
}

void Game::render()
{
    screenPtr->clear();
    if (BackgroundPtr != nullptr)
    {
        screenPtr->draw(*BackgroundPtr);
    }
    if (BackgroundPtr2 != nullptr)
    {
        screenPtr->draw(*BackgroundPtr2);
    }

    screenPtr->draw(*heroPtr);
    for (int l = 0; l < NPCs.size(); l++)
    {
        sendGoons(NPCs[l]);
    }

    drawProjectile();

    screenPtr->setMouseCursorVisible(false);
    screenPtr->display();
}

std::vector<NPC *> Game::populateGoons(int level)
{
    // std::cout << "Starting population\n";
    std::vector<NPC *> NPCtemp;
    for (int i = 1; i < 6; i++)
    {
        // std::cout << "populating " << i << std::endl;
        NPCtemp.push_back(new NPC(level, i));
        NPCtemp[i - 1]->setTexture(enemy1);
        NPCtemp[i - 1]->setTextureRect(sf::IntRect(0, 0, 100, 100));
        //  std::cout << "moving on\n";
    }
    return NPCtemp;
}

void Game::sendGoons(std::vector<NPC *> NPCtemp)
{

    for (int i = 0; i < NPCtemp.size(); i++)
    {

        screenPtr->draw(*NPCtemp[i]);
    }
}

void Game::drawProjectile()
{
    for (int i = 0; i < projectiles.size(); i++)
    {
        for (int j = 0; j < projectiles[i].size(); j++)
        {
            screenPtr->draw((*projectiles[i][j]));
        }
    }
}

void Game::projectileMaker(bool s)
{
    if (s)
    {
        for (int i = 0; i < 2; i++)
        {
            if (i % 2 == 0)
            {
                // std::cout << "Here\n";
                projectiles[i].push_back(new Projectile(sf::Vector2f(mouseCoord.x + 10, mouseCoord.y)));
                projectiles[i].back()->setTexture(bullet);
                projectiles[i].back()->setTextureRect(sf::IntRect(0, 0, 18, 51));

                // std::cout << "Projectile made in " << frame << " frame of col" << i << "  \n";
            }
            else
            {
                // std::cout << "Here 2.O\n";
                projectiles[i].push_back(new Projectile(sf::Vector2f(mouseCoord.x - 10, mouseCoord.y)));
                projectiles[i].back()->setTexture(bullet);
                projectiles[i].back()->setTextureRect(sf::IntRect(0, 0, 18, 51));
                // std::cout << "Projectile 2.O made in " << frame << " frame of col" << i << "  \n";
            }
        }
        // moveProjectile(); // Move the previous projectile up before making new ones
    }
}

void Game::moveProjectile() // moves each projectile up on the y axis
{
    // std::cout << "CP1\n";
    //  int i = 0;
    // std::cout << "CP2\n";
    for (int i = 0; i < projectiles.size(); i++)
    {
        // std::cout << "CP3\n";
        for (int j = 0; j < projectiles[i].size(); j++)
        {
            // std::cout<<"CP4\n";
            // std::cout << i << " , " << j << std::endl;
            projectiles[i][j]->move(sf::Vector2f(0, -5));
        }
    }
    // for (int j = 0; j < projectiles[i].size(); j++)
    // {
    //     std::cout << "CP3\n";
    //     for (i = 0; i < projectiles.size(); i++)
    //     {
    //         // std::cout<<"CP4\n";
    //         std::cout << i << " , " << j << std::endl;
    //         projectiles[i][j]->move(sf::Vector2f(0, -10));
    //     }
    // }
}

void Game::collisionDetection(int C)
{
    for (int pC = 0; pC < projectiles.size(); pC++)
    {
        for (int pR = 0; pR < projectiles[pC].size(); pR++)
        {
            float p_x = projectiles[pC][pR]->getPosition().x;
            float p_y = projectiles[pC][pR]->getPosition().y;
            if ((p_x > 1920) || (p_y < 0))
            {
                collisionHappened(pC, pR);
            }
            else
            {
                for (int i = 0; i < NPCs.size(); i++)
                {
                    for (int j = 0; j < NPCs[i].size(); j++)
                    {

                        float a_x = NPCs[i][j]->getPosition().x;
                        float a_y = NPCs[i][j]->getPosition().y;
                        bool condition = (fabs(a_x - p_x) <= 40) && (fabs(a_y - p_y) <= 80);
                        // bool c2 = a_Rect.intersects(b_Rect);

                        if (condition)
                        {
                            // std::cout << "old collision happened " << a_x << " , " << a_y << "  & " << p_x << " , " << p_y << std::endl;
                            collisionHappened(i, j, pC, pR);
                        }
                    }
                }
            }
        }
    }
}

void Game::collisionHappened(int pC, int pR)
{

    projectiles[pC][pR] = nullptr;
    delete projectiles[pC][pR];
    // projectiles[C].pop_front();
    projectiles[pC].erase(projectiles[pC].begin() + pR);
    // projectiles[R][0]->~Projectile();
}
void Game::collisionHappened(int i, int j, int pC, int pR)
{
    NPCs[i][j]->tookHit();
    if (NPCs[i][j]->getHealth() <= 0)
    {
        // NPCs[i][j]->setTexture(bullet);

        NPCs[i][j] = nullptr;
        delete NPCs[i][j];
        NPCs[i].erase(NPCs[i].begin() + j);
    }
    projectiles[pC][pR] = nullptr;
    delete projectiles[pC][pR];
    // projectiles[C].pop_front();
    projectiles[pC].erase(projectiles[pC].begin() + pR);
    // projectiles[R][0]->~Projectile();
}

void Game::handleKeyboardInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::W)
        diskIsMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        diskIsMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        diskIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        diskIsMovingRight = isPressed;
}

Game::~Game()
{
    std::cout << "Game destroyed \n";
}
