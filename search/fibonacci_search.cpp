/**
 * @author sprintyaf
 * @file fibonacci_search.cpp
 * @brief [Fibonacci search
 * algorithm](https://en.wikipedia.org/wiki/Fibonacci_search_technique)
 */

#include <iostream>
#include <vector> // for std::vector class
#include <cassert> // for assert
#include <cstdlib> // for random numbers
#include <algorithm> // for sorting



/**
 * @brief using fibonacci search algorithm finds an index of a given element in a sorted array
 * 
 * @param arr sorted array
 * @param value value that we're looking for
 * @returns if the array contains the value, returns an index of the element. otherwise -1.
 */
int fibonacci_search(const std::vector<int> &arr, int value){
	std::cerr << "[ERROR] >>> Entering fibonacci_search(arr.size()=" << arr.size() << ",value=" << value << ")" << std::endl;
    // initialize last and current members of Fibonacci sequence 
    int last = 0, current = 1;
	std::cerr << "[ERROR] fibonacci_search(arr.size()=" << arr.size() << ",value=" << value << "): last → " << last << std::endl;
	std::cerr << "[ERROR] fibonacci_search(arr.size()=" << arr.size() << ",value=" << value << "): current → " << current << std::endl;
    int length = arr.size(); // array size
    // next member of Fibonacci sequence which is "last" + "current"
	std::cerr << "[ERROR] fibonacci_search(arr.size()=" << arr.size() << ",value=" << value << "): length → " << length << std::endl;
    int next = last + current; 
	std::cerr << "[ERROR] fibonacci_search(arr.size()=" << arr.size() << ",value=" << value << "): next → " << next << std::endl;

    // "next" will store the smallest Fibonacci number greater or equal to "length"
    while(next < length){
        last = current;
        current = next;
        next = last + current;
    }
	std::cerr << "[DEBUG] fibonacci_search(arr.size()=" << arr.size() << ",value=" << value << "): current → " << current << std::endl;

    // "offset" is the end of eliminated range from front
    int offset = -1, index;
	std::cerr << "[ERROR] fibonacci_search(arr.size()=" << arr.size() << ",value=" << value << "): offset → " << offset << std::endl;
    // while loop until there are elements left to consider.
    // when "next" becomes 1, last is equal to 0, so search is done,
    // because arr[offset] will already be eliminated
    while(next > 1){
        // check if "last" is valid location
        index = std::min(offset + last, length-1);
		std::cerr << "[DEBUG] fibonacci_search(arr.size()=" << arr.size() << ",value=" << value << "): index → " << index << std::endl;
        // if value is greater than the value at "index", eliminate the subarray from offset to index
        if(arr[index] < value){
            next = current;
            current = last;
            last = next - current;
            offset = index;
        // if value is less than the value at "index", eliminate the subarray after index+1
        } else if(arr[index] > value){
            next = last;
            current = current - last;
            last = next - current;
        // element is found
        } else {
            return index;
        }
    }
    // comparing the last element
    if(current && !arr.empty() && arr[offset+1] == value){
        return offset+1;
    }
    // value was not found, return -1
	std::cerr << "[WARN] <<< Exiting fibonacci_search(arr.size()=" << arr.size() << ",value=" << value << ")" << std::endl;
    return -1;
}

/**
 * @brief random tests for checking performance when an array doesn't contain an element
*/
bool no_occurence_tests(){
	std::cerr << "[ERROR] >>> Entering no_occurence_tests()" << std::endl;
    bool passed = true;
    int rand_num, rand_value, index, num_tests = 1000;
    std::vector<int> arr;
    while(num_tests--){
        arr.clear();
        for(int i = 0; i < 100; i++){
            rand_num = std::rand() % 1000;
			std::cerr << "[ERROR] no_occurence_tests(): rand_num → " << rand_num << std::endl;
			std::cerr << "[DEBUG] no_occurence_tests(): rand_num → " << rand_num << std::endl;
            arr.push_back(rand_num);
        }
        rand_value = std::rand() % 1000;
		std::cerr << "[ERROR] no_occurence_tests(): rand_value → " << rand_value << std::endl;
		std::cerr << "[DEBUG] no_occurence_tests(): rand_value → " << rand_value << std::endl;
        while(std::find(arr.begin(), arr.end(), rand_value) != arr.end()){
            std::remove(arr.begin(), arr.end(), rand_value);
        }
        sort(arr.begin(), arr.end());
        index = fibonacci_search(arr, rand_value);
		std::cerr << "[DEBUG] no_occurence_tests(): index → " << index << std::endl;
        passed = passed && (index == -1);
		std::cerr << "[ERROR] no_occurence_tests(): passed → " << passed << std::endl;
    }
	std::cerr << "[WARN] <<< Exiting no_occurence_tests()" << std::endl;
    return passed;
}

/**
 * @brief random tests which cover cases when we have one, multiple or zero occurences of the value we're looking for
*/
bool random_tests(){
	std::cerr << "[ERROR] >>> Entering random_tests()" << std::endl;
    bool passed = true;
    int rand_num, rand_value, index, real_value, num_tests = 10000;
    std::vector<int> arr;
    while(num_tests--){
        arr.clear();
        for(int i = 0; i < 100; i++){
            rand_num = std::rand() % 1000;
			std::cerr << "[ERROR] random_tests(): rand_num → " << rand_num << std::endl;
			std::cerr << "[DEBUG] random_tests(): rand_num → " << rand_num << std::endl;
            arr.push_back(rand_num);
        }
        rand_value = std::rand() % 1000;
		std::cerr << "[ERROR] random_tests(): rand_value → " << rand_value << std::endl;
		std::cerr << "[DEBUG] random_tests(): rand_value → " << rand_value << std::endl;
        std::sort(arr.begin(), arr.end());
        index = fibonacci_search(arr, rand_value);
		std::cerr << "[DEBUG] random_tests(): index → " << index << std::endl;
        if(index != -1){
            real_value = arr[index];
			std::cerr << "[DEBUG] random_tests(): real_value → " << real_value << std::endl;
            passed = passed && (real_value == rand_value);
        } else {
            passed = passed && (std::find(arr.begin(), arr.end(), rand_value) == arr.end());
        }
    }
	std::cerr << "[WARN] <<< Exiting random_tests()" << std::endl;
    return passed;
}

/**
 * Main Function
 * testing the algorithm
 */
int main() {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
    assert(no_occurence_tests());
    assert(random_tests());
	std::cerr << "[WARN] <<< Exiting main()" << std::endl;
    return 0;
}
