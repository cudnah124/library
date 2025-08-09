#ifndef COLLECTIONS_UTILS_HPP
#define COLLECTIONS_UTILS_HPP

#include <map>
#include <unordered_map>
#include <deque>
#include <vector>
#include <algorithm>

template<typename T>
class Counter {
public:
    std::unordered_map<T, int> data;
    Counter() {}
    Counter(const std::vector<T>& arr) {
        for (auto &x : arr) data[x]++;
    }
    int operator[](const T& key) const {
        auto it = data.find(key);
        return (it == data.end()) ? 0 : it->second;
    }
};

template<typename Key, typename Value>
class DefaultDict {
public:
    std::unordered_map<Key, Value> data;
    Value default_value;
    DefaultDict(Value default_val) : default_value(default_val) {}
    Value& operator[](const Key& key) {
        if (data.find(key) == data.end()) data[key] = default_value;
        return data[key];
    }
};

#endif
