#include <iostream>
#include <cmath>
#include "Newton.h"

using namespace std;

int main() {
    cout << "========================================" << endl;
    cout << "     NEWTON'S ROOT FINDING METHODS     " << endl;
    cout << "========================================\n" << endl;

    // TEST CASE 5: Polynomial root finding - quadratic equation x^2 - 2 = 0
    // Roots: x = ±√2 ≈ ±1.414
    // Polynomial coefficients: [1, 0, -2] (x^2 + 0x - 2)
    // Expected output: Should find one of the roots (approximately 1.414 or -1.414)
    cout << "TEST CASE 5: Polynomial Root Finding (x^2 - 2 = 0)" << endl;
    cout << "Expected roots: x = ±√2 ≈ ±1.414" << endl;
    
    double coeffs1[] = {1, 0, -2}; // x^2 + 0x - 2
    double root1 = polynomialNewton(1.0, 3, coeffs1); // Start with positive guess
    
    cout << "Root found (starting from x=1.0): " << root1 << endl;
    cout << "Verification: x^2 = " << root1*root1 << " (should be ≈ 2.0)" << endl;
    cout << endl;

    // TEST CASE 6: Polynomial root finding - cubic equation x^3 - 6x^2 + 11x - 6 = 0
    // Roots: x = 1, 2, 3
    // Polynomial coefficients: [1, -6, 11, -6] (x^3 - 6x^2 + 11x - 6)
    // Expected output: Should find one of the roots (1, 2, or 3)
    cout << "TEST CASE 6: Polynomial Root Finding (x^3 - 6x^2 + 11x - 6 = 0)" << endl;
    cout << "Expected roots: x = 1, 2, 3" << endl;
    
    double coeffs2[] = {1, -6, 11, -6}; // x^3 - 6x^2 + 11x - 6
    double root2 = polynomialNewton(0.5, 4, coeffs2); // Start with guess near 1
    
    cout << "Root found (starting from x=0.5): " << root2 << endl;
    cout << "Verification: x^3 - 6x^2 + 11x - 6 = " 
         << root2*root2*root2 - 6*root2*root2 + 11*root2 - 6 << " (should be ≈ 0.0)" << endl;
    cout << endl;

    // TEST CASE 7: General function root finding - sin(x) = 0
    // Roots: x = nπ where n is integer
    // Expected output: Should find root near x=3.0 (π ≈ 3.14159)
    cout << "TEST CASE 7: General Function Root Finding (sin(x) = 0)" << endl;
    cout << "Expected roots: x = nπ (π ≈ 3.14159)" << endl;
    
    double root3 = newton(3.0, [](double x){ return sin(x); });
    
    cout << "Root found (starting from x=3.0): " << root3 << endl;
    cout << "Verification: sin(x) = " << sin(root3) << " (should be ≈ 0.0)" << endl;
    cout << "This should be close to π ≈ 3.14159" << endl;
    cout << endl;

    // TEST CASE 8: General function root finding - exponential equation e^x - 2 = 0
    // Root: x = ln(2) ≈ 0.693
    // Expected output: Should find root near ln(2)
    cout << "TEST CASE 8: General Function Root Finding (e^x - 2 = 0)" << endl;
    cout << "Expected root: x = ln(2) ≈ 0.693" << endl;
    
    double root4 = newton(0.5, [](double x){ return exp(x) - 2; });
    
    cout << "Root found (starting from x=0.5): " << root4 << endl;
    cout << "Verification: e^x - 2 = " << exp(root4) - 2 << " (should be ≈ 0.0)" << endl;
    cout << "This should be close to ln(2) ≈ 0.693" << endl;
    cout << endl;

    cout << "========================================" << endl;
    cout << "Algorithm explanations:" << endl;
    cout << endl;
    cout << "1. NEWTON'S DIVIDED DIFFERENCES METHOD:" << endl;
    cout << "Constructs a polynomial P(x) that passes through all given data points using:" << endl;
    cout << "P(x) = f[x0] + f[x0,x1]*(x-x0) + f[x0,x1,x2]*(x-x0)*(x-x1) + ..." << endl;
    cout << endl;
    cout << "2. NEWTON'S ROOT FINDING METHODS:" << endl;
    cout << "Iterative methods to find roots of equations f(x) = 0 using the formula:" << endl;
    cout << "x_{n+1} = x_n - f(x_n)/f'(x_n)" << endl;
    cout << "- polynomialNewton: For polynomial equations using Horner's method" << endl;
    cout << "- newton: For general functions using numerical differentiation" << endl;
    cout << "========================================" << endl;

    return 0;
}
