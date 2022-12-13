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

Interface::Interface() : window(new RenderWindow(VideoMode(800, 800), "SFML works!")), rectangle(RectangleShape(Vector2f(10, 10))), matrix(Matrix(80, 80)), acteurs(vector<Acteur*>())
{
    window->setFramerateLimit(20);
}

Interface::Interface(Matrix& A) : window(new RenderWindow(VideoMode(800, 800), "SFML works!")), rectangle(RectangleShape(Vector2f(10, 10))), matrix(A), acteurs(vector<Acteur*>())
{
    window->setFramerateLimit(20);
}

Interface::Interface(Matrix& A, vector<Acteur*>& acteurs) : window(new RenderWindow(VideoMode(800, 800), "SFML works!")), rectangle(RectangleShape(Vector2f(10, 10))), matrix(A), acteurs(acteurs)
{
    window->setFramerateLimit(20);
}

Interface::~Interface()
{
    delete window;
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
        //window->draw(rectangle);
        window->display();
    }
}

void Interface::close()
{
    window->close();
}