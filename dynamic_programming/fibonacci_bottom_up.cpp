#include <iostream>
using namespace std;
int fib(int n) {
	std::cerr << "[ERROR] >>> Entering fib(n=" << n << ")" << std::endl;
    int res[3];
    res[0] = 0;
    res[1] = 1;
    for (int i = 2; i <= n; i++) {
        res[2] = res[1] + res[0];
        res[0] = res[1];
        res[1] = res[2];
    }
	std::cerr << "[WARN] <<< Exiting fib(n=" << n << ")" << std::endl;
    return res[1];
}
int main() {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Fibonacci number is ";
    cout << fib(n) << endl;
	std::cerr << "[WARN] <<< Exiting main()" << std::endl;
    return 0;
}
