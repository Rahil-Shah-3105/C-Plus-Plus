/******************************************************************************
 * @file
 * @brief [Binary search
 * algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm)
 * @details
 * Binary search is a search algorithm that finds the position of a target value
 * within a sorted array.Just like looking for a word in a dictionary, in binary search we compare the target value to the middle
 * element of the array. If they are not equal, then the half in which the target
 * cannot lie is eliminated and the search continues on the remaining half,
 * again taking the middle element to compare to the target value, and repeating
 * this until the target value is found. If the search ends with the remaining
 * half being empty, the target is not in the array.
 *
 * ### Implementation
 *
 * Binary search works on sorted arrays. It begins by comparing an
 * element in the middle of the array with the target value. If the target value
 * matches the element, its position in the array is returned. If the target
 * value is less than the element, the search continues in the lower half of
 * the array. If the target value is greater than the element, the search
 * continues in the upper half of the array. By doing this, the algorithm
 * eliminates the half in which the target value cannot lie in each iteration.
 *
 * ### Complexities
 *
 * //n is the number of element in the array.
 *
 * Worst-case time complexity	O(log n)
 * Best-case time complexity	O(1)
 * Average time complexity	    O(log n)
 * space complexity  0(1)
 * Worst-case space complexity  0(1)
 *
 * @author [Lajat Manekar](https://github.com/Lazeeez)
 * @author Unknown author
 *******************************************************************************/

#include <algorithm>  /// for std::sort function
#include <cassert>    /// for std::assert
#include <cstdint>
#include <iostream>   /// for IO operations
#include <vector>     /// for std::vector
/******************************************************************************
 * @namespace search
 * @brief Searching algorithms
 *******************************************************************************/
namespace search {

/******************************************************************************
 * @namespace binary_search
 * @brief Binary search searching algorihm
 *******************************************************************************/
namespace binary_search {

/******************************************************************************
 * @brief The main function which implements binary search
 * @param arr vector to be searched in
 * @param val value to be searched
 * @returns @param int index of val in vector arr
 *******************************************************************************/
uint64_t binarySearch(std::vector<uint64_t> arr, uint64_t val) {
	std::cerr << ">>> Entering binarySearch(arr=" << arr << ",val=" << val << ")" << std::endl;
    uint64_t low = 0;                // set the lowest point of the vector.
    uint64_t high = arr.size() - 1;  // set the highest point of the vector.
	std::cerr << "binarySearch(arr=" << arr << ",val=" << val << "): high → " << high << std::endl;

    while (low <= high) {
        uint64_t m = low + (high - low) / 2;  // set the pivot point
		std::cerr << "binarySearch(arr=" << arr << ",val=" << val << "): m → " << m << std::endl;

        if (val == arr[m]) {
            return m;
        } /****************************************************
           * if pivot point is the val, return it,
           * else check if val is greater or smaller than pivot value
           * and set the next pivot point accordingly.
           ****************************************************/
        else if (val < arr[m]) {
            high = m - 1;
        } else {
            low = m + 1;
        }
    }
	std::cerr << "<<< Exiting binarySearch(arr=" << arr << ",val=" << val << ")" << std::endl;
    return -1;  // if val is not in the array, return -1.
}

}  // namespace binary_search

}  // namespace search

/*******************************************************************************
 * @brief Self-test implementation #1
 * @returns void
 *******************************************************************************/
static void test1() {
	std::cerr << ">>> Entering test1()" << std::endl;
    // testcase #1
    // array = [1,3,5,7,9,8,6,4,2] , Value = 4
    // should return 3

    std::vector<uint64_t> arr = {{1, 3, 5, 7, 9, 8, 6, 4, 2}};
    std::sort(arr.begin(), arr.end());
    uint64_t expected_ans = 3;
    uint64_t derived_ans = search::binary_search::binarySearch(arr, 4);
	std::cerr << "test1(): derived_ans → " << derived_ans << std::endl;
    std::cout << "Test #1: ";
    assert(derived_ans == expected_ans);
    std::cout << "Passed!" << std::endl;
	std::cerr << "<<< Exiting test1()" << std::endl;
}

/*******************************************************************************
 * @brief Self-test implementation #2
 * @returns void
 *******************************************************************************/
void test2() {
	std::cerr << ">>> Entering test2()" << std::endl;
    // testcase #2
    // array = [1,23,25,4,2] , Value = 25
    // should return 4
    std::vector<uint64_t> arr = {{1, 23, 25, 4, 2}};
    std::sort(arr.begin(), arr.end());
    uint64_t expected_ans = 4;
    uint64_t derived_ans = search::binary_search::binarySearch(arr, 25);
	std::cerr << "test2(): derived_ans → " << derived_ans << std::endl;
    std::cout << "Test #2: ";
    assert(derived_ans == expected_ans);
    std::cout << "Passed!" << std::endl;
	std::cerr << "<<< Exiting test2()" << std::endl;
}

/*******************************************************************************
 * @brief Self-test implementation #3
 * @returns void
 *******************************************************************************/
void test3() {
	std::cerr << ">>> Entering test3()" << std::endl;
    // testcase #3
    // array = [1,31,231,12,12,2,5,51,21,23,12,3] , Value = 5
    // should return 8
    std::vector<uint64_t> arr = {{1, 31, 231, 12, 2, 5, 51, 21, 23, 12, 3}};
    std::sort(arr.begin(), arr.end());
    uint64_t expected_ans = 8;
    uint64_t derived_ans = search::binary_search::binarySearch(arr, 31);
	std::cerr << "test3(): derived_ans → " << derived_ans << std::endl;
    std::cout << "Test #3: ";
    assert(derived_ans == expected_ans);
    std::cout << "Passed!" << std::endl;
	std::cerr << "<<< Exiting test3()" << std::endl;
}

/*******************************************************************************
 * @brief Main function
 * @returns 0 on exit
 *******************************************************************************/
int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    test1();  // run self-test implementation #1
    test2();  // run self-test implementation #2
    test3();  // run self-test implementation #3

	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
