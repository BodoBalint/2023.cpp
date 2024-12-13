//
// Created by Macilaci on 11/8/2023.
//
#include <random>
#include "Matrix.h"

// Ez a default constructor
Matrix::Matrix(int mRows, int mCols) {
    this->mRows = mRows;
    this->mCols = mCols;
    this->mElements = new double *[mRows];
    for (int i = 0; i < mRows; i++) {
        this->mElements[i] = new double[mCols];
        for (int j = 0; j < mCols; j++) {
            this->mElements[i][j] = 0;
        }
    }
}

// Copy  constructor
Matrix::Matrix(const Matrix &what) {
    mRows = what.mRows;
    mCols = what.mCols;
    mElements = new double *[mRows];
    for (int i = 0; i < mRows; i++) {
        mElements[i] = new double[mCols];
        for (int j = 0; j < mCols; j++) {
            mElements[i][j] = what.mElements[i][j];
        }
    }
}

// Move constructor
Matrix::Matrix(Matrix &&what) {
    mRows = what.mRows;
    mCols = what.mCols;
    mElements = what.mElements;
    what.mRows = 0;
    what.mCols = 0;
    what.mElements = nullptr;
}

// Destructor
Matrix::~Matrix() {
    for (int i = 0; i < mRows; i++) {
        delete[] mElements[i];
    }
    delete[] mElements;
}

//fills the matrix with identical elements
void Matrix::fillMatrix(double value) {
    for (int i = 0; i < mRows; i++) {
        for (int j = 0; j < mCols; j++) {
            mElements[i][j] = value;
        }
    }
}

//fills the matrix with random real numbers in the range [a, b)
void Matrix::randomMatrix(int a, int b) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(a, b);
    for (int i = 0; i < mRows; i++) {
        for (int j = 0; j < mCols; j++) {
            this->mElements[i][j] = rand() % (b - a) + a;
        }
    }
}

//prints the matrix
void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < mRows; i++) {
        for (int j = 0; j < mCols; j++) {
            os << this->mElements[i][j] << " ";
        }
        os << endl;
    }
}

//checks whether this matrix is a square one
bool Matrix::isSquare() const {
    return mRows == mCols;
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if (x.mRows != y.mRows || x.mCols != y.mCols) {
        throw out_of_range("Matrices must have the same dimensions");
    }
    Matrix result(x.mRows, x.mCols);
    for (int i = 0; i < x.mRows; i++) {
        for (int j = 0; j < x.mCols; j++) {
                result.mElements[i][j] += x.mElements[i][j] + y.mElements[i][j];
        }
    }
    return result;
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if (x.mCols != y.mRows) {
        throw out_of_range("Matrices must have compatible dimensions");
    }
    Matrix result(x.mRows, y.mCols);
    for (int i = 0; i < x.mRows; i++) {
        for (int j = 0; j < y.mCols; j++) {
            for (int k = 0; k < x.mCols; k++) {
                result.mElements[i][j] += x.mElements[i][k] * y.mElements[k][j];
            }
        }
    }
    return result;
}

istream &operator>>(istream &is, Matrix &mat) {
    is >> mat.mRows >> mat.mCols;
    mat.mElements = new double *[mat.mRows];
    for (int i = 0; i < mat.mRows; i++) {
        mat.mElements[i] = new double[mat.mCols];
        for (int j = 0; j < mat.mCols; j++) {
            is >> mat.mElements[i][j];
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const Matrix &mat) {
    mat.printMatrix(os);
    return os;
}

double *Matrix::operator[](int index) {
    if (index < 0 || index >= mRows) {
        throw std::out_of_range("Index out of range");
    }
    return mElements[index];
}

double *Matrix::operator[](int index) const {
    if (index < 0 || index >= mRows) {
        throw std::out_of_range("Index out of range");
    }
    return mElements[index];
}

Matrix &Matrix::operator=(const Matrix &mat) {
    if (this == &mat) {
        return *this;
    }
    for (int i = 0; i < mRows; i++) {
        delete[] mElements[i];
    }
    delete[] mElements;
    mRows = mat.mRows;
    mCols = mat.mCols;
    mElements = new double *[mRows];
    for (int i = 0; i < mRows; i++) {
        mElements[i] = new double[mCols];
        for (int j = 0; j < mCols; j++) {
            mElements[i][j] = mat.mElements[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&mat) {
    if (this == &mat) {
        return *this;
    }
    for (int i = 0; i < mRows; i++) {
        delete[] mElements[i];
    }
    delete[] mElements;
    mRows = mat.mRows;
    mCols = mat.mCols;
    mElements = mat.mElements;
    mat.mRows = 0;
    mat.mCols = 0;
    mat.mElements = nullptr;
    return *this;
}
