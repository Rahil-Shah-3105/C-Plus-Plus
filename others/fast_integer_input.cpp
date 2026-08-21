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
	std::cerr << ">>> Entering fastinput(number=" << number << ")" << std::endl;
    // variable to indicate sign of input integer
    bool negative = false;
	std::cerr << "fastinput(number=" << number << "): negative → " << negative << std::endl;
    int c;
    *number = 0;

    // extract current character from buffer
    c = std::getchar();
	std::cerr << "fastinput(number=" << number << "): c → " << c << std::endl;
    if (c == '-') {
        // number is negative
        negative = true;

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
		std::cerr << "<<< Exiting fastinput(number=" << number << ")" << std::endl;
}

/** Main function */
int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    int number;
    fastinput(&number);
    std::cout << number << std::endl;
	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
