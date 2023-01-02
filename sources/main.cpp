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
#include "../headers/input.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Matrix A(LARGEUR_MAX, LARGEUR_MAX);
    
    Marchandise m(&A, 1, 1);
    Strands s(&A, 2, 2);
    Protagoniste p(&A, 3, 3);
    Mules mules(&A, 4, 4);

    m.placement();
    s.placement();
    p.placement();
    mules.placement();

    cout << m << endl;
    cout << p << endl;
    cout << s << endl;
    cout << mules << endl;

    cout << A << endl;
    
    return 0;
}