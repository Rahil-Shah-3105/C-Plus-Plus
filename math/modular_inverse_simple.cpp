/**
 * @file
 * @brief Simple implementation of [modular multiplicative
 * inverse](https://en.wikipedia.org/wiki/Modular_multiplicative_inverse)
 *
 * @details
 * this algorithm calculates the modular inverse x^{-1} \mod y iteratively
 */

#include <cassert>   /// for assert
#include <cstdint>
#include <iostream>  /// for IO operations

/**
 * @brief Function imod
 * Calculates the modular inverse of x with respect to y, x^{-1} \mod y
 * @param x number
 * @param y number
 * @returns the modular inverse
 */
uint64_t imod(uint64_t x, uint64_t y) {
	std::cerr << "[ERROR] >>> Entering imod(x=" << x << ",y=" << y << ")" << std::endl;
    uint64_t aux = 0;  // auxiliary variable
    uint64_t itr = 0;  // iteration counter
	std::cerr << "[ERROR] imod(x=" << x << ",y=" << y << "): aux → " << aux << std::endl;

    do {  // run the algorithm while not find the inverse
        aux = y * itr + 1;
        itr++;
    } while (aux % x);  // while module aux % x non-zero

	std::cerr << "[WARN] <<< Exiting imod(x=" << x << ",y=" << y << ")" << std::endl;
    return aux / x;
}

/**
 * @brief  self-test implementations
 * @returns void
 */
static void test() {
	std::cerr << "[ERROR] >>> Entering test()" << std::endl;
    std::cout << "First case testing... \n";
    // for a = 3 and b = 11 return 4
    assert(imod(3, 11) == 4);
    std::cout << "\nPassed!\n";

    std::cout << "Second case testing... \n";
    // for a = 3 and b = 26 return 9
    assert(imod(3, 26) == 9);
    std::cout << "\nPassed!\n";

    std::cout << "Third case testing... \n";
    // for a = 7 and b = 26 return 15
    assert(imod(7, 26) == 15);
    std::cout << "\nPassed!\n";

    std::cout << "\nAll test cases have successfully passed!\n";
	std::cerr << "[WARN] <<< Exiting test()" << std::endl;
}
/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
    test();  // run self-test implementations
	std::cerr << "[WARN] <<< Exiting main()" << std::endl;
};
