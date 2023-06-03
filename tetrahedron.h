#pragma once
#include"square.h"
class tetrahedron : public square {
public:
	tetrahedron();
	tetrahedron(float x);
	tetrahedron(tetrahedron& x);
	~tetrahedron(){};
	float getSquare();
	float getSquare(int x);
	float get();
	void print();
private:
	float a,SQUARE;
};