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
         * @brief Retourne la position en x de l'entitee
         * 
         * @return int la position en x de l'entitee
         */
        int getX() const { return x; }

        /**
         * @brief Retourne la position en y de l'entitee
         * 
         * @return int la position en y de l'entitee
         */
        int getY() const { return y; }

        /**
         * @brief Retourne le type de l'entitee
         * 
         * @return TypeEntitee le type de l'entitee
         */
        int getType() const { return type; }

        /**
         * @brief Retourne la matrice de l'entitee
         * 
         * @return Matrix la matrice de l'entitee
         */
        Matrix getMatrice() const { return *A; }

    /*************/
    /* MUTATEURS */
    /*************/

        /**
         * @brief Modifie la position en x de l'entitee
         * 
         * @param _x la position en x de l'entitee
         */
        void setX(int _x) { this->x = _x; }

        /**
         * @brief Modifie la position en y de l'entitee
         * 
         * @param _y la position en y de l'entitee
         */
        void setY(int _y) { this->y = _y; }

        /**
         * @brief Modifie le type de l'entitee
         * 
         * @param _type le type de l'entitee
         */
        void setType(int _type) { this->type = _type; }

        /**
         * @brief Modifie la matrice de l'entitee
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