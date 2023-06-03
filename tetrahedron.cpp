#include"tetrahedron.h"
//#define DEBUG
// Площадь поверхности
float tetrahedron::getSquare() {
	SQUARE = 0.5 * a * a * sin(PI / 3) * 4;
	return SQUARE;
}
float tetrahedron::getSquare(int x) {
	a = x;
	SQUARE = 0.5 * a * a * sin(PI / 3) * 4;
	return SQUARE;
}
float tetrahedron::get() {
	return SQUARE;
}
void tetrahedron::print() {
	cout << SQUARE << endl;
}
// Конструктор по умолчинаю
tetrahedron::tetrahedron() {
	a = 1; SQUARE = sqrt(3);
}

// Конструктор с одним параметром (длина ребра)
tetrahedron::tetrahedron(float x) {
	a = x;
}
// Конструктор копирования
tetrahedron::tetrahedron(tetrahedron& x) {
	a = x.a;
}
