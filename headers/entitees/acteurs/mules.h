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
         */
        Mules(Matrix& A);

        /**
         * @brief Constructeur de la classe Mules
         * 
         */
        Mules(Matrix& A, int x, int y);

        /**
         * @brief Constructeur de la classe Mules
         * 
         */
        Mules(const Mules& m);

    
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
         * @brief Surcharge de l'opérateur <<
         * 
         * @param os 
         * @param m 
         * @return ostream& 
         */
        friend ostream& operator<<(ostream& os, const Mules& m);
    
    /*************/
    /* ACCESSEUR */
    /*************/

        /**
         * @brief Retourne le nombre de marchandises du mule
         * 
         * @return int 
         */
        int getNbMarchandises() const { return inventaire.size(); }

        /**
         * @brief Retourne la liste des marchandises du mule
         * 
         * @return vector<Marchandise> 
         */
        vector<Marchandise> getMarchandises() const { return inventaire; }

        /**
         * @brief Retourne la marchandise à l'indice i
         * 
         * @param i 
         * @return Marchandise 
         */
        Marchandise getMarchandise(int i) const { return inventaire[i]; }

        /**
         * @brief Retourne l'endurance du mule
         * 
         * @return double 
         */
        double getEndurance() const { return endurance; }

    /*************/
    /* MUTATEURS */
    /*************/

        /**
         * @brief Modifie la marchandise à la position i
         * 
         * @param i la position de la marchandise
         * @param m la nouvelle marchandise
         */
        void setMarchandise(int i, Marchandise& m) { inventaire[i] = m; }

        /**
         * @brief Modifie l'endurance du protagoniste
         * 
         * @param e la nouvelle endurance
         */
        void setEndurance(double e) { endurance = e; }
    
    /************/
    /* METHODES */
    /************/

        /**
         * @brief Poursuit le protagoniste
         * 
         * @param p 
         */
        void poursuite(Protagoniste& p);
    
    /*************/
    /* ATTRIBUTS */
    /*************/

};

#endif // __MULES_H__