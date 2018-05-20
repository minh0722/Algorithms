#include <iostream>
#include <vector>
using namespace std;
/*
 * Not stable sort
 * It is not stable since the smallest element is swapped to the front and it can change the order
 * Example:
 * 4 2 4 1
 * The first 4 will be swapped with 1 and the order of the 4's are reverted
 * 
 * 
 * It can be made to stable if we find the smallest element, remove it and push it to the front.
 * Then linked list should be used since insert is faster
*/

void swap(int& l, int& r) {
    l = l + r;
    r = l - r;
    l = l - r;
}

void selectionSort(vector<int>& v) {
    for(int i = 0; i < v.size(); ++i) {
        for(int j = i + 1; j < v.size(); ++j) {
            if(v[i] > v[j]) {
                swap(v[i], v[j]);
            }
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
    
    selectionSort(v);
    
    for(int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
    
return 0;
}