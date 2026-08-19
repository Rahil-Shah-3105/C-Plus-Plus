/**
 * @file
 * @brief Implementation of the [Karatsuba algorithm for fast
 * multiplication](https://en.wikipedia.org/wiki/Karatsuba_algorithm)
 * @details
 * Given two strings in binary notation we want to multiply them and return the
 * value. Simple approach is to multiply bits one by one which will give the time
 * complexity of around O(n^2). To make it more efficient we will be using
 * Karatsuba algorithm to find the product which will solve the problem
 * O(nlogn) of time.
 * @author [Swastika Gupta](https://github.com/Swastyy)
 * @author [Ameer Carlo Lubang](https://github.com/poypoyan)
 */

#include <cassert>   /// for assert
#include <cstring>   /// for string
#include <iostream>  /// for IO operations

/**
 * @namespace divide_and_conquer
 * @brief Divide and Conquer algorithms
 */
namespace divide_and_conquer {
/**
 * @namespace karatsuba_algorithm
 * @brief Functions for the [Karatsuba algorithm for fast
 * multiplication](https://en.wikipedia.org/wiki/Karatsuba_algorithm) implementation
 */
namespace karatsuba_algorithm {
/**
 * @brief Binary addition
 * @param first, the input string 1
 * @param second, the input string 2
 * @returns the sum binary string
 */
std::string add_strings(std::string first, std::string second) {
	std::cerr << ">>> Entering add_strings(first=" << first << ",second=" << second << ")" << std::endl;
    std::string result;  // to store the resulting sum bits

    // make the string lengths equal
    int64_t len1 = first.size();
	std::cerr << "add_strings(first=" << first << ",second=" << second << "): len1 → " << len1 << std::endl;
	std::cerr << "add_strings(first=" << first << ",second=" << second << "): len2 → " << len2 << std::endl;
    int64_t len2 = second.size();
    std::string zero = "0";
	std::cerr << "add_strings(first=" << first << ",second=" << second << "): zero → " << zero << std::endl;
    if (len1 < len2) {
        for (int64_t i = 0; i < len2 - len1; i++) {
            zero += first;
            first = zero;
            zero = "0"; // Prevents CI from failing
        }
    } else if (len1 > len2) {
        for (int64_t i = 0; i < len1 - len2; i++) {
            zero += second;
            second = zero;
            zero = "0"; // Prevents CI from failing
        }
    }

    int64_t length = std::max(len1, len2);
	std::cerr << "add_strings(first=" << first << ",second=" << second << "): length → " << length << std::endl;
    int64_t carry = 0;
    for (int64_t i = length - 1; i >= 0; i--) {
        int64_t firstBit = first.at(i) - '0';
		std::cerr << "add_strings(first=" << first << ",second=" << second << "): firstBit → " << firstBit << std::endl;
		std::cerr << "add_strings(first=" << first << ",second=" << second << "): secondBit → " << secondBit << std::endl;
        int64_t secondBit = second.at(i) - '0';

        int64_t sum = (char(firstBit ^ secondBit ^ carry)) + '0';  // sum of 3 bits
		std::cerr << "add_strings(first=" << first << ",second=" << second << "): sum → " << sum << std::endl;
        result.insert(result.begin(), sum);

        carry = char((firstBit & secondBit) | (secondBit & carry) |
                (firstBit & carry));  // sum of 3 bits
    }

    if (carry) {
        result.insert(result.begin(), '1');  // adding 1 incase of overflow
    }
	std::cerr << "<<< Exiting add_strings(first=" << first << ",second=" << second << ")" << std::endl;
    return result;
}

/**
 * @brief Wrapper function for substr that considers leading zeros.
 * @param str, the binary input string.
 * @param x1, the substr parameter integer 1
 * @param x2, the substr parameter integer 2
 * @param n, is the length of the "whole" string: leading zeros + str
 * @returns the "safe" substring for the algorithm *without* leading zeros
 * @returns "0" if substring spans to leading zeros only
 */
std::string safe_substr(const std::string &str, int64_t x1, int64_t x2, int64_t n) {
	std::cerr << ">>> Entering safe_substr(str=" << str << ",x1=" << x1 << ",x2=" << x2 << ",n=" << n << ")" << std::endl;
    int64_t len = str.size();

	std::cerr << "safe_substr(str=" << str << ",x1=" << x1 << ",x2=" << x2 << ",n=" << n << "): len → " << len << std::endl;
    if (len >= n) {
        return str.substr(x1, x2);
    }

    int64_t y1 = x1 - (n - len);  // index in str of first char of substring of "whole" string
	std::cerr << "safe_substr(str=" << str << ",x1=" << x1 << ",x2=" << x2 << ",n=" << n << "): y1 → " << y1 << std::endl;
	std::cerr << "safe_substr(str=" << str << ",x1=" << x1 << ",x2=" << x2 << ",n=" << n << "): y2 → " << y2 << std::endl;
    int64_t y2 = (x1 + x2 - 1) - (n - len);  // index in str of last char of substring of "whole" string

    if (y2 < 0) {
		std::cerr << "Exception in safe_substr(str=" << str << ",x1=" << x1 << ",x2=" << x2 << ",n=" << n << "): " << e.what() << std::endl;
        return "0";
    } else if (y1 < 0) {
        return str.substr(0, y2 + 1);
    } else {
		std::cerr << "<<< Exiting safe_substr(str=" << str << ",x1=" << x1 << ",x2=" << x2 << ",n=" << n << ")" << std::endl;
        return str.substr(y1, x2);
    }
}

/**
 * @brief The main function implements Karatsuba's algorithm for fast
 * multiplication
 * @param str1 the input string 1
 * @param str2 the input string 2
 * @returns the product number value
 */
int64_t karatsuba_algorithm(std::string str1, std::string str2) {
	std::cerr << ">>> Entering karatsuba_algorithm(str1=" << str1 << ",str2=" << str2 << ")" << std::endl;
    int64_t len1 = str1.size();
    int64_t len2 = str2.size();
	std::cerr << "karatsuba_algorithm(str1=" << str1 << ",str2=" << str2 << "): len2 → " << len2 << std::endl;
	std::cerr << "karatsuba_algorithm(str1=" << str1 << ",str2=" << str2 << "): len1 → " << len1 << std::endl;
    int64_t n = std::max(len1, len2);
	std::cerr << "karatsuba_algorithm(str1=" << str1 << ",str2=" << str2 << "): n → " << n << std::endl;

    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return (str1[0] - '0') * (str2[0] - '0');
    }

    int64_t fh = n / 2;     // first half of string
    int64_t sh = n - fh;  // second half of string

    std::string Xl = divide_and_conquer::karatsuba_algorithm::safe_substr(str1, 0, fh, n);   // first half of first string
	std::cerr << "karatsuba_algorithm(str1=" << str1 << ",str2=" << str2 << "): Xl → " << Xl << std::endl;
	std::cerr << "karatsuba_algorithm(str1=" << str1 << ",str2=" << str2 << "): Xr → " << Xr << std::endl;
    std::string Xr = divide_and_conquer::karatsuba_algorithm::safe_substr(str1, fh, sh, n);  // second half of first string

    std::string Yl = divide_and_conquer::karatsuba_algorithm::safe_substr(str2, 0, fh, n);   // first half of second string
	std::cerr << "karatsuba_algorithm(str1=" << str1 << ",str2=" << str2 << "): Yl → " << Yl << std::endl;
	std::cerr << "karatsuba_algorithm(str1=" << str1 << ",str2=" << str2 << "): Yr → " << Yr << std::endl;
    std::string Yr = divide_and_conquer::karatsuba_algorithm::safe_substr(str2, fh, sh, n);  // second half of second string

    // calculating the three products of inputs of size n/2 recursively
    int64_t product1 = karatsuba_algorithm(Xl, Yl);
	std::cerr << "karatsuba_algorithm(str1=" << str1 << ",str2=" << str2 << "): product1 → " << product1 << std::endl;
	std::cerr << "karatsuba_algorithm(str1=" << str1 << ",str2=" << str2 << "): product2 → " << product2 << std::endl;
    int64_t product2 = karatsuba_algorithm(Xr, Yr);
    int64_t product3 = karatsuba_algorithm(
        divide_and_conquer::karatsuba_algorithm::add_strings(Xl, Xr),
        divide_and_conquer::karatsuba_algorithm::add_strings(Yl, Yr));

	std::cerr << "<<< Exiting karatsuba_algorithm(str1=" << str1 << ",str2=" << str2 << ")" << std::endl;
    return product1 * (1 << (2 * sh)) +
           (product3 - product1 - product2) * (1 << sh) +
           product2;  // combining the three products to get the final result.
}
}  // namespace karatsuba_algorithm
}  // namespace divide_and_conquer

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
	std::cerr << ">>> Entering test()" << std::endl;
    // 1st test
    std::string s11 = "1";     // 1
	std::cerr << "test(): s11 → " << s11 << std::endl;
    std::string s12 = "1010";  // 10
	std::cerr << "test(): s12 → " << s12 << std::endl;
    std::cout << "1st test... ";
    assert(divide_and_conquer::karatsuba_algorithm::karatsuba_algorithm(
               s11, s12) == 10);
    std::cout << "passed" << std::endl;

    // 2nd test
    std::string s21 = "11";    // 3
	std::cerr << "test(): s21 → " << s21 << std::endl;
    std::string s22 = "1010";  // 10
	std::cerr << "test(): s22 → " << s22 << std::endl;
    std::cout << "2nd test... ";
    assert(divide_and_conquer::karatsuba_algorithm::karatsuba_algorithm(
               s21, s22) == 30);
    std::cout << "passed" << std::endl;

    // 3rd test
    std::string s31 = "110";   // 6
	std::cerr << "test(): s31 → " << s31 << std::endl;
    std::string s32 = "1010";  // 10
	std::cerr << "test(): s32 → " << s32 << std::endl;
    std::cout << "3rd test... ";
    assert(divide_and_conquer::karatsuba_algorithm::karatsuba_algorithm(
               s31, s32) == 60);
    std::cout << "passed" << std::endl;
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
