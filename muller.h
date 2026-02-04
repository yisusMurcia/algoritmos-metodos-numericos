#ifndef MULLER_H
#define MULLER_H

#include <cmath>

double H = 1e-4; // Small perturbation
int MAX_ITERATIONS = 1000;

double mullerMethod(double x, double (*func)(double)){
    double x0 = x - H;
    double x1 = x;
    double x2 = x + H;
    double x3;

    double d0 = 0, d1 = 0, h0 = 0, h1 = 0, a = 0, b = 0, c = 0, r = 0;

    int iterations = 0;

    do{
        iterations++;
        h0 = x1 - x0;
        h1 = x2 - x1;

        d0 = (func(x1) - func(x0)) / h0;
        d1 = (func(x2) - func(x1)) / h1;
        a = (d1 - d0) / (h1 + h0);
        b = a * h1 + d1;
        c = func(x2);
        r = sqrt(b * b - 4 * a * c);
        r = -2 * c / (b + (abs(b - r) < abs(b + r) ? r : -r));
        x3 = x2 + r;
        if(abs(x0 - x3) < abs(x1 - x3))
            if(abs(x1 - x3) < abs(x2 - x3))
                x2 = x3;
            else
                x1 = x3;
        else
            if(abs(x0 - x3) < abs(x2 - x3))
                x2 = x3;
            else
                x0 = x3;
    } while (abs(r) > H && iterations < MAX_ITERATIONS);

    return x3;
    
}

#endif