/**
 * @file mules.cpp
 * @author Lilian CHARDON (lilian.chardon@ynov.com)
 * @brief 
 * @version 0.1
 * @date 20-12-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../../headers/entitees/acteurs/mules.h"

/*****************/
/* CONSTRUCTEURS */
/*****************/

Mules::Mules() : Acteur(){}

Mules::Mules(Matrix& A) : Acteur(A){}

Mules::Mules(Matrix& A, int x, int y) : Acteur(A, x, y){}

Mules::Mules(const Mules& m) : Acteur((Matrix&)m.A, (int)m.x, (int)m.y){}

/***************/
/* DESTRUCTEUR */
/***************/

Mules::~Mules(){}

/**************/
/* OPERATEURS */
/**************/

Mules& Mules::operator=(const Mules& m)
{
    this->A = m.A;
    this->x = m.x;
    this->y = m.y;
    return *this;
}

ostream& operator<<(ostream& os, const Mules& m)
{
    os << "Mules : " << endl;
    os << "Position : (" << m.x << ", " << m.y << ")" << endl;
    return os;
}

/************/
/* METHODES */
/************/

void Mules::poursuite(Protagoniste& p)
{
    if (p.getX() > x) /*-------->*/ x++;
    else if (p.getX() < x) /*--->*/ x--;
    else if (p.getY() > y) /*--->*/ y++;
    else if (p.getY() < y) /*--->*/ y--;
}