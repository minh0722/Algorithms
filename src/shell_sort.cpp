#include <cstring>
#include <cstdio>
#include <vector>

//TODO: NOT WORKING!. FIX THIS

void insertionSort(int*& v, int size, int step)
{
    int firstIdx = step;
    int lastIdx = ((size - 1) / step) * step;
    
    for(int s = 0; s < step; ++s)
    {
        firstIdx = step + s;
        lastIdx = (((size - 1 + s) / (step + s)) * step) + s;
        
        for(int i = firstIdx; i < lastIdx; i += step)
        {
            int value = v[i];

            for(int j = 0; j < i; j += step)
            {

            }
        }
    }
}

void shellSort(int*& v, int size)
{
    int h = 4;
    
    while (h > 0)
    {        
        //do insertion sort with step h
        insertionSort(v, size, h);
        
        h /= 3;
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
//    shellSort(v, n);
//
//    for(int i = 0; i < n; ++i) {
//        printf("%d ", v[i]);
//    }
//    printf("\n");
//
//    delete[] v;
//
//    return 0;
//}
