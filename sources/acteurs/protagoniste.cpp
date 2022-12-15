/**
 * @file protagoniste.cpp
 * @author Lilian CHARDON (lilian.chardon@ynov.com)
 * @brief Fichier des déclarations des méthodes de la classe Protagoniste
 * @version 0.1
 * @date 15-12-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../headers/acteurs/protagoniste.h"

/****************/
/* CONSTRUCTEUR */
/****************/

Protagoniste::Protagoniste(Matrix& A) : Acteur(A){}

Protagoniste::Protagoniste(Matrix& A, int x, int y) : Acteur(A, x, y){}

Protagoniste::Protagoniste(const Protagoniste& p) : Acteur((Matrix&)p.A, (int)p.x, (int)p.y){}

/***************/
/* DESTRUCTEUR */
/***************/

Protagoniste::~Protagoniste(){}

/**************/
/* OPERATEURS */
/**************/

ostream& operator<<(ostream& os, const Protagoniste& p)
{
    os << "Protagoniste : " << endl;
    os << "Position : (" << p.x << ", " << p.y << ")" << endl;
    os << "Inventaire : " << endl;
    for (unsigned int i = 0; i < p.inventaire.size(); i++)
    {
        os << p.inventaire[i] << endl;
    }
    return os;
}

/************/
/* METHODES */
/************/

void Protagoniste::pickUp(Marchandise& m)
{
    if (inventaire.size() < NB_MARCHANDISE_MAX)
    {
        inventaire.push_back(&m);
    }
}

void Protagoniste::pickUpAll(vector<Marchandise>& m)
{
    for (unsigned int i = 0; i < m.size(); i++)
    {
        pickUp(m[i]);
    }
}

void Protagoniste::dropOff(Marchandise& m)
{
    for (unsigned int i = 0; i < inventaire.size(); i++)
    {
        if (inventaire[i] == &m)
        {
            inventaire.erase(inventaire.begin() + i);
        }
    }
}

void Protagoniste::dropOffAll()
{
    inventaire.clear();
}