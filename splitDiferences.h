#ifndef SPLIT_DIFFERENCES_H
#define SPLIT_DIFFERENCES_H

#include <string>

using namespace std;


class SplitDifferences {
    private:
    int size;
    double* xData;
    double* functionData;
    bool isUniformedSpaced = false;

    public:
    SplitDifferences(int n, double* x, double* y) : size(n), xData(x), functionData(y) {determineIfUniformedSpaced();};
    SplitDifferences(){};

    void determineIfUniformedSpaced(){
        isUniformedSpaced = true;
        double h = xData[1] - xData[0];
        for(int i = 1; i < size - 1; i++){
            if((xData[i+1] - xData[i]) != h){
                isUniformedSpaced = false;
                break;
            }
        }
    }

    void addData(int n, double* x, double* y) {
        size = n;
        xData = x;
        functionData = y;
        determineIfUniformedSpaced();
    }

    double delta(int k, int i = 0){
        if(k == 1) return (functionData[i+1]-functionData[i]);
        return delta(k-1, i+1) - delta(k-1, i);
    }

    int getFactorial(int n){
        int result = 1;
        for(int i = 2; i <= n; i++) result *= i;
        return result;
    }

    string calculateInterpolation(){
        return isUniformedSpaced ? calculateUniformedSpacedInterpolation(xData[1]-xData[0]) : calculateManualInterpolation();
    }

    string calculateManualInterpolation(){
        string result = "";
        int splitDifferencesSize = size;
        for(int i = 0; i < size; i++){
            result += to_string(functionData[0]);
            for(int j = 0; j < i; j++){
                result += "*(x - " + to_string(xData[j]) + ")";
            }
            for(int j = 0; j < splitDifferencesSize; j++){
                functionData[j] = (functionData[j+1]-functionData[j])/(xData[j+ i + 1]-xData[j]);
            }

            splitDifferencesSize--;
            if(i != size - 1) result += " + ";
        }

        return result;
    }

    string calculateUniformedSpacedInterpolation(double h){
        string result = to_string(functionData[0]);
        int splitDifferencesSize = size;
        string s = "(x - " + to_string(xData[0]) + ")/" + to_string(h);
        for(int i = 1; i < size; i++){
            result += " + " + to_string(delta(i)/getFactorial(i));
            for(int j = 0; j < i; j++){
                result += "*" + s + " - " + to_string(j);
            }
            splitDifferencesSize--;
        }

        return result;
    }
};

#endif