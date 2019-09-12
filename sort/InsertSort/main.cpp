#include <iostream>
#include <array>

// example set
const int last = 10;
std::array<int, last> val = { 3,42,11,34,56, 72, 97, 84, 23, 10 };

void insertSort(std::array<int, last>& arr, int last) {
	for (int i = 1; i < last; ++i) {
		if (arr.at(i - 1) > arr.at(i)) {
			for (int j = 0; j < last; ++j) {
				if (arr.at(j) > arr.at(i)) {
					int temp = arr.at(j);
					arr.at(j) = arr.at(i);
				}
			}
		}
	}
}

int main()
{
	insertSort(val, last);
	for (int i = 0; i < last; ++i) {
		printf("%d ",val[i]);
	}
}
