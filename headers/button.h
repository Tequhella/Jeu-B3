/**
 * @file button.h
 * @author Lilian CHARDON (lilian.chardon@ynov.com)
 * @brief 
 * @version 0.1
 * @date 17-01-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Button
{
    private:
        RectangleShape rectangle; // rectangle
        Text text;                // texte
        Font font;                // police
        Color color;              // couleur
        Color colorHover;         // couleur hover
        Color colorClick;         // couleur click
        Color colorText;          // couleur texte
        Color colorTextHover;     // couleur texte hover
        Color colorTextClick;     // couleur texte click
        int x;                    // position x
        int y;                    // position y
        int width;                // largeur
        int height;               // hauteur
        string textString;        // texte
        bool hover;               // hover
        bool click;               // click

    public:
    /****************/
    /* CONSTRUCTEUR */
    /****************/

        /**
         * @brief Constructeur de la classe Button
         */
        Button();

        /**
         * @brief Constructs a Button object with the specified parameters.
         * 
         * @param rectangle The rectangle shape of the button.
         * @param text The text of the button.
         * @param font The font of the button text.
         * @param color The color of the button.
         * @param colorHover The color of the button when hovered over.
         * @param colorClick The color of the button when clicked.
         * @param colorText The color of the button text.
         * @param colorTextHover The color of the button text when hovered over.
         * @param colorTextClick The color of the button text when clicked.
         * @param x The x-coordinate of the button.
         * @param y The y-coordinate of the button.
         * @param width The width of the button.
         * @param height The height of the button.
         * @param textString The string of the button text.
         */
        Button(
            RectangleShape rectangle,
            Text text,
            Font font,
            Color color,
            Color colorHover,
            Color colorClick,
            Color colorText,
            Color colorTextHover,
            Color colorTextClick,
            int x,
            int y,
            int width,
            int height,
            string textString
        );

    /***************/
    /* DESTRUCTEUR */
    /***************/

        /**
         * @brief Destructeur de la classe Button
         */
        ~Button();

    /***********/
    /* METHODE */
    /***********/

        /**
         * @brief Méthode qui permet de dessiner le bouton
         * 
         * @param window fenêtre
         */
        void draw(RenderWindow* window);

        /**
         * @brief Méthode qui permet de mettre à jour le bouton
         * 
         * @param mousePosition position de la souris
         * @param mouseClick clic de la souris
         */
        void update(Vector2i mousePosition, bool mouseClick);

        /**
         * @brief Méthode qui permet de savoir si le bouton est hover
         * 
         * @return true 
         * @return false 
         */
        bool isHover();

        /**
         * @brief Méthode qui permet de savoir si le bouton est click
         * 
         * @return true 
         * @return false 
         */
        bool isClick();

        /**
         * @brief Méthode qui permet de savoir si le bouton est hover
         * 
         * @param hover hover
         */
        void setHover(bool hover);

        /**
         * @brief Méthode qui permet de savoir si le bouton est click
         * 
         * @param click click
         */
        void setClick(bool click);

        /**
         * @brief Méthode qui permet de modifier la position x
         * 
         * @param x position x
         */
        void setX(int x);

        /**
         * @brief Méthode qui permet de modifier la position y
         * 
         * @param y position y
         */
        void setY(int y);

        /**
         * @brief Méthode qui permet de modifier la largeur
         * 
         * @param width largeur
         */
        void setWidth(int width);

        /**
         * @brief Méthode qui permet de modifier la hauteur
         * 
         * @param height hauteur
         */
        void setHeight(int height);

        /**
         * @brief Méthode qui permet de modifier le texte
         * 
         * @param textString texte
         */
        void setText(string textString);

        /**
         * @brief Méthode qui permet de modifier la couleur
         * 
         * @param color couleur
         */
        void setColor(Color color);

        /**
         * @brief Méthode qui permet de modifier la couleur
         * 
         * @param color couleur
         */
        void setColorHover(Color color);

        /**
         * @brief Méthode qui permet de modifier la couleur
         * 
         * @param color couleur
         */
        void setColorClick(Color color);

        /**
         * @brief Méthode qui permet de modifier la couleur
         * 
         * @param color couleur
         */
        void setColorText(Color color);

        /**
         * @brief Méthode qui permet de modifier la police
         * 
         * @param font police
         */
        void setFont(Font font);

    /***********/
    /* GETTER  */
    /***********/

        /**
         * @brief Méthode qui permet de récupérer la position x
         * 
         * @return int position x
         */
        int getX() const { return x;}

        /**
         * @brief Méthode qui permet de récupérer la position y
         * 
         * @return int position y
         */
        int getY() const { return y;}

        /**
         * @brief Méthode qui permet de récupérer la largeur
         * 
         * @return int largeur
         */
        int getWidth() const { return width;}

        /**
         * @brief Méthode qui permet de récupérer la hauteur
         * 
         * @return int hauteur
         */
        int getHeight() const { return height;}

        /**
         * @brief Méthode qui permet de récupérer le texte
         * 
         * @return string texte
         */
        string getText() const { return textString;}

        /**
         * @brief Méthode qui permet de récupérer la couleur
         * 
         * @return Color couleur
         */
        Color getColor() const { return color;}

        /**
         * @brief Méthode qui permet de récupérer la couleur
         * 
         * @return Color couleur
         */
        Color getColorHover() const { return colorHover;}

        /**
         * @brief Méthode qui permet de récupérer la couleur
         * 
         * @return Color couleur
         */
        Color getColorClick() const { return colorClick;}

        /**
         * @brief Méthode qui permet de récupérer la couleur
         * 
         * @return Color couleur
         */
        Color getColorText() const { return colorText;}

        /**
         * @brief Méthode qui permet de récupérer la police
         * 
         * @return Font police
         */
        Font getFont() const { return font;}

    private:

    /***********/
    /* METHODE */
    /***********/

        /**
         * @brief Méthode qui permet de mettre à jour le texte
         * 
         */
        void updateText();

};

#endif // __BUTTON_H__
