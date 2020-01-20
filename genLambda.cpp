#include <iostream>
using namespace std;

int main() {
    int n =32;
    double temp = 1;
    for (int i=0; i<n; i++) {
        temp /= 2.0;
        cout << temp << endl;
    }
    return 0;
}