#pragma once

#include <fstream>
#include <iostream>
#include <vector>
#include "config.h"
using namespace std;

void list_read(vector<double>& vec, const char* filename) {
    ifstream ifs;
    ifs.open(filename);
    if(ifs.fail()) {
        cerr << "Fail to open list file " << filename << endl;
        exit(-1);
    }
    char temp=0;
    vec.clear();
    double tempd=0;
    while(ifs >> tempd) {
        vec.push_back(tempd);
    }
    ifs.close();
    return;
}

void list_write(const vector<double>& vec, const char* filename) {    
    ofstream ofs;
    ofs.open(filename);
    ofs.precision(12);
    for(auto& d : vec) {
        ofs << fixed << d << '\n';
    }
    ofs.close();
    return;
}