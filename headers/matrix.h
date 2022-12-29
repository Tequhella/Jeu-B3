/*
 * matrix.h
 */

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>

class Entitee;

class Matrix
{
    friend class Entitee;
    friend class Acteur;

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
     * @param rows le nombre de lignes
     * @param cols le nombre de colonnes
     */
    Matrix(int, int);

    /**
     * @brief Constructeur de la classe Matrix
     *
     * @param p le tableau de pointeurs des éléments de décors
     * @param rows le nombre de lignes
     * @param cols le nombre de colonnes
     */
    Matrix(int **, int, int);

    /**
     * @brief Constructeur de la classe Matrix
     *
     * @param p le tableau de pointeurs des éléments de décors
     * @param e le tableau de pointeurs des éléments des entités
     * @param rows le nombre de lignes
     * @param cols le nombre de colonnes
     */
    Matrix(int **, int **, int, int);

    /**
     * @brief Constructeur par copie de la classe Matrix
     *
     * @param m la matrice à copier
     */
    Matrix(const Matrix &);

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
     * @brief Surcharge de l'opérateur d'affectation
     *
     * @param m la matrice à copier
     * @return Matrix& la matrice copiée
     */
    Matrix &operator=(const Matrix &);

    /**
     * @brief Surcharge de l'opérateur de comparaison
     * 
     * @param m la matrice à comparer
     * @return true si les matrices sont égales
     */
    bool operator==(const Matrix &) const;

    /**
     * @brief Surcharge de l'opérateur d'accès
     *
     * @param x la ligne
     * @param y la colonne
     * @return int& l'élément à la ligne x et à la colonne y
     */
    inline int &operator()(int x, int y) { return p[x][y]; }

    /**
     * @brief Surcharge de l'opérateur d'incrémentation
     *
     * @param m la matrice à incrémenter
     * @return Matrix& la matrice incrémentée
     */
    Matrix &operator+=(const Matrix &);

    /**
     * @brief Surcharge de l'opérateur de décrémentation
     *
     * @param m la matrice à décrémenter
     * @return Matrix& la matrice décrémentée
     */
    Matrix &operator-=(const Matrix &);

    /**
     * @brief Surcharge de l'opérateur de multiplication
     *
     * @param m la matrice à multiplier
     * @return Matrix& la matrice multipliée
     */
    Matrix &operator*=(const Matrix &);

    /**
     * @brief Surcharge de l'opérateur de multiplication par un scalaire
     *
     * @param n le scalaire
     * @return Matrix& la matrice multipliée par le scalaire
     */
    Matrix &operator*=(int);

    /**
     * @brief Surcharge de l'opérateur de division par un scalaire
     *
     * @param n le scalaire
     * @return Matrix& la matrice divisée par le scalaire
     */
    Matrix &operator/=(int);

    /**
     * @brief Surcharge de l'opérateur xor
     *
     * @param n le scalaire
     * @return Matrix la matrice exposée au scalaire
     */
    Matrix operator^(int);

    /**
     * @brief Surcharge de l'opérateur d'affichage
     *
     * @param os le flux de sortie
     * @param m la matrice à afficher
     * @return std::ostream& le flux de sortie
     */
    friend std::ostream &operator<<(std::ostream &, const Matrix &);

    /**
     * @brief Surcharge de l'opérateur d'entrée
     *
     * @param is le flux d'entrée
     * @param m la matrice à remplir
     * @return std::istream& le flux d'entrée
     */
    friend std::istream &operator>>(std::istream &, Matrix &);

    /************/
    /* METHODES */
    /************/

    /**
     * @brief Intervertit deux colonnes
     *
     * @param r1 la première colonne
     * @param r2 la deuxième colonne
     */
    void swapRows(int, int);

    /**
     * @brief transpose la matrice
     *
     * @return Matrix la matrice transposée
     */
    Matrix transpose();

    /**********************/
    /* METHODES STATIQUES */
    /**********************/

    /**
     * @brief crée une matrice identité
     *
     * @param n la taille de la matrice
     * @return Matrix la matrice identité
     */
    static Matrix createIdentity(int);

    /**
     * @brief résout un système linéaire
     *
     * @param A la matrice des coefficients
     * @param b le vecteur des constantes
     * @return Matrix le vecteur solution
     */
    static Matrix solve(Matrix, Matrix);

    /**
     * @brief résout un système linéaire avec pivot partiel
     *
     * @param A la matrice des coefficients
     * @param b le vecteur des constantes
     * @param k le nombre de pivots partiel
     * @return Matrix le vecteur solution
     */
    static Matrix bandSolve(Matrix, Matrix, int);

    /**
     * @brief dot product
     * *
     * @param A la matrice des coefficients
     * @param b le vecteur des constantes
     * @return int le produit scalaire
     */
    static int dotProduct(Matrix, Matrix);

    /**
     * @brief augmente une matrice avec une autre
     *
     * @param A la matrice à augmenter
     * @param B la matrice à ajouter
     * @return Matrix la matrice augmentée
     */
    static Matrix augment(Matrix, Matrix);

    /**
     * @brief gaussian elimination
     * 
     * @return Matrix la matrice réduite
     */
    Matrix gaussianEliminate();

    /**
     * @brief row reduce from gaussian
     * 
     * @return Matrix la matrice réduite
     */
    Matrix rowReduceFromGaussian();

    /**
     * @brief read solutions from rref
     * 
     * @param os le flux de sortie
     */
    void readSolutionsFromRREF(std::ostream &os);

    /**
     * @brief inverse
     * 
     * @return Matrix la matrice inverse
     */
    Matrix inverse();

private:
    int rows_, cols_; // nombre de lignes et de colonnes
    int **p;          // pointeur sur la matrice des décors
    int **e;          // pointeur sur la matrice des entités

    /**
     * @brief alloue de la mémoire pour la matrice
     */
    void allocSpace();

    /**
     * @brief expHelper
     * 
     * @param m la matrice à multiplier
     * @param n le nombre de fois à multiplier
     * @return Matrix la matrice exposée
     */
    Matrix expHelper(const Matrix &, int);

    /**
     * @brief permet d'ajouter une entité à la matrice
     * 
     * @param x la position x de l'entité
     * @param y la position y de l'entité
     * @param type le type de l'entité
     */
    void in(int x, int y, int type) { this->e[y][x] = type; }

    /**
     * @brief permet de retirer une entité à la matrice
     * 
     * @param x la position x de l'entité
     * @param y la position y de l'entité
     */
    void out(int x, int y) { this->e[y][x] = 0; }
};

/**
 * @brief Surcharge de l'opérateur d'addition
 *
 * @param m1 la première matrice
 * @param m2 la deuxième matrice
 * @return Matrix la matrice résultat
 */
Matrix operator+(const Matrix &, const Matrix &);

/**
 * @brief Surcharge de l'opérateur de soustraction
 *
 * @param m1 la première matrice
 * @param m2 la deuxième matrice
 * @return Matrix la matrice résultat
 */
Matrix operator-(const Matrix &, const Matrix &);

/**
 * @brief Surcharge de l'opérateur de multiplication
 *
 * @param m1 la première matrice
 * @param m2 la deuxième matrice
 * @return Matrix la matrice résultat
 */
Matrix operator*(const Matrix &, const Matrix &);

/**
 * @brief Surcharge de l'opérateur de multiplication par un scalaire
 *
 * @param m la matrice
 * @param n le scalaire
 * @return Matrix la matrice résultat
 */
Matrix operator*(const Matrix &, int);

/**
 * @brief Surcharge de l'opérateur de multiplication par un scalaire
 *
 * @param n le scalaire
 * @param m la matrice
 * @return Matrix la matrice résultat
 */
Matrix operator*(int, const Matrix &);

/**
 * @brief Surcharge de l'opérateur de division par un scalaire
 *
 * @param m la matrice
 * @param n le scalaire
 * @return Matrix la matrice résultat
 */
Matrix operator/(const Matrix &, int);

#endif