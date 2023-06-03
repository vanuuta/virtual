#include"sphere.h"
// Конструктор по умолчанию
sphere::sphere() {
	radius = 1; SQUARE = 4 * PI;
}

// Конструктор с параметром
sphere::sphere(float x) {
	radius = x;
}

// Конструктор копирования
sphere::sphere(sphere& x) {
	radius = x.radius;
}

// Площадь поверхности 
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