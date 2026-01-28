#ifndef SPLIT_DIFFERENCES_H
#define SPLIT_DIFFERENCES_H

#include <string>

using namespace std;


class SplitDifferences {
    private:
    int size;
    double* xData;
    double* functionData;

    public:
    SplitDifferences(int n, double* x, double* y) : size(n), xData(x), functionData(y) {};
    SplitDifferences(){};

    void addData(int n, double* x, double* y) {
        size = n;
        xData = x;
        functionData = y;
    }

    string calculateInterpolation(){
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
};

#endif