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
    int st[] = {1, 10000};
    int en[] = {10000, 20000};
#pragma omp parallel for
    for (int i=0; i<2; i++)
        plus(st[i], en[i]);
    return 0;
}

