#pragma once
#include"square.h"
class sphere :public square {
public:
	sphere();
	sphere(float x);
	sphere(sphere& x);
	float getSquare();
	float getSquare(int x);
	float get();
	void print();
	~sphere() {};
private:
	float radius, SQUARE;
};