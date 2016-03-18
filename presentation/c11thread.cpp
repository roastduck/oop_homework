#include <thread>
#include <mutex>
#include <iostream>

std::mutex lock;

void plus(int a, int b)
{
    int ret(0);
    for (int i=a; i<=b; i++)
        ret += i;
    lock.lock();
    std::cout << ret << std::endl;
    lock.unlock();
}

int main()
{
    std::thread thread1(plus, 1, 100),
                thread2(plus, 100, 200);
    thread1.join();
    thread2.join();
    return 0;
}

