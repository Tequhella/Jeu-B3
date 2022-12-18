/**
 * @file ennemi.h
 * @author Lilian CHARDON (lilian.chardon@ynov.com)
 * @brief Fichier des déclarations des méthodes de la classe Ennemi
 * @version 0.1
 * @date 16-12-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __ENNEMI_H__
#define __ENNEMI_H__

#include "acteur.h"

using namespace std;

class Ennemi : public Acteur
{
    public:
    /****************/
    /* CONSTRUCTEUR */
    /****************/

        /**
         * @brief Constructeur par défaut de la classe Ennemi
         */
        Ennemi();

        /**
         * @brief Constructeur de la classe Ennemi
         * 
         */
        Ennemi(Matrix& A);

        /**
         * @brief Constructeur de la classe Ennemi
         * 
         */
        Ennemi(Matrix& A, int x, int y);

        /**
         * @brief Constructeur de la classe Ennemi
         * 
         */
        Ennemi(const Ennemi& e);

    
    /***************/
    /* DESTRUCTEUR */
    /***************/

        /**
         * @brief Destructeur de la classe Ennemi
         */
        ~Ennemi();

    /**************/
    /* OPERATEURS */
    /**************/

        /**
         * @brief Surcharge de l'opérateur d'affichage
         * 
         * @param os 
         * @param e 
         * @return ostream& 
         */
        friend ostream& operator<<(ostream& os, const Ennemi& e);
};

#endif // __ENNEMI_H__