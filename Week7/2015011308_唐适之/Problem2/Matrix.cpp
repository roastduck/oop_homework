#include <fstream>
#include <iostream>
#include <exception>
#include <stdexcept>
#include "Matrix.h"

void Matrix::load(const std::string &filename)
{
    std::ifstream fs(filename.c_str());
    if (! fs)
        throw std::runtime_error("fail to load from " + filename);
    fs >> row >> col;
    data.resize(row * col);
    for (int i=0; i<row*col; i++)
        fs >> data[i];
}

void Matrix::save_product(const std::string &filename) const
{
    std::ofstream fs(filename.c_str());
    fs << row << ' ' << col << std::endl;
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
        {
            fs << at(i, j);
            if (j == col-1)
                fs << std::endl;
            else 
                fs << ' ';
        }
}

void Matrix::display() const
{
    std::cout << "Matrix of " << row << " rows and " << col << " columns:" << std::endl;
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
        {
            std::cout << at(i, j);
            if (j == col-1)
                std::cout << std::endl;
            else 
                std::cout << ' ';
        }
    std::cout << std::endl;
}

Matrix Matrix::multiply(const Matrix &other) const
{
    if (col != other.row)
        throw std::runtime_error("cannot multiply");
    Matrix ret(row, other.col);
    for (int i=0; i<row; i++)
        for (int j=0; j<other.col; j++)
            for (int k=0; k<col; k++)
                ret.at(i, j) += at(i, k) * other.at(k, j);
    return ret;
}

