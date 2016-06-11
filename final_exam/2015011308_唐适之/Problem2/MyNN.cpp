#include "MyNN.h"
using namespace std;

std::ostream &operator<<(std::ostream &os, const std::vector<int> &item);

//NOTE: need to add the overloaded stream operator << for MyNN
std::ostream &operator<<(std::ostream &os, const MyNN &item)
{
    os << "Queried = " << item.qPoint_ << std::endl;
    os << "Nearest = " << item.nnPoint_ << std::endl;
    os << "Visited Count = " << item.visitedPoints_.size() << std::endl;
    os << std::endl;
    return os;
}

