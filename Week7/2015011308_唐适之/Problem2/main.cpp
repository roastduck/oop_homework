// main.cpp
#include "Matrix.h"
// ...

int main()
{
    Matrix a("a.txt"), b;
    b.load("b.txt");
    a.display(); // print matrix a
    b.display(); // print matrix b
    Matrix c = a.multiply(b); // compute the product
    c.display_product(); // print the product
    c.save_product("aXb.txt"); // get a matrix of 6 rows and 6 columns
    return 0;
}

