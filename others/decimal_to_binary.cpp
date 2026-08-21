/**
 * @file
 * @brief Function to convert decimal number to binary representation
 */
#include <iostream>

/**
 * This method converts the bit representation and stores it as a decimal
 * number.
 */
void method1(int number) {
	std::cerr << ">>> Entering method1(number=" << number << ")" << std::endl;
    int remainder, binary = 0, var = 1;

    do {
        remainder = number % 2;
		std::cerr << "method1(number=" << number << "): remainder → " << remainder << std::endl;
        number = number / 2;
        binary = binary + (remainder * var);
        var = var * 10;
		std::cerr << "method1(number=" << number << "): binary → " << binary << std::endl;
    } while (number > 0);
    std::cout << "Method 1 : " << binary << std::endl;
	std::cerr << "<<< Exiting method1(number=" << number << ")" << std::endl;
}

/**
 * This method stores each bit value from LSB to MSB and then prints them back
 * from MSB to LSB
 */
void method2(int number) {
	std::cerr << ">>> Entering method2(number=" << number << ")" << std::endl;
    int num_bits = 0;
    char bit_string[50];

    do {
        bool bit = number & 0x01;  // get last bit
        if (bit)
            bit_string[num_bits++] = '1';
        else
            bit_string[num_bits++] = '0';
        number >>= 1;  // right shift bit 1 bit
    } while (number > 0);

    std::cout << "Method 2 : ";
    while (num_bits >= 0)
        std::cout << bit_string[num_bits--];  // print from MSB to LSB
    std::cout << std::endl;
	std::cerr << "<<< Exiting method2(number=" << number << ")" << std::endl;
}

int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    int number;
    std::cout << "Enter a number:";
    std::cin >> number;

    method1(number);
    method2(number);

	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
