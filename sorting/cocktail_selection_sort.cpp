// Returns Sorted elements after performing Cocktail Selection Sort
// It is a Sorting algorithm which chooses the minimum and maximum element in an
// array simultaneously, and swaps it with the lowest and highest available
// position iteratively or recursively

#include <algorithm>
#include <iostream>
#include <vector>

// Iterative Version

void CocktailSelectionSort(std::vector<int> *vec, int low, int high) {
	std::cerr << ">>> Entering CocktailSelectionSort(vec=" << vec << ",low=" << low << ",high=" << high << ")" << std::endl;
    while (low <= high) {
        int minimum = (*vec)[low];
		std::cerr << "CocktailSelectionSort(vec=" << vec << ",low=" << low << ",high=" << high << "): minimum → " << minimum << std::endl;
        int minimumindex = low;
		std::cerr << "CocktailSelectionSort(vec=" << vec << ",low=" << low << ",high=" << high << "): minimumindex → " << minimumindex << std::endl;
        int maximum = (*vec)[high];
		std::cerr << "CocktailSelectionSort(vec=" << vec << ",low=" << low << ",high=" << high << "): maximum → " << maximum << std::endl;
        int maximumindex = high;
		std::cerr << "CocktailSelectionSort(vec=" << vec << ",low=" << low << ",high=" << high << "): maximumindex → " << maximumindex << std::endl;

        for (int i = low; i <= high; i++) {
            if ((*vec)[i] >= maximum) {
                maximum = (*vec)[i];
                maximumindex = i;
            }
            if ((*vec)[i] <= minimum) {
                minimum = (*vec)[i];
                minimumindex = i;
            }
        }
        if (low != maximumindex || high != minimumindex) {
            std::swap((*vec)[low], (*vec)[minimumindex]);
            std::swap((*vec)[high], (*vec)[maximumindex]);
        } else {
            std::swap((*vec)[low], (*vec)[high]);
        }

        low++;
        high--;
    }
	std::cerr << "<<< Exiting CocktailSelectionSort(vec=" << vec << ",low=" << low << ",high=" << high << ")" << std::endl;
}

// Recursive Version

void CocktailSelectionSort_v2(std::vector<int> *vec, int low, int high) {
	std::cerr << ">>> Entering CocktailSelectionSort_v2(vec=" << vec << ",low=" << low << ",high=" << high << ")" << std::endl;
    if (low >= high)
        return;

    int minimum = (*vec)[low];
	std::cerr << "CocktailSelectionSort_v2(vec=" << vec << ",low=" << low << ",high=" << high << "): minimum → " << minimum << std::endl;
    int minimumindex = low;
	std::cerr << "CocktailSelectionSort_v2(vec=" << vec << ",low=" << low << ",high=" << high << "): minimumindex → " << minimumindex << std::endl;
    int maximum = (*vec)[high];
	std::cerr << "CocktailSelectionSort_v2(vec=" << vec << ",low=" << low << ",high=" << high << "): maximum → " << maximum << std::endl;
    int maximumindex = high;
	std::cerr << "CocktailSelectionSort_v2(vec=" << vec << ",low=" << low << ",high=" << high << "): maximumindex → " << maximumindex << std::endl;

    for (int i = low; i <= high; i++) {
        if ((*vec)[i] >= maximum) {
            maximum = (*vec)[i];
            maximumindex = i;
        }
        if ((*vec)[i] <= minimum) {
            minimum = (*vec)[i];
            minimumindex = i;
        }
    }
    if (low != maximumindex || high != minimumindex) {
        std::swap((*vec)[low], (*vec)[minimumindex]);
        std::swap((*vec)[high], (*vec)[maximumindex]);
    } else {
        std::swap((*vec)[low], (*vec)[high]);
    }

    CocktailSelectionSort(vec, low + 1, high - 1);
	std::cerr << "<<< Exiting CocktailSelectionSort_v2(vec=" << vec << ",low=" << low << ",high=" << high << ")" << std::endl;
}

// main function, select any one of iterative or recursive version

int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    int n;
    std::cout << "Enter number of elements\n";
    std::cin >> n;
    std::vector<int> v(n);
    std::cout << "Enter all the elements\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    int method;
    std::cout << "Enter method: \n\t0: iterative\n\t1: recursive:\t";
    std::cin >> method;

    if (method == 0) {
        CocktailSelectionSort(&v, 0, n - 1);
    } else if (method == 1) {
        CocktailSelectionSort_v2(&v, 0, n - 1);
    } else {
        std::cerr << "Unknown method" << std::endl;
        return -1;
    }
    std::cout << "Sorted elements are\n";
    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << " ";
    }

	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
