/**
 * @file
 * @brief A simple program to check if the given number is a
 * [factorial](https://en.wikipedia.org/wiki/Factorial) of some number or not.
 *
 * @details A factorial number is the sum of k! where any value of k is a
 * positive integer. https://www.mathsisfun.com/numbers/factorial.html
 *
 * @author [Divyajyoti Ukirde](https://github.com/divyajyotiuk)
 * @author [ewd00010](https://github.com/ewd00010)
 */
#include <cassert>   /// for assert
#include <cstdint>
#include <iostream>  /// for cout

/**
 * @namespace
 * @brief Mathematical algorithms
 */
namespace math {
/**
 * @brief Function to check if the given number is factorial of some number or
 * not.
 * @param n number to be checked.
 * @return true if number is a factorial returns true
 * @return false if number is not a factorial
 */
bool is_factorial(uint64_t n) {
	std::cerr << ">>> Entering is_factorial(n=" << n << ")" << std::endl;
    if (n <= 0) {  // factorial numbers are only ever positive Integers
        return false;
    }

    /*!
     * this loop is basically a reverse factorial calculation, where instead
     * of multiplying we are dividing. We start at i = 2 since i = 1 has
     * no impact division wise
     */
    int i = 2;
    while (n % i == 0) {
        n = n / i;
        i++;
    }

    /*!
     * if n was the sum of a factorial then it should be divided until it
     * becomes 1
     */
	std::cerr << "<<< Exiting is_factorial(n=" << n << ")" << std::endl;
    return (n == 1);
}
}  // namespace math

/**
 * @brief Self-test implementations
 * @returns void
 */
static void tests() {
	std::cerr << ">>> Entering tests()" << std::endl;
    assert(math::is_factorial(50) == false);
    assert(math::is_factorial(720) == true);
    assert(math::is_factorial(0) == false);
    assert(math::is_factorial(1) == true);
    assert(math::is_factorial(479001600) == true);
    assert(math::is_factorial(-24) == false);

    std::cout << "All tests have successfully passed!" << std::endl;
	std::cerr << "<<< Exiting tests()" << std::endl;
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    tests();  // run self-test implementations
	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
