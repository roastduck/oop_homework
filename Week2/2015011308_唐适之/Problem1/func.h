#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include <vector>

double polynomial_fast(const std::vector<double> &a, double x);
double polynomial_slow(const std::vector<double> &a, double x);

double posynomial_fast(const std::vector<double> &a, double x); // throws std::exception
double posynomial_slow(const std::vector<double> &a, double x); // throws std::exception

#endif // FUNC_H_INCLUDED
