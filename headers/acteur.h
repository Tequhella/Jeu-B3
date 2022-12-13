/**
 * @file acteur.h
 * @author Lilian CHARDON,
 * @brief 
 * @version 0.1
 * @date 25-10-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __ACTEUR_H__
#define __ACTEUR_H__

#define LARGEUR_MAX 80

#include <iostream>
#include <string>
#include "matrix.h"

class Acteur
{
    public:
        static int id;

        Acteur();
        Acteur(Matrix& A);
        Acteur(Matrix& A, int x, int y);
        ~Acteur();

        void move(int x, int y);
        void moveR();

        // getters
        int getX() const { return x; }
        int getY() const { return y; }

        // setters
        void setX(int x) { this->x = x; }
        void setY(int y) { this->y = y; }
        
    private:
        Matrix A;
        int x, y;
};

#endif // __ACTEUR_H__