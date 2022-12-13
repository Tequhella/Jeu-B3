/*
 * matrix.h
 */

#ifndef __MATRIX_H__
#define __MATRIX_H__


#include <iostream>

class Acteur;

class Matrix
{
    friend class Acteur;
    public:
        Matrix(int, int);
        Matrix(int**, int, int);
        Matrix(int**, int**, int, int);
        Matrix();
        ~Matrix();
        Matrix(const Matrix&);
        Matrix& operator=(const Matrix&);

        inline int& operator()(int x, int y) { return p[x][y]; }

        Matrix& operator+=(const Matrix&);
        Matrix& operator-=(const Matrix&);
        Matrix& operator*=(const Matrix&);
        Matrix& operator*=(int);
        Matrix& operator/=(int);
        Matrix  operator^(int);
        
        friend std::ostream& operator<<(std::ostream&, const Matrix&);
        friend std::istream& operator>>(std::istream&, Matrix&);

        void swapRows(int, int);
        Matrix transpose();

        static Matrix createIdentity(int);
        static Matrix solve(Matrix, Matrix);
        static Matrix bandSolve(Matrix, Matrix, int);

        // functions on vectors
        static int dotProduct(Matrix, Matrix);

        // functions on augmented matrices
        static Matrix augment(Matrix, Matrix);
        Matrix gaussianEliminate();
        Matrix rowReduceFromGaussian();
        void readSolutionsFromRREF(std::ostream& os);
        Matrix inverse();

    private:
        int rows_, cols_;
        int **p;
        int **e;

        void allocSpace();
        Matrix expHelper(const Matrix&, int);

        void in(int x, int y) {this->p[y][x]++;}
        void out(int x, int y) {this->p[y][x]--;}
};

Matrix operator+(const Matrix&, const Matrix&);
Matrix operator-(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, double);
Matrix operator*(double, const Matrix&);
Matrix operator/(const Matrix&, double);

#endif