/**
 * @file ennemi.cpp
 * @author Lilian CHARDON (lilian.chardon@ynov.com)
 * @brief Fichier des définitions des méthodes de la classe Ennemi
 * @version 0.1
 * @date 16-12-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../headers/acteurs/ennemi.h"

/****************/
/* CONSTRUCTEUR */
/****************/

Ennemi::Ennemi() : Acteur(){}

Ennemi::Ennemi(Matrix& A) : Acteur(A){}

Ennemi::Ennemi(Matrix& A, int x, int y) : Acteur(A, x, y){}

Ennemi::Ennemi(const Ennemi& e) : Acteur((Matrix&)e.A, (int)e.x, (int)e.y){}

/***************/
/* DESTRUCTEUR */
/***************/

Ennemi::~Ennemi(){}

/**************/
/* OPERATEURS */
/**************/

ostream& operator<<(ostream& os, const Ennemi& e)
{
    os << "Ennemi : " << endl;
    os << "Position : (" << e.x << ", " << e.y << ")" << endl;
    return os;
}