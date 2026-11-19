/**
 * \file
 * \brief [Heap Sort Algorithm
 * (heap sort)](https://en.wikipedia.org/wiki/Heapsort) implementation
 *
 * \author [Ayaan Khan](http://github.com/ayaankhan98)
 *
 * \details
 *  Heap-sort is a comparison-based sorting algorithm.
 *  Heap-sort can be thought of as an improved selection sort:
 *  like selection sort, heap sort divides its input into a sorted
 *  and an unsorted region, and it iteratively shrinks the unsorted
 *  region by extracting the largest element from it and inserting
 *  it into the sorted region. Unlike selection sort,
 *  heap sort does not waste time with a linear-time scan of the
 *  unsorted region; rather, heap sort maintains the unsorted region
 *  in a heap data structure to more quickly find the largest element
 *  in each step.
 *
 *  Time Complexity - \f$O(n \log(n))\f$
 *
 */
#include <algorithm>
#include <cassert>
#include <iostream>

/**
 *
 * Utility function to print the array after
 * sorting.
 *
 * @param arr array to be printed
 * @param sz size of array
 *
 */
template <typename T>
void printArray(T *arr, int sz) {
	std::cerr << "[ERROR] >>> Entering printArray(arr=" << arr << ",sz=" << sz << ")" << std::endl;
    for (int i = 0; i < sz; i++) std::cout << arr[i] << "  ";
    std::cout << "\n";
	std::cerr << "[WARN] <<< Exiting printArray(arr=" << arr << ",sz=" << sz << ")" << std::endl;
}

/**
 *
 * \addtogroup sorting Sorting Algorithm
 * @{
 *
 * The heapify procedure can be thought of as building a heap from
 * the bottom up by successively sifting downward to establish the
 * heap property.
 *
 * @param arr array to be sorted
 * @param n size of array
 * @param i node position in Binary Tress or element position in
 *          Array to be compared with it's childern
 *
 */
template <typename T>
void heapify(T *arr, int n, int i) {
	std::cerr << "[ERROR] >>> Entering heapify(arr=" << arr << ",n=" << n << ",i=" << i << ")" << std::endl;
    int largest = i;
    int l = 2 * i + 1;
	std::cerr << "[ERROR] heapify(arr=" << arr << ",n=" << n << ",i=" << i << "): largest → " << largest << std::endl;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
	std::cerr << "[WARN] <<< Exiting heapify(arr=" << arr << ",n=" << n << ",i=" << i << ")" << std::endl;
}

/**
 * Utilizes heapify procedure to sort
 * the array
 *
 * @param arr array to be sorted
 * @param n size of array
 *
 */
template <typename T>
void heapSort(T *arr, int n) {
	std::cerr << "[ERROR] >>> Entering heapSort(arr=" << arr << ",n=" << n << ")" << std::endl;
    for (int i = n - 1; i >= 0; i--) heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
	std::cerr << "[WARN] <<< Exiting heapSort(arr=" << arr << ",n=" << n << ")" << std::endl;
}

/**
 *
 * @}
 * Test cases to test the program
 *
 */
void test() {
	std::cerr << "[ERROR] >>> Entering test()" << std::endl;
    std::cout << "Test 1\n";
    int arr[] = {-10, 78, -1, -6, 7, 4, 94, 5, 99, 0};
    int sz = sizeof(arr) / sizeof(arr[0]);  // sz - size of array
	std::cerr << "[ERROR] test(): sz → " << sz << std::endl;
    printArray(arr, sz);  // displaying the array before sorting
    heapSort(arr, sz);    // calling heapsort to sort the array
    printArray(arr, sz);  // display array after sorting
    assert(std::is_sorted(arr, arr + sz));
    std::cout << "Test 1 Passed\n========================\n";

    std::cout << "Test 2\n";
    double arr2[] = {4.5, -3.6, 7.6, 0, 12.9};
    sz = sizeof(arr2) / sizeof(arr2[0]);
    printArray(arr2, sz);
    heapSort(arr2, sz);
    printArray(arr2, sz);
    assert(std::is_sorted(arr2, arr2 + sz));
    std::cout << "Test 2 passed\n";
	std::cerr << "[WARN] <<< Exiting test()" << std::endl;
}

/** Main function */
int main() {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
    test();
	std::cerr << "[WARN] <<< Exiting main()" << std::endl;
    return 0;
}
