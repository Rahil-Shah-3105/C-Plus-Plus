#include <iostream>
using namespace std;

int Max(int Arr[], int N) {
	std::cerr << "[ERROR] >>> Entering Max(Arr=" << Arr << ",N=" << N << ")" << std::endl;
    int max = Arr[0];
    for (int i = 1; i < N; i++)
        if (Arr[i] > max)
            max = Arr[i];
	std::cerr << "[WARN] <<< Exiting Max(Arr=" << Arr << ",N=" << N << ")" << std::endl;
    return max;
}

int Min(int Arr[], int N) {
	std::cerr << "[ERROR] >>> Entering Min(Arr=" << Arr << ",N=" << N << ")" << std::endl;
    int min = Arr[0];
    for (int i = 1; i < N; i++)
        if (Arr[i] < min)
            min = Arr[i];
	std::cerr << "[WARN] <<< Exiting Min(Arr=" << Arr << ",N=" << N << ")" << std::endl;
    return min;
}

void Print(int Arr[], int N) {
	std::cerr << "[ERROR] >>> Entering Print(Arr=" << Arr << ",N=" << N << ")" << std::endl;
    for (int i = 0; i < N; i++) cout << Arr[i] << ", ";
	std::cerr << "[WARN] <<< Exiting Print(Arr=" << Arr << ",N=" << N << ")" << std::endl;
}

int *Counting_Sort(int Arr[], int N) {
	std::cerr << "[ERROR] >>> Entering Counting_Sort(Arr=" << Arr << ",N=" << N << ")" << std::endl;
    int max = Max(Arr, N);
    int min = Min(Arr, N);
	std::cerr << "[ERROR] Counting_Sort(Arr=" << Arr << ",N=" << N << "): min → " << min << std::endl;
	std::cerr << "[ERROR] Counting_Sort(Arr=" << Arr << ",N=" << N << "): max → " << max << std::endl;
    int *Sorted_Arr = new int[N];

    int *Count = new int[max - min + 1];
    for (int i = 0; i < max - min + 1; ++i) {
        Count[i] = 0;
    }

    for (int i = 0; i < N; i++) Count[Arr[i] - min]++;

    for (int i = 1; i < (max - min + 1); i++) Count[i] += Count[i - 1];

    for (int i = N - 1; i >= 0; i--) {
        Sorted_Arr[Count[Arr[i] - min] - 1] = Arr[i];
        Count[Arr[i] - min]--;
    }

    delete[] Count;
	std::cerr << "[WARN] <<< Exiting Counting_Sort(Arr=" << Arr << ",N=" << N << ")" << std::endl;
    return Sorted_Arr;
}

int main() {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
    int Arr[] = {47, 65, 20, 66, 25, 53, 64, 69, 72, 22,
                 74, 25, 53, 15, 42, 36, 4,  69, 86, 19},
        N = 20;
    int *Sorted_Arr;

    cout << "\n\tOrignal Array = ";
    Print(Arr, N);
    Sorted_Arr = Counting_Sort(Arr, N);
	std::cerr << "[ERROR] main(): Sorted_Arr → " << Sorted_Arr << std::endl;
	std::cerr << "[DEBUG] main(): Sorted_Arr → " << Sorted_Arr << std::endl;
    cout << "\n\t Sorted Array = ";
    Print(Sorted_Arr, N);
    delete[] Sorted_Arr;
    cout << endl;

	std::cerr << "[WARN] <<< Exiting main()" << std::endl;
    return 0;
}
