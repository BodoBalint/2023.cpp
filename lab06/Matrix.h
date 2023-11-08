#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <stdexcept>
using namespace std;
class Matrix {
public:

    //Konstruktorok és destruktor:

// Default constructor
    Matrix( int mRows = 10, int mCols = 10);
// Copy constructor
    Matrix(const Matrix& what);
// Move constructor
    Matrix( Matrix&& what );
// Destructor
    ~Matrix();

    //Feltöltő és kiírató metódusok:

//fills the matrix with identical elements
    void fillMatrix(double value);
//fills the matrix with random real numbers in the range [a, b)
    void randomMatrix(int a, int b); //fills
//prints the matrix
    void printMatrix(ostream& os = cout) const;

    //Lekérdező metódusok:

    //checks whether this matrix is a square one
    bool isSquare() const;
    int getRows() const { return this->mRows;}
    int getCols() const { return this->mCols;}

    //Operátorfüggvények (operátorok túlterhelése):


    //● Összeadás és szorzás:

    // operation is permitted on matrices having the same dimensions
// otherwise throws an out_of_range exception!!
    friend Matrix operator+(const Matrix& x, const Matrix& y);
// operation is permitted on matrices having proper dimensions
// otherwise throws an out_of_range exception!!
    friend Matrix operator*(const Matrix& x, const Matrix& y);

    //●Olvasás és írás:

    // extractor operator
    friend istream & operator>>(istream& is, Matrix& mat);
// inserter operator
    friend ostream & operator<<(ostream& os, const Matrix& mat);

    //● Indexelés:

    // index operator
    double* operator[] (int index);
// index operator that works on constant matrices!
    double* operator[] (int index) const;


    //● Értékadás operátorok:

    // Copy assignment
// operation is permitted between matrices having the same dimensions
// otherwise throws an exception (out_of_range)
    Matrix & operator=(const Matrix& mat);
// Move assignment
    Matrix & operator=(Matrix&& mat);


//Methods
private:
//Data
    double ** mElements;
    int mRows; //number of rows
    int mCols; //number of columns
};
#endif /* MATRIX_H */
