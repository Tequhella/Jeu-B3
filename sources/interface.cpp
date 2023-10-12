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

    this->colorCell = Color::Black;
    this->colorVoid = Color::White;
    this->colorBackground = Color(235, 235, 235, 255);

    // gestion click souris
    event.mouseButton.button = Mouse::Left;
    event.mouseButton.x = 0;
    event.mouseButton.y = 0;

    Text textStart;

    font.loadFromFile("arial_mt_black/ARIBL0.ttf");
    textStart.setFont(font);
    textStart.setString("Start");
    textStart.setFillColor(Color::Black);
    textStart.setCharacterSize(24);
    

    start = Button(
        RectangleShape(Vector2f(100, 50)),
        Text(textStart),
        Font(font),
        Color(200, 200, 200, 255),
        Color(150, 150, 150, 255),
        Color(100, 100, 100, 255),
        textStart.getFillColor(),
        textStart.getFillColor(),
        textStart.getFillColor(),
        0,
        0,
        100,
        50,
        textStart.getString()
    );

    Text textDarkMode;

    textDarkMode.setFont(font);
    textDarkMode.setString("Dark mode");
    textDarkMode.setFillColor(Color::Black);
    textDarkMode.setCharacterSize(24);

    darkMode = Button(
        RectangleShape(Vector2f(200, 50)),
        Text(textDarkMode),
        Font(font),
        Color(200, 200, 200, 255),
        Color(150, 150, 150, 255),
        Color(100, 100, 100, 255),
        textDarkMode.getFillColor(),
        textDarkMode.getFillColor(),
        textDarkMode.getFillColor(),
        101,
        0,
        200,
        50,
        textDarkMode.getString()
    );

}

Interface::Interface(RenderWindow* window) : window(window), rectangle(RectangleShape(Vector2f(10, 10))), matrix(Matrix(80, 60))
{
    this->window->setFramerateLimit(20);
    this->window->setVerticalSyncEnabled(true);

    this->colorCell = Color::Black;
    this->colorVoid = Color::White;
    this->colorBackground = Color(235, 235, 235, 255);

    event.mouseButton.button = Mouse::Left;
    event.mouseButton.x = 0;
    event.mouseButton.y = 0;

    Text textStart;

    font.loadFromFile("arial_mt_black/ARIBL0.ttf");
    textStart.setFont(font);
    textStart.setString("Start");
    textStart.setFillColor(Color::Black);
    textStart.setCharacterSize(24);
    

    start = Button(
        RectangleShape(Vector2f(100, 50)),
        Text(textStart),
        Font(font),
        Color(200, 200, 200, 255),
        Color(150, 150, 150, 255),
        Color(100, 100, 100, 255),
        textStart.getFillColor(),
        textStart.getFillColor(),
        textStart.getFillColor(),
        0,
        0,
        100,
        50,
        textStart.getString()
    );

    Text textDarkMode;

    textDarkMode.setFont(font);
    textDarkMode.setString("Dark mode");
    textDarkMode.setFillColor(Color::Black);
    textDarkMode.setCharacterSize(24);

    darkMode = Button(
        RectangleShape(Vector2f(200, 50)),
        Text(textDarkMode),
        Font(font),
        Color(200, 200, 200, 255),
        Color(150, 150, 150, 255),
        Color(100, 100, 100, 255),
        textDarkMode.getFillColor(),
        textDarkMode.getFillColor(),
        textDarkMode.getFillColor(),
        101,
        0,
        200,
        50,
        textDarkMode.getString()
    );

}

Interface::Interface(RenderWindow* window, Matrix& matrix) : window(window), rectangle(RectangleShape(Vector2f(10, 10))), matrix(matrix)
{
    this->window->setFramerateLimit(20);
    this->window->setVerticalSyncEnabled(true);

    this->colorCell = Color::Black;
    this->colorVoid = Color::White;
    this->colorBackground = Color(235, 235, 235, 255);

    event.mouseButton.button = Mouse::Left;
    event.mouseButton.x = 0;
    event.mouseButton.y = 0;

    Text textStart;

    font.loadFromFile("arial_mt_black/ARIBL0.ttf");
    textStart.setFont(font);
    textStart.setString("Start");
    textStart.setFillColor(Color::Black);
    textStart.setCharacterSize(24);
    

    start = Button(
        RectangleShape(Vector2f(100, 50)),
        Text(textStart),
        Font(font),
        Color(200, 200, 200, 255),
        Color(150, 150, 150, 255),
        Color(100, 100, 100, 255),
        textStart.getFillColor(),
        textStart.getFillColor(),
        textStart.getFillColor(),
        0,
        0,
        100,
        50,
        textStart.getString()
    );

    Text textDarkMode;

    textDarkMode.setFont(font);
    textDarkMode.setString("Dark mode");
    textDarkMode.setFillColor(Color::Black);
    textDarkMode.setCharacterSize(24);

    darkMode = Button(
        RectangleShape(Vector2f(200, 50)),
        Text(textDarkMode),
        Font(font),
        Color(200, 200, 200, 255),
        Color(150, 150, 150, 255),
        Color(100, 100, 100, 255),
        textDarkMode.getFillColor(),
        textDarkMode.getFillColor(),
        textDarkMode.getFillColor(),
        101,
        0,
        200,
        50,
        textDarkMode.getString()
    );
}

Interface::Interface(RenderWindow* window, RectangleShape& rectangle) : window(window), rectangle(rectangle), matrix(Matrix(80, 60))
{
    this->window->setFramerateLimit(20);
    this->window->setVerticalSyncEnabled(true);

    this->colorCell = Color::Black;
    this->colorVoid = Color::White;
    this->colorBackground = Color(235, 235, 235, 255);

    event.mouseButton.button = Mouse::Left;
    event.mouseButton.x = 0;
    event.mouseButton.y = 0;

    Text textStart;

    // texte
    font.loadFromFile("arial_mt_black/ARIBL0.ttf");
    textStart.setFont(font);
    textStart.setString("Start");
    textStart.setFillColor(Color::Black);
    textStart.setCharacterSize(24);

    start = Button(
        RectangleShape(Vector2f(100, 50)),
        Text(textStart),
        Font(font),
        Color(200, 200, 200, 255),
        Color(150, 150, 150, 255),
        Color(100, 100, 100, 255),
        textStart.getFillColor(),
        textStart.getFillColor(),
        textStart.getFillColor(),
        0,
        0,
        100,
        50,
        textStart.getString()
    );

    Text textDarkMode;

    textDarkMode.setFont(font);
    textDarkMode.setString("Dark mode");
    textDarkMode.setFillColor(Color::Black);
    textDarkMode.setCharacterSize(24);

    darkMode = Button(
        RectangleShape(Vector2f(200, 50)),
        Text(textDarkMode),
        Font(font),
        Color(200, 200, 200, 255),
        Color(150, 150, 150, 255),
        Color(100, 100, 100, 255),
        textDarkMode.getFillColor(),
        textDarkMode.getFillColor(),
        textDarkMode.getFillColor(),
        101,
        0,
        200,
        50,
        textDarkMode.getString()
    );

}

Interface::Interface(RenderWindow* window, RectangleShape& rectangle, Matrix& matrix) : window(window), rectangle(rectangle), matrix(matrix)
{
    this->window->setFramerateLimit(20);
    this->window->setVerticalSyncEnabled(true);

    this->colorCell = Color::Black;
    this->colorVoid = Color::White;
    this->colorBackground = Color(235, 235, 235, 255);

    event.mouseButton.button = Mouse::Left;
    event.mouseButton.x = 0;
    event.mouseButton.y = 0;

    Text textStart;

    font.loadFromFile("arial_mt_black/ARIBL0.ttf");
    textStart.setFont(font);
    textStart.setString("Start");
    textStart.setFillColor(Color::Black);
    textStart.setCharacterSize(24);
    
    

    start = Button(
        RectangleShape(Vector2f(100, 50)),
        Text(textStart),
        Font(font),
        Color(200, 200, 200, 255),
        Color(150, 150, 150, 255),
        Color(100, 100, 100, 255),
        textStart.getFillColor(),
        textStart.getFillColor(),
        textStart.getFillColor(),
        0,
        0,
        100,
        50,
        textStart.getString()
    );

    Text textDarkMode;

    textDarkMode.setFont(font);
    textDarkMode.setString("Dark mode");
    textDarkMode.setFillColor(Color::Black);
    textDarkMode.setCharacterSize(24);

    darkMode = Button(
        RectangleShape(Vector2f(200, 50)),
        Text(textDarkMode),
        Font(font),
        Color(200, 200, 200, 255),
        Color(150, 150, 150, 255),
        Color(100, 100, 100, 255),
        textDarkMode.getFillColor(),
        textDarkMode.getFillColor(),
        textDarkMode.getFillColor(),
        101,
        0,
        200,
        50,
        textDarkMode.getString()
    );
}


Interface::~Interface()
{
    
}


/************/
/* METHODES */
/************/

/**
 * @brief Displays the game interface and handles user input.
 * 
 * The function displays the game interface and handles user input.
 * It creates a window and draws a grid of rectangles representing the cells of the game.
 * The user can click on the cells to toggle their state.
 * The function also adds a start button that toggles the game state between pause and play.
 * The game follows the rules of the Game of Life, where cells can either be alive or dead,
 * and their state changes based on the state of their neighbors.
 * 
 * @return void
 */
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
            darkMode.update(Mouse::getPosition(*window), Mouse::isButtonPressed(Mouse::Left));

            if (start.isClick())
            {
                isPause = !isPause;
                nbClick++;
                tempTempsClick = clock.getElapsedTime().asMilliseconds();
            }

            if (darkMode.isClick())
            {
                nbClick++;
                tempTempsClick = clock.getElapsedTime().asMilliseconds();
                if (darkMode.getText() == "Dark mode")
                {
                    start.setColor(Color(100, 100, 100, 255));
                    start.setColorHover(Color(150, 150, 150, 255));
                    start.setColorClick(Color(200, 200, 200, 255));
                    start.setColorText(Color::White);
                    start.setColorTextHover(Color::White);
                    start.setColorTextClick(Color::White);

                    darkMode.setText("Light mode");
                    darkMode.setColor(Color(100, 100, 100, 255));
                    darkMode.setColorHover(Color(150, 150, 150, 255));
                    darkMode.setColorClick(Color(200, 200, 200, 255));
                    darkMode.setColorText(Color::White);
                    darkMode.setColorTextHover(Color::White);
                    darkMode.setColorTextClick(Color::White);
                    colorCell = Color::White;
                    colorVoid = Color::Black;
                    colorBackground = Color(50, 50, 50, 255);
                }
                else
                {
                    start.setColor(Color(200, 200, 200, 255));
                    start.setColorHover(Color(150, 150, 150, 255));
                    start.setColorClick(Color(100, 100, 100, 255));
                    start.setColorText(Color::Black);
                    start.setColorTextHover(Color::Black);
                    start.setColorTextClick(Color::Black);

                    darkMode.setText("Dark mode");
                    darkMode.setColor(Color(200, 200, 200, 255));
                    darkMode.setColorHover(Color(150, 150, 150, 255));
                    darkMode.setColorClick(Color(100, 100, 100, 255));
                    darkMode.setColorText(Color::Black);
                    darkMode.setColorTextHover(Color::Black);
                    darkMode.setColorTextClick(Color::Black);
                    colorCell = Color::Black;
                    colorVoid = Color::White;
                    colorBackground = Color(235, 235, 235, 255);
                }
            }
        }

        if (nbClick > 0 && clock.getElapsedTime().asMilliseconds() - tempTempsClick > 50)
        {
            nbClick = 0;
        }

        start.draw(window);
        darkMode.draw(window);
        
        
        thread updateThread([&]() {
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
        });
        
        for (int i = 0; i < matrix.getLignes(); i++)
        {
            for (int j = 0; j < matrix.getColonnes(); j++)
            {
                rectangle.setPosition(j * 10, i * 10 + 50);
                if (matrix(j, i) == 0)
                {
                    // rectangle vide avec bordure
                    rectangle.setFillColor(colorVoid);
                    rectangle.setOutlineColor(Color::Black);
                    rectangle.setOutlineThickness(1);
                }
                else
                {
                    // rectangle plein
                    rectangle.setFillColor(colorCell);
                    rectangle.setOutlineColor(Color::Black);
                    rectangle.setOutlineThickness(1);
                }
                window->draw(rectangle);
            }
        }
        updateThread.join();

        window->display();

        window->clear(colorBackground);
    }
}

void Interface::close()
{
    window->close();
}