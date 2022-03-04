#pragma once
using namespace std;
#include<iostream>
#include<stdio.h>
class Bubble
{
public:
	int x, y;
	void construct(int tempx, int tempy) {
		x = tempx;
		y = tempy;
	}
	void show() {
		cout << "x " << x;
	}
};

