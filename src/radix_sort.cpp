#include "sorts.h"
#include "util.h"
#include <vector>
#include <cstring>

#define INT_BITS_COUNT 32

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
        void radixSort(int* v, int size)
        {
            int buckets[2];
            memset(buckets, 0, 2 * sizeof(int));

            int* temp = new int[size];
            memset(temp, 0, size * sizeof(int));

            for (int bit = 0; bit < INT_BITS_COUNT; ++bit)
            {
                for (int i = 0; i < size; ++i)
                {
                    int b = util::getBit(v[i], bit);
                    ++buckets[b];
                }

                // increment buckets position
                buckets[1] += buckets[0];

                for (int i = size - 1; i >= 0; --i)
                {
                    char numBit = util::getBit(v[i], bit);

                    if (buckets[numBit] != 0)
                    {
                        temp[--buckets[numBit]] = v[i];
                    }
                }

                memcpy(v, temp, size * sizeof(int));
                memset(temp, 0, size * sizeof(int));
                memset(buckets, 0, 2 * sizeof(int));
            }

            delete[]temp;
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
//    radixSort(v, n);
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
