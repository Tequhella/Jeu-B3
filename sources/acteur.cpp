#include "../headers/acteur.h"
#include <cstdlib>

/****************/
/* CONSTRUCTEUR */
/****************/

Acteur::Acteur()
{
    srand(time(NULL));
    this->x = rand() % LARGEUR_MAX;
    this->y = rand() % HAUTEUR_MAX;
    this->A = Matrix(LARGEUR_MAX, HAUTEUR_MAX);
    this->A.in(this->x, this->y);
}

Acteur::Acteur(Matrix& A) : A(A)
{
    srand(time(NULL));
    this->x = rand() % LARGEUR_MAX;
    this->y = rand() % HAUTEUR_MAX;
    this->A.in(this->x, this->y);
}

Acteur::Acteur(Matrix& A ,int x, int y): A(A), x(x), y(y)
{
    if (x > LARGEUR_MAX || y > HAUTEUR_MAX)
    {
        std::cout << "Erreur : les coordonnées sont trop grandes" << std::endl;
        exit(1);
    }
    this->A.in(this->x, this->y);
}

/***************/
/* DESTRUCTEUR */
/***************/

Acteur::~Acteur()
{
    A.out(this->x, this->y);
}

/************/
/* METHODES */
/************/

void Acteur::move(int x, int y)
{
    A.out(this->x, this->y);
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
    A.in(this->x, this->y);
}

void Acteur::moveR()
{
    srand(time(NULL));
    A.out(this->x, this->y);
    this->x = rand() % HAUTEUR_MAX;
    this->y = rand() % HAUTEUR_MAX;
    A.in(this->x, this->y);
}

void Acteur::rules()
{
    std::cout << "Entrée dans la méthode rules" << std::endl;
    // règle 1 : si un acteur est entouré de 2 ou 3 acteurs, il survit
    // règle 2 : si un acteur est entouré de moins de 2 acteurs, il meurt
    // règle 3 : si un acteur est entouré de plus de 3 acteurs, il meurt
    // règle 4 : si un acteur est entouré de 3 acteurs, il naît
    int nbActeurs = 0;
    for (int i = -1; i < 2; i++)
        for (int j = -1; j < 2; j++)
            if (A((this->x + i) % LARGEUR_MAX, (this->y + j) % HAUTEUR_MAX) == 1)
                nbActeurs++;

    if (nbActeurs < 2 || nbActeurs > 3)
        A.out(this->x, this->y);
}