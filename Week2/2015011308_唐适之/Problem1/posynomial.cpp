#include <vector>
#include <iterator>
#include <iostream>
#include <exception>

double posynomial_fast(const std::vector<double> &a, double x) // throws std::exception
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

double posynomial_slow(const std::vector<double> &a, double x) // throws std::exception
{
	if (!x)
	{
		std::cerr << "posynomial : x must be non-zero" << std::endl;
		throw(std::exception());
	}

	double ret(0);
	for (int i=0; i!=a.size(); i++)
	{
		double px(1);
		for (int j=1; j<=i; j++)
			px /= x;
		ret += a[i]*px;
	}
	return ret;
}

