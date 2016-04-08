#ifndef INCLUDED_MEMBER_H
#define INCLUDED_MEMBER_H

#include <string>

class Member
{
    const std::string name;
    const int age;

public:
    Member(const std::string &_name = "???", int _age = 0);
    void printInfo() const;
};

#endif // INCLUDED_MEMBER_H
