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

Interface::Interface() : window(new RenderWindow(VideoMode(LARGEUR, HAUTEUR), "SFML works!")), rectangle(RectangleShape(Vector2f(10, 10))), matrix(Matrix(80, 60))
{
    window->setFramerateLimit(60);
    window->setVerticalSyncEnabled(true);

    /*
    font.loadFromFile("arial_mt_black/ARIBL0.ttf");
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(Color::White);
    text.setPosition(10, 10);
    */
}

Interface::Interface(RenderWindow* window) : window(window), rectangle(RectangleShape(Vector2f(10, 10))), matrix(Matrix(80, 60))
{
    window->setFramerateLimit(20);
}

Interface::Interface(RenderWindow* window, Matrix& matrix) : window(window), rectangle(RectangleShape(Vector2f(10, 10))), matrix(matrix)
{
    window->setFramerateLimit(20);
}

Interface::Interface(RenderWindow* window, RectangleShape& rectangle) : window(window), rectangle(rectangle), matrix(Matrix(80, 60))
{
    window->setFramerateLimit(20);
}

Interface::Interface(RenderWindow* window, RectangleShape& rectangle, Matrix& matrix) : window(window), rectangle(rectangle), matrix(matrix)
{
    window->setFramerateLimit(20);
}


Interface::~Interface()
{
    
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

        for (int i = 0; i < matrix.getLignes(); i++)
        {
            for (int j = 0; j < matrix.getColonnes(); j++)
            {
                rectangle.setPosition(i * 10, j * 10);
                if (matrix(i, j) == 0)
                {
                    // rectangle vide avec bordure
                    rectangle.setFillColor(Color::White);
                    rectangle.setOutlineColor(Color::Black);
                    rectangle.setOutlineThickness(1);
                }
                else
                {
                    // rectangle plein
                    rectangle.setFillColor(Color::Black);
                    rectangle.setOutlineColor(Color::Black);
                    rectangle.setOutlineThickness(1);
                }
                window->draw(rectangle);
            }
        }

        window->display();

        sleep(milliseconds(100));
    }
}

void Interface::close()
{
    window->close();
}