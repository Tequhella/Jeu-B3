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
using namespace std;

int main(int argc, char const *argv[])
{

    Matrix A(10,10);
    Acteur Un(A, 1, 9);
    Acteur Deux(A, 1, 9);
    Acteur Trois(A, 1, 9);
    Acteur Quatre(A, 1, 9);
    Acteur Cinq(A, 1, 9);
    Acteur Six(A, 1, 9);
    Acteur Sept(A, 1, 9);
    Acteur Huit(A, 1, 9);
    Acteur neuf(A, 1, 9);
    Acteur Dix(A, 1, 9);
    
    cout << A << endl;

    Un.moveR();
    Deux.moveR();
    Trois.move(1, 4);

    cout << A << endl;
    
    Trois.move(-3, 0);

    
    cout << A << endl;
    
    return 0;
}