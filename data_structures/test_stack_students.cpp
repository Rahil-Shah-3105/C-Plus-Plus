/*
 * This program reads a data file consisting of students' GPAs
 * followed by their names. The program then prints the highest
 * GPA and the names of the students with the highest GPA.
 * It uses stack to store the names of the students
 * Run:
 *     make all
 *     ./main student.txt
 ************************************************************
 * */
#include <cassert>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "./stack.hpp"

int main(int argc, char* argv[]) {
	std::cerr << ">>> Entering main(argc=" << argc << ",argv=" << argv << ")" << std::endl;
    double GPA = NAN;
    double highestGPA = NAN;
	std::cerr << "main(argc=" << argc << ",argv=" << argv << "): highestGPA → " << highestGPA << std::endl;
    std::string name;

    assert(argc == 2);
    std::ifstream infile;
    stack<std::string> stk;

    infile.open(argv[1]);
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(2);
    infile >> GPA >> name;
    highestGPA = GPA;

    while (infile) {
        if (GPA > highestGPA) {
            stk.clear();
            stk.push(name);
            highestGPA = GPA;
        } else if (GPA == highestGPA) {
            stk.push(name);
        }
        infile >> GPA >> name;
    }
    std::cout << "Highest GPA: " << highestGPA << std::endl;
    std::cout << "Students the highest GPA are: " << std::endl;
    while (!stk.isEmptyStack()) {
        std::cout << stk.top() << std::endl;
        stk.pop();
    }
    std::cout << std::endl;
	std::cerr << "<<< Exiting main(argc=" << argc << ",argv=" << argv << ")" << std::endl;
    return 0;
}
