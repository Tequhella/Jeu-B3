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

#include "acteur.h"
#include "marchandise.h"
#include <vector>

#define NB_MARCHANDISE_MAX 10

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
         * @param A la matrice dans laquelle le protagoniste se trouve
         */
        Protagoniste(Matrix& A);

        /**
         * @brief Constructeur avec une matrice et une position
         * 
         * @param A la matrice dans laquelle le protagoniste se trouve
         * @param x la position en x du protagoniste
         * @param y la position en y du protagoniste
         */
        Protagoniste(Matrix& A, int x, int y);

        /**
         * @brief Constructeur de copie
         * 
         * @param p le protagoniste à copier
         */
        Protagoniste(const Protagoniste& p);

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
         * @brief Affiche l'inventaire du protagoniste
         */
        friend ostream& operator<<(ostream& os, const Protagoniste& p);

    
    /***********/
    /* GETTERS */
    /***********/

        /**
         * @brief Renvoie le nombre de marchandises que le protagoniste transporte
         * 
         * @return int le nombre de marchandises que le protagoniste transporte
         */
        int getNbMarchandise() const { return nbMarchandise; }

        /**
         * @brief Renvoie la marchandise à la position i
         * 
         * @param i la position de la marchandise
         * 
         * @return Marchandise& la marchandise à la position i
         */
        Marchandise getMarchandise(int i) const { return *inventaire[i];}

    /***********/
    /* SETTERS */
    /***********/

        /**
         * @brief Modifie la marchandise à la position i
         * 
         * @param i la position de la marchandise
         * @param m la nouvelle marchandise
         */
        void setMarchandise(int i, Marchandise& m) { inventaire[i] = &m; }
    
    /************/
    /* METHODES */
    /************/

        /**
         * @brief Prend une marchandise
         * 
         * @param m la marchandise à prendre
         */
        void pickUp(Marchandise& m);

        /**
         * @brief Prend toutes les marchandises
         */
        void pickUpAll(vector<Marchandise>& m);

        /**
         * @brief Dépose une marchandise
         * 
         * @param m la marchandise à déposer
         */
        void dropOff(Marchandise& m);

        /**
         * @brief Dépose toutes les marchandises
         */
        void dropOffAll();

    private:
        vector<Marchandise*> inventaire;
        int nbMarchandise;
};

#endif // __PROTAGONISTE_H__