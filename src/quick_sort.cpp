#include "sorts.h"
#include "util.h"

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

namespace algorithm
{
    namespace sort
    {
        int partition(int*& v, int leftIndex, int rightIndex)
        {
            if (leftIndex == rightIndex)
            {
                return leftIndex;
            }

            int pivotIndex = (leftIndex + rightIndex) / 2;
            int pivotValue = v[pivotIndex];

            util::swap(v[rightIndex], v[pivotIndex]);

            int swapIndex = leftIndex;

            for (int i = leftIndex; i < rightIndex; ++i)
            {
                if (v[i] <= pivotValue)
                {
                    util::swap(v[swapIndex++], v[i]);
                }
            }

            util::swap(v[rightIndex], v[swapIndex]);
            return swapIndex;
        }

        void quickSort(int*& v, int leftIndex, int rightIndex)
        {
            if (leftIndex >= rightIndex)
            {
                return;
            }

            int pivotIndex = partition(v, leftIndex, rightIndex);

            quickSort(v, leftIndex, pivotIndex - 1);
            quickSort(v, pivotIndex + 1, rightIndex);
        }
    }
}

//int main() {
//
//    int n;
//    scanf("%d", &n);
//
//    int* v = new int[n];
//
//    for(int i = 0; i < n; ++i) {
//        scanf("%d", &v[i]);
//    }
//
//    quickSort(v, 0, n - 1);
//
//    for(int i = 0; i < n; ++i) {
//        printf("%d ", v[i]);
//    }
//    printf("\n");
//
//    delete[] v;
//
//return 0;
//}
