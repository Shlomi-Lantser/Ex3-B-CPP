#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Matrix.hpp"
#include <string>

using namespace std;

namespace zich
{

    bool operator==(const Matrix &lhs, const Matrix &rhs)
    {
        if (lhs._rows != rhs._rows || lhs._cols != rhs._cols)
        {
            throw "Matrices are not at the same size";
        }
        for (uint i = 0; i < lhs._matrix.size(); i++)
        {
            if (lhs._matrix[i] != rhs._matrix[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Matrix &lhs, const Matrix &rhs)
    {
        bool ans = false;
        if (lhs == rhs)
        {
            return ans;
        }
        return true;
    }

    bool operator>(const Matrix &lhs, const Matrix &rhs)
    {
        bool ans = true;
        if (lhs._rows != rhs._rows || lhs._cols != rhs._cols)
        {
            throw "Matrices are not the same size";
        }
        double sumLHS = 0;
        double sumRHS = 0;
        for (uint i = 0; i < lhs._matrix.size(); i++)
        {
            sumLHS += lhs._matrix[i];
            sumRHS += rhs._matrix[i];
        }

        if (sumLHS > sumRHS)
        {
            return ans;
        }
        return false;
    }

    bool operator<(const Matrix &lhs, const Matrix &rhs)
    {
        if (lhs == rhs)
        {
            return false;
        }
        if (lhs > rhs)
        {
            return false;
        }
        return true;
    }

    bool operator>=(const Matrix &lhs, const Matrix &rhs)
    {
        return (lhs > rhs || lhs == rhs);
    }

    bool operator<=(const Matrix &lhs, const Matrix &rhs)
    {
        return (lhs < rhs || lhs == rhs);
    }

    Matrix operator+(const Matrix &lhs, const Matrix &rhs)
    {
        if (lhs._cols != rhs._cols || lhs._rows != rhs._rows)
        {
            throw "Matrices are not the same size";
        }
        Matrix result(lhs._rows, lhs._cols);
        for (uint i = 0; i < lhs._matrix.size(); i++)
        {
            result._matrix[i] = lhs._matrix[i] + rhs._matrix[i];
        }
        return result;
    }

    Matrix operator+(const Matrix &lhs)
    {
        return 1 * (lhs);
    }
    Matrix operator-(const Matrix &lhs)
    {
        return -1 * (lhs);
    }

    Matrix operator-(const Matrix &lhs, const Matrix &rhs)
    {
        if (lhs._cols != rhs._cols || lhs._rows != rhs._rows)
        {
            throw "Matrices are not the same size";
        }
        Matrix result(lhs._rows, lhs._cols);
        for (uint i = 0; i < lhs._matrix.size(); i++)
        {
            result._matrix[i] = lhs._matrix[i] - rhs._matrix[i];
        }
        return result;
    }

    Matrix Matrix::operator-(const Matrix &lhs)
    {
        if (this->_cols != lhs._cols || this->_rows != lhs._rows)
        {
            throw "Matrices are not the same size";
        }
        Matrix result(lhs._rows, lhs._cols);
        for (uint i = 0; i < lhs._matrix.size(); i++)
        {
            result._matrix[i] = this->_matrix[i] - lhs._matrix[i];
        }
        return result;
    }

    Matrix operator*(const Matrix &lhs, const Matrix &rhs)
    { // Need to complete
        if (lhs._cols != rhs._rows)
        {
            throw "Illegal multiplication";
        }
        Matrix result(lhs._rows, rhs._cols);
        for (uint i = 0; i < lhs._rows; i++)
        {
            for (uint j = 0; j < rhs._cols; j++)
            {
                for (uint k = 0; k < lhs._cols; k++)
                {
                    result._matrix[i * (uint)rhs._cols + j] += lhs._matrix[i * (uint)lhs._cols + k] * rhs._matrix[k * (uint)rhs._cols + j];
                }
            }
        }
        return result;
    }

    Matrix operator*(const Matrix &lhs, double rhs)
    {
        Matrix result(lhs._rows, lhs._cols);
        for (uint i = 0; i < lhs._matrix.size(); i++)
        {
            result._matrix[i] = lhs._matrix[i] * rhs;
        }
        return result;
    }

    Matrix operator*(double lhs, const Matrix &rhs)
    {
        Matrix result(rhs._rows, rhs._cols);
        for (uint i = 0; i < rhs._matrix.size(); i++)
        {
            result._matrix[i] = lhs * rhs._matrix[i];
        }
        return result;
    }

    void operator+=(Matrix &lhs, const Matrix &rhs)
    {
        if (lhs._cols == rhs._cols && lhs._rows == rhs._rows)
        {
            for (uint i = 0; i < lhs._matrix.size(); i++)
            {
                lhs._matrix[i] += rhs._matrix[i];
            }
        }
        else
        {
            throw "Matrices are not the same size";
        }
    }

    void operator-=(Matrix &lhs, const Matrix &rhs)
    {
        if (lhs._cols != rhs._cols || lhs._rows != rhs._rows)
        {
            throw "Matrices are not the same size";
        }
        for (uint i = 0; i < lhs._matrix.size(); i++)
        {
            lhs._matrix[i] -= rhs._matrix[i];
        }
    }

    void operator*=(Matrix &lhs, const Matrix &rhs)
    {
        if (lhs._cols != rhs._rows)
        {
            throw "Illegal multiplication";
        }
        for (uint i = 0; i < lhs._matrix.size(); i++)
        {
            lhs._matrix[i] *= rhs._matrix[i];
        }
    }

    void operator*=(Matrix &lhs, double rhs)
    {
        for (uint i = 0; i < lhs._matrix.size(); i++)
        {
            lhs._matrix[i] *= rhs;
        }
    }

    Matrix &Matrix::operator++()
    {
        for (uint i = 0; i < _matrix.size(); i++)
        {
            _matrix[i] += 1;
        }
        return *this;
    }

    Matrix Matrix::operator++(int)
    {
        Matrix result(*this);
        for (uint i = 0; i < _matrix.size(); i++)
        {
            _matrix[i] += 1;
        }
        return result;
    }

    Matrix &Matrix::operator--()
    {
        for (uint i = 0; i < _matrix.size(); i++)
        {
            this->_matrix[i] -= 1;
        }
        return *this;
    }

    Matrix Matrix::operator--(int)
    {
        Matrix result(*this);
        for (uint i = 0; i < _matrix.size(); i++)
        {
            this->_matrix[i]--;
        }
        return result;
    }

    std::ostream &operator<<(ostream &os, const Matrix &rhs)
    {
        for (uint i = 0; i < rhs._rows; i++)
        {
            os << "[";
            for (uint j = 0; j < rhs._cols; j++)
            {
                os << rhs._matrix[i * (uint)rhs._cols + j];
                if (j != rhs._cols - 1)
                {
                    os << " ";
                }
            }
            if (i != rhs._rows - 1)
            {
                os << "]" << endl;
            }
            else
            {
                os << "]";
            }
        }
        return os;
    }

    istream &operator>>(istream &is, Matrix &rhs)
    {
        string check;
        vector<double> temp;
        int finalCols = 0;
        bool flag = false;
        bool inInterval = false;
        getline(is, check);
        if (check[0] != '[')
        {
            throw "Invalid input";
        }

        int rows = 0;
        int cols = 1;
        for (uint i = 0; i < check.size(); i++)
        {
            if (check[i] == '[')
            {
                inInterval = true;
            }
            if (check[i] == ']')
            {
                inInterval = false;
                if (i != check.size() - 1 && check[i + 1] != ',')
                {
                    throw "Invalid input";
                }
                if (!flag)
                {
                    finalCols = cols;
                    flag = true;
                }
                cols = 1;
                rows++;
            }
            else if (check[i] == ',')
            {
                if (check[i + 1] != ' ')
                {
                    throw "Invalid input";
                }
            }
            else if (check[i] == ' ' && inInterval)
            {
                cols++;
            }
        }
        uint j = 0;

        for (uint i = 0; i < check.size(); i++)
        {
            string tempNum;
            j = i + 1;
            if (isdigit(check[i]) != 0)
            {
                tempNum += check[i];
                while (isdigit(check[j]) != 0)
                {
                    tempNum += check[j];
                    j++;
                    i++;
                }
                temp.push_back(stod(tempNum));
            }
            else if (check[i] == '-')
            {
                while (isdigit(check[j]) != 0)
                {
                    tempNum += check[j];
                    j++;
                    i++;
                }
                double tempNumd = stod(tempNum);
                tempNumd *= -1;
                temp.push_back(tempNumd);
                i++;
            }
        }
        Matrix result = Matrix(temp, rows, finalCols);
        rhs = result;
        return is;
    }
}