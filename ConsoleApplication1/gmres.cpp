// vuive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm>    // std::sort
#include <iomanip>
#include "SpaMatrix.h"
#include "lib2.h"
#include "arnoldi.h"
using namespace std;

int main()
{
    std::cout << "Hello World \n";
    cout << setprecision(20);
    srand(time(NULL));
    SpaMatrix A;
    //A.construct(5, 2);
    A.buildvd();
    A.show();
    A.showTab();

    Vecto b;
   // b.construct(5);
    b.buildvd();
    b.normalize(); //gia su rang b co chuan = 1
    b.show();

    int n = 5;
    int m = 3;//so lan lap
    Vecto r = subtract(b, nhanSpaMatrix(A, b));
    double b_norm = b.norm2();
    double error = r.norm2() / b_norm;
    Vecto q0;
    q0.buildq1(5);
    vector<Vecto> Q;
    vector<vector<double> > h;
    h.assign(4, vector<double>(3,0));
    Q.push_back(b);
    double eps = 1e-12;

    for (int k = 1; k < 4; k++) {
        Vecto v = nhanSpaMatrix(A, Q[k - 1]);
        for (int j = 0; j < k; j++) {
            h[j][k - 1] = dot(v, Q[j]);
            v = subtract(v, mulScala(h[j][k - 1], Q[j]));
        }
        h[k][k - 1] = v.norm2();
        v.normalize();
        if (h[k][k - 1] > eps) {
            Q.push_back(v);
        }
        else break;
    }
    cout << "Q"<<endl;
    for (int i = 0; i < Q.size(); i++) {
        Q[i].show();
    }
    cout << "Hess";
    for (int i = 0; i < h.size(); i++) {
        for (int j = 0; j < h[i].size(); j++) {
            cout << h[i][j] << "  ";
        }
        cout << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
