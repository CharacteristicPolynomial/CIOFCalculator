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
    while(temp != '=') {
        if(ifs.eof()) {
            ifs.close();
            return;
        }
        temp = ifs.get();
    }
    double tempd=0;
    while(ifs >> tempd) {
        vec.push_back(tempd);
    }
    ifs.close();
    return;
}

void list_write(const vector<double>& vec, const char* filename) {
    ifstream ifs;
    ifs.open(filename);
    string str;
    if(!ifs.fail()) {
        // if the output file already exists
        // then we will save the comments
        char temp=0;
        while(temp != '=') {
            if(ifs.eof()) {
                str += '\n';
                str += '=';
                break;
            }
            temp = ifs.get();
            str += temp;
        }
    } else {
        str += '\n';
        str += '=';
    }
    ifs.close();
    
    ofstream ofs;
    ofs.open(filename, ios_base::trunc);
    ofs << str << endl;
    for(auto& d : vec) {
        ofs << d << '\n';
    }
    ofs.close();
    return;
}