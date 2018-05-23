#ifndef ALGORITHM_SELECTION_SORT
#define ALGORITHM_SELECTION_SORT

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

#include <vector>

namespace algorithm
{
    namespace sort
    {
        void selectionSort(std::vector<int>& v);
    }
}

#endif // ALGORITHM_SELECTION_SORT