/**
 * @file acteur.cpp
 * @author Lilian CHARDON
 * @brief Fichier des définitions des méthodes de la classe Acteur
 * @version 0.1
 * @date 15-12-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../headers/entitees/acteur.h"

/*****************/
/* CONSTRUCTEURS */
/*****************/

Acteur::Acteur()
{
    srand(time(NULL));
    this->x = rand() % LARGEUR_MAX;
    this->y = rand() % LARGEUR_MAX;
}

Acteur::Acteur(Matrix& A) : A(A)
{
    srand(time(NULL));
    this->x = rand() % LARGEUR_MAX;
    this->y = rand() % LARGEUR_MAX;
    this->A.in(this->x, this->y, 0);
}

Acteur::Acteur(Matrix& A ,int x, int y): A(A), x(x), y(y)
{
    if (x > LARGEUR_MAX || y > LARGEUR_MAX)
    {
        std::cout << "Erreur : les coordonnées sont trop grandes" << std::endl;
        exit(1);
    }
    this->A.in(this->x, this->y, 0);
}

Acteur::Acteur(Matrix& A, int x, int y, int type) : A(A), x(x), y(y), type(type)
{
    if (x > LARGEUR_MAX || y > LARGEUR_MAX)
    {
        std::cout << "Erreur : les coordonnées sont trop grandes" << std::endl;
        exit(1);
    }
    this->A.in(this->x, this->y, this->type);
}

Acteur::Acteur(const Acteur& a) : A(a.A), x(a.x), y(a.y)
{
    this->A.in(this->x, this->y, 0);
}

/***************/
/* DESTRUCTEUR */
/***************/

Acteur::~Acteur()
{
    
}

/***************/
/* OPERATEURS  */
/***************/

Acteur& Acteur::operator=(const Acteur& a)
{
    this->A = a.A;
    this->x = a.x;
    this->y = a.y;
    return *this;
}

ostream& operator<<(ostream& os, const Acteur& a)
{
    os << "Acteur : " << a.x << " " << a.y << endl;
    return os;
}

/************/
/* METHODES */
/************/

void Acteur::attaquer(Acteur& a)
{
    
}

void Acteur::deplacement(int x, int y)
{
    A.out(this->x, this->y);
    this->x += x;
    if (this->x < 0)
        this->x += LARGEUR_MAX;
    else if (this->x > LARGEUR_MAX)
        this->x -= LARGEUR_MAX;

    this->y += y;
    if (this->y < 0)
        this->y += LARGEUR_MAX;
    else if (this->y > LARGEUR_MAX)
        this->y -= LARGEUR_MAX;

    A.in(this->x, this->y, 0);
}

void Acteur::deplacementR()
{
    srand(time(NULL));
    A.out(this->x, this->y);
    this->x = rand() % LARGEUR_MAX;
    this->y = rand() % LARGEUR_MAX;
    A.in(this->x, this->y, 0);
}

void Acteur::pickUp(Marchandise& m)
{
    this->inventaire.push_back(m);
}

void Acteur::pickUpAll(vector<Marchandise>& m)
{
    for (int i = 0; i < m.size(); i++)
    {
        this->inventaire.push_back(m[i]);
    }
}

void Acteur::dropOff(Marchandise& m)
{
    for (int i = 0; i < this->inventaire.size(); i++)
    {
        if (this->inventaire[i] == m)
        {
            this->inventaire.erase(this->inventaire.begin() + i);
            break;
        }
    }
}

void Acteur::dropOffAll()
{
    this->inventaire.clear();
}

void Acteur::rechargerEndurance()
{
    if (endurance < ENDURANCE_MAX)
    {
        endurance += 1;
    }
}

void Acteur::rechargerEndurance(double e)
{
    if (endurance < ENDURANCE_MAX)
    {
        endurance += e;
    }
}

void Acteur::diminuerEndurance()
{
    if (endurance > 0)
    {
        endurance -= 1;
    }
}

void Acteur::diminuerEndurance(double e)
{
    if (endurance > 0)
    {
        endurance -= e;
    }
}