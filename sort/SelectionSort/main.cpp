#include <iostream>
#include <array>

// example set
const int last = 10;
std::array<int, last> val = { 3,42,11,34,56, 72, 97, 84, 23, 10 };

int largest(std::array<int, last> arr, int last) {
	int idx = 0;
	for (int i = 0; i < last; ++i) {
		idx = arr.at(i) > arr.at(idx) ? i : idx;
	}
	return idx;
}

void selectionSort(std::array<int, last>& arr, int last) {
	for (int i = last-1; i >= 0; --i) {
		int max_idx = largest(arr, i + 1);
		int temp = arr.at(i);
		arr.at(i) = arr.at(max_idx);
		arr.at(max_idx) = temp;
	}
}

int main()
{
	selectionSort(val, size);
	for (int i = 0; i < last; ++i) {
		printf("%d ",val[i]);
	}
}
