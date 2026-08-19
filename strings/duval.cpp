/**
 * @file duval.cpp
 * @brief Implementation of [Duval's algorithm](https://en.wikipedia.org/wiki/Lyndon_word).
 *
 * @details
 * Duval's algorithm is an algorithm to find the lexicographically smallest
 * rotation of a string. It is based on the concept of Lyndon words.
 * Lyndon words are defined as the lexicographically smallest string in a
 * rotation equivalence class. A rotation equivalence class is a set of strings
 * that can be obtained by rotating a string. For example, the rotation
 * equivalence class of "abc" is {"abc", "bca", "cab"}. The lexicographically
 * smallest string in this class is "abc".
 *
 * Duval's algorithm works by iterating over the string and finding the
 * smallest rotation of the string that is a Lyndon word. This is done by
 * comparing the string with its suffixes and finding the smallest suffix that
 * is lexicographically smaller than the string. This suffix is then added to
 * the result and the process is repeated with the remaining string.
 * The algorithm has a time complexity of O(n) where n is the length of the
 * string.
 *
 * @note While Lyndon words are described in the context of strings,
 * Duval's algorithm can be used to find the lexicographically smallest cyclic
 * shift of any sequence of comparable elements.
 *
 * @author [Amine Ghoussaini](https://github.com/aminegh20)
*/

#include <array>    /// for std::array
#include <cassert>  /// for assert
#include <cstddef>  /// for std::size_t
#include <deque>    /// for std::deque
#include <iostream> /// for std::cout and std::endl
#include <string>   /// for std::string
#include <vector>   /// for std::vector

/**
 * @brief string manipulation algorithms
 * @namespace
 */
namespace string {
/**
 * @brief Find the lexicographically smallest cyclic shift of a sequence.
 * @tparam T type of the sequence
 * @param s the sequence
 * @returns the 0-indexed position of the least cyclic shift of the sequence
 */
template <typename T>
size_t duval(const T& s) {
	std::cerr << ">>> Entering duval(s=" << s << ")" << std::endl;
    size_t n = s.size();
    size_t i = 0, ans = 0;
	std::cerr << "duval(s=" << s << "): n → " << n << std::endl;
    while (i < n) {
        ans = i;
		std::cerr << "duval(s=" << s << "): ans → " << ans << std::endl;
        size_t j = i + 1, k = i;
        while (j < (n + n) && s[j % n] >= s[k % n]) {
            if (s[k % n] < s[j % n]) {
                k = i;
            } else {
                k++;
            }
            j++;
        }
        while (i <= k) {
            i += j - k;
        }
    }
	std::cerr << "<<< Exiting duval(s=" << s << ")" << std::endl;
    return ans;
    // returns 0-indexed position of the least cyclic shift
}

}  // namespace string

/**
 * @brief self test implementation
 * returns void
 */
static void test() {
	std::cerr << ">>> Entering test()" << std::endl;
    using namespace string;

    // Test 1
    std::string s1 = "abcab";
	std::cerr << "test(): s1 → " << s1 << std::endl;
    assert(duval(s1) == 3);

    // Test 2
    std::string s2 = "011100";
	std::cerr << "test(): s2 → " << s2 << std::endl;
    assert(duval(s2) == 4);

    // Test 3
    std::vector<int> v = {5, 2, 1, 3, 4};
    assert(duval(v) == 2);

    // Test 4
    std::array<int, 5> a = {1, 2, 3, 4, 5};
    assert(duval(a) == 0);

    // Test 5
    std::deque<char> d = {'a', 'z', 'c', 'a', 'b'};
	std::cerr << "test(): d → " << d << std::endl;
    assert(duval(d) == 3);

    // Test 6
    std::string s3;
    assert(duval(s3) == 0);

    // Test 7
    std::vector<int> v2 = {5, 2, 1, 3, -4};
    assert(duval(v2) == 4);

    std::cout << "All tests passed!" << std::endl;
	std::cerr << "<<< Exiting test()" << std::endl;
}

/**
 * @brief main function
 * @returns 0 on exit
 */
int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    test();  // run self test implementations
	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
