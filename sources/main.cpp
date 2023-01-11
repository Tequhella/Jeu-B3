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
    for (int i = 0; i < 60; i++)
        for (int j = 0; j < 80; j++)
            p[i][j] = 0;
    */  
    Matrix matrix(60, 80);
    /*
    matrix.in(38, 40);
    matrix.in(39, 40);
    matrix.in(39, 39);
    matrix.in(40, 40);
    matrix.in(41, 40);
    matrix.in(42, 40);
    */
    RenderWindow window(VideoMode(LARGEUR, HAUTEUR), "Jeu de la vie !");

    Interface interface(&window, matrix);

    interface.display();
    
    return 0;
}