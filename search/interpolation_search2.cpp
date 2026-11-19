/**
 * \file
 * \brief [Interpolation
 * search](https://en.wikipedia.org/wiki/Interpolation_search) algorithm
 */
#include <iostream>

/** function to search the value in an array using interpolation search
 * \param [in] arr array to search in
 * \param [in] value value to search for
 * \param [in] len length of array
 * \returns index where the value is found
 * \returns -1 if not found
 */
int InterpolationSearch(int A[], int n, int x) {
	std::cerr << "[ERROR] >>> Entering InterpolationSearch(A=" << A << ",n=" << n << ",x=" << x << ")" << std::endl;
    int low = 0;
    int high = n - 1;
	std::cerr << "[ERROR] InterpolationSearch(A=" << A << ",n=" << n << ",x=" << x << "): high → " << high << std::endl;
    while (low <= high) {
        int mid = low + (((high - 1) * (x - A[low])) / (A[high] - A[low]));
		std::cerr << "[ERROR] InterpolationSearch(A=" << A << ",n=" << n << ",x=" << x << "): mid → " << mid << std::endl;
        if (x == A[mid])
            return mid;  // Found x, return (exit)
        else if (x < A[mid])
            high = mid - 1;  // X lies before mid
        else
            low = mid + 1;  // x lies after mid
			std::cerr << "[ERROR] InterpolationSearch(A=" << A << ",n=" << n << ",x=" << x << "): low → " << low << std::endl;
    }

	std::cerr << "[WARN] <<< Exiting InterpolationSearch(A=" << A << ",n=" << n << ",x=" << x << ")" << std::endl;
    return -1;
}

/** main function */
int main() {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
    int A[] = {2, 4, 5, 7, 13, 14, 15, 23};
    int x = 17;

    ///< passed array A inside the InterpolationSearch function
    int index = InterpolationSearch(A, 8, x);
    if (index < 0)
        std::cout << "Number " << x << " not found" << std::endl;
    else
        std::cout << "Number " << x << " is at " << index << std::endl;
		std::cerr << "[WARN] <<< Exiting main()" << std::endl;
}

// randomly set x bcoz array was defined by us , therefore not reasonable for
// asking input. We could have asked for input if array elements were inputed by
// the user.
