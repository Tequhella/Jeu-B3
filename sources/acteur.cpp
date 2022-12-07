#include "../headers/acteur.h"
#include <cstdlib>


Acteur::Acteur()
{
    srand(time(NULL));
    this->x = rand() % LARGEUR_MAX;
    this->y = rand() % HAUTEUR_MAX;
}

Acteur::Acteur(Matrix& A) : A(&A)
{
    srand(time(NULL));
    this->x = rand() % LARGEUR_MAX;
    this->y = rand() % HAUTEUR_MAX;
    this->A->in(this->x, this->y);
}

Acteur::Acteur(Matrix& A ,int x, int y): A(&A), x(x), y(y)
{
    if (x > LARGEUR_MAX || y > HAUTEUR_MAX)
    {
        std::cout << "Erreur : les coordonnées sont trop grandes" << std::endl;
        exit(1);
    }
    this->A->in(this->x, this->y);
}

Acteur::~Acteur()
{
    A->out(this->x, this->y);
}

void Acteur::move(int x, int y)
{
    A->out(this->x, this->y);
    this->x += x;
    if (this->x < 0)
    {
        this->x += LARGEUR_MAX;
    }
    else if (this->x > LARGEUR_MAX)
    {
        this->x -= LARGEUR_MAX;
    }

    this->y += y;
    if (this->y < 0)
    {
        this->y += HAUTEUR_MAX;
    }
    else if (this->y > HAUTEUR_MAX)
    {
        this->y -= HAUTEUR_MAX;
    }
    A->in(this->x, this->y);
}

void Acteur::moveR()
{
    srand(time(NULL));
    A->out(this->x, this->y);
    this->x = rand() % HAUTEUR_MAX;
    this->y = rand() % HAUTEUR_MAX;
    A->in(this->x, this->y);
}
