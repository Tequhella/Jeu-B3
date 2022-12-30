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

Strands::Strands(Matrix* _A) : Entitee(_A){}

Strands::Strands(Matrix* _A, int _x, int _y) : Entitee(_A, _x, _y, STRANDS){}

Strands::Strands(const Strands& _s) : Entitee((Matrix*)_s.A, (int)_s.x, (int)_s.y, (int)_s.type){}

/***************/
/* DESTRUCTEUR */
/***************/

Strands::~Strands(){}

/**************/
/* OPERATEURS */
/**************/

Strands& Strands::operator=(const Strands& _s)
{
    x    = _s.x;
    y    = _s.y;
    type = _s.type;
    A    = _s.A;
    return *this;
}

ostream& operator<<(ostream& _os, const Strands& _s)
{
    _os << "Strands : " << endl;
    _os << "Position : (" << _s.getX() << ", " << _s.getY() << ")" << endl;
    return _os;
}

/************/
/* METHODES */
/************/

bool Strands::poursuite(Protagoniste& _p)
{
    if (_p.getX() > x) /*-------->*/ x++;
    else if (_p.getX() < x) /*--->*/ x--;
    else if (_p.getY() > y) /*--->*/ y++;
    else if (_p.getY() < y) /*--->*/ y--;
    return (_p.getX() == x && _p.getY() == y);
}