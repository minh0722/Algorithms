#include "quick_sort.h"
#include "util.h"

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
