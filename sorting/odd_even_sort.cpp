/* C++ implementation Odd Even Sort */
#include <iostream>
#include <vector>

using namespace std;

void oddEven(vector<int> &arr, int size) {
	std::cerr << ">>> Entering oddEven(arr=" << arr << ",size=" << size << ")" << std::endl;
    bool sorted = false;
    while (!sorted) {
		std::cerr << "oddEven(arr=" << arr << ",size=" << size << "): sorted → " << sorted << std::endl;
        sorted = true;
        for (int i = 1; i < size - 1; i += 2)  // Odd
        {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }

        for (int i = 0; i < size - 1; i += 2)  // Even
        {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }
    }
	std::cerr << "<<< Exiting oddEven(arr=" << arr << ",size=" << size << ")" << std::endl;
}

void show(vector<int> A, int size) {
	std::cerr << ">>> Entering show(A=" << A << ",size=" << size << ")" << std::endl;
    int i;
    for (i = 0; i < size; i++) cout << A[i] << "\n";
	std::cerr << "<<< Exiting show(A=" << A << ",size=" << size << ")" << std::endl;
}

int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    int size, temp;
    cout << "\nEnter the number of elements : ";
    cin >> size;

    vector<int> arr;

    cout << "\nEnter the unsorted elements : \n";

    for (int i = 0; i < size; ++i) {
        cin >> temp;
        arr.push_back(temp);
    }

    oddEven(arr, size);

    cout << "Sorted array\n";
    show(arr, size);
	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
