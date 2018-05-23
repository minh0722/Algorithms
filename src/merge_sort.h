#ifndef ALGORITHM_MERGE_SORT
#define ALGORITHM_MERGE_SORT

/*
* Stable sort
* It is stable because function merge compares two elements from two chunks and
* if two elements are equal it takes from the left chunk. So the order is preserved
*
* Complexity:
* Worst case: nlogn
* Best case: nlogn
* Average: nlogn
*/

namespace algorithm
{
    namespace sort
    {
        void mergeSort(int* listed, int begin, int end);
    }
}

#endif // ALGORITHM_MERGE_SORT