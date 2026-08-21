#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>

void radixsort(int a[], int n) {
	std::cerr << ">>> Entering radixsort(a=" << a << ",n=" << n << ")" << std::endl;
    int count[10];
    int* output = new int[n];
    memset(output, 0, n * sizeof(*output));
    memset(count, 0, sizeof(count));
    int max = 0;
	std::cerr << "radixsort(a=" << a << ",n=" << n << "): max → " << max << std::endl;
    for (int i = 0; i < n; ++i) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    int maxdigits = 0;
    while (max) {
        maxdigits++;
        max /= 10;
    }
    for (int j = 0; j < maxdigits; j++) {
        for (int i = 0; i < n; i++) {
            int t = std::pow(10, j);
			std::cerr << "radixsort(a=" << a << ",n=" << n << "): t → " << t << std::endl;
            count[(a[i] % (10 * t)) / t]++;
        }
        int k = 0;
        for (int p = 0; p < 10; p++) {
            for (int i = 0; i < n; i++) {
                int t = std::pow(10, j);
                if ((a[i] % (10 * t)) / t == p) {
                    output[k] = a[i];
                    k++;
                }
            }
        }
        memset(count, 0, sizeof(count));
        for (int i = 0; i < n; ++i) {
            a[i] = output[i];
        }
    }
    delete[] output;
	std::cerr << "<<< Exiting radixsort(a=" << a << ",n=" << n << ")" << std::endl;
}

void print(int a[], int n) {
	std::cerr << ">>> Entering print(a=" << a << ",n=" << n << ")" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
	std::cerr << "<<< Exiting print(a=" << a << ",n=" << n << ")" << std::endl;
}

int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    int a[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(a) / sizeof(a[0]);
	std::cerr << "main(): n → " << n << std::endl;
    radixsort(a, n);
    print(a, n);
	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
