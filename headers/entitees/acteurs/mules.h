/**
 * @file mules.h
 * @author Lilian CHARDON (lilian.chardon@ynov.com)
 * @brief Fichier des déclarations des méthodes de la classe Mules
 * @version 0.1
 * @date 19-12-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __MULES_H__
#define __MULES_H__

#include "../acteur.h"
#include "protagoniste.h"

#include <vector>
#include <math.h>

using namespace std;

class Mules : public Acteur
{
    public:
    /****************/
    /* CONSTRUCTEUR */
    /****************/

        /**
         * @brief Constructeur par défaut de la classe Mules
         */
        Mules();

        /**
         * @brief Constructeur de la classe Mules
         * 
         * @param _A la matrice de l'entitee
         */
        Mules(Matrix* _A);

        /**
         * @brief Constructeur de la classe Mules
         * 
         * @param _A la matrice de l'entitee
         * @param _x la position x de l'entitee
         * @param _y la position y de l'entitee
         */
        Mules(Matrix* _A, int _x, int _y);

        /**
         * @brief Constructeur par copie de la classe Mules
         * 
         * @param _m la mule a copier
         */
        Mules(const Mules& _m);

    
    /***************/
    /* DESTRUCTEUR */
    /***************/

        /**
         * @brief Destructeur de la classe Mules
         */
        ~Mules();

    /**************/
    /* OPERATEURS */
    /**************/

        /**
         * @brief Surcharge de l'opérateur =
         * 
         * @param _m 
         * @return Mules& 
         */
        Mules& operator=(const Mules& _m);

        /**
         * @brief Surcharge de l'opérateur <<
         * 
         * @param _os 
         * @param _m 
         * @return ostream& 
         */
        friend ostream& operator<<(ostream& _os, const Mules& _m);
    
    /*************/
    /* ACCESSEUR */
    /*************/


    /*************/
    /* MUTATEURS */
    /*************/

    
    /************/
    /* METHODES */
    /************/

        /**
         * @brief Poursuit le protagoniste
         * 
         * @param _p 
         */
        void poursuite(Protagoniste& _p);
    
    /*************/
    /* ATTRIBUTS */
    /*************/

};

#endif // __MULES_H__