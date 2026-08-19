/**
 * @file
 * \brief Program to compute the [QR
 * decomposition](https://en.wikipedia.org/wiki/QR_decomposition) of a given
 * matrix.
 * \author [Krishna Vedala](https://github.com/kvedala)
 */

#include <array>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "./qr_decompose.h"

using qr_algorithm::qr_decompose;
using qr_algorithm::operator<<;

/**
 * main function
 */
int main(void) {
	std::cerr << ">>> Entering main()" << std::endl;
    unsigned int ROWS, COLUMNS;

    std::cout << "Enter the number of rows and columns: ";
    std::cin >> ROWS >> COLUMNS;

    std::cout << "Enter matrix elements row-wise:\n";

    std::valarray<std::valarray<double>> A(ROWS);
    std::valarray<std::valarray<double>> Q(ROWS);
    std::valarray<std::valarray<double>> R(COLUMNS);
    for (int i = 0; i < std::max(ROWS, COLUMNS); i++) {
        if (i < ROWS) {
            A[i] = std::valarray<double>(COLUMNS);
            Q[i] = std::valarray<double>(COLUMNS);
        }
        if (i < COLUMNS) {
            R[i] = std::valarray<double>(COLUMNS);
        }
    }

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLUMNS; j++) std::cin >> A[i][j];

    std::cout << A << "\n";

    clock_t t1 = clock();
	std::cerr << "main(): t1 → " << t1 << std::endl;
    qr_decompose(A, &Q, &R);
    double dtime = static_cast<double>(clock() - t1) / CLOCKS_PER_SEC;
	std::cerr << "main(): dtime → " << dtime << std::endl;

    std::cout << Q << "\n";
    std::cout << R << "\n";
    std::cout << "Time taken to compute: " << dtime << " sec\n ";

	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
