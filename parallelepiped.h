#pragma once
#include"square.h"
class parallelepiped :public square {
public:
	parallelepiped();
	parallelepiped(float x, float y, float z);
	parallelepiped(parallelepiped& x);
	~parallelepiped() {};
	float getSquare();
	float getSquare(int x,int y,int z);
	float get();
	void print();
private:
	float a, b, c, SQUARE;
};