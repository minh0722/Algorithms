#include <type_traits>

namespace Util
{
    template <typename T>
    void swap(T& l, T& r)
    {
        static_assert(std::is_integral<T>());
        l = l + r;
        r = l - r;
        l = l - r;
    }

    template <typename T>
    bool isSorted(const std::vector<T>& v)
    {
        for (int i = 0; i < v.size() - 1; ++i)
        {
            if (v[i] > v[i + 1])
            {
                return false;
            }
        }
        return true;
    }
}