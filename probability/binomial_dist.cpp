/**
 * @file
 * @brief [Binomial
 * distribution](https://en.wikipedia.org/wiki/Binomial_distribution) example
 *
 * The binomial distribution models the number of
 * successes in a sequence of n independent events
 *
 * Summary of variables used:
 * * n : number of trials
 * * p : probability of success
 * * x : desired successes
 */
#include <cmath>
#include <iostream>

/** finds the expected value of a binomial distribution
 * \param [in] n
 * \param [in] p
 * \returns \f$\mu=np\f$
 */
double binomial_expected(double n, double p) { return n * p; }

/** finds the variance of the binomial distribution
 * \param [in] n
 * \param [in] p
 * \returns \f$\sigma^2 = n\cdot p\cdot (1-p)\f$
 */
double binomial_variance(double n, double p) { return n * p * (1 - p); }

/** finds the standard deviation of the binomial distribution
 * \param [in] n
 * \param [in] p
 * \returns \f$\sigma = \sqrt{\sigma^2} = \sqrt{n\cdot p\cdot (1-p)}\f$
 */
double binomial_standard_deviation(double n, double p) {
	std::cerr << ">>> Entering binomial_standard_deviation(n=" << n << ",p=" << p << ")" << std::endl;
	std::cerr << "<<< Exiting binomial_standard_deviation(n=" << n << ",p=" << p << ")" << std::endl;
    return std::sqrt(binomial_variance(n, p));
}

/** Computes n choose r
 * \param [in] n
 * \param [in] r
 * \returns \f$\displaystyle {n\choose r} =
 * \frac{n!}{r!(n-r)!} = \frac{n\times(n-1)\times(n-2)\times\cdots(n-r)}{r!}
 * \f$
 */
double nCr(double n, double r) {
	std::cerr << ">>> Entering nCr(n=" << n << ",r=" << r << ")" << std::endl;
    double numerator = n;
    double denominator = r;

    for (int i = n - 1; i >= ((n - r) + 1); i--) {
        numerator *= i;
    }

    for (int i = 1; i < r; i++) {
        denominator *= i;
    }

	std::cerr << "<<< Exiting nCr(n=" << n << ",r=" << r << ")" << std::endl;
    return numerator / denominator;
}

/** calculates the probability of exactly x successes
 * \returns \f$\displaystyle P(n,p,x) = {n\choose x} p^x (1-p)^{n-x}\f$
 */
double binomial_x_successes(double n, double p, double x) {
	std::cerr << ">>> Entering binomial_x_successes(n=" << n << ",p=" << p << ",x=" << x << ")" << std::endl;
	std::cerr << "<<< Exiting binomial_x_successes(n=" << n << ",p=" << p << ",x=" << x << ")" << std::endl;
    return nCr(n, x) * std::pow(p, x) * std::pow(1 - p, n - x);
}

/** calculates the probability of a result within a range (inclusive, inclusive)
 * \returns \f$\displaystyle \left.P(n,p)\right|_{x_0}^{x_1} =
 * \sum_{i=x_0}^{x_1} P(i)
 * =\sum_{i=x_0}^{x_1} {n\choose i} p^i (1-p)^{n-i}\f$
 */
double binomial_range_successes(double n, double p, double lower_bound,
                                double upper_bound) {
    double probability = 0;
    for (int i = lower_bound; i <= upper_bound; i++) {
        probability += nCr(n, i) * std::pow(p, i) * std::pow(1 - p, n - i);
    }
    return probability;
}

/** main function */
int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    std::cout << "expected value : " << binomial_expected(100, 0.5)
              << std::endl;

    std::cout << "variance : " << binomial_variance(100, 0.5) << std::endl;

    std::cout << "standard deviation : "
              << binomial_standard_deviation(100, 0.5) << std::endl;

    std::cout << "exactly 30 successes : " << binomial_x_successes(100, 0.5, 30)
              << std::endl;

    std::cout << "45 or more successes : "
              << binomial_range_successes(100, 0.5, 45, 100) << std::endl;

	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
