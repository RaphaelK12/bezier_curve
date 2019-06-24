/**
 * @file    Types.hpp
 *
 * @brief   Types
 *
 * @author  btran
 *
 * @date    2019-06-19
 *
 * Bezier
 *
 * Copyright (c) organization
 *
 */

#ifndef TYPES_HPP_
#define TYPES_HPP_

#include <cmath>
#include <cstdlib>
#include <stdexcept>
#include <vector>

namespace robotics
{
namespace maths
{
constexpr double FUZZY_EPSILON = 1e-4;

/**
 *  @brief function to calculate binomial coefficients
 *
 *  This is a O(k) algorithm. return type of double is used to avoid overflow
 *
 *  @param n for kCn
 *  @param k for kCn
 *  @return double
 */
inline double binomialCoeff(size_t n, size_t k)
{
    if (n < k) {
        throw std::out_of_range("n must not be less than k");
    }

    double res = 1.0;

    if (k > n - k)
        k = n - k;

    for (size_t i = 0; i < k; ++i) {
        res = (n - i) * res / (i + 1);
    }

    return res;
}

std::vector<double> binomialCoeffs(size_t n);

std::vector<double> polynomialCoeffs(size_t n, double t);

template <typename T> bool fuzzyEquals(T val, T correctVal)
{
    return std::abs(val - correctVal) <= static_cast<T>(FUZZY_EPSILON);
}

template <typename T> bool isWithinZeroAndOne(T x)
{
    return x >= -static_cast<T>(FUZZY_EPSILON) && x <= static_cast<T>(1.0 + FUZZY_EPSILON);
}
}  // namespace maths
}  // namespace robotics

#endif /* TYPES_HPP_ */
