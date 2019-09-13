#include <iostream>
#include <array>

// example set
const int last = 10;
std::array<int, last> val = { 3,42,11,34,56, 72, 97, 84, 23, 10 };

void insertSort(std::array<int, last>& arr, int last) {
	for (int i = 0; i < last; ++i) {
		if ( i-1 > 0 && (arr.at(i - 1) > arr.at(i))) {
			// search
			for (int j = 0; j < i; ++j) {
				if (arr.at(j) > arr.at(i)) {
					int temp = arr.at(j);
					arr.at(j) = arr.at(i);
					arr.at(i) = temp;
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
