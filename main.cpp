#include <iostream>
#include <complex>
#include "muller.h"

using namespace std;

int main() {
    cout << "========================================" << endl;
    cout << "         MULLER'S METHOD TESTS         " << endl;
    cout << "========================================\n" << endl;

    // TEST CASE 1: Quadratic equation x^2 - 2 = 0
    // Roots: x = ±√2 ≈ ±1.414
    // Expected output: Should find one of the real roots
    cout << "TEST CASE 1: Quadratic Equation (x^2 - 2 = 0)" << endl;
    cout << "Expected roots: x = ±√2 ≈ ±1.414" << endl;

    double (*func1)(double) = [](double x) { return x*x - 2.0; };
    double root1 = mullerMethod(1.0, func1);

    cout << "Root found (starting from x=1.0): " << root1 << endl;
    cout << "Verification: x^2 - 2 = " << func1(root1) << " (should be ≈ 0.0)" << endl;
    cout << "Should be close to √2 ≈ 1.414" << endl;
    cout << endl;

    // TEST CASE 2: Cubic equation x^3 - 6x^2 + 11x - 6 = 0
    // Roots: x = 1, 2, 3
    // Expected output: Should find one of the real roots
    cout << "TEST CASE 2: Cubic Equation (x^3 - 6x^2 + 11x - 6 = 0)" << endl;
    cout << "Expected roots: x = 1, 2, 3" << endl;

    double (*func2)(double) = [](double x) {
        return x*x*x - 6.0*x*x + 11.0*x - 6.0;
    };
    double root2 = mullerMethod(0.8, func2);

    cout << "Root found (starting from x=0.8): " << root2 << endl;
    cout << "Verification: x^3 - 6x^2 + 11x - 6 = " << func2(root2) << " (should be ≈ 0.0)" << endl;
    cout << "Should be close to 1, 2, or 3" << endl;
    cout << endl;

    // TEST CASE 3: Transcendental equation sin(x) = 0
    // Roots: x = nπ where n is integer
    // Expected output: Should find root near the starting point
    cout << "TEST CASE 3: Transcendental Equation (sin(x) = 0)" << endl;
    cout << "Expected roots: x = nπ (π ≈ 3.14159)" << endl;

    double (*func3)(double) = [](double x) { return sin(x); };
    double root3 = mullerMethod(3.0, func3);

    cout << "Root found (starting from x=3.0): " << root3 << endl;
    cout << "Verification: sin(x) = " << sin(root3) << " (should be ≈ 0.0)" << endl;
    cout << "Should be close to π ≈ 3.14159" << endl;
    cout << endl;

    // TEST CASE 4: Exponential equation e^x - 2 = 0
    // Root: x = ln(2) ≈ 0.693
    // Expected output: Should find the natural log root
    cout << "TEST CASE 4: Exponential Equation (e^x - 2 = 0)" << endl;
    cout << "Expected root: x = ln(2) ≈ 0.693" << endl;

    double (*func4)(double) = [](double x) { return exp(x) - 2.0; };
    double root4 = mullerMethod(0.5, func4);

    cout << "Root found (starting from x=0.5): " << root4 << endl;
    cout << "Verification: e^x - 2 = " << exp(root4) - 2.0 << " (should be ≈ 0.0)" << endl;
    cout << "Should be close to ln(2) ≈ 0.693" << endl;
    cout << endl;

    // TEST CASE 5: Equation with multiple roots x^4 - 5x^2 + 4 = 0
    // Roots: x = ±1, ±2 (from factoring: (x^2-1)(x^2-4) = 0)
    // Expected output: Should find one of the real roots
    cout << "TEST CASE 5: Quartic Equation (x^4 - 5x^2 + 4 = 0)" << endl;
    cout << "Expected roots: x = ±1, ±2" << endl;

    double (*func5)(double) = [](double x) {
        return x*x*x*x - 5.0*x*x + 4.0;
    };
    double root5 = mullerMethod(1.5, func5);

    cout << "Root found (starting from x=1.5): " << root5 << endl;
    cout << "Verification: x^4 - 5x^2 + 4 = " << func5(root5) << " (should be ≈ 0.0)" << endl;
    cout << "Should be close to ±1 or ±2" << endl;
    cout << endl;

    // TEST CASE 6: Polynomial with repeated root (x-1)^2 = 0
    // Root: x = 1 (multiplicity 2)
    // Expected output: Should find the repeated root
    cout << "TEST CASE 6: Polynomial with Repeated Root ((x-1)^2 = 0)" << endl;
    cout << "Expected root: x = 1 (multiplicity 2)" << endl;

    double (*func6)(double) = [](double x) {
        double diff = x - 1.0;
        return diff * diff;
    };
    double root6 = mullerMethod(0.8, func6);

    cout << "Root found (starting from x=0.8): " << root6 << endl;
    cout << "Verification: (x-1)^2 = " << func6(root6) << " (should be ≈ 0.0)" << endl;
    cout << "Should be close to 1.0" << endl;
    cout << endl;

    cout << "========================================" << endl;
    cout << "  MULLER'S METHOD - COMPLEX ROOTS      " << endl;
    cout << "========================================\n" << endl;

    // TEST CASE 7: Quadratic with complex roots x^2 + 4 = 0
    // Roots: x = ±2i
    // Expected output: Should find one of the complex roots
    cout << "TEST CASE 7: Quadratic with Complex Roots (x^2 + 4 = 0)" << endl;
    cout << "Expected roots: x = ±2i" << endl;

    complex<double> (*func7)(complex<double>) = [](complex<double> x) { 
        return x*x + complex<double>(4.0);
    };
    complex<double> root7 = mullerComplexMethod(complex<double>(0.0, 1.0), func7);

    cout << "Root found (starting from x=0+1i): " << root7 << endl;
    cout << "Verification: x^2 + 4 = " << func7(root7) << " (should be ≈ 0.0)" << endl;
    cout << "Should be close to 0 ± 2i" << endl;
    cout << endl;

    // TEST CASE 8: Cubic with mixed roots x^3 - 1 = 0
    // Roots: x = 1, (-1 + i√3)/2, (-1 - i√3)/2 (cube roots of unity)
    // Expected output: Should find one of the roots
    cout << "TEST CASE 8: Cubic Equation (x^3 - 1 = 0)" << endl;
    cout << "Expected roots: x = 1 and complex cube roots of unity" << endl;

    complex<double> (*func8)(complex<double>) = [](complex<double> x) {
        return x*x*x - complex<double>(1.0);
    };
    complex<double> root8 = mullerComplexMethod(complex<double>(0.5, 0.5), func8);

    cout << "Root found (starting from x=0.5+0.5i): " << root8 << endl;
    cout << "Verification: x^3 - 1 = " << func8(root8) << " (should be ≈ 0.0)" << endl;
    cout << "Expected: one of the cube roots of unity" << endl;
    cout << endl;

    // TEST CASE 9: Quadratic x^2 - 2x + 2 = 0
    // Roots: x = 1 ± i
    // Expected output: Should find one of the complex roots
    cout << "TEST CASE 9: Quadratic Equation (x^2 - 2x + 2 = 0)" << endl;
    cout << "Expected roots: x = 1 ± i" << endl;

    complex<double> (*func9)(complex<double>) = [](complex<double> x) {
        return x*x - complex<double>(2.0)*x + complex<double>(2.0);
    };
    complex<double> root9 = mullerComplexMethod(complex<double>(1.0, 1.0), func9);

    cout << "Root found (starting from x=1+1i): " << root9 << endl;
    cout << "Verification: x^2 - 2x + 2 = " << func9(root9) << " (should be ≈ 0.0)" << endl;
    cout << "Should be close to 1 ± i" << endl;
    cout << endl;

    // TEST CASE 10: Polynomial x^4 + 1 = 0
    // Roots: x = e^(iπ/4), e^(i3π/4), e^(i5π/4), e^(i7π/4)
    // Expected output: Should find one of the complex roots
    cout << "TEST CASE 10: Quartic Equation (x^4 + 1 = 0)" << endl;
    cout << "Expected roots: x = 4th roots of -1 (all complex)" << endl;

    complex<double> (*func10)(complex<double>) = [](complex<double> x) {
        complex<double> x2 = x*x;
        return x2*x2 + complex<double>(1.0);
    };
    complex<double> root10 = mullerComplexMethod(complex<double>(0.5, 0.5), func10);

    cout << "Root found (starting from x=0.5+0.5i): " << root10 << endl;
    cout << "Verification: x^4 + 1 = " << func10(root10) << " (should be ≈ 0.0)" << endl;
    cout << "Should be one of the 4th roots of -1" << endl;
    cout << endl;

    cout << "========================================" << endl;
    cout << "Algorithm explanation:" << endl;
    cout << "Muller's method is a root-finding algorithm that uses quadratic" << endl;
    cout << "interpolation to locate roots of equations f(x) = 0. It works" << endl;
    cout << "particularly well when derivatives are difficult to compute" << endl;
    cout << "or don't exist, and can handle both real and complex functions." << endl;
    cout << endl;
    cout << "The method uses three points to construct a quadratic" << endl;
    cout << "approximation and finds its root, then iterates this process." << endl;
    cout << "The complex version extends this to handle complex numbers," << endl;
    cout << "making it capable of finding both real and complex roots." << endl;
    cout << "========================================" << endl;

    return 0;
}
