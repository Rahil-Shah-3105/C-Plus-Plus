/**
 * @file
 * @brief Compute the greatest common denominator of two integers using
 * *iterative form* of
 * [Euclidean algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm)
 *
 * @see gcd_recursive_euclidean.cpp, gcd_of_n_numbers.cpp
 */
#include <iostream>
#include <stdexcept>

/**
 * algorithm
 */
int gcd(int num1, int num2) {
	std::cerr << ">>> Entering gcd(num1=" << num1 << ",num2=" << num2 << ")" << std::endl;
    if (num1 <= 0 | num2 <= 0) {
		std::cerr << "Throwing std from gcd(num1=" << num1 << ",num2=" << num2 << ")" << std::endl;
        throw std::domain_error("Euclidean algorithm domain is for ints > 0");
    }

    if (num1 == num2) {
        return num1;
    }

    int base_num = 0;
	std::cerr << "gcd(num1=" << num1 << ",num2=" << num2 << "): base_num → " << base_num << std::endl;
    int previous_remainder = 1;
	std::cerr << "gcd(num1=" << num1 << ",num2=" << num2 << "): previous_remainder → " << previous_remainder << std::endl;

    if (num1 > num2) {
        base_num = num1;
        previous_remainder = num2;
    } else {
        base_num = num2;
        previous_remainder = num1;
    }

    while ((base_num % previous_remainder) != 0) {
        int old_base = base_num;
        base_num = previous_remainder;
        previous_remainder = old_base % previous_remainder;
    }

	std::cerr << "<<< Exiting gcd(num1=" << num1 << ",num2=" << num2 << ")" << std::endl;
    return previous_remainder;
}

/**
 * Main function
 */
int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    std::cout << "gcd of 120,7 is " << (gcd(120, 7)) << std::endl;
    try {
        std::cout << "gcd of -120,10 is " << gcd(-120, 10) << std::endl;
    } catch (const std::domain_error &e) {
		std::cerr << "Exception in main(): " << e.what() << std::endl;
        std::cout << "Error handling was successful" << std::endl;
    }
    std::cout << "gcd of 312,221 is " << (gcd(312, 221)) << std::endl;
    std::cout << "gcd of 289,204 is " << (gcd(289, 204)) << std::endl;

	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
