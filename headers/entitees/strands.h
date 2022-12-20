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
         */
        Strands(Matrix& A);

        /**
         * @brief Constructeur de la classe Strands
         * 
         */
        Strands(Matrix& A, int x, int y);

        /**
         * @brief Constructeur de la classe Strands
         * 
         */
        Strands(const Strands& s);

    
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
         * @param s le Strands à copier
         * @return Strands& le Strands copié
         */
        Strands& operator=(const Strands& s);

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