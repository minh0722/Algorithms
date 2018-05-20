#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*
 * Stable sort
 * It is stable because function merge compares two elements from two chunks and
 * if two elements are equal it takes from the left chunk. So the order is preserved
 * 
 * Complexity:
 * Worst case: nlogn
 * Best case: nlogn
 * Average: nlogn
*/

void merge(int* listed, int begin, int mid, int end){
	
	int left_size = mid - begin + 1;
	int right_size = end - (mid + 1) + 1;
    
    // if last element of left chunk is <= first element of right chunk
    // then no merging is needed
    if(listed[mid] <= listed[mid + 1]) {
        return;
    }

	vector<int> left(left_size);
	vector<int> right(right_size);

	int k = begin;
	for(int i=0; i<left_size; ++i){
		left[i] = listed[k];
		++k;
	}

	int m = mid+1;
	for(int j=0; j<right_size; ++j){
		right[j] = listed[m];
		++m;
	}

	int i=0, j=0, index = begin;
	while(i<left_size && j<right_size){
		if(left[i] < right[j]){
			listed[index] = left[i];
			++index;
			++i;
		}
		else{
			listed[index] = right[j];
			++index;
			++j;
		}
	}

	if(i == left_size){
		while(j<right_size){
			listed[index] = right[j];
			++index;
			++j;
		}
	}
	if(j == right_size){
		while (i<left_size){
			listed[index] = left[i];
			++index;
			++i;
		}
	}

}

void mergeSort(int* listed, int begin, int end){
	if(begin < end){
		int mid = (begin + end) / 2;

		mergeSort(listed, begin, mid);
		mergeSort(listed, mid+1, end);

		merge(listed,begin, mid, end);
	}
}

int main() {

    int n;
    cin >> n;

    int* v = new int[n];

    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    mergeSort(v, 0, n-1);

    for(int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    delete[] v;

return 0;
}
