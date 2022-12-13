/**
 * @file acteur.h
 * @author Lilian CHARDON,
 * @brief 
 * @version 0.1
 * @date 25-10-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __ACTEUR_H__
#define __ACTEUR_H__

#define LARGEUR_MAX 80
#define HAUTEUR_MAX 60

#include <iostream>
#include <string>
#include "matrix.h"

class Acteur
{
    private:
        Matrix A;
        int x, y;

    public:
        static int id;

    /****************/
    /* CONSTRUCTEUR */
    /****************/

        /**
         * @brief Constructeur par défaut de la classe Acteur
         */
        Acteur();

        /**
         * @brief Constructeur de la classe Acteur
         * 
         * @param A la matrice
         */
        Acteur(Matrix& A);

        /**
         * @brief Constructeur de la classe Acteur
         * 
         * @param A la matrice
         * @param x la position en absisse
         * @param y la position en ordonnée
         */
        Acteur(Matrix& A, int x, int y);

    /***************/
    /* DESTRUCTEUR */
    /***************/

        /**
         * @brief Destructeur de la classe Acteur
         */
        ~Acteur();

    /************/
    /* METHODES */
    /************/

        /**
         * @brief Déplace l'acteur
         * 
         * @param x la position en absisse
         * @param y la position en ordonnée
         */
        void move(int x, int y);

        /**
         * @brief Déplace l'acteur de manière aléatoire
         */
        void moveR();

        /**
         * @brief Règles de vie de l'acteur
         */
        void rules();

    /***********/
    /* GETTERS */
    /***********/

        /**
         * @brief Retourne la position en absisse
         * 
         * @return int la position en absisse
         */
        int getX() const { return x; }

        /**
         * @brief Retourne la position en ordonnée
         * 
         * @return int la position en ordonnée
         */
        int getY() const { return y; }

    /***********/
    /* SETTERS */
    /***********/

        /**
         * @brief Définit la position en absisse
         * 
         * @param x la position en absisse
         */
        void setX(int x) { this->x = x; }

        /**
         * @brief Définit la position en ordonnée
         * 
         * @param y la position en ordonnée
         */
        void setY(int y) { this->y = y; }
};

#endif // __ACTEUR_H__