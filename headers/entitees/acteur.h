/**
 * @file acteur.h
 * @author Lilian CHARDON,
 * @brief Fichier des déclarations des méthodes de la classe Acteur
 * @version 0.1
 * @date 25-10-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __ACTEUR_H__
#define __ACTEUR_H__

#define LARGEUR_MAX 80
#define NB_MARCHANDISE_MAX 10
#define ENDURANCE_MAX 100

enum Type
{
    PROTAGONISTE,
    MARCHANDISE,
    ENNEMI,
    OBSTACLE
};

#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include "../entitee.h"
#include "marchandise.h"

class Acteur : public Entitee
{
    public:
        static int id;

    /*****************/
    /* CONSTRUCTEURS */
    /*****************/

        /**
         * @brief Constructeur par défaut de la classe Acteur
         */
        Acteur();

        /**
         * @brief Constructeur de la classe Acteur
         * 
         * @param A la matrice dans laquelle l'acteur se trouve
         */
        Acteur(Matrix& A);

        /**
         * @brief Constructeur de la classe Acteur
         * 
         * @param A la matrice dans laquelle l'acteur se trouve
         * @param x la position en x de l'acteur
         * @param y la position en y de l'acteur
         */
        Acteur(Matrix& A, int x, int y);

        /**
         * @brief Constructeur de la classe Acteur
         * 
         * @param A la matrice dans laquelle l'acteur se trouve
         * @param x la position en x de l'acteur
         * @param y la position en y de l'acteur
         * @param type le type de l'acteur
         */
        Acteur(Matrix& A, int x, int y, int type);

        /**
         * @brief Constructeur de copie de la classe Acteur
         * 
         * @param a l'acteur à copier
         */
        Acteur(const Acteur& a);

    /***************/
    /* DESTRUCTEUR */
    /***************/

        /**
         * @brief Destructeur de la classe Acteur
         */
        ~Acteur();

    /**************/
    /* OPERATEURS */
    /**************/

        /**
         * @brief Opérateur d'affectation de la classe Acteur
         * 
         * @param a l'acteur à affecter
         * @return Acteur& l'acteur affecté
         */
        Acteur& operator=(const Acteur& a);

        /**
         * @brief Opérateur d'affichage de la classe Acteur
         * 
         * @param os le flux de sortie
         * @param a l'acteur à afficher
         * @return ostream& le flux de sortie
         */
        friend ostream& operator<<(ostream& os, const Acteur& a);

    /************/
    /* METHODES */
    /************/

        /**
         * @brief Attaque l'acteur passé en paramètre
         * 
         * @param a
         */
        void attaquer(Acteur& p);

        /**
         * @brief Déplace l'acteur dans la matrice avec les coordonnées x et y
         * 
         * @param x la position en x de l'acteur
         * @param y la position en y de l'acteur
         */
        void deplacement(int x, int y);

        /**
         * @brief Déplace l'acteur de manière aléatoire dans la matrice
         */
        void deplacementR();

        /**
         * @brief Prend une marchandise
         * 
         * @param m la marchandise à prendre
         */
        void pickUp(Marchandise& m);

        /**
         * @brief Prend toutes les marchandises
         * 
         * @param m le vecteur de marchandises
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

        /**
         * @brief Recharge l'endurance du protagoniste
         */
        void rechargerEndurance();

        /**
         * @brief Recharge l'endurance du protagoniste d'une certaine valeur
         */
        void rechargerEndurance(double e);

        /**
         * @brief Diminue l'endurance du protagoniste
         */
        void diminuerEndurance();

        /**
         * @brief Diminue l'endurance du protagoniste d'une certaine valeur
         */
        void diminuerEndurance(double e);

    /**************/
    /* ACCESSEURS */
    /**************/

        /**
         * @brief Renvoie la coordonnée x de l'acteur
         * 
         * @return int la coordonnée x de l'acteur
         */
        int getX() const { return x; }

        /**
         * @brief Renvoie la coordonnée y de l'acteur
         * 
         * @return int la coordonnée y de l'acteur
         */
        int getY() const { return y; }

        /**
         * @brief Renvoie les points de vie de l'acteur
         * 
         * @return int les points de vie de l'acteur
         */
        int getVie() const { return vie; }

        /**
         * @brief Renvoie la force de l'acteur
         * 
         * @return int la force de l'acteur
         */
        int getForce() const { return force; }

        /**
         * @brief Renvoie la vitesse de l'acteur
         * 
         * @return double la vitesse de l'acteur
         */
        double getVitesse() const { return vitesse; }

        /**
         * @brief Renvoie le type de l'acteur
         * 
         * @return int le type de l'acteur
         */
        int getType() const { return type; }

    /*************/
    /* MUTATEURS */
    /*************/

        /**
         * @brief Modifie la coordonnée x de l'acteur
         * 
         * @param x la nouvelle coordonnée x de l'acteur
         */
        void setX(int x) { this->x = x; }

        /**
         * @brief Modifie la coordonnée y de l'acteur
         * 
         * @param y la nouvelle coordonnée y de l'acteur
         */
        void setY(int y) { this->y = y; }

        /**
         * @brief Modifie les points de vie de l'acteur
         * 
         * @param v 
         */
        void setVie(int v) { vie = v;}

        /**
         * @brief Modifie la force de l'acteur
         * 
         * @param d 
         */
        void setForce(int d) { force = d;}

        /**
         * @brief Modifie la vitesse de l'acteur
         * 
         * @param v 
         */
        void setVitesse(double v) { vitesse = v;}

        /**
         * @brief Modifie le type de l'acteur
         * 
         * @param t 
         */
        void setType(int t) { type = t;}
        
    protected:
        Matrix A;
        int type;
        int x, y;
        int vie;
        int force;
        int vitesse;
        double endurance;
        vector<Marchandise> inventaire;
};

#endif // __ACTEUR_H__