// C++ program to sort an array using bucket sort
#include <algorithm>
#include <iostream>
#include <vector>

// Function to sort arr[] of size n using bucket sort
void bucketSort(float arr[], int n) {
	std::cerr << "[ERROR] >>> Entering bucketSort(arr=" << arr << ",n=" << n << ")" << std::endl;
    // 1) Create n empty buckets
    std::vector<float> *b = new std::vector<float>[n];

    // 2) Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];  // Index in bucket
        b[bi].push_back(arr[i]);
    }

    // 3) Sort individual buckets
    for (int i = 0; i < n; i++) std::sort(b[i].begin(), b[i].end());

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++) arr[index++] = b[i][j];
    delete[] b;
	std::cerr << "[WARN] <<< Exiting bucketSort(arr=" << arr << ",n=" << n << ")" << std::endl;
}

/* Driver program to test above funtion */
int main() {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
	std::cerr << "[ERROR] main(): n → " << n << std::endl;
    bucketSort(arr, n);

    std::cout << "Sorted array is \n";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
	std::cerr << "[WARN] <<< Exiting main()" << std::endl;
    return 0;
}
