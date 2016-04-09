#ifndef INCLUDED_MATRIX_H
#define INCLUDED_MATRIX_H

#include <vector>
#include <string>

class Matrix
{
    int row, col;
    std::vector<int> data;

    /// Construct a matrix with row*col zeros
    Matrix(int _row, int _col) : row(_row), col(_col), data(row*col, 0) {}
    
    /// Access an element
    int &at(int x, int y) { return data.at(x*col+y); }
    int at(int x, int y) const { return data.at(x*col+y); }
    
public:
    /// Construct a empty matrix
    Matrix() : row(0), col(0) {}
    
    /// Construct a matrix and load data from a file
    Matrix(const std::string &filename) { this->load(filename); }
    
    /// Load data from a file
    void load(const std::string &filename);
    
    /// Save data to a file
    void save_product(const std::string &filename) const;
    
    /// Display info
    void display() const;
    
    /// Alias of display
    void display_product() const { display(); }
    
    /// Calculate product
    Matrix multiply(const Matrix &other) const;
};

#endif // INCLUDED_MATRIX_H

