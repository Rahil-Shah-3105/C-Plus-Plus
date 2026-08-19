/**
 * Copyright 2020 @author iamnambiar
 *
 * @file
 * \brief A C++ Program to find the Sum of Digits of input integer.
 */
#include <cassert>
#include <iostream>

/**
 * Function to find the sum of the digits of an integer.
 * @param num The integer.
 * @return Sum of the digits of the integer.
 *
 * \detail
 * First the algorithm check whether the num is negative or positive,
 * if it is negative, then we neglect the negative sign.
 * Next, the algorithm extract the last digit of num by dividing by 10
 * and extracting the remainder and this is added to the sum.
 * The number is then divided by 10 to remove the last digit.
 * This loop continues until num becomes 0.
 */
int sum_of_digits(int num) {
	std::cerr << ">>> Entering sum_of_digits(num=" << num << ")" << std::endl;
    // If num is negative then negative sign is neglected.
    if (num < 0) {
		std::cerr << "sum_of_digits(num=" << num << "): num → " << num << std::endl;
        num = -1 * num;
    }
    int sum = 0;
	std::cerr << "sum_of_digits(num=" << num << "): sum → " << sum << std::endl;
    while (num > 0) {
        sum = sum + (num % 10);
        num = num / 10;
    }
	std::cerr << "<<< Exiting sum_of_digits(num=" << num << ")" << std::endl;
    return sum;
}

/**
 * Function for testing the sum_of_digits() function with a
 * first test case of 119765 and assert statement.
 */
void test1() {
	std::cerr << ">>> Entering test1()" << std::endl;
    int test_case_1 = sum_of_digits(119765);
    assert(test_case_1 == 29);
	std::cerr << "test1(): test_case_1 → " << test_case_1 << std::endl;
	std::cerr << "<<< Exiting test1()" << std::endl;
}

/**
 * Function for testing the sum_of_digits() function with a
 * second test case of -12256 and assert statement.
 */
void test2() {
	std::cerr << ">>> Entering test2()" << std::endl;
    int test_case_2 = sum_of_digits(-12256);
    assert(test_case_2 == 16);
	std::cerr << "test2(): test_case_2 → " << test_case_2 << std::endl;
	std::cerr << "<<< Exiting test2()" << std::endl;
}

/**
 * Function for testing the sum_of_digits() with
 * all the test cases.
 */
void test() {
	std::cerr << ">>> Entering test()" << std::endl;
    // First test.
    test1();
    // Second test.
    test2();
	std::cerr << "<<< Exiting test()" << std::endl;
}

/**
 * Main Function
 */
int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    test();
    std::cout << "Success." << std::endl;
	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
