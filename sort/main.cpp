#include <iostream>
#include "sort.h"

int main()
{
	std::vector<int> val = { 3, 42, 11, 34, 56, 72, 97, 84, 23, 10 };
	std::vector<int> val1 = val;
	std::vector<int> val2 = val;
	std::vector<int> val3 = val;
	std::vector<int> val4 = val;
	my::sort::Sort::selectionSort(val1, val.size()-1);
	for (int i = 0; i < val.size(); ++i) {
		printf("%d ", val1[i]);
	}
	std::cout<<std::endl;
	my::sort::Sort::bubbleSort(val2, val.size() -1);
	for (int i = 0; i < val.size(); ++i) {
		printf("%d ", val2[i]);
	}
	std::cout << std::endl;
	my::sort::Sort::insertSort(val3, val.size() - 1);
	for (int i = 0; i < val.size(); ++i) {
		printf("%d ", val3[i]);
	}
	std::cout << std::endl;
	my::sort::Sort::mergeSort(val3, 0, val.size()-1);
	for (int i = 0; i < val.size(); ++i) {
		printf("%d ", val3[i]);
	}
	std::cout << std::endl;
	return 0;
}