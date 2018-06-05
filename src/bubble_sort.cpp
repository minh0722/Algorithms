#include "sorts.h"

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

namespace algorithm
{
	namespace sort
	{
		void swap(int& l, int& r)
		{
			l = l + r;
			r = l - r;
			l = l - r;
		}

		void bubbleSort(std::vector<int>& v)
		{
			int size = v.size();
			bool swapped = false;

			while (1)
			{
				swapped = false;
				for (int i = 0; i < size - 1; ++i)
				{
					if (v[i] > v[i + 1])
					{
						swap(v[i], v[i + 1]);
						swapped = true;
					}
				}
				--size;

				if (!swapped)
				{
					break;
				}
			}
		}
	}
}
