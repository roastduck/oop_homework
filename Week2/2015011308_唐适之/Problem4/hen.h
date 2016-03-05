#ifndef INCLUDED_HEN_H
#define INCLUDED_HEN_H

#include "egg.h"

class Hen
{
public:
    class Nest
    {
    public:
        Egg egg;

        void display();
    } nest;
    
    void display();
};

#endif // INCLUDED_HEN_H
