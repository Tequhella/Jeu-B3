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

/*****************/
/* CONSTRUCTEURS */
/*****************/

Entitee::Entitee() : x(0), y(0), A(Matrix(1, 1))
{
    A.in(0, 0, 0);
}

Entitee::Entitee(Matrix& A) : x(0), y(0), A(A)
{
    A.in(0, 0, 0);
}

Entitee::Entitee(Matrix& _A, int _x, int _y) : x(_x), y(_y), A(_A)
{
    A.in(_x, _y, 0);
}

Entitee::Entitee(const Entitee& e) : x(e.x), y(e.y), A(e.A){}

/***************/
/* DESTRUCTEUR */
/***************/

Entitee::~Entitee() {}

/**************/
/* OPERATEURS */
/**************/

Entitee& Entitee::operator=(const Entitee& e)
{
    x = e.x;
    y = e.y;
    A = e.A;
    return *this;
}

bool Entitee::operator==(const Entitee& e)
{
    return (x == e.x && y == e.y && A == e.A);
}

ostream& operator<<(ostream& os, const Entitee& e)
{
    os << "Entitee : " << endl;
    os << "x : " << e.x << endl;
    os << "y : " << e.y << endl;
    os << "A : " << endl;
    os << e.A;
    return os;
}