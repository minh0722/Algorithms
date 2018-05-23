#ifndef ALGORITHM_INSERTION_SORT
#define ALGORITHM_INSERTION_SORT

#include <vector>

/*
*  Stable sort
*  It is stable since we don't insert the element before another element that is equal to it
*
*  In insertion sort we try to sort from left to right,
*  which means when we try to insert element at index n to the right place,
*  all elements from 0 to n-1 are sorted.
*
*
* Complexity:
* Worst case: n^2
* Best case: n
* Average: n^2
*/

namespace algorithm
{
    namespace sort
    {
        void insertionSort(std::vector<int>& v);
    }
}

#endif // ALGORITHM_INSERTION_SORT