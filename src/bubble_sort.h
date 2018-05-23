#ifndef ALGORITHM_BUBBLE_SORT
#define ALGORITHM_BUBBLE_SORT

/*
* Stable sort
* It is stable since we dont swap elements that are equal
*
* iterate by pair so the biggest element go to the end
*
* flag swapped is for checking if there was any swap. If not then the array is already sorted
* and no more traverse is needed.
*
* Complexity:
* Worst case: n^2
* Best case: n
* Average: n^2
*
*/

#include <vector>


namespace algorithm
{
	namespace sort
	{
		void sort(std::vector<int>& v);
	}
}

#endif // ALGORITHM_BUBBLE_SORT