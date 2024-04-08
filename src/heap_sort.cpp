#include "sorts.h"
#include "util.h"
#include <cstddef>

/*
* Not stable sort
* nlog(n) worst case complexity
*/

namespace algorithm
{
    namespace sort
    {
        void heapifyDown(std::vector<int>& v, size_t index, size_t size)
        {
            // if there is no children
            if (index * 2 + 1 >= size)
            {
                return;
            }

            size_t left = index * 2 + 1;
            size_t right = index * 2 + 2 < size ? index * 2 + 2 : left;
            int maxIdx;

            while (left < size)
            {
                // get the max child of the 2 children
                maxIdx = v[left] > v[right] ? left : right;

                // if the parent is already bigger than max child, then no need to proceed
                if (v[index] >= v[maxIdx])
                    break;

                // swap the parent with the max child
                util::swap(v[index], v[maxIdx]);

                // change the parent index to the max child that we just swapped and get its children indexes
                index = maxIdx;
                left = index * 2 + 1;
                right = index * 2 + 2 < size ? index * 2 + 2 : left;
            }
        }

        void heapSort(std::vector<int>& v)
        {
            size_t size = v.size();

            for (int i = size / 2 - 1; i >= 0; --i)
            {
                heapifyDown(v, i, size);
            }

            // start the normalizing process that converts the heap into sorted array
            for (size_t i = size - 1; i > 0; --i)
            {
                // swap the top element with the last element
                util::swap(v[i], v[0]);

                // then heapify down the top element up until the last element that we just swap
                // this ensure that the last element will be the biggest element in the array
                heapifyDown(v, 0, i);
            }
        }
    }
}

//int main() {
//    
//    vector<int> v = {7,2,6,3,8,1,55,33,2,9,8,21};
//    
//    heapSort(v);
//    
//    for(auto el : v) {
//        cout << el << " ";
//    }cout << endl;
//    
//    
//return 0;
//}
