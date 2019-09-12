#include <iostream>
#include <array>

// example set
const int last = 10;
std::array<int, last> val = { 3,42,11,34,56, 72, 97, 84, 23, 10 };

void bubbleSort(std::array<int, last>& arr, int last) {
	for (int i = last - 1 ; i >= 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (arr.at(j) > arr.at(j + 1)) {
				int temp = arr.at(j);
				arr.at(j) = arr.at(j + 1);
				arr.at(j + 1) = temp;
			}
		}
	}
}

int main()
{
	bubbleSort(val, last);
	for (int i = 0; i < last; ++i) {
		printf("%d ",val[i]);
	}
}
