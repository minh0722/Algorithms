#include "selection_sort.h"
#include "util.h"

namespace algorithm
{
    namespace sort
    {
        void selectionSort(std::vector<int>& v)
        {
            for (int i = 0; i < v.size(); ++i)
            {
                for (int j = i + 1; j < v.size(); ++j)
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