/**
 * @file
 * @brief Pascal's triangle implementation
 */
#ifdef _MSC_VER
#include <string>  // required for Visual C
#else
#include <cstring>
#endif
#include <iomanip>
#include <iostream>

/**
 * Print the triangle
 * \param [in] arr  2D-array containing Pascal numbers
 * \param [in] n    depth of Pascal triangle to print
 */
void show_pascal(int **arr, int n) {
	std::cerr << ">>> Entering show_pascal(arr=" << arr << ",n=" << n << ")" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n + i; ++j) {
            if (arr[i][j] == 0)
                std::cout << std::setw(4) << " ";
            else
                std::cout << std::setw(4) << arr[i][j];
        }
        std::cout << std::endl;
    }
	std::cerr << "<<< Exiting show_pascal(arr=" << arr << ",n=" << n << ")" << std::endl;
}

/**
 * Print the triangle
 * \param [in,out] arr  array containing Pascal numbers
 * \param [in] n    depth of Pascal triangle to print
 * \result arr pointer returned
 */
int **pascal_triangle(int **arr, int n) {
	std::cerr << ">>> Entering pascal_triangle(arr=" << arr << ",n=" << n << ")" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = n - i - 1; j < n + i; ++j) {
            if (j == n - i - 1 || j == n + i - 1)
                arr[i][j] = 1;  // The edge of the Pascal triangle goes in 1
            else
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
        }
    }

	std::cerr << "<<< Exiting pascal_triangle(arr=" << arr << ",n=" << n << ")" << std::endl;
    return arr;
}

/**
 * main function
 */
int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    int n = 0;

    std::cout << "Set Pascal's Triangle Height" << std::endl;
    std::cin >> n;

    // memory allocation (Assign two-dimensional array to store Pascal triangle)
    int **arr = new int *[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[2 * n - 1];
        memset(arr[i], 0, sizeof(int) * (2 * n - 1));
    }

    pascal_triangle(arr, n);
    show_pascal(arr, n);

    // deallocation
    for (int i = 0; i < n; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
