/**
 * @file main.cpp
 * @author Lilian CHARDON,
 * @brief 
 * @version 0.1
 * @date 25-10-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include "../headers/matrix.h"
#include "../headers/acteur.h"
#include "../headers/interface.h"

using namespace std;

int main(int argc, char const *argv[])
{

    Matrix matrix(80, 60);

    vector<Acteur*> acteurs;

    acteurs.push_back(new Acteur(matrix, 10, 10));
    acteurs.push_back(new Acteur(matrix, 20, 20));
    acteurs.push_back(new Acteur(matrix, 30, 30));

    RenderWindow window(VideoMode(LARGEUR, HAUTEUR), "SFML works!");

    Interface interface(&window, acteurs, matrix);

    interface.display();

    for (unsigned int i = 0; i < acteurs.size(); i++)
        delete acteurs[i];
    
    return 0;
}