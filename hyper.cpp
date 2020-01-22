#include <iostream>
#include <fstream>
#include <vector>
#include "list.h"
using namespace std;

int main() {
    ofstream ofs;
    ofs.open(HYPER_FILE);
    double tempi = 1;
    for (int i=0; i<PARAMETER_N; i++) {
        tempi /= 2.0;
        double tempj = 1;
        for (int j=0; j<PARAMETER_N; j++) {
            tempj /= 2.0;
            ofs << 0.5 * 4.0 / (tempi + tempj) << "\t\t";
        }
        ofs << endl;
    }
    ofs.close();
    return 0;
}