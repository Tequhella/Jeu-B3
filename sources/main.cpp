/**
 * @file main.cpp
 * @author Lilian CHARDON,
 * @brief Fichier du main, qui lance l'interface et le jeu
 * @version 0.1
 * @date 25-10-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include "../headers/matrix.h"
#include "../headers/entitees/acteurs/protagoniste.h"
#include "../headers/entitees/acteurs/mules.h"
#include "../headers/entitees/marchandise.h"
#include "../headers/entitees/strands.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Matrix A(LARGEUR_MAX, LARGEUR_MAX);
    
    Entitee e(&A, 1, 0, MARCHANDISE);

    cout << e << endl;

    cout << A << endl;
    
    return 0;
}