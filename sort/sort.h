#pragma once

#include <vector>

namespace my { namespace sort {
	class Sort {
	public:
		static void selectionSort(std::vector<int>& arr, int last);
		static void bubbleSort(std::vector<int>& arr, int last);
		static void insertSort(std::vector<int>& arr, int last);
		static void mergeSort(std::vector<int>& arr, int begin, int last);
		static void quickSort(std::vector<int>& arr, int begin, int last);
	private:
		static int largest(std::vector<int> arr, int last);
		static void merge(std::vector<int>& arr, int begin, int center, int last);
		static int partition(std::vector<int>& arr, int begin, int last);
	};
} // sort
} // my