#include"sphere.h"
// ����������� �� ���������
sphere::sphere() {
	radius = 1; SQUARE = 4 * PI;
}

// ����������� � ����������
sphere::sphere(float x) {
	radius = x;
}

// ����������� �����������
sphere::sphere(sphere& x) {
	radius = x.radius;
}

// ������� ����������� 
float sphere::getSquare() {
	SQUARE = 4 * PI * radius * radius;
	return SQUARE;
}
float sphere::getSquare(int x) {
	radius = x;
	SQUARE = 4 * PI * radius * radius;
	return SQUARE;
}

float sphere::get() {
	return SQUARE;
}
void sphere::print() {
	cout << SQUARE << endl;
}