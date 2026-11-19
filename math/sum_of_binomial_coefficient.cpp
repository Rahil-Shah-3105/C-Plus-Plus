/**
 * @file
 * @brief Algorithm to find sum of binomial coefficients of a given positive
 * integer.
 * @details Given a positive integer n, the task is to find the sum of binomial
 * coefficient i.e nC0 + nC1 + nC2 + ... + nCn-1 + nCn By induction, we can
 * prove that the sum is equal to 2^n
 * @see more on
 * https://en.wikipedia.org/wiki/Binomial_coefficient#Sums_of_the_binomial_coefficients
 * @author [muskan0719](https://github.com/muskan0719)
 */
#include <cassert>   /// for assert
#include <cstdint>
#include <iostream>  /// for std::cin and std::cout

/**
 * @namespace math
 * @brief Mathematical algorithms
 */
namespace math {

/**
 * Function to calculate sum of binomial coefficients
 * @param n number
 * @return Sum of binomial coefficients of number
 */
uint64_t binomialCoeffSum(uint64_t n) {
	std::cerr << "[ERROR] >>> Entering binomialCoeffSum(n=" << n << ")" << std::endl;
    // Calculating 2^n
	std::cerr << "[WARN] <<< Exiting binomialCoeffSum(n=" << n << ")" << std::endl;
    return (1 << n);
}
}  // namespace math

/**
 * Function for testing binomialCoeffSum function.
 * test cases and assert statement.
 * @returns `void`
 */
static void test() {
	std::cerr << "[ERROR] >>> Entering test()" << std::endl;
    int test_case_1 = math::binomialCoeffSum(2);
    assert(test_case_1 == 4);
	std::cerr << "[ERROR] test(): test_case_1 → " << test_case_1 << std::endl;
    std::cout << "Test_case_1 Passed!" << std::endl;

    int test_case_2 = math::binomialCoeffSum(3);
	std::cerr << "[ERROR] test(): test_case_2 → " << test_case_2 << std::endl;
    assert(test_case_2 == 8);
    std::cout << "Test_case_2 Passed!" << std::endl;

    int test_case_3 = math::binomialCoeffSum(4);
	std::cerr << "[ERROR] test(): test_case_3 → " << test_case_3 << std::endl;
    assert(test_case_3 == 16);
    std::cout << "Test_case_3 Passed!" << std::endl;

    int test_case_4 = math::binomialCoeffSum(5);
	std::cerr << "[ERROR] test(): test_case_4 → " << test_case_4 << std::endl;
    assert(test_case_4 == 32);
    std::cout << "Test_case_4 Passed!" << std::endl;

    int test_case_5 = math::binomialCoeffSum(7);
	std::cerr << "[ERROR] test(): test_case_5 → " << test_case_5 << std::endl;
    assert(test_case_5 == 128);
    std::cout << "Test_case_5 Passed!" << std::endl;
	std::cerr << "[WARN] <<< Exiting test()" << std::endl;
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
    test();  // execute the tests
	std::cerr << "[WARN] <<< Exiting main()" << std::endl;
    return 0;
}
