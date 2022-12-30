/**
 * @file protagoniste.h
 * @author Lilian CHARDON
 * @brief Fichier des déclarations des méthodes de la classe Protagoniste
 * @version 0.1
 * @date 14-12-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __PROTAGONISTE_H__
#define __PROTAGONISTE_H__

#include "../acteur.h"
#include <vector>

using namespace std;

class Protagoniste : public Acteur
{
    public:
    /****************/
    /* CONSTRUCTEUR */
    /****************/

        /**
         * @brief Constructeur par défaut
         */
        Protagoniste();

        /**
         * @brief Constructeur avec une matrice
         * 
         * @param _A la matrice dans laquelle le protagoniste se trouve
         */
        Protagoniste(Matrix* _A);

        /**
         * @brief Constructeur avec une matrice et une position
         * 
         * @param _A la matrice dans laquelle le protagoniste se trouve
         * @param _x la position en x du protagoniste
         * @param _y la position en y du protagoniste
         */
        Protagoniste(Matrix* _A, int _x, int _y);

        /**
         * @brief Constructeur de copie
         * 
         * @param _p le protagoniste à copier
         */
        Protagoniste(const Protagoniste& _p);

    /***************/
    /* DESTRUCTEUR */
    /***************/

        /**
         * @brief Destructeur
         */
        ~Protagoniste();

    /**************/
    /* OPERATEURS */
    /**************/

        /**
         * @brief opérateur de flux de sortie
         * 
         * @param _os le flux de sortie
         * @param _p le protagoniste
         */
        friend ostream& operator<<(ostream& _os, const Protagoniste& _p);

    
    /**************/
    /* ACCESSEURS */
    /**************/

        

    /*************/
    /* MUTATEURS */
    /*************/

        
    
    /************/
    /* METHODES */
    /************/
        
        


    private:
        
};

#endif // __PROTAGONISTE_H__