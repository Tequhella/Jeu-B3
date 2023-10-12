/**
 * @file interface.h
 * @author Lilian CHARDON (lilian.chardon@ynov.com)
 * @brief 
 * @version 0.1
 * @date 06-12-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#define LARGEUR 800
#define HAUTEUR 600

#include <iostream>
#include <thread>
#include "matrix.h"
#include "button.h"

using namespace std;
using namespace sf;

class Interface
{
    private:
        RenderWindow* window;     // fenêtre
        RectangleShape rectangle; // rectangle
        Matrix matrix;            // matrice
        Event event;              // évènement
        Font font;                // police
        Button start;             // bouton start
        Button darkMode;          // bouton dark mode
        Color colorCell;          // couleur cellule
        Color colorVoid;          // couleur vide
        Color colorBackground;    // couleur fond

    public:
    /****************/
    /* CONSTRUCTEUR */
    /****************/

        /**
         * @brief Constructeur par défaut de la classe Interface
         */
        Interface();

        /**
         * @brief Constructeur de la classe Interface
         * 
         * @param window la fenêtre
         */
        Interface(RenderWindow* window);

        /**
         * @brief Constructeur de la classe Interface
         * 
         * @param window la fenêtre
         * @param matrix la matrice
         */
        Interface(RenderWindow* window, Matrix& matrix);

        /**
         * @brief Constructeur de la classe Interface
         * 
         * @param window la fenêtre
         * @param rectangle le rectangle
         */
        Interface(RenderWindow* window, RectangleShape& rectangle);

        /**
         * @brief Constructeur de la classe Interface
         * 
         * @param window la fenêtre
         * @param rectangle le rectangle
         * @param matrix la matrice
         */
        Interface(RenderWindow* window, RectangleShape& rectangle, Matrix& matrix);


    
    /***************/
    /* DESTRUCTEUR */
    /***************/

        /**
         * @brief Destructeur de la classe Interface
         */
        ~Interface();

    /***********/
    /* GETTERS */
    /***********/

        /**
         * @brief Récupère la fenêtre
         * 
         * @return RenderWindow 
         */
        RenderWindow* getWindow() const { return window; }

        /**
         * @brief Récupère l'évènement
         * 
         * @return Event 
         */
        Event getEvent() const { return event; }

        /**
         * @brief Récupère le rectangle
         * 
         * @return RectangleShape 
         */
        RectangleShape getRectangle() const { return rectangle; }

    /***********/
    /* SETTERS */
    /***********/

        /**
         * @brief Définit la fenêtre
         * 
         * @param _window 
         */
        void setWindow(RenderWindow* _window) { this->window = _window; }

        /**
         * @brief Définit l'évènement
         * 
         * @param _event 
         */
        void setEvent(Event _event) { this->event = _event; }

        /**
         * @brief Définit le rectangle
         * 
         * @param rectangle 
         */
        void setRectangle(RectangleShape rectangle) { this->rectangle = rectangle; }

    /************/
    /* METHODES */
    /************/

        /**
         * @brief Affiche la fenêtre
         * 
         */
        void display();

        /**
         * @brief Ferme la fenêtre
         * 
         */
        void close();

};

#endif // __INTERFACE_H__