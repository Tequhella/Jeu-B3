/**
 * @file interface.cpp
 * @author Lilian CHARDON (lilian.chardon@ynov.com)
 * @brief 
 * @version 0.1
 * @date 06-12-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../headers/interface.h"

/****************/
/* CONSTRUCTEUR */
/****************/

Interface::Interface()
{
    window = new RenderWindow(VideoMode(200, 200), "SFML works!");
    rectangle = new RectangleShape(Vector2f(100, 100));
    rectangle->setFillColor(Color::Green);
    acteur = new Acteur();
}

Interface::~Interface()
{
    delete window;
    delete rectangle;
    delete acteur;
}


/************/
/* METHODES */
/************/

void Interface::display()
{
    while (window->isOpen())
    {
        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)
                window->close();
        }

        window->clear();
        window->draw(*rectangle);
        window->display();
    }
}

void Interface::close()
{
    window->close();
}