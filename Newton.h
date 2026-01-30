#ifndef NEWTON_H
#define NEWTON_H

#include <stdlib.h>

using namespace std;



double polynomialNewton(double x, int n, double* polynomicArr) {
    double temp, derivativeValue, *q;
    int iterations = 0;
    do{
        iterations++;
        q = new double[n];
        q[0] = polynomicArr[0];
        temp = q[0];
        for (int i = 1; i < n; i++) {
            temp = temp*x + polynomicArr[i];
            q[i] = temp;
        }

        //Derivative
        derivativeValue = polynomicArr[0];
        for(int i = 1; i < n - 1; i++) {
            derivativeValue = derivativeValue*x + q[i];
            q[i] = derivativeValue;
        }

        x = x - temp/derivativeValue;
    }while(abs(temp/derivativeValue) > 0.00001 && iterations < 1000);
    delete[] q;
    return x;
}

double newton(double x, double (*function)(double)){
    double h = 0.0001;
    double x0 = x;
    double fx0 = function(x0);
    double dfx0 = (function(x0 + h) - function(x0 - h)) / (2 * h);
    double x1 = x0 - fx0 / dfx0;
    int iterations = 0;

    while (abs(x1 - x0) > 0.00001 && iterations < 1000) {
        x0 = x1;
        fx0 = function(x0);
        dfx0 = (function(x0 + h) - function(x0 - h)) / (2 * h);
        x1 = x0 - fx0 / dfx0;
        iterations++;
    }

    return x1;
}

#endif