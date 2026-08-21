/**
 * @file
 * @brief Solve the [Tower of
 * Hanoi](https://en.wikipedia.org/wiki/Tower_of_Hanoi) problem.
 */
#include <iostream>

/**
 * Define the state of tower
 */
struct tower {
    //! Values in the tower
    int values[10];
    //! top tower ID
    int top;
};

/** Display the towers */
void show(const struct tower *const F, const struct tower *const T,
          const struct tower *const U) {
    std::cout << "\n\n\tF : ";
    for (int i = 0; i < F->top; i++) {
        std::cout << F->values[i] << "\t";
    }
    std::cout << "\n\tU : ";
    for (int i = 0; i < U->top; i++) {
        std::cout << U->values[i] << "\t";
    }
    std::cout << "\n\tT : ";
    for (int i = 0; i < T->top; i++) {
        std::cout << T->values[i] << "\t";
    }
}

/** Move one disc from one tower to another
 * \param [in,out] From tower to move disk *from*
 * \param [in,out] To  tower to move disk *to*
 */
void mov(tower *From, tower *To) {
	std::cerr << ">>> Entering mov(From=" << From << ",To=" << To << ")" << std::endl;
    --From->top;
    To->values[To->top] = From->values[From->top];
    ++To->top;
	std::cerr << "<<< Exiting mov(From=" << From << ",To=" << To << ")" << std::endl;
}

/**
 * Recursive algorithm to solve the puzzle
 * \param [in] n starting number of disks
 * \param [in,out] From  tower to move disks from
 * \param [in,out] Using temporary tower for the puzzle
 * \param [in,out] To  tower to move disk to
 */
void TH(int n, tower *From, tower *Using, tower *To) {
	std::cerr << ">>> Entering TH(n=" << n << ",From=" << From << ",Using=" << Using << ",To=" << To << ")" << std::endl;
    if (n == 1) {
        mov(From, To);
        show(From, To, Using);
    } else {
        TH(n - 1, From, To, Using);
        mov(From, To);
        show(From, To, Using);
        TH(n - 1, Using, From, To);
    }
	std::cerr << "<<< Exiting TH(n=" << n << ",From=" << From << ",Using=" << Using << ",To=" << To << ")" << std::endl;
}

/** Main function */
int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    struct tower F, U, T;

    F.top = 0;
	std::cerr << "main(): F.top → " << F.top << std::endl;
	std::cerr << "main(): U.top → " << U.top << std::endl;
	std::cerr << "main(): T.top → " << T.top << std::endl;
    U.top = 0;
    T.top = 0;

    int no;

    std::cout << "\nEnter number of discs : ";
    std::cin >> no;

    for (int i = no; i > 0; i--) {
        F.values[F.top++] = i;
    }

    show(&F, &T, &U);
    TH(no, &F, &U, &T);

	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
