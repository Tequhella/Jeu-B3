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

#include "../../headers/acteurs/marchandise.h"

/****************/
/* CONSTRUCTEUR */
/****************/

Marchandise::Marchandise() : Acteur(){}

Marchandise::Marchandise(Matrix& A) : Acteur(A){}

Marchandise::Marchandise(Matrix& A, int x, int y) : Acteur(A, x, y){}

Marchandise::Marchandise(const Marchandise& m) : Acteur((Matrix&)m.A, (int)m.x, (int)m.y){}

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
    return *this;
}

bool Marchandise::operator==(const Marchandise& m) const
{
    return (x == m.x && y == m.y && valeur == m.valeur);
}

ostream& operator<<(ostream& os, const Marchandise& m)
{
    os << "Marchandise : " << endl;
    os << "Position : (" << m.x << ", " << m.y << ")" << endl;
    return os;
}
