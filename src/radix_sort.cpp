#include "sorts.h"
#include "util.h"
#include <vector>
#include <cstring>

#define INT_BITS_COUNT 32
#define MSB_IDX 31

/*
* Implementation of Least significant bit radix sort
*
* Stable sort
*
* Complexity:
* O(INT_BITS_COUNT * 2n)
*
* For clearer visual representation of this algorithm:
* https://www.cs.usfca.edu/~galles/visualization/RadixSort.html
*/

namespace algorithm
{
    namespace sort
    {
        void separateNegativeIntegers(int* v, int size, int& negativeCount, int& positiveCount)
        {
            int buckets[2] = {};

            int* temp = new int[size];
            memset(temp, 0, size * sizeof(int));

            for (int i = 0; i < size; ++i)
            {
                int b = util::getBit(v[i], MSB_IDX);
                ++buckets[b];
            }

            positiveCount = buckets[0];
            negativeCount = buckets[1];

            // we keep negative numbers first, then positive numbers
            buckets[0] += buckets[1];

            for (int i = 0; i < size; ++i)
            {
                int bit = util::getBit(v[i], MSB_IDX);

                if (buckets[bit] != 0)
                {
                    temp[--buckets[bit]] = v[i];
                }
            }

            memcpy(v, temp, size * sizeof(int));
            delete[] temp;
        }

        void radixSortHelper(int* v, int size)
        {
            int buckets[2];
            memset(buckets, 0, 2 * sizeof(int));

            int* temp = new int[size];
            memset(temp, 0, size * sizeof(int));

            // iterate 31 bits because we've already separated negative integers
            for (int bit = 0; bit < INT_BITS_COUNT - 1; ++bit)
            {
                for (int i = 0; i < size; ++i)
                {
                    int numBit = util::getBit(v[i], bit);
                    ++buckets[numBit];
                }

                // increment buckets position
                buckets[1] += buckets[0];

                for (int i = size - 1; i >= 0; --i)
                {
                    int numBit = util::getBit(v[i], bit);

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

        void radixSort(int* v, int size)
        {
            // separate the negative and positive numbers
            int negativeCount = 0, positiveCount = 0;
            separateNegativeIntegers(v, size, negativeCount, positiveCount);

            // sort negative and positive parts
            radixSortHelper(v, negativeCount);
            radixSortHelper(v + negativeCount, positiveCount);
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
