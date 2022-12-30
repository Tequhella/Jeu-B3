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

Mules::Mules() : Acteur()
{
    type = MULE;
}

Mules::Mules(Matrix* _A) : Acteur(_A)
{
    type = MULE;
}

Mules::Mules(Matrix* _A, int _x, int _y) : Acteur(_A, _x, _y, MULE){}

Mules::Mules(const Mules& _m) : Acteur((Matrix*)_m.A, (int)_m.x, (int)_m.y, (int)_m.type){}

/***************/
/* DESTRUCTEUR */
/***************/

Mules::~Mules(){}

/**************/
/* OPERATEURS */
/**************/

Mules& Mules::operator=(const Mules& _m)
{
    this->A = _m.A;
    this->x = _m.x;
    this->y = _m.y;
    return *this;
}

ostream& operator<<(ostream& _os, const Mules& _m)
{
    _os << "Mules : " << endl;
    _os << "Position : (" << _m.x << ", " << _m.y << ")" << endl;
    return _os;
}

/************/
/* METHODES */
/************/

void Mules::poursuite(Protagoniste& _p)
{
    if (_p.getX() > x) /*-------->*/ x++;
    else if (_p.getX() < x) /*--->*/ x--;
    else if (_p.getY() > y) /*--->*/ y++;
    else if (_p.getY() < y) /*--->*/ y--;
}