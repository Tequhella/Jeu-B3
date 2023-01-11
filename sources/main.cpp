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

    Matrix matrix(80, 60);

    RenderWindow window(VideoMode(LARGEUR, HAUTEUR), "Jeu de la vie !");

    Interface interface(&window, matrix);

    interface.display();
    
    return 0;
}