#ifndef ALGORITHM_UTIL
#define ALGORITHM_UTIL

#include <vector>

namespace Util
{
    template <typename T>
    void swap(T& l, T& r);

    template <typename T>
    bool isSorted(const std::vector<T>& v);
}

#include "util.hpp"

#endif // ALGORITHM_UTIL