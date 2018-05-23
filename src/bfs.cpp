#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TODO: FIX THIS, NOT WORKING

void heapifyUp(std::vector<int>& v, int index) {
    while (v[index] > v[index / 2]) {
        swap(v[index], v[index / 2]);        
        index /= 2;
    }
}

void heapifyDown(std::vector<int>& v, int index, size_t size) {
    
    // if there is no children
    if (index * 2 + 1 >= size) {
        return;
    }
    
    if(v[index] < v[index * 2 + 1]) {
        swap(v[index], v[index * 2 + 1]);
        heapifyDown(v, index * 2 + 1, size);
        return;
    }
    
    if(index * 2 + 2 < size && v[index] < v[index * 2 + 2]) {
        swap(v[index], v[index * 2 + 2]);
        heapifyDown(v, index * 2 + 2, size);
    }
}

void heapSort(std::vector<int>& v) {
    size_t size = v.size();
    
    for (int i = size/2 - 1; i >= 0; --i) {
        heapifyDown(v, i, size);
        
//         for(auto it : v) {
//             cout << it << " ";
//         }cout << endl;
    }
    
    for (size_t i = size - 1; i > 0; --i) {
        swap(v[i], v[0]);
        
        heapifyDown(v, 0, i+1);
    }
}

//int main() {
//    
//    vector<int> v = {7,2,6,3,3,1,3,4,5,21};
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