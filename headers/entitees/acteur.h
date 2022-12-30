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

#define NB_MARCHANDISE_MAX 10
#define ENDURANCE_MAX 100

enum typeActeur
{
    PROTAGONISTE,
    MULE
};

enum direction
{
    HAUT,
    BAS,
    GAUCHE,
    DROITE
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
         * @param _A la matrice dans laquelle l'acteur se trouve
         */
        Acteur(Matrix* _A);

        /**
         * @brief Constructeur de la classe Acteur
         * 
         * @param _A la matrice dans laquelle l'acteur se trouve
         * @param _x la position en x de l'acteur
         * @param _y la position en y de l'acteur
         */
        Acteur(Matrix* _A, int _x, int _y);

        /**
         * @brief Constructeur de la classe Acteur
         * 
         * @param _A la matrice dans laquelle l'acteur se trouve
         * @param _x la position en x de l'acteur
         * @param _y la position en y de l'acteur
         * @param _type le type de l'acteur
         */
        Acteur(Matrix* _A, int _x, int _y, int _type);

        /**
         * @brief Constructeur de copie de la classe Acteur
         * 
         * @param _a l'acteur à copier
         */
        Acteur(const Acteur& _a);

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
         * @param _a l'acteur à affecter
         * @return Acteur& l'acteur affecté
         */
        Acteur& operator=(const Acteur& _a);

        /**
         * @brief Opérateur d'affichage de la classe Acteur
         * 
         * @param _os le flux de sortie
         * @param _a l'acteur à afficher
         * @return ostream& le flux de sortie
         */
        friend ostream& operator<<(ostream& _os, const Acteur& _a);

    /************/
    /* METHODES */
    /************/

        /**
         * @brief Attaque l'acteur passé en paramètre
         * 
         * @param _a
         */
        void attaquer(Acteur& _a);

        /**
         * @brief Déplace l'acteur dans la matrice avec les coordonnées x et y
         * 
         * @param _x la position en x de l'acteur
         * @param _y la position en y de l'acteur
         */
        void deplacement(int _x, int _y);

        /**
         * @brief Déplace l'acteur de manière aléatoire dans la matrice
         */
        void deplacementR();

        /**
         * @brief Prend une marchandise
         * 
         * @param m la marchandise à prendre
         */
        void pickUp(Marchandise& _m);

        /**
         * @brief Prend toutes les marchandises
         * 
         * @param _m le vecteur de marchandises
         */
        void pickUpAll(vector<Marchandise>& _m);

        /**
         * @brief Dépose une marchandise
         * 
         * @param _m la marchandise à déposer
         */
        void dropOff(Marchandise& _m);

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
         * 
         * @param _e la valeur à recharger
         */
        void rechargerEndurance(double _e);

        /**
         * @brief Diminue l'endurance du protagoniste
         */
        void diminuerEndurance();

        /**
         * @brief Diminue l'endurance du protagoniste d'une certaine valeur
         * 
         * @param _e la valeur à diminuer
         */
        void diminuerEndurance(double _e);

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
        int getType() const { return typeActeur; }

    /*************/
    /* MUTATEURS */
    /*************/

        /**
         * @brief Modifie la coordonnée x de l'acteur
         * 
         * @param x la nouvelle coordonnée x de l'acteur
         */
        void setX(int _x) { this->x = _x; }

        /**
         * @brief Modifie la coordonnée y de l'acteur
         * 
         * @param y la nouvelle coordonnée y de l'acteur
         */
        void setY(int _y) { this->y = _y; }

        /**
         * @brief Modifie les points de vie de l'acteur
         * 
         * @param v 
         */
        void setVie(int _v) { vie = _v;}

        /**
         * @brief Modifie la force de l'acteur
         * 
         * @param d 
         */
        void setForce(int _d) { force = _d;}

        /**
         * @brief Modifie la vitesse de l'acteur
         * 
         * @param v 
         */
        void setVitesse(double _v) { vitesse = _v;}

        /**
         * @brief Modifie le type de l'acteur
         * 
         * @param t 
         */
        void setType(int _t) { typeActeur = _t;}
        
    protected:
        int typeActeur;
        int vie;
        int force;
        int vitesse;
        double endurance;
        uint8_t direction;
        vector<Marchandise> inventaire;
};

#endif // __ACTEUR_H__