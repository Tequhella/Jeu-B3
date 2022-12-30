/**
 * @file protagoniste.cpp
 * @author Lilian CHARDON (lilian.chardon@ynov.com)
 * @brief Fichier des déclarations des méthodes de la classe Protagoniste
 * @version 0.1
 * @date 15-12-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../../headers/entitees/acteurs/protagoniste.h"

/****************/
/* CONSTRUCTEUR */
/****************/

Protagoniste::Protagoniste() : Acteur()
{
    type = PROTAGONISTE;
}

Protagoniste::Protagoniste(Matrix* _A) : Acteur(_A){}

Protagoniste::Protagoniste(Matrix* _A, int _x, int _y) : Acteur(_A, _x, _y){}

Protagoniste::Protagoniste(const Protagoniste& _p) : Acteur((Matrix*)_p.A, (int)_p.x, (int)_p.y){}

/***************/
/* DESTRUCTEUR */
/***************/

Protagoniste::~Protagoniste(){}

/**************/
/* OPERATEURS */
/**************/

ostream& operator<<(ostream& _os, const Protagoniste& _p)
{
    _os << "Protagoniste : " << endl;
    _os << "Position : (" << _p.x << ", " << _p.y << ")" << endl;
    _os << "Inventaire : " << endl;
    for (unsigned int i = 0; i < _p.inventaire.size(); i++)
    {
        _os << _p.inventaire[i] << endl;
    }
    return _os;
}

/************/
/* METHODES */
/************/

