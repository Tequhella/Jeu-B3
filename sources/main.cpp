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
#include "../headers/interface.h"
using namespace std;

int main(int argc, char const *argv[])
{

    Interface* interface = new Interface();

    interface->display();

    delete interface;
    
    return 0;
}