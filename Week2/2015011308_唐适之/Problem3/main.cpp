#include <thread>
#include <chrono>
#include <iostream>
#include "video.h"

int main()
{
    std::cout << "Create two video" << std::endl;
    Video V1("Video1"), V2("Video2", "Foobar");
    V1.print(), V2.print();

    std::cout << "================" << std::endl;
    std::cout << "Rent out them" << std::endl;
    V1.rent_out(), V2.rent_out(0);
    V1.print(), V2.print();

    std::cout << "================" << std::endl;
    std::cout << "Cannot rent them again" << std::endl;
    V1.rent_out(), V2.rent_out();

    std::cout << "================" << std::endl;
    std::cout << "Make some delay" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "================" << std::endl;
    std::cout << "Check for expiring" << std::endl;
    V1.print(), V2.print();

    std::cout << "================" << std::endl;
    std::cout << "Return back them" << std::endl;
    V1.return_back(), V2.return_back();
    V1.print(), V2.print();

    std::cout << "================" << std::endl;
    std::cout << "Cannot return them again" << std::endl;
    V1.return_back(), V2.return_back();
}

