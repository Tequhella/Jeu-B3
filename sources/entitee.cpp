/**
 * @file entitee.cpp
 * @author Lilian CHARDON,
 * @brief Fichier des définitions des méthodes de la classe Entitee
 * @version 0.1
 * @date 19-12-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../headers/entitee.h"
#include "../headers/entitees/acteur.h"

/*****************/
/* CONSTRUCTEURS */
/*****************/

Entitee::Entitee() : x(0), y(0), A(new Matrix(1, 1))
{
    A->in(0, 0, 0);
}

Entitee::Entitee(Matrix* A) : x(0), y(0), A(A)
{
    A->in(0, 0, 0);
}

Entitee::Entitee(Matrix* _A, int _x, int _y) : x(_x), y(_y), A(_A)
{
    if (_x > LARGEUR_MAX || _y > LARGEUR_MAX)
    {
        cout << "Erreur : les coordonnées sont trop grandes" << endl;
        exit(1);
    }
    A->in(_x, _y, 0);
}

Entitee::Entitee(Matrix* _A, int _x, int _y, int _type) : x(_x), y(_y), type(_type), A(_A)
{
    // Vérification des paramètres
    if (_x > LARGEUR_MAX || _y > LARGEUR_MAX)
    {
        cout << "Erreur : les coordonnées sont trop grandes" << endl;
        exit(1);
    }
    else if (type > 3)
    {
        cout << "Erreur : le type n'est pas valide" << endl;
        exit(1);
    }

    // Vérifie le type de l'entité pour l'ajouter dans la matrice
    if (type == ACTEUR)
    {
        // On caste l'objet pour récupérer le type de l'acteur
        Acteur* acteur = static_cast<Acteur*>(this);
        cout << "Type de l'acteur : " << acteur->getType() << endl;
        A->in(_x, _y, ACTEUR + acteur->getType());
    }
    else /*--->*/ A->in(_x, _y, type);
}

Entitee::Entitee(const Entitee& _e) : x(_e.x), y(_e.y), A(_e.A){}

/***************/
/* DESTRUCTEUR */
/***************/

Entitee::~Entitee()
{
    
}

/**************/
/* OPERATEURS */
/**************/

Entitee& Entitee::operator=(const Entitee& _e)
{
    x = _e.x;
    y = _e.y;
    A = _e.A;
    return *this;
}

bool Entitee::operator==(const Entitee& _e)
{
    return (x == _e.x && y == _e.y && A == _e.A);
}

ostream& operator<<(ostream& _os, const Entitee& _e)
{
    _os << "Entitee : " << endl;
    _os << "Position : (" << _e.x << ", " << _e.y << ")" << endl;
    return _os;
}

/************/
/* METHODES */
/************/

void Entitee::placement()
{
    // Vérifie le type de l'entité pour l'ajouter dans la matrice
    if (type == ACTEUR)
    {
        // On caste l'objet pour récupérer le type de l'acteur
        Acteur* acteur = static_cast<Acteur*>(this);
        cout << "Type de l'acteur : " << acteur->getType() << endl;
        A->in(x, y, ACTEUR + acteur->getType());
    }
    else /*--->*/ A->in(x, y, type);
}