/**
 * @file
 * @brief Implementations for the [area](https://en.wikipedia.org/wiki/Area) of
 * various shapes
 * @details The area of a shape is the amount of 2D space it takes up.
 * All shapes have a formula to get the area of any given shape.
 * These implementations support multiple return types.
 *
 * @author [Focusucof](https://github.com/Focusucof)
 */
#define _USE_MATH_DEFINES
#include <cassert>  /// for assert
#include <cmath>    /// for M_PI definition and pow()
#include <cmath>
#include <cstdint>   /// for uint16_t datatype
#include <iostream>  /// for IO operations

/**
 * @namespace math
 * @brief Mathematical algorithms
 */
namespace math {
/**
 * @brief area of a [square](https://en.wikipedia.org/wiki/Square) (l * l)
 * @param length is the length of the square
 * @returns area of square
 */
template <typename T>
T square_area(T length) {
	std::cerr << ">>> Entering square_area(length=" << length << ")" << std::endl;
	std::cerr << "<<< Exiting square_area(length=" << length << ")" << std::endl;
    return length * length;
}

/**
 * @brief area of a [rectangle](https://en.wikipedia.org/wiki/Rectangle) (l * w)
 * @param length is the length of the rectangle
 * @param width is the width of the rectangle
 * @returns area of the rectangle
 */
template <typename T>
T rect_area(T length, T width) {
	std::cerr << ">>> Entering rect_area(length=" << length << ",width=" << width << ")" << std::endl;
	std::cerr << "<<< Exiting rect_area(length=" << length << ",width=" << width << ")" << std::endl;
    return length * width;
}

/**
 * @brief area of a [triangle](https://en.wikipedia.org/wiki/Triangle) (b * h /
 * 2)
 * @param base is the length of the bottom side of the triangle
 * @param height is the length of the tallest point in the triangle
 * @returns area of the triangle
 */
template <typename T>
T triangle_area(T base, T height) {
	std::cerr << ">>> Entering triangle_area(base=" << base << ",height=" << height << ")" << std::endl;
	std::cerr << "<<< Exiting triangle_area(base=" << base << ",height=" << height << ")" << std::endl;
    return base * height / 2;
}

/**
 * @brief area of a [circle](https://en.wikipedia.org/wiki/Area_of_a_circle) (pi
 * * r^2)
 * @param radius is the radius of the circle
 * @returns area of the circle
 */
template <typename T>
T circle_area(T radius) {
	std::cerr << ">>> Entering circle_area(radius=" << radius << ")" << std::endl;
	std::cerr << "<<< Exiting circle_area(radius=" << radius << ")" << std::endl;
    return M_PI * pow(radius, 2);
}

/**
 * @brief area of a [parallelogram](https://en.wikipedia.org/wiki/Parallelogram)
 * (b * h)
 * @param base is the length of the bottom side of the parallelogram
 * @param height is the length of the tallest point in the parallelogram
 * @returns area of the parallelogram
 */
template <typename T>
T parallelogram_area(T base, T height) {
	std::cerr << ">>> Entering parallelogram_area(base=" << base << ",height=" << height << ")" << std::endl;
	std::cerr << "<<< Exiting parallelogram_area(base=" << base << ",height=" << height << ")" << std::endl;
    return base * height;
}

/**
 * @brief surface area of a [cube](https://en.wikipedia.org/wiki/Cube) ( 6 * (l
 * * l))
 * @param length is the length of the cube
 * @returns surface area of the cube
 */
template <typename T>
T cube_surface_area(T length) {
	std::cerr << ">>> Entering cube_surface_area(length=" << length << ")" << std::endl;
	std::cerr << "<<< Exiting cube_surface_area(length=" << length << ")" << std::endl;
    return 6 * length * length;
}

/**
 * @brief surface area of a [sphere](https://en.wikipedia.org/wiki/Sphere) ( 4 *
 * pi * r^2)
 * @param radius is the radius of the sphere
 * @returns surface area of the sphere
 */
template <typename T>
T sphere_surface_area(T radius) {
	std::cerr << ">>> Entering sphere_surface_area(radius=" << radius << ")" << std::endl;
	std::cerr << "<<< Exiting sphere_surface_area(radius=" << radius << ")" << std::endl;
    return 4 * M_PI * pow(radius, 2);
}

/**
 * @brief surface area of a [cylinder](https://en.wikipedia.org/wiki/Cylinder)
 * (2 * pi * r * h + 2 * pi * r^2)
 * @param radius is the radius of the cylinder
 * @param height is the height of the cylinder
 * @returns surface area of the cylinder
 */
template <typename T>
T cylinder_surface_area(T radius, T height) {
	std::cerr << ">>> Entering cylinder_surface_area(radius=" << radius << ",height=" << height << ")" << std::endl;
	std::cerr << "<<< Exiting cylinder_surface_area(radius=" << radius << ",height=" << height << ")" << std::endl;
    return 2 * M_PI * radius * height + 2 * M_PI * pow(radius, 2);
}

/**
 * @brief surface area of a [hemi-sphere](https://en.wikipedia.org/wiki/Surface_area) ( 3 *
 * pi * r^2)
 * @param radius is the radius of the hemi-sphere
 * @tparam T datatype of radius
 * @returns surface area of the hemi-sphere
 */
template <typename T>
T hemi_sphere_surface_area(T radius) {
	std::cerr << ">>> Entering hemi_sphere_surface_area(radius=" << radius << ")" << std::endl;
	std::cerr << "<<< Exiting hemi_sphere_surface_area(radius=" << radius << ")" << std::endl;
    return 3 * M_PI * pow(radius, 2);
}
}  // namespace math

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
	std::cerr << ">>> Entering test()" << std::endl;
    // I/O variables for testing
    uint16_t int_length = 0;    // 16 bit integer length input
	std::cerr << "test(): int_length → " << int_length << std::endl;
    uint16_t int_width = 0;     // 16 bit integer width input
	std::cerr << "test(): int_width → " << int_width << std::endl;
    uint16_t int_base = 0;      // 16 bit integer base input
	std::cerr << "test(): int_base → " << int_base << std::endl;
    uint16_t int_height = 0;    // 16 bit integer height input
	std::cerr << "test(): int_height → " << int_height << std::endl;
    uint16_t int_expected = 0;  // 16 bit integer expected output
	std::cerr << "test(): int_expected → " << int_expected << std::endl;
    uint16_t int_area = 0;      // 16 bit integer output
	std::cerr << "test(): int_area → " << int_area << std::endl;

    float float_length = NAN;    // float length input
	std::cerr << "test(): float_length → " << float_length << std::endl;
    float float_expected = NAN;  // float expected output
	std::cerr << "test(): float_expected → " << float_expected << std::endl;
    float float_area = NAN;      // float output
	std::cerr << "test(): float_area → " << float_area << std::endl;

    double double_length = NAN;    // double length input
	std::cerr << "test(): double_length → " << double_length << std::endl;
    double double_width = NAN;     // double width input
	std::cerr << "test(): double_width → " << double_width << std::endl;
    double double_radius = NAN;    // double radius input
	std::cerr << "test(): double_radius → " << double_radius << std::endl;
    double double_height = NAN;    // double height input
	std::cerr << "test(): double_height → " << double_height << std::endl;
    double double_expected = NAN;  // double expected output
	std::cerr << "test(): double_expected → " << double_expected << std::endl;
    double double_area = NAN;      // double output
	std::cerr << "test(): double_area → " << double_area << std::endl;

    // 1st test
    int_length = 5;
    int_expected = 25;
    int_area = math::square_area(int_length);

    std::cout << "AREA OF A SQUARE (int)" << std::endl;
    std::cout << "Input Length: " << int_length << std::endl;
    std::cout << "Expected Output: " << int_expected << std::endl;
    std::cout << "Output: " << int_area << std::endl;
    assert(int_area == int_expected);
    std::cout << "TEST PASSED" << std::endl << std::endl;

    // 2nd test
    float_length = 2.5;
    float_expected = 6.25;
    float_area = math::square_area(float_length);

    std::cout << "AREA OF A SQUARE (float)" << std::endl;
    std::cout << "Input Length: " << float_length << std::endl;
    std::cout << "Expected Output: " << float_expected << std::endl;
    std::cout << "Output: " << float_area << std::endl;
    assert(float_area == float_expected);
    std::cout << "TEST PASSED" << std::endl << std::endl;

    // 3rd test
    int_length = 4;
    int_width = 7;
    int_expected = 28;
    int_area = math::rect_area(int_length, int_width);

    std::cout << "AREA OF A RECTANGLE (int)" << std::endl;
    std::cout << "Input Length: " << int_length << std::endl;
    std::cout << "Input Width: " << int_width << std::endl;
    std::cout << "Expected Output: " << int_expected << std::endl;
    std::cout << "Output: " << int_area << std::endl;
    assert(int_area == int_expected);
    std::cout << "TEST PASSED" << std::endl << std::endl;

    // 4th test
    double_length = 2.5;
    double_width = 5.7;
    double_expected = 14.25;
    double_area = math::rect_area(double_length, double_width);

    std::cout << "AREA OF A RECTANGLE (double)" << std::endl;
    std::cout << "Input Length: " << double_length << std::endl;
    std::cout << "Input Width: " << double_width << std::endl;
    std::cout << "Expected Output: " << double_expected << std::endl;
    std::cout << "Output: " << double_area << std::endl;
    assert(double_area == double_expected);
    std::cout << "TEST PASSED" << std::endl << std::endl;

    // 5th test
    int_base = 10;
    int_height = 3;
    int_expected = 15;
    int_area = math::triangle_area(int_base, int_height);

    std::cout << "AREA OF A TRIANGLE" << std::endl;
    std::cout << "Input Base: " << int_base << std::endl;
    std::cout << "Input Height: " << int_height << std::endl;
    std::cout << "Expected Output: " << int_expected << std::endl;
    std::cout << "Output: " << int_area << std::endl;
    assert(int_area == int_expected);
    std::cout << "TEST PASSED" << std::endl << std::endl;

    // 6th test
    double_radius = 6;
    double_expected =
        113.09733552923255;  // rounded down because the double datatype
                             // truncates after 14 decimal places
    double_area = math::circle_area(double_radius);

    std::cout << "AREA OF A CIRCLE" << std::endl;
    std::cout << "Input Radius: " << double_radius << std::endl;
    std::cout << "Expected Output: " << double_expected << std::endl;
    std::cout << "Output: " << double_area << std::endl;
    assert(double_area == double_expected);
    std::cout << "TEST PASSED" << std::endl << std::endl;

    // 7th test
    int_base = 6;
    int_height = 7;
    int_expected = 42;
    int_area = math::parallelogram_area(int_base, int_height);

    std::cout << "AREA OF A PARALLELOGRAM" << std::endl;
    std::cout << "Input Base: " << int_base << std::endl;
    std::cout << "Input Height: " << int_height << std::endl;
    std::cout << "Expected Output: " << int_expected << std::endl;
    std::cout << "Output: " << int_area << std::endl;
    assert(int_area == int_expected);
    std::cout << "TEST PASSED" << std::endl << std::endl;

    // 8th test
    double_length = 5.5;
    double_expected = 181.5;
    double_area = math::cube_surface_area(double_length);

    std::cout << "SURFACE AREA OF A CUBE" << std::endl;
    std::cout << "Input Length: " << double_length << std::endl;
    std::cout << "Expected Output: " << double_expected << std::endl;
    std::cout << "Output: " << double_area << std::endl;
    assert(double_area == double_expected);
    std::cout << "TEST PASSED" << std::endl << std::endl;

    // 9th test
    double_radius = 10.0;
    double_expected = 1256.6370614359172;  // rounded down because the whole
                                           // value gets truncated
    double_area = math::sphere_surface_area(double_radius);

    std::cout << "SURFACE AREA OF A SPHERE" << std::endl;
    std::cout << "Input Radius: " << double_radius << std::endl;
    std::cout << "Expected Output: " << double_expected << std::endl;
    std::cout << "Output: " << double_area << std::endl;
    assert(double_area == double_expected);
    std::cout << "TEST PASSED" << std::endl << std::endl;

    // 10th test
    double_radius = 4.0;
    double_height = 7.0;
    double_expected = 276.46015351590177;
    double_area = math::cylinder_surface_area(double_radius, double_height);

    std::cout << "SURFACE AREA OF A CYLINDER" << std::endl;
    std::cout << "Input Radius: " << double_radius << std::endl;
    std::cout << "Input Height: " << double_height << std::endl;
    std::cout << "Expected Output: " << double_expected << std::endl;
    std::cout << "Output: " << double_area << std::endl;
    assert(double_area == double_expected);
    std::cout << "TEST PASSED" << std::endl << std::endl;

    // 11th test
    double_radius = 10.0;
    double_expected = 942.4777960769379;
    double_area = math::hemi_sphere_surface_area(double_radius);

    std::cout << "SURFACE AREA OF A HEMI-SPHERE" << std::endl;
    std::cout << "Input Radius: " << double_radius << std::endl;
    std::cout << "Expected Output: " << double_expected << std::endl;
    std::cout << "Output: " << double_area << std::endl;
    assert(double_area == double_expected);
    std::cout << "TEST PASSED" << std::endl << std::endl;
	std::cerr << "<<< Exiting test()" << std::endl;
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    test();  // run self-test implementations
	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
