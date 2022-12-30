/**
 * @file acteur.cpp
 * @author Lilian CHARDON
 * @brief Fichier des définitions des méthodes de la classe Acteur
 * @version 0.1
 * @date 15-12-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../headers/entitees/acteur.h"

/*****************/
/* CONSTRUCTEURS */
/*****************/

Acteur::Acteur() :
    typeActeur(0),
    vie(100),
    force(10),
    vitesse(10),
    endurance(10),
    direction(BAS),
    inventaire()
{
    Matrix A(LARGEUR_MAX, LARGEUR_MAX);
    srand(time(NULL));
    this->x = rand() % LARGEUR_MAX;
    this->y = rand() % LARGEUR_MAX;
    Entitee(&A, x, y, ACTEUR);
}

Acteur::Acteur(Matrix* _A) :
    typeActeur(0),
    vie(100),
    force(10),
    vitesse(10),
    endurance(10),
    direction(BAS),
    inventaire()
{
    srand(time(NULL));
    this->x = rand() % LARGEUR_MAX;
    this->y = rand() % LARGEUR_MAX;
    Entitee(_A, x, y, ACTEUR);
}

Acteur::Acteur(Matrix* _A, int _x, int _y) :
    Entitee(_A, _x, _y, ACTEUR),
    typeActeur(0),
    vie(100),
    force(10),
    vitesse(10),
    endurance(10),
    direction(BAS),
    inventaire()
{
    
}

Acteur::Acteur(Matrix* _A, int _x, int _y, int _type) : 
    Entitee(_A, _x, _y, ACTEUR),
    typeActeur(_type), 
    vie(100), 
    force(10), 
    vitesse(10), 
    endurance(10), 
    direction(BAS),
    inventaire()
{

}

Acteur::Acteur(const Acteur& _a) :
    Entitee((Matrix*)_a.A, (int)_a.x, (int)_a.y, (int)_a.type), 
    typeActeur(_a.typeActeur), 
    vie(_a.vie), 
    force(_a.force), 
    vitesse(_a.vitesse), 
    endurance(_a.endurance), 
    direction(_a.direction),
    inventaire(_a.inventaire)
{
    
}

/***************/
/* DESTRUCTEUR */
/***************/

Acteur::~Acteur()
{
    
}

/***************/
/* OPERATEURS  */
/***************/

Acteur& Acteur::operator=(const Acteur& _a)
{
    this->A = _a.A;
    this->x = _a.x;
    this->y = _a.y;
    return *this;
}

ostream& operator<<(ostream& _os, const Acteur& _a)
{
    _os << "Acteur : " << _a.x << " " << _a.y << endl;
    return _os;
}

/************/
/* METHODES */
/************/

void Acteur::attaquer(Acteur& _a, vector<Marchandise>& _m)
{
    _a.vie -= this->force;

    if (_a.vie <= 0)
    {
        _a.vie = 0;
        _a.A->out(_a.x, _a.y, ACTEUR + _a.type);
    }

    // Déséquipe l'acteur d'une marchandise aléatoire sur une case aléatoire autour de lui
    srand(time(NULL));
    _m.push_back(_a.inventaire[rand() % _a.inventaire.size()]);
    _a.dropOff(_m[_m.size() - 1]);
    int x, y;
    while (true)
    {
        x = rand() % 3 - 1;
        y = rand() % 3 - 1;
        if (x != 0 || y != 0)
            break;
    }
    _m[_m.size() - 1].setX(_a.x + x);
    _m[_m.size() - 1].setY(_a.y + y);
    _m[_m.size() - 1].getMatrice().in(_m[_m.size() - 1].getX(), _m[_m.size() - 1].getY(), MARCHANDISE);
}

void Acteur::deplacement(int _x, int _y)
{
    A->out(this->x, this->y, ACTEUR + this->type);

    // On vérifie que le déplacement ne sort pas de la map
    this->x += _x;
    if (this->x < 0)
        this->x += LARGEUR_MAX;
    else if (this->x > LARGEUR_MAX)
        this->x -= LARGEUR_MAX;

    this->y += _y;
    if (this->y < 0)
        this->y += LARGEUR_MAX;
    else if (this->y > LARGEUR_MAX)
        this->y -= LARGEUR_MAX;

    // On vérifie la direction
    if (_x == 0 && _y == -1)
        this->direction = HAUT;
    else if (_x == 0 && _y == 1)
        this->direction = BAS;
    else if (_x == -1 && _y == 0)
        this->direction = GAUCHE;
    else if (_x == 1 && _y == 0)
        this->direction = DROITE;

    A->in(this->x, this->y, ACTEUR + this->type);
}

void Acteur::deplacementR()
{
    srand(time(NULL));
    A->out(this->x, this->y, ACTEUR + this->type);
    this->x = rand() % LARGEUR_MAX;
    this->y = rand() % LARGEUR_MAX;
    A->in(this->x, this->y, ACTEUR + this->type);
}

void Acteur::pickUp(Marchandise& m)
{
    this->inventaire.push_back(m);
}

void Acteur::pickUpAll(vector<Marchandise>& m)
{
    for (unsigned int i = 0; i < m.size(); i++)
    {
        this->inventaire.push_back(m[i]);
    }
}

void Acteur::dropOff(Marchandise& _m)
{
    for (unsigned int i = 0; i < this->inventaire.size(); i++)
    {
        if (this->inventaire[i] == _m)
        {
            this->inventaire.erase(this->inventaire.begin() + i);
            break;
        }
    }
}

void Acteur::dropOffAll()
{
    this->inventaire.clear();
}

void Acteur::rechargerEndurance()
{
    if (endurance < ENDURANCE_MAX)
    {
        endurance += 1;
    }
}

void Acteur::rechargerEndurance(double _e)
{
    if (endurance < ENDURANCE_MAX)
    {
        endurance += _e;
    }
}

void Acteur::diminuerEndurance()
{
    if (endurance > 0)
    {
        endurance -= 1;
    }
}

void Acteur::diminuerEndurance(double _e)
{
    if (endurance > 0)
    {
        endurance -= _e;
    }
}