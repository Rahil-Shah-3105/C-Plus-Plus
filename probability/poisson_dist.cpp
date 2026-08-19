/**
 * @file
 * @brief [Poisson
 * statistics](https://en.wikipedia.org/wiki/Poisson_distribution)
 *
 * The Poisson distribution counts how many
 * events occur over a set time interval.
 */
#include <cmath>
#include <iostream>

/**
 * poisson rate:\n
 * calculate the events per unit time\n
 * e.g 5 dollars every 2 mins = 5 / 2 = 2.5
 */
double poisson_rate(double events, double timeframe) {
	std::cerr << ">>> Entering poisson_rate(events=" << events << ",timeframe=" << timeframe << ")" << std::endl;
	std::cerr << "<<< Exiting poisson_rate(events=" << events << ",timeframe=" << timeframe << ")" << std::endl;
    return events / timeframe;
}

/**
 *  calculate the expected value over a time
 * e.g rate of 2.5 over 10 mins = 2.5 x 10 = 25
 */
double poisson_expected(double rate, double time) { return rate * time; }

/**
 * Compute factorial of a given number
 */
double fact(double x) {
	std::cerr << ">>> Entering fact(x=" << x << ")" << std::endl;
    double x_fact = x;
    for (int i = x - 1; i > 0; i--) {
		std::cerr << "fact(x=" << x << "): x_fact → " << x_fact << std::endl;
        x_fact *= i;
    }

    if (x_fact <= 0) {
        x_fact = 1;
    }
	std::cerr << "<<< Exiting fact(x=" << x << ")" << std::endl;
    return x_fact;
}

/**
 * Find the probability of x successes in a Poisson dist.
 * \f[p(\mu,x) = \frac{\mu^x e^{-\mu}}{x!}\f]
 */
double poisson_x_successes(double expected, double x) {
	std::cerr << ">>> Entering poisson_x_successes(expected=" << expected << ",x=" << x << ")" << std::endl;
	std::cerr << "<<< Exiting poisson_x_successes(expected=" << expected << ",x=" << x << ")" << std::endl;
    return (std::pow(expected, x) * std::exp(-expected)) / fact(x);
}

/**
 * probability of a success in range for Poisson dist (inclusive, inclusive)
 * \f[P = \sum_i p(\mu,i)\f]
 */
double poisson_range_successes(double expected, double lower, double upper) {
	std::cerr << ">>> Entering poisson_range_successes(expected=" << expected << ",lower=" << lower << ",upper=" << upper << ")" << std::endl;
    double probability = 0;
    for (int i = lower; i <= upper; i++) {
        probability += poisson_x_successes(expected, i);
    }
	std::cerr << "<<< Exiting poisson_range_successes(expected=" << expected << ",lower=" << lower << ",upper=" << upper << ")" << std::endl;
    return probability;
}

/**
 * main function
 */
int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    double rate, expected;
    rate = poisson_rate(3, 1);
    std::cout << "Poisson rate : " << rate << std::endl;
	std::cerr << "main(): rate → " << rate << std::endl;

    expected = poisson_expected(rate, 2);
    std::cout << "Poisson expected : " << expected << std::endl;
	std::cerr << "main(): expected → " << expected << std::endl;

    std::cout << "Poisson 0 successes : " << poisson_x_successes(expected, 0)
              << std::endl;
    std::cout << "Poisson 0-8 successes : "
              << poisson_range_successes(expected, 0, 8) << std::endl;

	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
