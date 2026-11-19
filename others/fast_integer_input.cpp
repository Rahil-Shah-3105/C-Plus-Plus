/**
 * @file
 * @brief Read integers from stdin continuously as they are entered without
 * waiting for the `\n` character
 */
#include <iostream>

/** Function to read the number from stdin. The function reads input until a non
 * numeric character is entered.
 */
void fastinput(int *number) {
	std::cerr << "[ERROR] >>> Entering fastinput(number=" << number << ")" << std::endl;
    // variable to indicate sign of input integer
    bool negative = false;
    int c;
    *number = 0;

    // extract current character from buffer
    c = std::getchar();
	std::cerr << "[ERROR] fastinput(number=" << number << "): c → " << c << std::endl;
    if (c == '-') {
        // number is negative
        negative = true;
		std::cerr << "[ERROR] fastinput(number=" << number << "): negative → " << negative << std::endl;

        // extract the next character from the buffer
        c = std::getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c > 47 && c < 58); c = std::getchar())
        *number = *number * 10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        *(number) *= -1;
		std::cerr << "[WARN] <<< Exiting fastinput(number=" << number << ")" << std::endl;
}

/** Main function */
int main() {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
    int number;
    fastinput(&number);
    std::cout << number << std::endl;
	std::cerr << "[WARN] <<< Exiting main()" << std::endl;
    return 0;
}
