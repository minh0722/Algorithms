#include "sorts.h"
#include "util.h"

/*
* Not stable sort
* It is not stable since the smallest element is swapped to the front and it can change the order
* Example:
* 4 2 4 1
* The first 4 will be swapped with 1 and the order of the 4's are reverted
*
*
* It can be made to stable if we find the smallest element, remove it and push it to the front.
* Then linked list should be used since insert is faster
*/

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