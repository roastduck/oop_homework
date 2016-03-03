#include <cstdlib>
#include <vector>
#include <iostream>
#include <exception>
#include "func.h"

int main(int argc, char **argv)
{
	std::vector<double> a;
	for (int i=1; i<argc-1; i++)
		a.push_back(atof(argv[i]));
	double x(atof(argv[argc-1]));

	std::cout << polynomial(a, x) << std::endl;
	try
	{
		std::cout << posynomial(a, x) << std::endl;
	} catch (std::exception)
	{
		return 1;
	}
	return 0;
}

