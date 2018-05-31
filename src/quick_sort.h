#ifndef ALGORITHM_QUICK_SORT
#define ALGORITHM_QUICK_SORT

/*
* Not stable
* It is not stable because in partition, if there is another element that is to the right of pivot and equal to it,
* then that element will be positioned to the left of pivot, thus they are reverted.
*
* Complexity:
* Worst case: n^2 (already sorted array)
* Best case: nlogn
* Average: nlogn
*
*/

#include "common.h"

namespace algorithm
{
    namespace sort
    {
        ALGO_API void quickSort(int*& v, int leftIndex, int rightIndex);
    }
}

#endif // ALGORITHM_QUICK_SORT