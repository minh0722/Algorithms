#include "bubble_sort.h"

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