#ifndef RANDOM_UTILS_HPP
#define RANDOM_UTILS_HPP

#include <random>
#include <vector>
#include <algorithm>

int randint(int a, int b) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(a, b);
    return dis(gen);
}

template<typename T>
T choice(const std::vector<T>& arr) {
    return arr[randint(0, arr.size()-1)];
}

template<typename T>
void shuffle_vector(std::vector<T>& arr) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::shuffle(arr.begin(), arr.end(), gen);
}

#endif
