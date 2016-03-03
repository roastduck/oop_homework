#include <vector>
#include <iterator>

double polynomial_fast(const std::vector<double> &a, double x)
{
	double ret(0);
	for (std::vector<double>::const_reverse_iterator i=a.rbegin(); i!=a.rend(); i++)
		ret = ret * x + *i;
	return ret;
}

double polynomial_slow(const std::vector<double> &a, double x)
{
	double ret(0);
	for (int i=0; i!=a.size(); i++)
	{
		double px(1);
		for (int j=1; j<=i; j++)
			px *= x;
		ret += a[i]*px;
	}
	return ret;
}

