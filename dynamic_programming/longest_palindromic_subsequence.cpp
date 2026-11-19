/**
 * @file
 * @brief Program to find the [Longest Palindormic
 * Subsequence](https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/) of a string
 *
 * @details
 * [Palindrome](https://en.wikipedia.org/wiki/Palindrome) string sequence of
 * characters which reads the same backward as forward
 * [Subsequence](https://en.wikipedia.org/wiki/Subsequence)  is a sequence that
 * can be derived from another sequence by deleting some or no elements without
 * changing the order of the remaining elements.

 * @author [Anjali Jha](https://github.com/anjali1903)
 */

#include "iostream"
#include <cassert>  /// for assert
#include <string>   /// for std::string
#include <vector>   /// for std::vector

/**
 * @namespace
 * @brief Dynamic Programming algorithms
 */
namespace dynamic_programming {
/**
 * @brief Function that returns the longest palindromic
 * subsequence of a string
 * @param a string whose longest palindromic subsequence is to be found
 * @returns longest palindromic subsequence of the string
 */
std::string lps(const std::string& a) {
	std::cerr << "[ERROR] >>> Entering lps(a=" << a << ")" << std::endl;
    const auto b = std::string(a.rbegin(), a.rend());
    const auto m = a.length();
	std::cerr << "[ERROR] lps(a=" << a << "): m → " << m << std::endl;
	std::cerr << "[ERROR] lps(a=" << a << "): b → " << b << std::endl;
    using ind_type = std::string::size_type;
    std::vector<std::vector<ind_type> > res(m + 1,
                                            std::vector<ind_type>(m + 1));

    // Finding the length of the longest
    // palindromic subsequence and storing
    // in a 2D array in bottoms-up manner
    for (ind_type i = 0; i <= m; i++) {
        for (ind_type j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                res[i][j] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                res[i][j] = res[i - 1][j - 1] + 1;
            } else {
                res[i][j] = std::max(res[i - 1][j], res[i][j - 1]);
            }
        }
    }
    // Length of longest palindromic subsequence
    auto idx = res[m][m];
    // Creating string of index+1 length
    std::string ans(idx, '\0');
    ind_type i = m, j = m;

    // starting from right-most bottom-most corner
    // and storing them one by one in ans
    while (i > 0 && j > 0) {
        // if current characters in a and b are same
        // then it is a part of the ans
        if (a[i - 1] == b[j - 1]) {
            ans[idx - 1] = a[i - 1];
            i--;
            j--;
            idx--;
        }
        // If they are not same, find the larger of the
        // two and move in that direction
        else if (res[i - 1][j] > res[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

	std::cerr << "[WARN] <<< Exiting lps(a=" << a << ")" << std::endl;
    return ans;
}
}  // namespace dynamic_programming

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
	std::cerr << "[ERROR] >>> Entering test()" << std::endl;
    assert(dynamic_programming::lps("radar") == "radar");
    assert(dynamic_programming::lps("abbcbaa") == "abcba");
    assert(dynamic_programming::lps("bbbab") == "bbbb");
    assert(dynamic_programming::lps("") == "");
	std::cerr << "[WARN] <<< Exiting test()" << std::endl;
}

/**
 * @brief Main Function
 * @returns 0 on exit
 */
int main() {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
    test();  // execute the tests
	std::cerr << "[WARN] <<< Exiting main()" << std::endl;
    return 0;
}
