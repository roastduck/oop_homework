#include <iostream>
#include <omp.h>

omp_lock_t lock;

void plus(int a, int b)
{
    int ret(0);
    for (int i=a; i<=b; i++)
        ret += i;
    omp_set_lock(&lock);
    std::cout << ret << std::endl;
    omp_unset_lock(&lock);
}

int main()
{
    omp_init_lock(&lock);
#pragma omp parallel
    {
#pragma omp sections
        {
#pragma omp section
            plus(1, 100);
#pragma omp section
            plus(100, 200);
        }
    }
    return 0;
}

