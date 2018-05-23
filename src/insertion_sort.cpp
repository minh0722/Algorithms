#include "insertion_sort.h"
#include "util.h"

namespace Algorithm
{
    namespace InsertionSort
    {
        void insertionSort(std::vector<int>& v)
        {
            /* This is my optimization for avoiding the worst case by checking if it's sorted first */
            if (Util::isSorted(v))
            {
                return;
            }

            int size = v.size();

            for (int i = 1; i < size; ++i)
            {
                int num = v[i];
                int minIndex = -1;

                for (int j = i - 1; j >= 0; --j)
                {
                    if (v[j] <= num)
                        break;

                    v[j + 1] = v[j];
                    minIndex = j;
                }

                if (minIndex != -1)
                {
                    v[minIndex] = num;
                }
            }
        }
    }
}

//int main() {
//    
//    int n;
//    scanf("%d", &n);
//    
//    vector<int> v(n);
//    
//    for(int i = 0; i < n; ++i) {
//        scanf("%d", &v[i]);
//    }
//    
//    insertionSort(v);
//    
//    for(int i = 0; i < n; ++i) {
//        printf("%d ", v[i]);
//    }
//    printf("\n");
//    
//return 0;
//}