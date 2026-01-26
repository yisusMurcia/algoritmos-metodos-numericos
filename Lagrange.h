#ifndef LAGRANGE_H
#define LAGRANGE_H

#include <string>
using namespace std;

string lagrangeInterpolation(double* x, double* y, int n){
    string result;
    for(int i = 0; i < n; i++){
        string term = to_string(y[i]);
        for(int j = 0; j < n; j++){
            if(j != i){
                term += " * (x - " + to_string(x[j]) + ") / (" + to_string(x[i] - x[j]) + ")";
            }
        }
        if(i > 0 && y[i] >= 0){
            result += " + ";
        }
        result += term;
    }

    return result;
};

#endif