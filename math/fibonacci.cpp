/**
 * @file
 * @brief n-th [Fibonacci
 * number](https://en.wikipedia.org/wiki/Fibonacci_sequence).
 *
 * @details
 * Naive recursive implementation to calculate the n-th Fibonacci number.
 * \f[\text{fib}(n) = \text{fib}(n-1) + \text{fib}(n-2)\f]
 *
 * @see fibonacci_large.cpp, fibonacci_fast.cpp, string_fibonacci.cpp
 */

#include <cstdint>
#include <cassert>   /// for assert
#include <iostream>  /// for IO operations

/**
 * @namespace math
 * @brief Math algorithms
 */
namespace math {
/**
 * @namespace fibonacci
 * @brief Functions for Fibonacci sequence
 */
namespace fibonacci {
/**
 * @brief Function to compute the n-th Fibonacci number
 * @param n the index of the Fibonacci number
 * @returns n-th element of the Fibonacci's sequence
 */
uint64_t fibonacci(uint64_t n) {
	std::cerr << ">>> Entering fibonacci(n=" << n << ")" << std::endl;
    // If the input is 0 or 1 just return the same (Base Case)
    // This will set the first 2 values of the sequence
    if (n <= 1) {
	std::cerr << "<<< Exiting fibonacci(n=" << n << ")" << std::endl;
        return n;
    }

    // Add the preceding 2 values of the sequence to get next
    return fibonacci(n - 1) + fibonacci(n - 2);
}
}  // namespace fibonacci
}  // namespace math

/**
 * @brief Self-test implementation
 * @returns `void`
 */
static void test() {
	std::cerr << ">>> Entering test()" << std::endl;
    assert(math::fibonacci::fibonacci(0) == 0);
    assert(math::fibonacci::fibonacci(1) == 1);
    assert(math::fibonacci::fibonacci(2) == 1);
    assert(math::fibonacci::fibonacci(3) == 2);
    assert(math::fibonacci::fibonacci(4) == 3);
    assert(math::fibonacci::fibonacci(15) == 610);
    assert(math::fibonacci::fibonacci(20) == 6765);
    std::cout << "All tests have passed successfully!\n";
	std::cerr << "<<< Exiting test()" << std::endl;
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    test();  // run self-test implementations
	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
