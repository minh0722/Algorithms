#ifndef ALGORITHM_UTIL_HPP
#define ALGORITHM_UTIL_HPP

#include <type_traits>
#include <cstddef>

namespace util
{
    template <typename T>
    void swap(T& l, T& r)
    {
        static_assert(std::is_integral<T>::value, "Only integral value is allowed fow swap");
        T temp = r;
        r = l;
        l = temp;
    }

    template <typename T>
    bool isSorted(const std::vector<T>& v)
    {
        for (size_t i = 0; i < v.size() - 1; ++i)
        {
            if (v[i] > v[i + 1])
            {
                return false;
            }
        }
        return true;
    }
}

#endif // ALGORITHM_UTIL_HPP