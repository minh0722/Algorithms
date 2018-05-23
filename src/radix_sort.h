#ifndef ALGORTHM_RADIX_SORT
#define ALGORITHM_RADIX_SORT

/*
* Implementation of Least significant bit radix sort
*
* Stable sort
*
* Complexity:
* O(INT_BITS_COUNT * 2n) (Amortized nlogn)
*
* For clearer visual representation of this algorithm:
* https://www.cs.usfca.edu/~galles/visualization/RadixSort.html
*/

namespace algorithm
{
    namespace sort
    {
        void radixSort(int*& v, int size);
    }
}

#endif // ALGORITHM_RADIX_SORT