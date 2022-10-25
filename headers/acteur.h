/**
 * @file acteur.h
 * @author Lilian CHARDON (lilian.chardon@ynov.com)
 * @brief 
 * @version 0.1
 * @date 25-10-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __ACTEUR_H__
#define __ACTEUR_H__

#include <iostream>
#include <string>

class Acteur
{
    public:
        Acteur();
        Acteur(int x, int y);
        ~Acteur();

        void move(int x, int y);
        void moveR(int x, int y);

    private:
        std::string nom;
        std::string prenom;
        int age;
};

#endif // __ACTEUR_H__