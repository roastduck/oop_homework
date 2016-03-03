#ifndef INCLUDED_MEASURE_H
#define INCLUDED_MEASURE_H

#include <ctime>
#include <vector>

class Measure
{
	typedef double (*func_t) (const std::vector<double> &, double);

	clock_t accu;
	func_t func;
	std::vector<double> param1;
	double param2;
	double ret;

public:
	Measure(func_t _func, const std::vector<double> &_param1, double _param2)
		: accu(0), func(_func), param1(_param1), param2(_param2) {}

	void run()
	{
		clock_t begin = clock();
		ret = func(param1, param2);
		clock_t end = clock();
		accu += end-begin;
	}

	double get_time()
	{
		return (double)accu / CLOCKS_PER_SEC;
	}

	double get_return()
	{
		return ret;
	}
};

#endif // INCLUDED_MEASURE_H
