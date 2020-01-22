#include <iostream>
#include <vector>
#include "list.h"
using namespace std;

int index(int i, int j) {
    return i*PARAMETER_N + j;
}

int main() {
    vector<double> vec;
    vector<double> ax, bx;
    list_read(ax, AX_FILE);
    list_read(bx, BX_FILE);
    if (ax.size() != PARAMETER_N*PARAMETER_N) {
        cout << "ax list incorrect size" << endl;
    }
    if (bx.size() != PARAMETER_N*PARAMETER_N) {
        cout << "bx list incorrect size" << endl;
    }
    for (int i=0; i<PARAMETER_N; i++) {
        for (int j=0; j<PARAMETER_N; j++) {
            if ( i == 0) {
                if ( j == 0) {
                    vec.push_back (
                        (bx[index(i,j)] )
                        /
                        (ax[index(i,j)] )
                    );
                } else {
                    vec.push_back (
                        (bx[index(i,j)] - bx[index(i,j-1)] )
                        /
                        (ax[index(i,j)] - ax[index(i,j-1)] )
                    );
                }
            } else {
                if ( j == 0) {
                    vec.push_back (
                        (bx[index(i,j)] - bx[index(i-1,j)] )
                        /
                        (ax[index(i,j)] - ax[index(i-1,j)] )
                    );
                } else {
                    vec.push_back (
                        (bx[index(i,j)] - bx[index(i-1,j)] - bx[index(i,j-1)] + bx[index(i-1,j-1)])
                        /
                        (ax[index(i,j)] - ax[index(i-1,j)] - ax[index(i,j-1)] + ax[index(i-1,j-1)])
                    );
                }
            }
        }
    }
    list_write(vec, GI_FILE);
    cout << "estimates generaged" << endl;
    ofstream ofs;
    ofs.open(GI_ARRAY_FILE);
    for(int i=0; i<PARAMETER_N; i++) {
        for(int j=0; j<PARAMETER_N; j++) {
            ofs << vec[index(i,j)] << "\t\t";
        }
        ofs << endl;
    }
    ofs.close();
    return 0;
}