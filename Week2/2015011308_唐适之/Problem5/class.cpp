#include <iostream>
#include "class.h"

void Class::showMap()
{
    std::cout << "a @ " << &a << std::endl;
    std::cout << "b @ " << &b << std::endl;
    std::cout << "c @ " << &c << std::endl;
    std::cout << "d @ " << &d << std::endl;

    std::cout << "m @ " << &m << std::endl;
    std::cout << "n @ " << &n << std::endl;
    std::cout << "o @ " << &o << std::endl;
    std::cout << "p @ " << &p << std::endl;

    std::cout << "w @ " << &w << std::endl;
    std::cout << "x @ " << &x << std::endl;
    std::cout << "y @ " << &y << std::endl;
    std::cout << "z @ " << &z << std::endl;
}
