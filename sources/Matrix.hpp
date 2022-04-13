#include <iostream>
#include <vector>

using namespace std;

namespace zich
{

    class Matrix
    {
    private:
        std::vector<double> _matrix;
        int _rows;
        int _cols;

    public:
        Matrix(int rows, int cols)
        {
            if (rows < 1 || cols < 1)
            {
                throw "Matrix dimensions must be greater than 0";
            }
            else
            {
                this->_rows = rows;
                this->_cols = cols;
                this->_matrix.resize((uint)rows * (uint)cols);
            }
        }

        Matrix(std::vector<double> matrix, int rows, int cols)
        {
            if (matrix.size() != (uint)rows * (uint)cols)
            {
                throw "Matrix size does not match";
            }
            else if (rows < 1 || cols < 1)
            {
                throw "Matrix dimensions must be greater than 0";
            }
            else
            {
                this->_rows = rows;
                this->_cols = cols;
                this->_matrix = matrix;
            }
        }

        ~Matrix() {}

        friend bool operator==(const Matrix &lhs, const Matrix &rhs); // Checking equality
        friend bool operator!=(const Matrix &lhs, const Matrix &rhs); // Checking inequality
        friend bool operator>(const Matrix &lhs, const Matrix &rhs);  // Checking if matrix is bigger than another matrix
        friend bool operator<(const Matrix &lhs, const Matrix &rhs);  // Checking if matrix is smaller than another matrix
        friend bool operator>=(const Matrix &lhs, const Matrix &rhs); // Checking if matrix is bigger or equal to another matrix
        friend bool operator<=(const Matrix &lhs, const Matrix &rhs); // Checking if matrix is smaller or equal to another matrix

        friend Matrix operator+(const Matrix &lhs, const Matrix &rhs); // Adding two matrices to new matrix
        friend Matrix operator-(const Matrix &lhs, const Matrix &rhs); // Subtracting two matrices to new matrix
        friend Matrix operator*(const Matrix &lhs, const Matrix &rhs); // Multiplying two matrices to new matrix
        friend Matrix operator*(const Matrix &lhs, double rhs);        // Multiplying matrix by scalar to new matrix
        friend Matrix operator*(double lhs, const Matrix &rhs);        // Multiplying matrix by scalar to new matrix
        friend Matrix operator-(const Matrix &lhs);                    // Unari
        Matrix operator-(const Matrix &lhs);                           // REGULAR

        friend void operator+=(Matrix &lhs, const Matrix &rhs); // Adding two matrices to the first matrix
        friend void operator-=(Matrix &lhs, const Matrix &rhs); // Subtracting two matrices to the first matrix
        friend Matrix operator+(const Matrix &lhs);
        friend void operator*=(Matrix &lhs, const Matrix &rhs); // Multiplying two matrices to the first matrix
        friend void operator*=(Matrix &lhs, double rhs);        // Multiplying matrix by scalar to the matrix
        Matrix &operator++();                                   // Incrementing matrix by
        Matrix operator++(int);
        Matrix &operator--();
        Matrix operator--(int); // Decrementing matrix by 1

        friend ostream &operator<<(ostream &os, const Matrix &rhs); // Printing matrix
        friend istream &operator>>(istream &is, Matrix &rhs);       // Reading matrix
    };

}