#ifndef ITERTOOLS_UTILS_HPP
#define ITERTOOLS_UTILS_HPP

#include <vector>
#include <numeric>
#include <functional>

template<typename T>
std::vector<std::vector<T>> permutations(std::vector<T> arr) {
    std::vector<std::vector<T>> result;
    std::sort(arr.begin(), arr.end());
    do {
        result.push_back(arr);
    } while (std::next_permutation(arr.begin(), arr.end()));
    return result;
}

template<typename T>
std::vector<std::vector<T>> combinations(std::vector<T> arr, int k) {
    std::vector<std::vector<T>> result;
    std::vector<bool> v(arr.size());
    std::fill(v.begin(), v.begin() + k, true);
    do {
        std::vector<T> subset;
        for (size_t i = 0; i < arr.size(); i++) {
            if (v[i]) subset.push_back(arr[i]);
        }
        result.push_back(subset);
    } while (std::prev_permutation(v.begin(), v.end()));
    return result;
}

template<typename T>
std::vector<T> accumulate(const std::vector<T>& arr) {
    std::vector<T> result(arr.size());
    std::partial_sum(arr.begin(), arr.end(), result.begin());
    return result;
}

#endif
