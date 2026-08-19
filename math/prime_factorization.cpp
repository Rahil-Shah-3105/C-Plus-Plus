/**
 * @file
 * @brief Prime factorization of positive integers
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

/** Declaring variables for maintaing prime numbers and to check whether a
 * number is prime or not
 */
bool isprime[1000006];

/** list of prime numbers */
std::vector<int> prime_numbers;

/** list of prime factor-pairs */
std::vector<std::pair<int, int>> factors;

/** Calculating prime number upto a given range
 */
void SieveOfEratosthenes(int N) {
	std::cerr << ">>> Entering SieveOfEratosthenes(N=" << N << ")" << std::endl;
    // initializes the array isprime
    memset(isprime, true, sizeof isprime);

    for (int i = 2; i <= N; i++) {
        if (isprime[i]) {
            for (int j = 2 * i; j <= N; j += i) isprime[j] = false;
        }
    }

    for (int i = 2; i <= N; i++) {
        if (isprime[i])
            prime_numbers.push_back(i);
    }
	std::cerr << "<<< Exiting SieveOfEratosthenes(N=" << N << ")" << std::endl;
}

/** Prime factorization of a number */
void prime_factorization(int num) {
	std::cerr << ">>> Entering prime_factorization(num=" << num << ")" << std::endl;
    int number = num;

	std::cerr << "prime_factorization(num=" << num << "): number → " << number << std::endl;
    for (int i = 0; prime_numbers[i] <= num; i++) {
        int count = 0;
		std::cerr << "prime_factorization(num=" << num << "): count → " << count << std::endl;

        // termination condition
        if (number == 1) {
            break;
        }

        while (number % prime_numbers[i] == 0) {
            count++;
            number = number / prime_numbers[i];
        }

        if (count)
            factors.push_back(std::make_pair(prime_numbers[i], count));
    }
	std::cerr << "<<< Exiting prime_factorization(num=" << num << ")" << std::endl;
}

/** Main program */
int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    int num;
    std::cout << "\t\tComputes the prime factorization\n\n";
    std::cout << "Type in a number: ";
    std::cin >> num;

    SieveOfEratosthenes(num);

    prime_factorization(num);

    // Prime factors with their powers in the given number in new line
    for (auto it : factors) {
        std::cout << it.first << " " << it.second << std::endl;
    }

	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
