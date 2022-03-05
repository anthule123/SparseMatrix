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
    vector<double> core;
    int size;
    void build(vector<double>& temb) {
        size = temb.size();
        core = temb;
    }
    void build0(int n) {
        size = n;
        core = vector<double>(n, 0);
    }
    void buildq1(int n) { //vecto kieu (1,0,0,0,...)
        size = n;
        core = vector<double>(n, 0);
        core[0] = 1;
    }
    void construct(int tempsize) {
        size = tempsize;
        core.assign(tempsize, 0);
        for (int i = 0; i < tempsize; i++) {
            core[i] = rand() % 100 - 50;
        };
    }
    void buildvd() {
        size = 5;
        core.assign(5, 0);
        core[0] = 27;
        core[1] = -25;
        core[2] = 32;
        core[3] = -43;
        core[4] = 15;
    }
    void show() {
        cout << "Vector ";
        cout << "[ ";
        for (int i = 0; i < size - 1; i++) {
            cout << core[i] << " ,";
        }
        if (size >= 1) cout << core[size - 1];
        cout << "] " << endl;
    }
    void normalize() {
        double sqchuan = 0;
        for (int i = 0; i < size; i++) {
            sqchuan += core[i] * core[i];
        };
        double chuan = sqrt(sqchuan);
        for (int i = 0; i < size; i++) {
            core[i] = core[i] / chuan;
        };
    }
    double norm2() {
        double sqchuan = 0;
        for (int i = 0; i < size; i++) {
            sqchuan += core[i] * core[i];
        }
        return sqrt(sqchuan);
    }
};

Vecto normali(Vecto B) {
    Vecto ans = B;
    ans.normalize();
    return ans;
}
class SpaMatrix
{
public:
    int size, k;
    vector<vector<pair <int, double>  > > row;
    void construct(int tempn, int tempk) {
        size = tempn;
        k = tempk;
        row = vector< vector<pair<int, double> > >(size, vector<pair<int, double> >());
        for (int i = 0; i < size; i++) {
            vector<int> c(size, 0);
            for (int j = 0; j < k; j++) {
                double a = rand() % 100 - 50;
                int pos = rand() % size;
                if (c[pos] == 1) continue;
                else {
                    c[pos] = 1;
                    row[i].push_back(make_pair(pos, a));
                }
            }
            sort(row[i].begin(), row[i].end());
        }
    }
    void buildvd() {
        size = 5;
        k = 2;
        row = vector< vector<pair<int, double> > >(size, vector<pair<int, double> >());
        row[0].push_back(make_pair(4, 4));
        row[1].push_back(make_pair(3, 15));
        row[1].push_back(make_pair(4, 17));
        row[2].push_back(make_pair(1,9));
        row[2].push_back(make_pair(2,-43));
        row[3].push_back(make_pair(0, 19));
        row[3].push_back(make_pair(0,-15));
        row[4].push_back(make_pair(0, 19));
        row[4].push_back(make_pair(2, 47));
    }
    void show() {
        cout << "kich thuoc va k" << size << "   " << k << endl;
        for (int i = 0; i < size; i++) {
            cout << "Hang " << i + 1 << " : " << endl;
            for (int j = 0; j < row[i].size(); j++) {
                cout << "Vi tri " << row[i][j].first + 1 << ", va gia tri  " << row[i][j].second << " ;  ";
            };
        }
    }
    void showTab() {
        for (int i = 0; i < size; i++) {
            int r = 0;
            int j = 0;
            while (r < size) {
                if (j<row[i].size()) {
                    if (r == row[i][j].first) {
                        cout << row[i][j].second << " ";
                        r++;
                        j++;
                    }
                    else {
                        cout << "0 ";
                        r++;
                    }
                }
                else {
                    cout << "0 ";
                    r++;
                }
            }
            cout << endl;
        }
    }
};

