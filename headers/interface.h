/**
 * @file interface.h
 * @author Lilian CHARDON (lilian.chardon@ynov.com)
 * @brief Fichier des déclarations des méthodes de la classe Interface
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

#include "entitees/acteur.h"

using namespace std;
using namespace sf;

class Interface
{
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
         */
        Interface(Matrix& A);

        /**
         * @brief Constructeur de la classe Interface
         * 
         */
        Interface(Matrix& A, vector<Acteur*>& acteurs);

    
    /***************/
    /* DESTRUCTEUR */
    /***************/

        /**
         * @brief Destructeur de la classe Interface
         */
        ~Interface();

    /**************/
    /* ACCESSEURS */
    /**************/

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
        RectangleShape getRectangle() const { return rectangle; }

        /**
         * @brief Récupère l'acteur
         * 
         * @return Acteur
         * @param i
         */
        Acteur getActeur(int i) const { return *acteurs[i]; }

        /**
         * @brief Récupère l'acteur
         * 
         * @return vector<Acteur*>
         */
        vector<Acteur*> getActeurs() const { return acteurs; }

    /*************/
    /* MUTATEURS */
    /*************/

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
        void setRectangle(RectangleShape rectangle) { this->rectangle = rectangle; }

        /**
         * @brief Définit l'acteur
         * 
         * @param acteur
         * @param i
         */
        void setActeur(Acteur* acteur, int i) { this->acteurs[i] = acteur; }

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

    private:
        RenderWindow* window;      // fenêtre
        Event event;               // évènement
        RectangleShape rectangle;  // rectangle
        Matrix matrix;             // matrice
        vector<Acteur*> acteurs;   // acteurs
};

#endif // __INTERFACE_H__