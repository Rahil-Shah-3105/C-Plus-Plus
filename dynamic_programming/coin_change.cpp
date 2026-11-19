#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// Function to find the Minimum number of coins required to get Sum S
int findMinCoins(int arr[], int n, int N) {
	std::cerr << "[ERROR] >>> Entering findMinCoins(arr=" << arr << ",n=" << n << ",N=" << N << ")" << std::endl;
    // dp[i] = no of coins required to get a total of i
    std::vector<int> dp(N + 1);

    // 0 coins are needed for 0 sum

    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        // initialize minimum number of coins needed to infinity
        dp[i] = INT_MAX;
        int res = INT_MAX;
		std::cerr << "[ERROR] findMinCoins(arr=" << arr << ",n=" << n << ",N=" << N << "): res → " << res << std::endl;

        // do for each coin
        for (int c = 0; c < n; c++) {
            if (i - arr[c] >=
                0)  // check if coins doesn't become negative by including it
                res = dp[i - arr[c]];

            // if total can be reached by including current coin c,
            // update minimum number of coins needed dp[i]
            if (res != INT_MAX)
                dp[i] = min(dp[i], res + 1);
        }
    }

    // The Minimum No of Coins Required for N = dp[N]
	std::cerr << "[WARN] <<< Exiting findMinCoins(arr=" << arr << ",n=" << n << ",N=" << N << ")" << std::endl;
    return dp[N];
}

int main() {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
    // No of Coins We Have
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
	std::cerr << "[ERROR] main(): n → " << n << std::endl;

    // Total Change Required
    int N = 15;

    cout << "Minimum Number of Coins Required " << findMinCoins(arr, n, N)
         << "\n";

	std::cerr << "[WARN] <<< Exiting main()" << std::endl;
    return 0;
}