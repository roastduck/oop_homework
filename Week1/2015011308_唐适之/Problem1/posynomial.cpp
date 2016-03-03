#include <vector>
#include <iterator>
#include <iostream>
#include <exception>

double posynomial(const std::vector<double> &a, double x) // throws std::exception
{
	if (!x)
	{
		std::cerr << "posynomial : x must be non-zero" << std::endl;
		throw(std::exception());
	}

	double ret(0);
	for (std::vector<double>::const_reverse_iterator i=a.rbegin(); i!=a.rend(); i++)
		ret = ret / x + *i;
	return ret;
}

