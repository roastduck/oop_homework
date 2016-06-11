#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <fstream>
#include "MyNN.h"

using namespace std;

void GeneratePoints(vector<vector<int> > &points)
{
    //NOTE: generate 3D integer points as follows: 
    //generate the integer points (x, y, z) (x, y, z ∈ [0, 5, 10, 15, …, 95, 100])
}

int main(int argc, char* argv[])
{
    ofstream file("result.txt");
    vector<vector<int> > points;
	GeneratePoints(points);
    vector<int> point;
    //NOTE: search the point (6,7,8)
    //you may search more other points if you like

    MyNN myNN(points);
    myNN.search(point);
    cout << myNN << endl;
    file << myNN << endl;
    file.close();

	return 0;
}
