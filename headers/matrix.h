/*
 * matrix.h
 */

#ifndef __MATRIX_H__
#define __MATRIX_H__


#include <iostream>

class Matrix
{
    public:
    /*****************/
    /* CONSTRUCTEURS */
    /*****************/

        /**
         * @brief Constructeur par défaut de la classe Matrix
         */
        Matrix();

        /**
         * @brief Constructeur de la classe Matrix
         * 
         * @param rows nombre de lignes de la matrice
         * @param cols nombre de colonnes de la matrice
         */
        Matrix(int, int);

        /**
         * @brief Constructeur de la classe Matrix
         * 
         * @param p pointeur vers un tableau de double
         * @param rows nombre de lignes de la matrice
         * @param cols nombre de colonnes de la matrice
         */
        Matrix(double**, int, int);

        /**
         * @brief Constructeur par recopie
         * 
         * @param m matrice à recopier
         */
        Matrix(const Matrix&);
    
    /***************/
    /* DESTRUCTEUR */
    /***************/

        /**
         * @brief Destructeur de la classe Matrix
         */
        ~Matrix();
    
    /**************/
    /* OPERATEURS */
    /**************/

        /**
         * @brief Opérateur d'affectation
         * 
         * @param m matrice à affecter
         * @return Matrix& référence sur la matrice affectée
         */
        Matrix& operator=(const Matrix&);

        /**
         * @brief Opérateur d'accès à un élément de la matrice
         * 
         * @param x abscisse de l'élément
         * @param y ordonnée de l'élément
         * @return double& référence sur l'élément
         */
        inline double& operator()(int x, int y) { return p[x][y]; }

        /**
         * @brief Opérateur d'addition d'une matrice à une autre
         * 
         * @param m matrice à ajouter
         * @return Matrix& référence sur la matrice résultat
         */
        Matrix& operator+=(const Matrix&);

        /**
         * @brief Opérateur de soustraction d'une matrice à une autre
         * 
         * @param m matrice à soustraire
         * @return Matrix& référence sur la matrice résultat
         */
        Matrix& operator-=(const Matrix&);

        /**
         * @brief Opérateur de multiplication d'une matrice à une autre
         * 
         * @param m matrice à multiplier
         * @return Matrix& référence sur la matrice résultat
         */
        Matrix& operator*=(const Matrix&);

        /**
         * @brief Opérateur de multiplication d'une matrice par un scalaire
         * 
         * @param d scalaire à multiplier
         * @return Matrix& référence sur la matrice résultat
         */
        Matrix& operator*=(double);

        /**
         * @brief Opérateur de division d'une matrice par un scalaire
         * 
         * @param d scalaire à diviser
         * @return Matrix& référence sur la matrice résultat
         */
        Matrix& operator/=(double);

        /**
         * @brief Opérateur de puissance d'une matrice
         * 
         * @param n exposant
         * @return Matrix& référence sur la matrice résultat
         */
        Matrix  operator^(int);
        
        /**
         * @brief Opérateur de comparaison d'égalité entre deux matrices
         * 
         * @param m matrice à comparer
         * @return true si les matrices sont égales
         * @return false si les matrices ne sont pas égales
         */
        bool operator==(const Matrix&);

        /**
         * @brief Opérateur de comparaison d'inégalité entre deux matrices
         * 
         * @param m matrice à comparer
         * @return true si les matrices ne sont pas égales
         * @return false si les matrices sont égales
         */
        bool operator!=(const Matrix&);

        /**
         * @brief Opérateur de comparaison d'ordre inférieur entre deux matrices
         * 
         * @param m matrice à comparer
         * @return true si la matrice est inférieure à la matrice passée en paramètre
         * @return false si la matrice n'est pas inférieure à la matrice passée en paramètre
         */
        bool operator<(const Matrix&);

        /**
         * @brief Opérateur de comparaison d'ordre supérieur entre deux matrices
         * 
         * @param m matrice à comparer
         * @return true si la matrice est supérieure à la matrice passée en paramètre
         * @return false si la matrice n'est pas supérieure à la matrice passée en paramètre
         */
        bool operator>(const Matrix&);

        /**
         * @brief Opérateur de comparaison d'ordre inférieur ou égal entre deux matrices
         * 
         * @param m matrice à comparer
         * @return true si la matrice est inférieure ou égale à la matrice passée en paramètre
         * @return false si la matrice n'est pas inférieure ou égale à la matrice passée en paramètre
         */
        bool operator<=(const Matrix&);

        /**
         * @brief Opérateur de comparaison d'ordre supérieur ou égal entre deux matrices
         * 
         * @param m matrice à comparer
         * @return true si la matrice est supérieure ou égale à la matrice passée en paramètre
         * @return false si la matrice n'est pas supérieure ou égale à la matrice passée en paramètre
         */
        bool operator>=(const Matrix&);

        /**
         * @brief Opérateur de flux de sortie
         * 
         * @param os flux de sortie
         * @param m matrice à afficher
         * @return std::ostream& flux de sortie
         */
        friend std::ostream& operator<<(std::ostream&, const Matrix&);

        /**
         * @brief Opérateur de flux d'entrée
         * 
         * @param is flux d'entrée
         * @param m matrice à remplir
         * @return std::istream& flux d'entrée
         */
        friend std::istream& operator>>(std::istream&, Matrix&);

    /************/
    /* METHODES */
    /************/

        /**
         * @brief Intervertit deux colonnes de la matrice
         * 
         * @param r1 numéro de la première colonne
         * @param r2 numéro de la deuxième colonne
         */
        void swapRows(int, int);
        
        /**
         * @brief Transpose la matrice
         * 
         * @return Matrix matrice transposée
         */
        Matrix transpose();

        /**
         * @brief Crée une matrice identité de taille size
         * 
         * @param size taille de la matrice
         * @return Matrix matrice identité
         */
        static Matrix createIdentity(int);

        /**
         * @brief Solveur de système linéaire avec pivot de Gauss
         * 
         * @param A matrice des coefficients
         * @param b vecteur des constantes
         * @return Matrix vecteur solution
         */
        static Matrix solve(Matrix, Matrix);

        /**
         * @brief Solveur de système linéaire avec pivot de Gauss
         * 
         * @param A matrice des coefficients
         * @param b vecteur des constantes
         * @param k nombre de diagonales sous et au dessus de la diagonale principale
         * @return Matrix vecteur solution
         */    
        static Matrix bandSolve(Matrix, Matrix, int);

        /**
         * @brief Produit scalaire de deux matrices
         * 
         * @param A matrice 1
         * @param B matrice 2
         * @return double produit scalaire
         */
        static double dotProduct(Matrix, Matrix);

        /**
         * @brief Augmente une matrice avec une autre
         * 
         * @param A matrice 1
         * @param B matrice 2
         * @return Matrix matrice résultat
         */
        static Matrix augment(Matrix, Matrix);

        /**
         * @brief Elimination de Gauss
         * 
         * @return Matrix matrice résultat
         */
        Matrix gaussianEliminate();

        /**
         * @brief Rédution de Gauss-Jordan
         * 
         * @return Matrix matrice résultat
         */
        Matrix rowReduceFromGaussian();

        /**
         * @brief Lecture des solutions d'un système linéaire à partir d'une matrice réduite
         * 
         * @param os flux de sortie
         */
        void readSolutionsFromRREF(std::ostream& os);

        /**
         * @brief Crée une matrice inverse
         * 
         * @return Matrix matrice inverse
         */
        Matrix inverse();

    /***********/
    /* GETTERS */
    /***********/

        /**
         * @brief Retourne le nombre de lignes de la matrice
         * 
         * @return int nombre de lignes
         */
        inline int getLignes() const { return rows_; }

        /**
         * @brief Retourne le nombre de colonnes de la matrice
         * 
         * @return int nombre de colonnes
         */
        inline int getColonnes() const { return cols_; }

        /**
         * @brief Retourne la matrice
         * 
         * @return double** matrice
         */
        inline double** getMatrice() const { return p; }

    private:
        int rows_, cols_;
        double **p;

        /**
         * @brief Alloue de l'espace mémoire pour la matrice
         */
        void allocSpace();

        /**
         * @brief effectue une puissance de la matrice
         * 
         * @param m matrice
         * @param n puissance
         * @return Matrix matrice résultat
         */
        Matrix expHelper(const Matrix&, int);

        /**
         * @brief effectue une entrée dans la matrice en incrémentant la valeur
         * 
         * @param x la position en x
         * @param y la position en y
         */
        void in(int x, int y) {this->p[y][x]++;}

        /**
         * @brief effectue une sortie dans la matrice en décrémentant la valeur
         * 
         * @param x la position en x
         * @param y la position en y
         */
        void out(int x, int y) {this->p[y][x]--;}
};

/**************/
/* OPERATEURS */
/**************/

/**
 * @brief Opérateur d'addition de deux matrices
 * 
 * @param m1 matrice 1
 * @param m2 matrice 2
 * @return Matrix matrice résultat
 */
Matrix operator+(const Matrix&, const Matrix&);

/**
 * @brief Opérateur de soustraction de deux matrices
 * 
 * @param m1 matrice 1
 * @param m2 matrice 2
 * @return Matrix matrice résultat
 */
Matrix operator-(const Matrix&, const Matrix&);

/**
 * @brief Opérateur de multiplication de deux matrices
 * 
 * @param m1 matrice 1
 * @param m2 matrice 2
 * @return Matrix matrice résultat
 */
Matrix operator*(const Matrix&, const Matrix&);

/**
 * @brief Opérateur de multiplication d'une matrice par un scalaire
 * 
 * @param m matrice
 * @param d scalaire
 * @return Matrix matrice résultat
 */
Matrix operator*(const Matrix&, double);

/**
 * @brief Opérateur de multiplication d'une matrice par un scalaire
 * 
 * @param d scalaire
 * @param m matrice
 * @return Matrix matrice résultat
 */
Matrix operator*(double, const Matrix&);

/**
 * @brief Opérateur de division d'une matrice par un scalaire
 * 
 * @param m matrice
 * @param d scalaire
 * @return Matrix matrice résultat
 */
Matrix operator/(const Matrix&, double);

#endif