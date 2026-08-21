/**
 * \file
 * \brief Method of successive approximations using [fixed-point
 * iteration](https://en.wikipedia.org/wiki/Fixed-point_iteration) method
 */
#include <cmath>
#include <iostream>

/** equation 1
 * \f[f(y) = 3y - \cos y -2\f]
 */
static float eq(float y) { return (3 * y) - cos(y) - 2; }

/** equation 2
 * \f[f(y) = \frac{\cos y+2}{2}\f]
 */
static float eqd(float y) { return 0.5 * (cos(y) + 2); }

/** Main function */
int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    float y, x1, x2, sum;
    int i, n;

    for (i = 0; i < 10; i++) {
        sum = eq(y);
        std::cout << "value of equation at " << i << " " << sum << "\n";
		std::cerr << "main(): sum → " << sum << std::endl;
        y++;
    }
    std::cout << "enter the x1->";
    std::cin >> x1;
    std::cout << "enter the no iteration to perform->\n";
    std::cin >> n;

    for (i = 0; i <= n; i++) {
        x2 = eqd(x1);
		std::cerr << "main(): x2 → " << x2 << std::endl;
        std::cout << "\nenter the x2->" << x2;
        x1 = x2;
    }
	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
