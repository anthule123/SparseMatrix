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
using namespace std;

int main()
{
    std::cout << "Hello World \n";
    srand(time(NULL));
    SpaMatrix emT;
    emT.construct(5, 1);
    emT.show();
    emT.showTab();

    Vecto b;
    b.construct(5);
    b.show();
    Vecto c = nhanSpaMatrix(emT, b);
    c.normalize();
    c.show();
    Vecto d = sum(c, b);
    d.show();
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
