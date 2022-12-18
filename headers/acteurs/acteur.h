/**
 * @file acteur.h
 * @author Lilian CHARDON,
 * @brief Fichier des déclarations des méthodes de la classe Acteur
 * @version 0.1
 * @date 25-10-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __ACTEUR_H__
#define __ACTEUR_H__

#define LARGEUR_MAX 80

enum Type
{
    PROTAGONISTE,
    MARCHANDISE,
    ENNEMI,
    OBSTACLE
};

#include <iostream>
#include <string>
#include <time.h>
#include "../matrix.h"

class Acteur
{
    public:
        static int id;

    /*****************/
    /* CONSTRUCTEURS */
    /*****************/

        /**
         * @brief Constructeur par défaut de la classe Acteur
         */
        Acteur();

        /**
         * @brief Constructeur de la classe Acteur
         * 
         * @param A la matrice dans laquelle l'acteur se trouve
         */
        Acteur(Matrix& A);

        /**
         * @brief Constructeur de la classe Acteur
         * 
         * @param A la matrice dans laquelle l'acteur se trouve
         * @param x la position en x de l'acteur
         * @param y la position en y de l'acteur
         */
        Acteur(Matrix& A, int x, int y);

        /**
         * @brief Constructeur de la classe Acteur
         * 
         * @param A la matrice dans laquelle l'acteur se trouve
         * @param x la position en x de l'acteur
         * @param y la position en y de l'acteur
         * @param type le type de l'acteur
         */
        Acteur(Matrix& A, int x, int y, int type);

        /**
         * @brief Constructeur de copie de la classe Acteur
         * 
         * @param a l'acteur à copier
         */
        Acteur(const Acteur& a);

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
         * @brief Déplace l'acteur dans la matrice avec les coordonnées x et y
         * 
         * @param x la position en x de l'acteur
         * @param y la position en y de l'acteur
         */
        void move(int x, int y);

        /**
         * @brief Déplace l'acteur de manière aléatoire dans la matrice
         */
        void moveR();

    /***********/
    /* GETTERS */
    /***********/

        /**
         * @brief Renvoie la coordonnée x de l'acteur
         * 
         * @return int la coordonnée x de l'acteur
         */
        int getX() const { return x; }

        /**
         * @brief Renvoie la coordonnée y de l'acteur
         * 
         * @return int la coordonnée y de l'acteur
         */
        int getY() const { return y; }

    /***********/
    /* SETTERS */
    /***********/

        /**
         * @brief Modifie la coordonnée x de l'acteur
         * 
         * @param x la nouvelle coordonnée x de l'acteur
         */
        void setX(int x) { this->x = x; }

        /**
         * @brief Modifie la coordonnée y de l'acteur
         * 
         * @param y la nouvelle coordonnée y de l'acteur
         */
        void setY(int y) { this->y = y; }
        
    protected:
        Matrix A;
        int x, y;
        int type;
};

#endif // __ACTEUR_H__