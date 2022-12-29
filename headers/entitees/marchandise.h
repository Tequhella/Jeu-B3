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

#include <string>
#include "../entitee.h"

using namespace std;

class Marchandise : public Entitee
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
         * @param _A la matrice dans laquelle la marchandise se trouve
         */
        Marchandise(Matrix& _A);

        /**
         * @brief Constructeur avec une matrice et une position
         * 
         * @param _A la matrice dans laquelle la marchandise se trouve
         * @param _x la position en x de la marchandise
         * @param _y la position en y de la marchandise
         */
        Marchandise(Matrix& _A, int _x, int _y);

        /**
         * @brief Constructeur avec une matrice, une position et un type
         * 
         * @param _A la matrice dans laquelle la marchandise se trouve
         * @param _x la position en x de la marchandise
         * @param _y la position en y de la marchandise
         * @param _valeur la valeur de la marchandise
         * @param _nomMarchandise le nom de la marchandise
         * @param _type le type de la marchandise
         */
        Marchandise(Matrix& _A, int _x, int _y, int _valeur, string _nom, int _type);

        /**
         * @brief Constructeur de copie
         * 
         * @param m la marchandise à copier
         */
        Marchandise(const Marchandise& _m);

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
         * @param _m la marchandise à copier
         * @return Marchandise& la marchandise copiée
         */
        Marchandise& operator=(const Marchandise& _m);

        /**
         * @brief Opérateur de comparaison
         * 
         * @param _m la marchandise à comparer
         * @return true si les deux marchandises sont égales
         */
        bool operator==(const Marchandise& _m) const;

        /**
         * @brief Affiche la marchandise
         */
        friend ostream& operator<<(ostream& _os, const Marchandise& _m);

    /**************/
    /* ACCESSEURS */
    /**************/

        /**
         * @brief Récupère la valeur de la marchandise
         * 
         * @return int la valeur de la marchandise
         */
        int getValeur() const { return valeur; }
    
    /*************/
    /* MUTATEURS */
    /*************/

        /**
         * @brief Modifie la valeur de la marchandise
         * 
         * @param valeur la nouvelle valeur de la marchandise
         */
        void setValeur(int _valeur) { this->valeur = _valeur; }

    private:
        int  valeur;
        string nomMarchandise;

};

#endif // __MARCHANDISE_H__