#pragma once

#include <vector>
#include <fstream>
#include <thread>
#include "gmp.h"
#include "config.h"
#include "list.h"
using namespace std;

long current_n;
bool stopQ;

void report_n(string title) {
    while(stopQ == 0) {
        this_thread::sleep_for(chrono::seconds(1));
        cout << title;
        cout << "(calculating: " << current_n << " | " << (double) current_n/ PARAMETER_T  * 100.0 << "\%)            \r"  << flush;
    }
}

double compute_ax(double x) {
    // calculate
    // \sum_{n=s}^t \frac{x^n}{n^2}
    mpq_t sq; // partial sum
    mpq_t xq; // x
    mpq_t xnq; // x^n
    mpq_t nq; // n
    mpq_t n2q; // n^2 
    mpq_t enq; // entry
    mpq_t oneq; // 1
    mpq_inits(sq, xq, xnq, nq, n2q, enq, oneq, NULL);

    mpq_set_d(xq, x);
    mpq_set_ui(xnq, 1, 1);
    mpq_set_ui(oneq, 1, 1);
    mpq_set_ui(nq, PARAMETER_S, 1);
    mpq_init(sq);

    for(long n = 1; n <= PARAMETER_S; n++) {
        mpq_mul(xnq, xnq, xq);
    }
    string title = "a(" + to_string(x) + ") = ";
    current_n = 0;
    stopQ = 0;
    // thread th(report_n, title);
    for(long n = PARAMETER_S; n <= PARAMETER_T; n++) {
        current_n = n;
        mpq_mul(n2q, nq, nq); // n^2
        mpq_div(enq, xnq, n2q); // x^n/n^2
        mpq_add(sq, sq, enq); // add to the partial sum

        mpq_add(nq, nq, oneq); // n
        mpq_mul(xnq, xnq, xq); // x^n
    }
    stopQ = 1;
    // th.join();

    double ax;
    ax = mpq_get_d(sq);
    mpq_clears(sq, xq,xnq,nq,n2q,enq,oneq,NULL);
    return ax;
}

double compute_bx(double x) {
    // calculate
    // \sum_{n=s}^t \frac{x^n}{n}
    mpq_t sq; // partial sum
    mpq_t xq; // x
    mpq_t xnq; // x^n
    mpq_t nq; // n
    mpq_t enq; // entry
    mpq_t oneq; // 1
    mpq_inits(sq, xq, xnq, nq, enq, oneq, NULL);

    mpq_set_d(xq, x);
    mpq_set_ui(xnq, 1, 1);
    mpq_set_ui(oneq, 1, 1);
    mpq_set_ui(nq, PARAMETER_S, 1);
    mpq_init(sq);

    for(long n = 1; n <= PARAMETER_S; n++) {
        mpq_mul(xnq, xnq, xq);
    }
    string title = "b(" + to_string(x) + ") = ";
    current_n = 0;
    stopQ = 0;
    // thread th(report_n, title);
    for(long n = PARAMETER_S; n <= PARAMETER_T; n++) {
        current_n = n;
        mpq_div(enq, xnq, nq); // x^n/n
        mpq_add(sq, sq, enq); // add to the partial sum

        mpq_add(nq, nq, oneq); // n
        mpq_mul(xnq, xnq, xq); // x^n
    }
    stopQ = 1;
    // th.join();

    double bx;
    bx = mpq_get_d(sq);
    mpq_clears(sq, xq,xnq,nq,enq,oneq,NULL);
    return bx;
}

void compute_axlist() {
    vector<double> lambda;
    vector<double> ax;
    list_read(lambda, LAMBDA_FILE);
    cout << "calculating ax list" << endl;
    for(int k = ax.size(); k<lambda.size(); k++ ) {
        // cout << k << endl;
        // cout << lambda[k] << endl;
        ax.push_back(compute_ax(lambda[k]));
        cout << "\r" << k << "\t\t(" << (double)k/lambda.size()*100.0 << "\%)" << WHITESPACE << flush;
    }
    list_write(ax, AX_FILE);
    cout << "ax list completed" << WHITESPACE << endl;
    return;
}

void compute_bxlist() {
    vector<double> lambda;
    vector<double> bx;
    list_read(lambda, LAMBDA_FILE);
    cout << "calculating bx list" << endl;
    for(int k = bx.size(); k<lambda.size(); k++ ) {
        bx.push_back(compute_bx(lambda[k]));
        cout << "\r" << k << "\t\t(" << (double)k/lambda.size()*100.0 << "\%)" << WHITESPACE << flush;
    }
    list_write(bx, BX_FILE);
    cout << "bx list completed" << WHITESPACE << endl;
    return;
}