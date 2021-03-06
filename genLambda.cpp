#include <iostream>
#include <fstream>
#include <vector>
#include "config.h"
#include "list.h"
using namespace std;

// two path version

int main() {
    ofstream ofs;
    vector<double> vec;
    double tempi = 1;
    for (int i=0; i<PARAMETER_N; i++) {
        tempi /= 2.0;
        double tempj = 1;
        for (int j=0; j<PARAMETER_N; j++) {
            tempj /= 2.0;
            if(i == PARAMETER_N-1) 
                tempi = 0;
            if(j == PARAMETER_N-1)
                tempj = 0;
            vec.push_back(1-(tempi+tempj)/2.0);
        }
    }
    list_write(vec, LAMBDA_FILE);
    cout << "lambdas generaged" << endl;
    return 0;
}