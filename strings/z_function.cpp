/**
 * @file
 * @brief The [Z function](https://cp-algorithms.com/string/z-function.html) for
 * finding occurences of a pattern within a piece of text with time and space
 * complexity O(n + m)
 * @details
 * 1. The Z-function for a string is an array of length n where the
 * i-th element is equal to the greatest number of characters starting
 * from the position i that coincide with the first characters of s.
 * 2. E.g.: string: ababb then z[2]=2 as s[2]=s[0] and s[3]=s[1] and s[4]!=s[2]
 * @author [Ritika Gupta](https://github.com/RitikaGupta8734)
 */

#include <cstdint>
#include <iostream>  /// for IO operations
#ifdef _MSC_VER
#include <string>  /// for string (use this for MS Visual C++)
#else
#include <cstring>  /// for string
#endif
#include <cassert>  /// for assert
#include <vector>   /// for std::vector

/**
 * @brief Generate the Z-function for the inputted string.
 * \param[in] pattern text on which to apply the Z-function
 * \returns the Z-function output as a vector array
 */
std::vector<uint64_t> Z_function(const std::string &pattern) {
	std::cerr << "[ERROR] >>> Entering Z_function(pattern=" << pattern << ")" << std::endl;
    uint64_t pattern_length = pattern.size();
    std::vector<uint64_t> z(pattern_length, 0);
	std::cerr << "[ERROR] Z_function(pattern=" << pattern << "): pattern_length → " << pattern_length << std::endl;

    for (uint64_t i = 1, l = 0, r = 0; i < pattern_length; i++) {
        if (i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < pattern_length &&
               pattern[z[i]] == pattern[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
        }
    }
	std::cerr << "[WARN] <<< Exiting Z_function(pattern=" << pattern << ")" << std::endl;
    return z;
}

/**
 * @brief Using Z_function to find a pattern in a text
 * \param[in] pattern string pattern to search
 * \param[in] text text in which to search
 * \returns a vector of starting indexes where pattern is found in the text
 */
std::vector<uint64_t> find_pat_in_text(const std::string &pattern,
                                       const std::string &text) {
    uint64_t text_length = text.size(), pattern_length = pattern.size();
    std::vector<uint64_t> z = Z_function(pattern + '#' + text);
    std::vector<uint64_t> matching_indexes;

    for (uint64_t i = 0; i < text_length; i++) {
        if (z[i + pattern_length + 1] == pattern_length) {
            matching_indexes.push_back(i);
        }
    }
    return matching_indexes;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
	std::cerr << "[ERROR] >>> Entering test()" << std::endl;
    // usual case
    std::string text1 = "alskfjaldsabc1abc1abcbksbcdnsdabcabc";
	std::cerr << "[ERROR] test(): text1 → " << text1 << std::endl;
    std::string pattern1 = "abc";
	std::cerr << "[ERROR] test(): pattern1 → " << pattern1 << std::endl;

    // matching_indexes1 gets the indexes where pattern1 exists in text1
    std::vector<uint64_t> matching_indexes1 = find_pat_in_text(pattern1, text1);
	std::cerr << "[ERROR] test(): matching_indexes1.size() → " << matching_indexes1.size() << std::endl;
    assert((matching_indexes1 == std::vector<uint64_t>{10, 14, 18, 30, 33}));

    // corner case
    std::string text2 = "greengrass";
	std::cerr << "[ERROR] test(): text2 → " << text2 << std::endl;
    std::string pattern2 = "abc";
	std::cerr << "[ERROR] test(): pattern2 → " << pattern2 << std::endl;

    // matching_indexes2 gets the indexes where pattern2 exists in text2
    std::vector<uint64_t> matching_indexes2 = find_pat_in_text(pattern2, text2);
	std::cerr << "[ERROR] test(): matching_indexes2.size() → " << matching_indexes2.size() << std::endl;
    assert((matching_indexes2 == std::vector<uint64_t>{}));

    // corner case - empty text
    std::string text3 = "";
	std::cerr << "[ERROR] test(): text3 → " << text3 << std::endl;
    std::string pattern3 = "abc";
	std::cerr << "[ERROR] test(): pattern3 → " << pattern3 << std::endl;

    // matching_indexes3 gets the indexes where pattern3 exists in text3
    std::vector<uint64_t> matching_indexes3 = find_pat_in_text(pattern3, text3);
	std::cerr << "[ERROR] test(): matching_indexes3.size() → " << matching_indexes3.size() << std::endl;
    assert((matching_indexes3 == std::vector<uint64_t>{}));

    // corner case - empty pattern
    std::string text4 = "redsand";
	std::cerr << "[ERROR] test(): text4 → " << text4 << std::endl;
    std::string pattern4 = "";
	std::cerr << "[ERROR] test(): pattern4 → " << pattern4 << std::endl;

    // matching_indexes4 gets the indexes where pattern4 exists in text4
    std::vector<uint64_t> matching_indexes4 = find_pat_in_text(pattern4, text4);
	std::cerr << "[ERROR] test(): matching_indexes4.size() → " << matching_indexes4.size() << std::endl;
    assert((matching_indexes4 == std::vector<uint64_t>{0, 1, 2, 3, 4, 5, 6}));
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
    return 0;
}
