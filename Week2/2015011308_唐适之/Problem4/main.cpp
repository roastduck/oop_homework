#include "hen.h"
#include "egg.h"

int main()
{
    /*
     * original code:
    Hen hen;
    hen.display();
    hen.nest.display();
    hen.nest.egg.display();
     */
    
    // zyn says it requires to be as below:
    Hen hen;
    Hen::Nest nest;
    Egg egg;
    hen.display();
    nest.display();
    egg.display();
    return 0;
}

