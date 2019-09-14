#include <iostream>
#include <vector>

#include "sort.h"

namespace my { namespace sort {

void Sort::selectionSort(std::vector<int>& arr, int last) {
	for (int i = last; i >= 0; --i) {
		int max_idx = largest(arr, i);
		int temp = arr.at(i);
		arr.at(i) = arr.at(max_idx);
		arr.at(max_idx) = temp;
	}
}

void Sort::bubbleSort(std::vector<int>& arr, int last) {
	for (int i = last; i >= 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (arr.at(j) > arr.at(j + 1)) {
				int temp = arr.at(j);
				arr.at(j) = arr.at(j + 1);
				arr.at(j + 1) = temp;
			}
		}
	}
}

void Sort::insertSort(std::vector<int>& arr, int last) {
	for (int i = 0; i <= last; ++i) {
		if (i - 1 > 0 && (arr.at(i - 1) > arr.at(i))) {
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

void Sort::mergeSort(std::vector<int>& arr, int begin, int last) {
	if (begin < last) {
		int center = (begin + last) / 2;
		mergeSort (arr, begin, center);
		mergeSort (arr, center + 1, last);
		Sort::merge(arr, begin, center, last);
	}
}

void Sort::quickSort(std::vector<int>& arr, int begin, int last) {
	if (begin < last) {
		int q = Sort::partition(arr, begin, last);
		Sort::quickSort(arr, begin, q-1);
		Sort::quickSort(arr, q+1, last);

	}
}

int Sort::largest(std::vector<int> arr, int last) {
	int idx = 0;
	for (int i = 0; i <= last; ++i) {
		idx = arr.at(i) > arr.at(idx) ? i : idx;
	}
	return idx;
}

void Sort::merge(std::vector<int>& arr, int begin, int center, int last) {
	std::vector<int> tmp_array;
	int p = begin, q = center+1;
	while (p <= center || q <= last) {
		if (p > center && q > last) {
			break;
		} else if (p > center) {
			tmp_array.push_back(arr[q++]);
		} else if (q > last) {
			tmp_array.push_back(arr[p++]);
		} else {
			if (arr[p] < arr[q]) {
				tmp_array.push_back(arr[p++]);
			} else {
				tmp_array.push_back(arr[q++]);
			}
		}
	}
	for (int i = 0; i < tmp_array.size(); ++i) {
		arr.at(begin + i) = tmp_array.at(i);
	}
}

int Sort::partition(std::vector<int>& arr, int begin, int last) {
	int x = arr.at(last);
	int i = begin, j = begin;

	for (int k = begin; k < last; ++k) {
		if (arr.at(k) <= x) {
			if (i != k ) {
				int tmp = arr.at(k);
				arr.at(k) = arr.at(i);
				arr.at(i) = tmp;
				++j;
			}
			++i;
			// ¿ÞÂÊ
		} else {
			++j;
			// ¿À¸¥ÂÊ
		}
	}
	int tmp = arr.at(i);
	arr.at(i) = arr.at(last);
	arr.at(last) = tmp;
	return i;
}

} // sort
} // my