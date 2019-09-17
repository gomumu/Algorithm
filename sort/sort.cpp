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

void Sort::heapSort(std::vector<int>& arr, int n) {
	buildHeap(arr, n);
	for (int i = n-1; i >= 0; --i) {
		int tmp = arr.at(i);
		arr.at(i) = arr.at(0);
		arr.at(0) = tmp;
		heapify(arr, 1, i);
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
			// 왼쪽
		} else {
			++j;
			// 오른쪽
		}
	}
	int tmp = arr.at(i);
	arr.at(i) = arr.at(last);
	arr.at(last) = tmp;
	return i;
}

void Sort::buildHeap(std::vector<int>& arr, int last) {
	// 리프를 제외한 노드들에 대해서 heapify
	for (int i = last/2; i > 0; --i) {
		heapify(arr, i, last);
	}
}

void Sort::heapify(std::vector<int>& arr, int root, int n) {
	int left = root * 2;
	int right = root * 2 + 1;

	int smaller;
	//right가 있는경우
	if (right <= n) {
		if (arr.at(left-1) < arr.at(right-1)) {
			smaller = left;
		} else {
			smaller = right;
		}
	//right가 없는 경우
	} else if (left <= n) {
		smaller = left;
	} else
		return;

	if (arr.at(smaller-1) < arr.at(root-1)) {
		int tmp = arr.at(root-1);
		arr.at(root-1) = arr.at(smaller-1);
		arr.at(smaller-1) = tmp;
		heapify(arr,smaller,n);
	}
}

} // sort
} // my