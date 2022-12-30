/**
 * @file entitee.h
 * @author Lilian CHARDON (lilian.chardon@ynov.com)
 * @brief Fichier des déclarations des méthodes de la classe Entitee
 * @version 0.1
 * @date 19-12-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __ENTITEE_H__
#define __ENTITEE_H__

#define LARGEUR_MAX 20

#include <iostream>
#include "matrix.h"

enum TypeEntitee
{
    VIDE,
    MARCHANDISE,
    STRANDS,
    ACTEUR
};

using namespace std;

class Entitee
{
    public:
    /****************/
    /* CONSTRUCTEUR */
    /****************/

        /**
         * @brief Constructeur par défaut de la classe Entitee
         */
        Entitee();

        /**
         * @brief Constructeur de la classe Entitee
         * 
         */
        Entitee(Matrix* _A);

        /**
         * @brief Constructeur de la classe Entitee
         * 
         */
        Entitee(Matrix* _A, int _x, int _y);

        /**
         * @brief Constructeur de la classe Entitee
         * 
         */
        Entitee(Matrix* _A, int _x, int _y, int _type);

        /**
         * @brief Constructeur de la classe Entitee
         * 
         */
        Entitee(const Entitee& e);

    
    /***************/
    /* DESTRUCTEUR */
    /***************/

        /**
         * @brief Destructeur de la classe Entitee
         */
        ~Entitee();

    /**************/
    /* OPERATEURS */
    /**************/

        /**
         * @brief Opérateur d'affectation de la classe Entitee
         * 
         * @param _e 
         * @return Entitee& 
         */
        Entitee& operator=(const Entitee& _e);

        /**
         * @brief Opérateur de comparaison de la classe Entitee
         * 
         * @param _e
         * @return true
         */
        bool operator==(const Entitee& _e);

        /**
         * @brief Opérateur de flux de la classe Entitee
         * 
         * @param _os
         * @param _e
         * @return ostream&
         */
        friend ostream& operator<<(ostream& _os, const Entitee& _e);

    /**************/
    /* ACCESSEURS */
    /**************/

        /**
         * @brief Accesseur de la classe Entitee
         * 
         * @return int la position en x de l'entitee
         */
        int getX() const { return x; }

        /**
         * @brief Accesseur de la classe Entitee
         * 
         * @return int la position en y de l'entitee
         */
        int getY() const { return y; }

        /**
         * @brief Accesseur de la classe Entitee
         * 
         * @return Matrix la matrice de l'entitee
         */
        Matrix getMatrice() const { return *A; }

    /*************/
    /* MUTATEURS */
    /*************/

        /**
         * @brief Mutateur de la classe Entitee
         * 
         * @param _x la position en x de l'entitee
         */
        void setX(int _x) { this->x = _x; }

        /**
         * @brief Mutateur de la classe Entitee
         * 
         * @param _y la position en y de l'entitee
         */
        void setY(int _y) { this->y = _y; }

        /**
         * @brief Mutateur de la classe Entitee
         * 
         * @param _m la matrice de l'entitee
         */
        void setMatrice(Matrix& _m) { this->A = &_m; }
    
    /************/
    /* METHODES */
    /************/

        void placement();

    protected:
        int x;
        int y;
        int type;
        Matrix* A;
};


#endif // __ENTITEE_H__