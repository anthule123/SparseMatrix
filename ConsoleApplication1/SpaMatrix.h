#pragma once

#include <iostream>
#include<vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm>    // std::sort
#include<cmath>
using namespace std;
class Vecto {
public:
    vector<double> b;
    int n;
    void build(vector<double>& temb) {
        n = temb.size();
        b = temb;
    }
    void construct(int tempn) {
        n = tempn;
        b = vector<double>(n, 0);
        for (int i = 0; i < n; i++) {
            b[i] = rand() % 100 - 50;
        }
    }
    void show() {
        cout << "Vector ";
        cout << "[ ";
        for (int i = 0; i < n-1; i++) {
            cout << b[i] << " ,";
        }
        if(n>=1) cout << b[n - 1];
        cout << "] " << endl;
    }
    void normalize() {
        double sqchuan = 0;
        for (int i = 0; i < n; i++) {
            sqchuan += b[i]*b[i];
        }
        double chuan = sqrt(sqchuan);
        for (int i = 0; i < n; i++) {
            b[i] = b[i] / chuan;
        }
    }
};

class SpaMatrix
{
public:
    int n, k;
    vector<vector<pair <int, double>  > > row;

    void construct(int tempn, int tempk) {
        n = tempn;
        k = tempk;
        row = vector< vector<pair<int, double> > >(n, vector<pair<int, double> >());
        for (int i = 0; i < n; i++) {
            vector<int> c(n, 0);
            for (int j = 0; j < k; j++) {
                double a = rand() % 100 - 50;
                int pos = rand() % n;
                if (c[pos] == 1) continue;
                else {
                    c[pos] = 1;
                    row[i].push_back(make_pair(pos, a));
                }
            }
            sort(row[i].begin(), row[i].end());
        }
    }
    void show() {
        cout << "n va k" << n << "   " << k << endl;
        for (int i = 0; i < n; i++) {
            cout << "Hang " << i + 1 << " : " << endl;
            for (int j = 0; j < row[i].size(); j++) {
                cout << "Vi tri " << row[i][j].first + 1 << ", va gia tri  " << row[i][j].second << " ;  ";
            };
        }
    }
    void showTab() {
        for (int i = 0; i < n; i++) {
            int r = 0;
            for (int j = 0; j < n; j++) {
                if (r < row[i].size() && row[i][r].first == j) {
                    cout << row[i][r].second << " ";
                    r++;
                }
                else cout << "0 ";
            }
            cout << endl;
        }
    }
};

