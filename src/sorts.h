#ifndef ALGORITHM_SORTS
#define ALGORITHM_SORTS

#include <vector>
#include <cstddef>
#include "common.h"

namespace algorithm
{
	namespace sort
	{
	    ALGO_API void bubbleSort(std::vector<int>& v);
        ALGO_API void heapSort(std::vector<int>& v);
        ALGO_API void insertionSort(std::vector<int>& v);
        ALGO_API void mergeSort(int* listed, int begin, int end);
        ALGO_API void quickSort(int* v, int leftIndex, int rightIndex);
        ALGO_API void radixSort(int*& v, int size);
        ALGO_API void selectionSort(std::vector<int>& v);
	}
}

#endif // ALGORITHM_SORTS
