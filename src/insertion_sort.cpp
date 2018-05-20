#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

/*
 *  Stable sort
 *  It is stable since we don't insert the element before another element that is equal to it
 *  
 *  In insertion sort we try to sort from left to right, 
 *  which means when we try to insert element at index n to the right place,
 *  all elements from 0 to n-1 are sorted.
 *  
 * 
 * Complexity:
 * Worst case: n^2
 * Best case: n
 * Average: n^2
*/

/* This is my optimization for avoiding the worst case by checking if it's sorted first */
bool isSorted(const vector<int>& v) {
    for(int i = 0; i < v.size() - 1; ++i) {
        if(v[i] > v[i+1]) {
            return false;
        }
    }
    return true;
}

void insertionSort(vector<int>& v) {
    if(isSorted(v)) {
        return;
    }
    
    int size = v.size();
    
    for(int i = 1; i < size; ++i) {
        int num = v[i];
        int minIndex = -1;

        for(int j = i - 1; j >= 0; --j) {
            if(v[j] > num) {
                v[j+1] = v[j];
                minIndex = j;
            }
            else {
                break;
            }
        }
        
        if(minIndex != -1) {
            v[minIndex] = num;
        }
    }
}

int main() {
    
    int n;
    scanf("%d", &n);
    
    vector<int> v(n);
    
    for(int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    
    insertionSort(v);
    
    for(int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
    
return 0;
}