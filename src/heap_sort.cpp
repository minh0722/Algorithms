#include "heap_sort.h"
#include "util.h"
#include <cstddef>

namespace algorithm
{
    namespace sort
    {
        void heapifyUp(std::vector<int>& v, size_t index)
        {
            while (v[index] > v[index / 2])
            {
                util::swap(v[index], v[index / 2]);
                index /= 2;
            }
        }

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
                maxIdx = v[left] > v[right] ? left : right;

                if (v[index] >= v[maxIdx])
                    break;

                util::swap(v[index], v[maxIdx]);
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

            for (size_t i = size - 1; i > 0; --i)
            {
                util::swap(v[i], v[0]);
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