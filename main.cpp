#include <iostream>
#include "splitDiferences.h"

using namespace std;

int main() {
    cout << "========================================" << endl;
    cout << "  NEWTON'S DIVIDED DIFFERENCES METHOD  " << endl;
    cout << "========================================\n" << endl;

    // TEST CASE 1: Linear function y = 2x + 1
    // Points: (0, 1), (1, 3), (2, 5)
    // Expected output: A polynomial representation of the interpolating function
    // For a linear function, divided differences should give: 1 + 2*(x - 0) + 0*(x - 0)*(x - 1)
    cout << "TEST CASE 1: Linear Function (y = 2x + 1)" << endl;
    cout << "Points: (0, 1), (1, 3), (2, 5)" << endl;
    
    double x1[] = {0, 1, 2};
    double y1[] = {1, 3, 5};
    
    SplitDifferences sd1(3, x1, y1);
    string result1 = sd1.calculateInterpolation();
    
    cout << "Interpolating polynomial: " << result1 << endl;
    cout << "Expected output: Polynomial of degree <= 2 passing through all three points" << endl;
    cout << endl;

    // TEST CASE 2: Quadratic function y = x^2
    // Points: (0, 0), (1, 1), (2, 4)
    // Expected output: A polynomial representation of the quadratic function
    // The divided differences should reconstruct: 0 + 1*(x - 0) + 1*(x - 0)*(x - 1)
    cout << "TEST CASE 2: Quadratic Function (y = x^2)" << endl;
    cout << "Points: (0, 0), (1, 1), (2, 4)" << endl;
    
    double x2[] = {0, 1, 2};
    double y2[] = {0, 1, 4};
    
    SplitDifferences sd2(3, x2, y2);
    string result2 = sd2.calculateInterpolation();
    
    cout << "Interpolating polynomial: " << result2 << endl;
    cout << "Expected output: Polynomial of degree <= 2 representing y = x^2" << endl;
    cout << endl;

    // TEST CASE 3: Four points with higher degree polynomial
    // Points: (1, 1), (2, 4), (3, 9), (4, 16)
    // These points lie on y = x^2
    // Expected output: A cubic polynomial that passes through all four points
    // For equidistant points on y = x^2, divided differences will give the quadratic
    cout << "TEST CASE 3: Four Points on Quadratic (y = x^2)" << endl;
    cout << "Points: (1, 1), (2, 4), (3, 9), (4, 16)" << endl;
    
    double x3[] = {1, 2, 3, 4};
    double y3[] = {1, 4, 9, 16};
    
    SplitDifferences sd3(4, x3, y3);
    string result3 = sd3.calculateInterpolation();
    
    cout << "Interpolating polynomial: " << result3 << endl;
    cout << "Expected output: Polynomial of degree <= 3 that reproduces y = x^2 through all points" << endl;
    cout << endl;

    cout << "========================================" << endl;
    cout << "Algorithm explanation:" << endl;
    cout << "Newton's Divided Differences method constructs a polynomial P(x)" << endl;
    cout << "that passes through all given data points using the formula:" << endl;
    cout << "P(x) = f[x0] + f[x0,x1]*(x-x0) + f[x0,x1,x2]*(x-x0)*(x-x1) + ..." << endl;
    cout << "========================================" << endl;

    return 0;
}
