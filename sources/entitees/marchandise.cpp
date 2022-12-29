/**
 * @file marchandise.cpp
 * @author Lilian CHARDON (lilian.chardon@ynov.com)
 * @brief Fichier des déclarations des méthodes de la classe Marchandise
 * @version 0.1
 * @date 15-12-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../headers/entitees/marchandise.h"

/****************/
/* CONSTRUCTEUR */
/****************/

Marchandise::Marchandise() : Entitee(), valeur(0), nomMarchandise("default")
{
    type = 0;
}

Marchandise::Marchandise(Matrix& _A) : Entitee(&_A), valeur(0), nomMarchandise("default")
{
    type = 0;
}

Marchandise::Marchandise(Matrix& _A, int _x, int _y) : Entitee(&_A, _x, _y, 0), valeur(0), nomMarchandise("default"){}

Marchandise::Marchandise(Matrix& _A, int _x, int _y, int _valeur, string _nomMarchandise, int _type) : Entitee(&_A, _x, _y, _type), valeur(_valeur), nomMarchandise(_nomMarchandise){}

Marchandise::Marchandise(const Marchandise& _m) : Entitee((Matrix*)_m.A, (int)_m.x, (int)_m.y, (int)_m.type), valeur(_m.valeur), nomMarchandise(_m.nomMarchandise){}

/***************/
/* DESTRUCTEUR */
/***************/

Marchandise::~Marchandise(){}

/**************/
/* OPERATEURS */
/**************/

Marchandise& Marchandise::operator=(const Marchandise& m)
{
    A = m.A;
    x = m.x;
    y = m.y;
    valeur = m.valeur;
    nomMarchandise = m.nomMarchandise;
    type = m.type;
    return *this;
}

bool Marchandise::operator==(const Marchandise& m) const
{
    return (x == m.x && y == m.y && A == m.A && valeur == m.valeur && nomMarchandise == m.nomMarchandise && type == m.type);
}

ostream& operator<<(ostream& os, const Marchandise& m)
{
    os << "Marchandise : " << endl;
    os << "Position : (" << m.x << ", " << m.y << ")" << endl;
    os << "valeur : " << m.valeur << endl;
    os << "nomMarchandise : " << m.nomMarchandise << endl;
    os << "type : " << m.type << endl;
    return os;
}
