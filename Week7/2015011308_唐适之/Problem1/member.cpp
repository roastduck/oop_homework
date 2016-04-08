#include <iostream>
#include "member.h"

Member::Member(const std::string &_name, int _age)
    : name(_name), age(_age) {}

void Member::printInfo() const
{
    std::cout << "name : " << name << ", age : " << age << std::endl;
}

