#include "sorts.h"
#include "util.h"



namespace algorithm
{
    namespace sort
    {
        void selectionSort(std::vector<int>& v)
        {
            for (size_t i = 0; i < v.size(); ++i)
            {
                for (size_t j = i + 1; j < v.size(); ++j)
                {
                    if (v[i] > v[j])
                    {
                        util::swap(v[i], v[j]);
                    }
                }
            }
        }
    }
}