#include <iostream>
#include "sort.h"

int main()
{
	std::vector<int> val = { 3, 42, 11, 34, 56, 72, 97, 84, 10, 23 };
	std::vector<int> val1 = val;
	std::vector<int> val2 = val;
	std::vector<int> val3 = val;
	std::vector<int> val4 = val;
	std::vector<int> val5 = val;
	std::vector<int> val6 = val;
	std::vector<int> val7 = { 123, 2154, 222, 4, 283, 1560, 1061, 2150 };
	std::vector<int> val8 = { 3, 21, 19, 32, 14, 9, 12, 8, 27, 16 };
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
	my::sort::Sort::mergeSort(val4, 0, val.size()-1);
	for (int i = 0; i < val.size(); ++i) {
		printf("%d ", val4[i]);
	}
	std::cout << std::endl;

	my::sort::Sort::quickSort(val5, 0, val.size() - 1);
	for (int i = 0; i < val.size(); ++i) {
		printf("%d ", val5[i]);
	}
	std::cout << std::endl;
	
	my::sort::Sort::heapSort(val6, val6.size());
	for (int i = 0; i < val.size(); ++i) {
		printf("%d ", val6[i]);
	}
	std::cout << std::endl;

	my::sort::Sort::radixSort(val7, val7.size(), 4);
	for (int i = 0; i < val7.size(); ++i) {
		printf("%d ", val7[i]);
	}
	std::cout << std::endl;

	std::vector<int> res = my::sort::Sort::countingSort(val8, 32, val8.size());
	for (int i = 0; i < res.size(); ++i) {
		printf("%d ", res[i]);
	}
	std::cout << std::endl;
	return 0;
}