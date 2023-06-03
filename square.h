#pragma once
#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#define PI 3.14159265 
using namespace std;
class square {
public:
	virtual float getSquare() = 0;
	virtual float get() = 0;
	virtual void print() = 0;
};