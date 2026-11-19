/**
 * \file
 * \brief C++ program to implement [Jump
 * Search](https://en.wikipedia.org/wiki/Jump_search)
 */
#include <algorithm>
#include <cmath>
#include <iostream>

/** jump search implementation
 */
int jumpSearch(int arr[], int x, int n) {
	std::cerr << "[ERROR] >>> Entering jumpSearch(arr=" << arr << ",x=" << x << ",n=" << n << ")" << std::endl;
    // Finding block size to be jumped
    int step = std::sqrt(n);
	std::cerr << "[ERROR] jumpSearch(arr=" << arr << ",x=" << x << ",n=" << n << "): step → " << step << std::endl;

    // Finding the block where element is
    // present (if it is present)
    int prev = 0;
    while (arr[std::min(step, n) - 1] < x) {
        prev = step;
		std::cerr << "[ERROR] jumpSearch(arr=" << arr << ",x=" << x << ",n=" << n << "): prev → " << prev << std::endl;
        step += std::sqrt(n);
        if (prev >= n)
            return -1;
    }

    // Doing a linear search for x in block
    // beginning with prev.
    while (arr[prev] < x) {
        prev++;

        // If we reached next block or end of
        // array, element is not present.
        if (prev == std::min(step, n))
            return -1;
    }
    // If element is found
    if (arr[prev] == x)
        return prev;

    return -1;
}

// Driver program to test function
int main() {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int x = 55;
    int n = sizeof(arr) / sizeof(arr[0]);
	std::cerr << "[ERROR] main(): n → " << n << std::endl;

    // Find the index of 'x' using Jump Search
    int index = jumpSearch(arr, x, n);

    // Print the index where 'x' is located
    std::cout << "\nNumber " << x << " is at index " << index;
	std::cerr << "[WARN] <<< Exiting main()" << std::endl;
    return 0;
}
