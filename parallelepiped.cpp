#include"parallelepiped.h"

// ����������� �� ���������
parallelepiped::parallelepiped() {
	a = b = c = 1; SQUARE = 6;
}

// ����������� � ����� ����������� (�����, ������, ������)
parallelepiped::parallelepiped(float x, float y, float z) {
	a = x; b = y; c = z; SQUARE = (a * b + b * c + a * c) * 2;
}

// ����������� �����������
parallelepiped::parallelepiped(parallelepiped& x) {
	a = x.a; b = x.b; c = x.c;
}

// ������� �����������
float parallelepiped::getSquare() {
	SQUARE = 2 * (a * b + a * c + b * c);
	return SQUARE;
}
float parallelepiped::getSquare(int x,int y,int z) {
	a = x; b = y; c = z;
	SQUARE = 2 * (a * b + a * c + b * c);
	return SQUARE;
}
float parallelepiped::get() {
	return SQUARE;
}
void parallelepiped::print() {
	cout << SQUARE << endl;
}