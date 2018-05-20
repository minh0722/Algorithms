#include <iostream>
#include <vector>
using namespace std;

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

void swap(int& l, int& r) {
    l = l + r;
    r = l - r;
    l = l - r;
}

void bubbleSort(vector<int>& v) {
    int size = v.size();
    bool swapped = false;
    
    while(1) {
        swapped = false;
        for(int i = 0; i < size - 1; ++i) {
            if(v[i] > v[i+1]) {
                swap(v[i], v[i+1]);
                swapped = true;
            }
        }
        --size;

        if(!swapped) {
            break;
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
    
    bubbleSort(v);
    
    for(int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
    
return 0;
}