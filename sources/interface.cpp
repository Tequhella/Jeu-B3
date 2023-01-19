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

Interface::Interface() : window(new RenderWindow(VideoMode(LARGEUR, HAUTEUR + 50), "SFML works!")), rectangle(RectangleShape(Vector2f(10, 10))), matrix(Matrix(80, 60))
{
    window->setFramerateLimit(20);
    window->setVerticalSyncEnabled(true);

    /*
    font.loadFromFile("arial_mt_black/ARIBL0.ttf");
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(Color::White);
    text.setPosition(10, 10);
    */
    // gestion click souris
    event.mouseButton.button = Mouse::Left;
    event.mouseButton.x = 0;
    event.mouseButton.y = 0;

    // bouton start
    struct ButtonArgs args = 
    {
        .rectangle      = RectangleShape(Vector2f(100, 50)),
        .color          = Color(200, 200, 200, 255),
        .colorHover     = Color(150, 150, 150, 255),
        .colorClick     = Color(100, 100, 100, 255),
        .colorText      = Color::White,
        .colorTextHover = Color::White,
        .colorTextClick = Color::White,
        .x = 0,
        .y = 0,
        .width = 100,
        .height = 50,
        .textString = "Start"
    };

    start = Button(args);
}

Interface::Interface(RenderWindow* window) : window(window), rectangle(RectangleShape(Vector2f(10, 10))), matrix(Matrix(80, 60))
{
    this->window->setFramerateLimit(20);
    this->window->setVerticalSyncEnabled(true);

    event.mouseButton.button = Mouse::Left;
    event.mouseButton.x = 0;
    event.mouseButton.y = 0;

    // bouton start
    struct ButtonArgs args = 
    {
        .rectangle      = RectangleShape(Vector2f(100, 50)),
        .color          = Color(200, 200, 200, 255),
        .colorHover     = Color(150, 150, 150, 255),
        .colorClick     = Color(100, 100, 100, 255),
        .colorText      = Color::White,
        .colorTextHover = Color::White,
        .colorTextClick = Color::White,
        .x = 0,
        .y = 0,
        .width = 100,
        .height = 50,
        .textString = "Start"
    };

    start = Button(args);

}

Interface::Interface(RenderWindow* window, Matrix& matrix) : window(window), rectangle(RectangleShape(Vector2f(10, 10))), matrix(matrix)
{
    this->window->setFramerateLimit(20);
    this->window->setVerticalSyncEnabled(true);

    font.loadFromFile("arial_mt_black/ARIBL0.ttf");
    text.setFont(font);

    event.mouseButton.button = Mouse::Left;
    event.mouseButton.x = 0;
    event.mouseButton.y = 0;

    // bouton start
    struct ButtonArgs args = 
    {
        .rectangle      = RectangleShape(Vector2f(100, 50)),
        .text           = Text(text),
        .font           = Font(font),
        .color          = Color(200, 200, 200, 255),
        .colorHover     = Color(150, 150, 150, 255),
        .colorClick     = Color(100, 100, 100, 255),
        .colorText      = Color::White,
        .colorTextHover = Color::White,
        .colorTextClick = Color::White,
        .x = 0,
        .y = 0,
        .width = 100,
        .height = 50,
        .textString = "Start"
    };

    

    start = Button(args);
}

Interface::Interface(RenderWindow* window, RectangleShape& rectangle) : window(window), rectangle(rectangle), matrix(Matrix(80, 60))
{
    this->window->setFramerateLimit(20);
    this->window->setVerticalSyncEnabled(true);

    event.mouseButton.button = Mouse::Left;
    event.mouseButton.x = 0;
    event.mouseButton.y = 0;

    // bouton start
    struct ButtonArgs args = 
    {
        .rectangle      = RectangleShape(Vector2f(100, 50)),
        .color          = Color(200, 200, 200, 255),
        .colorHover     = Color(150, 150, 150, 255),
        .colorClick     = Color(100, 100, 100, 255),
        .colorText      = Color::White,
        .colorTextHover = Color::White,
        .colorTextClick = Color::White,
        .x = 0,
        .y = 0,
        .width = 100,
        .height = 50,
        .textString = "Start"
    };

    start = Button(args);
}

Interface::Interface(RenderWindow* window, RectangleShape& rectangle, Matrix& matrix) : window(window), rectangle(rectangle), matrix(matrix)
{
    this->window->setFramerateLimit(20);
    this->window->setVerticalSyncEnabled(true);

    event.mouseButton.button = Mouse::Left;
    event.mouseButton.x = 0;
    event.mouseButton.y = 0;

    // bouton start
    struct ButtonArgs args = 
    {
        .rectangle      = RectangleShape(Vector2f(100, 50)),
        .color          = Color(200, 200, 200, 255),
        .colorHover     = Color(150, 150, 150, 255),
        .colorClick     = Color(100, 100, 100, 255),
        .colorText      = Color::White,
        .colorTextHover = Color::White,
        .colorTextClick = Color::White,
        .x = 0,
        .y = 0,
        .width = 100,
        .height = 50,
        .textString = "Start"
    };

    start = Button(args);
}


Interface::~Interface()
{
    
}


/************/
/* METHODES */
/************/

void Interface::display()
{
    // ajout du bouton start
    Clock clock;
    int32_t tempTemps      = 0;
    bool isPause           = true;
    uint8_t nbClick        = 0;
    int32_t tempTempsClick = 0;

    while (window->isOpen())
    {
        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)
                window->close();

            if (event.type == Event::MouseButtonPressed && Mouse::getPosition(*window).y > 50)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    event.mouseButton.x = Mouse::getPosition(*window).x;
                    event.mouseButton.y = Mouse::getPosition(*window).y;
                    matrix(Mouse::getPosition(*window).x / 10, (Mouse::getPosition(*window).y - 50) / 10) = (matrix(Mouse::getPosition(*window).x / 10, (Mouse::getPosition(*window).y - 50) / 10) == MORT) ? VIVANT : MORT;
                }
            }
        }

        if (nbClick == 0)
        {
            start.update(Mouse::getPosition(*window), Mouse::isButtonPressed(Mouse::Left));

            if (start.isClick())
            {
                isPause = !isPause;
                nbClick++;
                tempTempsClick = clock.getElapsedTime().asMilliseconds();
            }
        }

        if (nbClick > 0 && clock.getElapsedTime().asMilliseconds() - tempTempsClick > 50)
        {
            nbClick = 0;
        }

        start.draw(window);
        
        for (int i = 0; i < matrix.getLignes(); i++)
        {
            for (int j = 0; j < matrix.getColonnes(); j++)
            {
                rectangle.setPosition(j * 10, i * 10 + 50);
                if (matrix(j, i) == 0)
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

        window->clear();

        if (isPause == false && clock.getElapsedTime().asMilliseconds() - tempTemps >= 100)
        {
            for (int i = 0; i < matrix.getLignes(); i++)
            {
                for (int j = 0; j < matrix.getColonnes(); j++)
                {
                    if (matrix(j, i) == VIVANT)
                        matrix.reglesVie(j, i);
                    else
                        matrix.reglesMort(j, i);
                }
            }
            tempTemps = clock.getElapsedTime().asMilliseconds();
            matrix.rafraichir();
        }
    }
}

void Interface::close()
{
    window->close();
}