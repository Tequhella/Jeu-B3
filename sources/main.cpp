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
#include "../headers/interface.h"

using namespace std;

int main(int argc, char const *argv[])
{
    /*
    int** p = new int*[60];
    for (int i = 0; i < 60; i++)
    {
        p[i] = new int[80];
    }
    Matrix matrix(p, 60, 80);
    */
    Matrix matrix(HAUTEUR / 10, LARGEUR / 10);

    

    RenderWindow window(VideoMode(LARGEUR, HAUTEUR + 50), "Jeu de la vie !");

    Interface interface(&window, matrix);

    interface.display();
    
    return 0;
}