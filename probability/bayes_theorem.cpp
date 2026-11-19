/**
 * @file
 * @brief [Bayes' theorem](https://en.wikipedia.org/wiki/Bayes%27_theorem)
 *
 * Bayes' theorem allows one to find \f$P(A|B)\f$ given \f$P(B|A)\f$ or
 * \f$P(B|A)\f$ given \f$P(A|B)\f$ and \f$P(A)\f$ and \f$P(B)\f$.\n
 * Note that \f$P(A|B)\f$ is read 'The probability of A given that the event B
 * has occured'.
 */
#include <iostream>

/** returns P(A|B)
 */
double bayes_AgivenB(double BgivenA, double A, double B) {
	std::cerr << "[ERROR] >>> Entering bayes_AgivenB(BgivenA=" << BgivenA << ",A=" << A << ",B=" << B << ")" << std::endl;
    std::cerr << "[WARN] <<< Exiting bayes_AgivenB(BgivenA=" << BgivenA << ",A=" << A << ",B=" << B << ")" << std::endl;
    return (BgivenA * A) / B;
}

/** returns P(B|A)
 */
double bayes_BgivenA(double AgivenB, double A, double B) {
	std::cerr << "[ERROR] >>> Entering bayes_BgivenA(AgivenB=" << AgivenB << ",A=" << A << ",B=" << B << ")" << std::endl;
    std::cerr << "[WARN] <<< Exiting bayes_BgivenA(AgivenB=" << AgivenB << ",A=" << A << ",B=" << B << ")" << std::endl;
    return (AgivenB * B) / A;
}

/** Main function
 */
int main() {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
    double A = 0.01;
    double B = 0.1;
	std::cerr << "[ERROR] main(): B → " << B << std::endl;
	std::cerr << "[ERROR] main(): A → " << A << std::endl;
    double BgivenA = 0.9;
    double AgivenB = bayes_AgivenB(BgivenA, A, B);
	std::cerr << "[ERROR] main(): AgivenB → " << AgivenB << std::endl;
    std::cout << "A given B = " << AgivenB << std::endl;
    std::cout << "B given A = " << bayes_BgivenA(AgivenB, A, B) << std::endl;
	std::cerr << "[WARN] <<< Exiting main()" << std::endl;
    return 0;
}
