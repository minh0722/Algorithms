#ifndef ALGORITHM_UTIL_H
#define ALGORITHM_UTIL_H

#include <vector>

namespace util
{
    template <typename T>
    void swap(T& l, T& r);

    template <typename T>
    bool isSorted(const std::vector<T>& v);

    int getBit(int number, int bitIdx);
}

#include "util.hpp"

#endif // ALGORITHM_UTIL_H