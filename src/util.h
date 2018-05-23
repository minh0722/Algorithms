#ifndef ALGORITHM_UTIL
#define ALGORITHM_UTIL

#include <vector>

namespace util
{
    template <typename T>
    void swap(T& l, T& r);

    template <typename T>
    bool isSorted(const std::vector<T>& v);

    int getBit(int number, int bitIdx)
    {
        return (number >> bitIdx) & 1;
    }
}

#include "util.hpp"

#endif // ALGORITHM_UTIL