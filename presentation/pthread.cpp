#include <iostream>
#include <pthread.h>

struct Param
{
    int a, b;
    Param(int _a, int _b)
        : a(_a), b(_b) {}
};

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *plus(void *param)
{
    int a = ((Param*)param)->a;
    int b = ((Param*)param)->b;
    int ret(0);
    for (int i=a; i<=b; i++)
        ret += i;
    pthread_mutex_lock(&lock);
    std::cout << ret << std::endl;
    pthread_mutex_unlock(&lock);
    return 0;
}

int main()
{
    pthread_t thread1, thread2;
    Param *p1 = new Param(1,100);
    Param *p2 = new Param(100,200);
    pthread_create(&thread1, NULL, plus, p1);
    pthread_create(&thread2, NULL, plus, p2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    delete p1;
    delete p2;
    return 0;
}

