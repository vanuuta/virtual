#include"tetrahedron.h"
//#define DEBUG
// ������� �����������
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
// ����������� �� ���������
tetrahedron::tetrahedron() {
	a = 1; SQUARE = sqrt(3);
}

// ����������� � ����� ���������� (����� �����)
tetrahedron::tetrahedron(float x) {
	a = x;
}
// ����������� �����������
tetrahedron::tetrahedron(tetrahedron& x) {
	a = x.a;
}
