#include <cstdlib>
#include <vector>
#include <iostream>
#include <exception>
#include "func.h"
#include "measure.h"

int main(int argc, char **argv)
{
	std::cout << "running. may last for minutes" << std::endl;
	std::vector<double> a;
	for (int i=1; i<argc-1; i++)
		a.push_back(atof(argv[i]));
	double x(atof(argv[argc-1]));

	Measure
		mPolyFast(polynomial_fast, a, x),
		mPolySlow(polynomial_slow, a, x),
		mPosyFast(posynomial_fast, a, x),
		mPosySlow(posynomial_slow, a, x);
	
	for (int i=1; i<=10000; i++)
		for (int j=1; j<=10000; j++)
		{
			mPolyFast.run();
			mPolySlow.run();
		}
	std::cout << "polynomial_fast:"
	          << " result = " << mPolyFast.get_return()
			  << " elapsed time = " << mPolyFast.get_time()
			  << std::endl
	          << "polynomial_slow:"
	          << " result = " << mPolySlow.get_return()
			  << " elapsed time = " << mPolySlow.get_time()
			  << std::endl
	          << "imp = "
	          << (mPolySlow.get_time()-mPolyFast.get_time())/mPolySlow.get_time()
			  << std::endl
			  << std::endl;

	try
	{
		for (int i=1; i<=10000; i++)
			for (int j=1; j<=10000; j++)
			{
				mPosyFast.run();
				mPosySlow.run();
			}
		std::cout << "posynomial_fast:"
				  << " result = " << mPosyFast.get_return()
				  << " elapsed time = " << mPosyFast.get_time()
				  << std::endl
				  << "posynomial_slow:"
				  << " result = " << mPosySlow.get_return()
				  << " elapsed time = " << mPosySlow.get_time()
				  << std::endl
				  << "imp = "
				  << (mPosySlow.get_time()-mPosyFast.get_time())/mPosySlow.get_time()
				  << std::endl
				  << std::endl;
	} catch (std::exception)
	{
		return 1;
	}
	return 0;
}

