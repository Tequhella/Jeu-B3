/**
 * @file strands.h
 * @author Lilian CHARDON,
 * @brief Fichier des déclarations des méthodes de la classe Strands
 * @version 0.1
 * @date 19-12-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __STRANDS_H__
#define __STRANDS_H__

#include <iostream>
#include <string>
#include <time.h>
#include "../entitee.h"
#include "acteurs/protagoniste.h"

using namespace std;

class Strands : public Entitee
{
    public:
    /*****************/
    /* CONSTRUCTEURS */
    /*****************/

        /**
         * @brief Constructeur par défaut de la classe Strands
         */
        Strands();

        /**
         * @brief Constructeur de la classe Strands
         * 
         * @param _A la matrice de l'entitee
         */
        Strands(Matrix* _A);

        /**
         * @brief Constructeur de la classe Strands
         * 
         * @param _A la matrice de l'entitee
         * @param _x la position x de l'entitee
         * @param _y la position y de l'entitee
         */
        Strands(Matrix* _A, int _x, int _y);

        /**
         * @brief Constructeur par copie de la classe Strands
         * 
         * @param _s le Strands à copier
         */
        Strands(const Strands& _s);

    
    /***************/
    /* DESTRUCTEUR */
    /***************/

        /**
         * @brief Destructeur de la classe Strands
         */
        ~Strands();

    /**************/
    /* OPERATEURS */
    /**************/

        /**
         * @brief Opérateur d'affectation de la classe Strands
         * 
         * @param _s le Strands à copier
         * @return Strands& le Strands copié
         */
        Strands& operator=(const Strands& _s);

        /**
         * @brief Opérateur de flux de sortie de la classe Strands
         * 
         * @param _os le flux de sortie
         * @param _s le Strands à afficher
         */
        friend ostream& operator<<(ostream& _os, const Strands& _s);

    /************/
    /* METHODES */
    /************/

        /**
         * @brief Méthode qui permet de poursuivre le Strands
         * 
         * @param p le protagoniste à poursuivre
         * @return true si le Strands a atteint le protagoniste
         */
        bool poursuite(Protagoniste& p);
    
};

#endif // __STRANDS_H__