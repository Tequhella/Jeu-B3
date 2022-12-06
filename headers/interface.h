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

#include <iostream>
#include <SFML/Graphics.hpp>

#include "acteur.h"

using namespace std;
using namespace sf;

class Interface
{
    private:
        RenderWindow* window;      // fenêtre
        Event event;               // évènement
        RectangleShape* rectangle; // rectangle
        Acteur* acteur;            // acteur

    public:
    /****************/
    /* CONSTRUCTEUR */
    /****************/

        /**
         * @brief Constructeur par défaut de la classe Interface
         */
        Interface();

    
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
         * @return RenderWindow* 
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
         * @return RectangleShape* 
         */
        RectangleShape* getRectangle() const { return rectangle; }

        /**
         * @brief Récupère l'acteur
         * 
         * @return Acteur* 
         */
        Acteur* getActeur() const { return acteur; }

    /***********/
    /* SETTERS */
    /***********/

        /**
         * @brief Définit la fenêtre
         * 
         * @param window 
         */
        void setWindow(RenderWindow* window) { this->window = window; }

        /**
         * @brief Définit l'évènement
         * 
         * @param event 
         */
        void setEvent(Event event) { this->event = event; }

        /**
         * @brief Définit le rectangle
         * 
         * @param rectangle 
         */
        void setRectangle(RectangleShape* rectangle) { this->rectangle = rectangle; }

        /**
         * @brief Définit l'acteur
         * 
         * @param acteur 
         */
        void setActeur(Acteur* acteur) { this->acteur = acteur; }

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