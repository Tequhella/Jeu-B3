/**
 * @file marchandise.h
 * @author Lilian CHARDON
 * @brief 
 * @version 0.1
 * @date 14-12-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __MARCHANDISE_H__
#define __MARCHANDISE_H__

#include "acteur.h"
#include <list>

using namespace std;

class Marchandise : public Acteur
{
    public:
    /****************/
    /* CONSTRUCTEUR */
    /****************/

        /**
         * @brief Constructeur par défaut
         */
        Marchandise();

        /**
         * @brief Constructeur avec une matrice
         * 
         * @param A la matrice dans laquelle la marchandise se trouve
         */
        Marchandise(Matrix& A);

        /**
         * @brief Constructeur avec une matrice et une position
         * 
         * @param A la matrice dans laquelle la marchandise se trouve
         * @param x la position en x de la marchandise
         * @param y la position en y de la marchandise
         */
        Marchandise(Matrix& A, int x, int y);

        /**
         * @brief Constructeur de copie
         * 
         * @param m la marchandise à copier
         */
        Marchandise(const Marchandise& m);

    /***************/
    /* DESTRUCTEUR */
    /***************/

        /**
         * @brief Destructeur de la classe Marchandise
         */
        ~Marchandise();

    /**************/
    /* OPERATEURS */
    /**************/

        /**
         * @brief Opérateur d'affectation
         * 
         * @param m la marchandise à copier
         * @return Marchandise& la marchandise copiée
         */
        Marchandise& operator=(const Marchandise& m);

        /**
         * @brief Opérateur de comparaison
         * 
         * @param m la marchandise à comparer
         * @return true si les deux marchandises sont égales
         */
        bool operator==(const Marchandise& m) const;

        /**
         * @brief Affiche la marchandise
         */
        friend ostream& operator<<(ostream& os, const Marchandise& m);

    /***********/
    /* GETTERS */
    /***********/

        /**
         * @brief Récupère la valeur de la marchandise
         * 
         * @return int la valeur de la marchandise
         */
        int getValeur() const { return valeur; }
    
    /***********/
    /* SETTERS */
    /***********/

        /**
         * @brief Modifie la valeur de la marchandise
         * 
         * @param valeur la nouvelle valeur de la marchandise
         */
        void setValeur(int valeur) { this->valeur = valeur; }

    private:
        int valeur;

};

#endif // __MARCHANDISE_H__