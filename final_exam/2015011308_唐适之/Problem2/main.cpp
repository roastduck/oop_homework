#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include "MyNN.h"
#include "SimpleNN.h"

using namespace std;

std::ostream &operator<<(std::ostream &os, const std::vector<int> &item)
{
    os << '(';
    for (int i = 0; i < (int)item.size(); i++)
        os << item[i] << (i == (int)item.size() - 1 ? ')' : ',');
    return os;
}

void GeneratePoints(vector<vector<int> > &points)
{
    //NOTE: generate 3D integer points as follows: 
    //generate the integer points (x, y, z) (x, y, z ∈ [0, 5, 10, 15, …, 95, 100])
    for (int i = 0; i <= 100; i += 5)
        for (int j = 0; j <= 100; j += 5)
            for (int k = 0; k <= 100; k += 5)
                points.push_back({i, j, k});
}

int main(int argc, char* argv[])
{
    ofstream file("result.txt");
    vector<vector<int> > points;
	GeneratePoints(points);
    vector<int> point = {6, 7, 8};
    //NOTE: search the point (6,7,8)
    //you may search more other points if you like

    clock_t clockSt, clockEn;
    
    std::cout << "============ MyNN =============" << std::endl;
    MyNN myNN(points);
    clockSt = clock();
    myNN.search(point);
    clockEn = clock();
    cout << myNN << endl;
    std::cout << "Time = " << (double)(clockEn - clockSt) / CLOCKS_PER_SEC << "(s)" << std::endl;

    std::cout << "============ MyNN =============" << std::endl;
    SimpleNN simpleNN(points);
    clockSt = clock();
    auto simpleNNRet = simpleNN.search(point);
    clockEn = clock();
    cout << "Nearest = " << simpleNNRet << endl;
    std::cout << "Time = " << (double)(clockEn - clockSt) / CLOCKS_PER_SEC << "(s)" << std::endl;

    file << myNN << endl;
    file.close();

	return 0;
}
