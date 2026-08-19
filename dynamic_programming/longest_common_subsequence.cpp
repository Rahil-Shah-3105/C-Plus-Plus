// Longest common subsequence - Dynamic Programming
#include <iostream>
#include <vector>
using namespace std;

void Print(int trace[20][20], int m, int n, string a) {
	std::cerr << ">>> Entering Print(trace=" << trace << ",m=" << m << ",n=" << n << ",a=" << a << ")" << std::endl;
    if (m == 0 || n == 0) {
        return;
    }
    if (trace[m][n] == 1) {
        Print(trace, m - 1, n - 1, a);
        cout << a[m - 1];
    } else if (trace[m][n] == 2) {
        Print(trace, m - 1, n, a);
    } else if (trace[m][n] == 3) {
        Print(trace, m, n - 1, a);
    }
	std::cerr << "<<< Exiting Print(trace=" << trace << ",m=" << m << ",n=" << n << ",a=" << a << ")" << std::endl;
}

int lcs(string a, string b) {
	std::cerr << ">>> Entering lcs(a=" << a << ",b=" << b << ")" << std::endl;
    int m = a.length(), n = b.length();
    std::vector<std::vector<int> > res(m + 1, std::vector<int>(n + 1));
	std::cerr << "lcs(a=" << a << ",b=" << b << "): m → " << m << std::endl;
    int trace[20][20];

    // fills up the arrays with zeros.
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            res[i][j] = 0;
            trace[i][j] = 0;
        }
    }

    for (int i = 0; i < m + 1; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            if (i == 0 || j == 0) {
                res[i][j] = 0;
                trace[i][j] = 0;
            }

            else if (a[i - 1] == b[j - 1]) {
                res[i][j] = 1 + res[i - 1][j - 1];
                trace[i][j] = 1;  // 1 means trace the matrix in upper left
                                  // diagonal direction.
            } else {
                if (res[i - 1][j] > res[i][j - 1]) {
                    res[i][j] = res[i - 1][j];
                    trace[i][j] =
                        2;  // 2 means trace the matrix in upwards direction.
                } else {
                    res[i][j] = res[i][j - 1];
                    trace[i][j] =
                        3;  //  means trace the matrix in left direction.
                }
            }
        }
    }
    Print(trace, m, n, a);
	std::cerr << "<<< Exiting lcs(a=" << a << ",b=" << b << ")" << std::endl;
    return res[m][n];
}

int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    string a, b;
    cin >> a >> b;
    cout << lcs(a, b);
	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
