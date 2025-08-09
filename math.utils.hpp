#ifndef MATH_UTILS_HPP
#define MATH_UTILS_HPP

#include <cmath>
#include <numeric>
#include <vector>

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

template<typename T>
T mean(const std::vector<T>& arr) {
    return std::accumulate(arr.begin(), arr.end(), (T)0) / (T)arr.size();
}

template<typename T>
T gcd_all(const std::vector<T>& arr) {
    T g = arr[0];
    for (auto &x : arr) g = std::gcd(g, x);
    return g;
}

#endif
