#include "../headers/acteur.h"

Acteur::Acteur()
{
    srand(time(NULL));
    this->x = rand() % LARGEUR_MAX;
    this->y = rand() % LARGEUR_MAX;
}

Acteur::Acteur(Matrix& A) : A(A)
{
    srand(time(NULL));
    this->x = rand() % LARGEUR_MAX;
    this->y = rand() % LARGEUR_MAX;
    this->A.in(this->x, this->y);
}

Acteur::Acteur(Matrix& A ,int x, int y): A(A), x(x), y(y)
{
    if (x > LARGEUR_MAX || y > LARGEUR_MAX)
    {
        std::cout << "Erreur : les coordonnées sont trop grandes" << std::endl;
        exit(1);
    }
    this->A.in(this->x, this->y);
}

Acteur::~Acteur()
{
    
}

void Acteur::move(int x, int y)
{
    A.out(this->x, this->y);
    this->x += x;
    if (this->x < 0)
        this->x += LARGEUR_MAX;
    else if (this->x > LARGEUR_MAX)
        this->x -= LARGEUR_MAX;

    this->y += y;
    if (this->y < 0)
        this->y += LARGEUR_MAX;
    else if (this->y > LARGEUR_MAX)
        this->y -= LARGEUR_MAX;
        
    A.in(this->x, this->y);
}

void Acteur::moveR()
{
    srand(time(NULL));
    A.out(this->x, this->y);
    this->x = rand() % LARGEUR_MAX;
    this->y = rand() % LARGEUR_MAX;
    A.in(this->x, this->y);
}
