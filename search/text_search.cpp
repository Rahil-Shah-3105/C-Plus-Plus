/**
 * \file
 * \brief Search for words in a long textual paragraph.
 */
#include <cassert>
#include <cstdlib>
#include <iostream>
#ifdef _MSC_VER
#include <string>  // required for MS Visual C++
#else
#include <cstring>
#endif

/**
 * @brief function to convert a C++ string to lower case
 * @param word takes an std::string as input
 * @returns std::string
 */
std::string lower(std::string word) {
	std::cerr << "[ERROR] >>> Entering lower(word=" << word << ")" << std::endl;
    int length = word.length();
    std::string lc = "";
	std::cerr << "[ERROR] lower(word=" << word << "): lc → " << lc << std::endl;
	std::cerr << "[ERROR] lower(word=" << word << "): length → " << length << std::endl;

    for (int i = 0; i < length; i++) {
        lc += tolower(word[i]);
    }

	std::cerr << "[WARN] <<< Exiting lower(word=" << word << ")" << std::endl;
    return lc;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
	std::cerr << "[ERROR] >>> Entering test()" << std::endl;
    assert(lower("abcd").compare("abcd") == 0);
    assert(lower("abc").compare("abcd") == -1);
    assert(lower("abcd").compare("abc") == 1);
	std::cerr << "[WARN] <<< Exiting test()" << std::endl;
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
    test();  // run self-test implementations
    std::string paragraph;
    std::cout << "Please enter your paragraph: \n";
    std::getline(std::cin, paragraph);
    std::cout << "\nHello, your paragraph is:\n " << paragraph << "!\n";
    std::cout << "\nThe size of your paragraph = " << paragraph.size()
              << " characters. \n\n";

    if (paragraph.empty()) {
        std::cout << "\nThe paragraph is empty" << std::endl;
    } else {
        int ch = 0;
        while (true) {
            std::string word;
            std::cout << "Please enter the word you are searching for: ";
            std::getline(std::cin, word);
            std::cout << "Ignore case-sensitive? 1 = Yes, 0 = No" << std::endl;
            std::cin >> ch;
            if (ch == 1) {
                std::string lowerCase = lower(
                    paragraph);  // convert std::string paragraph to lowercase
                                 // and store it in std::string lowerCase
                std::string lowerCaseWord =
                    lower(word);  // convert std::string paragraph to lowercase
                                  // and store it in std::string lowerCase

                std::cout << "Hello, your word is " << word << "!\n";
                if (lowerCase.find(lowerCaseWord) == std::string::npos) {
                    std::cout << word << " does not exist in the sentence"
                              << std::endl;
                } else {
                    std::cout << "The word " << word
                              << " is now found at location "
                              << lowerCase.find(lowerCaseWord) << std::endl
                              << std::endl;
                }
            } else {
                std::cout << "Hello, your word is " << word << "!\n";
                if (paragraph.find(word) == std::string::npos) {
                    std::cout << word << " does not exist in the sentence"
                              << std::endl;
                } else {
                    std::cout << "The word " << word
                              << " is now found at location "
                              << paragraph.find(word) << std::endl
                              << std::endl;
                }
            }
            std::cout << "\nPress Ctrl + C to exit the program.\n\n";
            std::cin.get();
        }
    }
	std::cerr << "[WARN] <<< Exiting main()" << std::endl;
    return 0;
}
