#ifndef MATH_H
#define MATH_H

// std includes
#include <cmath>
#include <ctime>
#include <random>
#include <algorithm>

static std::mt19937 RANDOMGEN(time(NULL));

static double random_dis(const double e1, const double e2)
{
    std::uniform_real_distribution<double> distribution(e1, e2);
    return distribution(RANDOMGEN);
}

#endif // MATH_H
