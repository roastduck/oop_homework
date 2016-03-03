#include <vector>
#include <iterator>

double polynomial(const std::vector<double> &a, double x)
{
	double ret(0);
	for (std::vector<double>::const_reverse_iterator i=a.rbegin(); i!=a.rend(); i++)
		ret = ret * x + *i;
	return ret;
}

