/**
 * @file strands.cpp
 * @author Lilian CHARDON,
 * @brief Fichier des définitions des méthodes de la classe Strands
 * @version 0.1
 * @date 19-12-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../headers/entitees/strands.h"

/*****************/
/* CONSTRUCTEURS */
/*****************/

Strands::Strands() : Entitee(){}

Strands::Strands(Matrix& A) : Entitee(&A){}

Strands::Strands(Matrix& A, int x, int y) : Entitee(&A, x, y){}

Strands::Strands(const Strands& s) : Entitee((Matrix*)s.A, (int)s.x, (int)s.y){}

/***************/
/* DESTRUCTEUR */
/***************/

Strands::~Strands(){}

/**************/
/* OPERATEURS */
/**************/

ostream& operator<<(ostream& os, const Strands& s)
{
    os << "Strands : " << endl;
    os << "Position : (" << s.getX() << ", " << s.getY() << ")" << endl;
    return os;
}

/************/
/* METHODES */
/************/

bool Strands::poursuite(Protagoniste& p)
{
    if (p.getX() > x) /*-------->*/ x++;
    else if (p.getX() < x) /*--->*/ x--;
    else if (p.getY() > y) /*--->*/ y++;
    else if (p.getY() < y) /*--->*/ y--;
    return (p.getX() == x && p.getY() == y);
}