#include"windows.h"
#include"parallelepiped.h"
#include"tetrahedron.h"
#include"sphere.h"
//#define MENU
using namespace std;
int stateMenu;
int input;
int num = 0;
square* mas[100] = { 0 };
void menu() {
	cout << "�������� ������: " << endl;
	cout << "(1) ���� �������" << endl;
	cout << "(2) ������ ������ �� �����" << endl;
	cout << "(3) ������ �� ����������� �����" << endl;
	cout << "(4) ����� �� ���������" << "(��������� ������ ��������� ��������� � ����� result.txt)" << endl;
	cin >> input;
	if (input > 4 || input < 1) {
		cout << "����������� ��������!";
		system("pause");
		system("cls");
		menu();
	}
}

void Menu() {
	cout << "�������� �������������� ����: " << endl;
	cout << "(1) ��������������" << endl;
	cout << "(2) ��������" << endl;
	cout << "(3) �����" << endl;
	cout << "(4) �����" << endl;
	cin >> stateMenu;
	if (stateMenu > 4 || stateMenu < 1) {
		cout << "����������� ��������!";
		system("pause");
		system("cls");
		Menu();
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
#ifndef MENU
	menu();
	system("cls");
	tetrahedron* t; parallelepiped* p;sphere* s;
	ofstream out;
	out.open("result.txt");
	while (input != 4) {
		switch (input)
		{
		//���� �������
		case 1: {
			Menu(); system("cls");
			while (stateMenu != 4) {
				switch (stateMenu)
				{
				case 1: {
					float x, y, z;
					cout << "������� �����: "; cin >> x;
					cout << "������� ������: "; cin >> y;
					cout << "������� ������: "; cin >> z;
					p = new parallelepiped(x, y, z);
					mas[num] = p;
					p->getSquare();
					out << p->getSquare() << endl;
					break;
				}
				case 2: {
					float a;
					cout << "������� ����� ����� ���������: "; cin >> a;
					t = new tetrahedron(a);
					mas[num] = t;
					t->getSquare();
					out << t->getSquare() << endl;
					break;
				}
				case 3: {
					float r;
					cout << "������� ������ �����: "; cin >> r;
					s = new sphere(r);
					mas[num] = s;
					s->getSquare();
					out << s->getSquare() << endl;
					break;
				}
				default: {
					cout << "����������� ��������." << endl;
					system("pause"); system("cls");
					Menu();
					break;
				}
				}
				num++;
				system("pause"); system("cls");
				Menu();
				}
			break;
		}
		//������ �� �����
		case 2: {
			loop1:
				string filename;
				cout << "������� �������� �����: (������: data.txt)" << endl;
				cin >> filename;
				system("cls");
				ifstream in(filename);
				if (!in.is_open()) {
					cout << "���� �� ������";
					goto loop1;
				}
				float c;
				in >> c; 
				int x = c;
				string type;
				for (int i = 0; i < x; i++) {
					in >> type; 
					if (!type.compare("tetrahedron")) {
						in >> c;
						t = new tetrahedron(c);
						mas[num] = t;
						t->getSquare();
						out << t->getSquare() << endl;
					}
					if (!type.compare("parallelepiped")) {
						float a, b, c;
						in >> a >> b >> c;
						p = new parallelepiped(a, b, c);
						mas[num] = p;
						p->getSquare();
						out << p->getSquare() << endl;
					}
					if (!type.compare("sphere")) {
						float r;
						in >> r;
						s = new sphere(r);
						mas[num] = s;
						s->getSquare();
						out << s->getSquare() << endl;
					}
					num++;
				}
		cout << "������ ������� �������!" << endl;
		break;
		}
		//������ ������
		case 3: {
			
			for (int i = 0; i < num; i++) {
				cout << mas[i]/*->getSquare()*/ << endl;
			}
			break;
		}
		}
		system("pause"); system("cls");
		menu();
	}
	system("pause");
#else
	ifstream in("data.txt");
	float c;
	in >> c;
	int x = c;
	string type;
	
	for (int i = 0; i < x; i++) {
		in >> type;
		cout << type << endl;
		if (!type.compare("tetrahedron")) {
			in >> c;
			tetrahedron t(c);
			t.getSquare();
			mas[num] = &t;
			t.~tetrahedron();
			cout << "tetra: " << &t << " " << mas[num]->getSquare() << endl;
			//t.getSquare();
		}
		if (!type.compare("parallelepiped")) {
			float a, b, c;
			in >> a >> b >> c;
			parallelepiped p(a, b, c);
			p.getSquare();
			mas[num] = &p;
			p.~parallelepiped();
			cout << "paral: " << &p << " " << mas[num]->getSquare() << endl;
			//t.getSquare();
		}
		if (!type.compare("sphere")) {
			float r;
			in >> r;
			sphere s(r);
			s.getSquare();
			mas[num] = &s;
			s.~sphere();
			cout << "sphere: " << &s << " " << mas[num]->getSquare() << endl;
			//t.getSquare();
		}
		num++;
		cout << endl << "-------------------------------" << endl;
	}
	cout << num << endl;
	for (int i = 0; i < num; i++) {
		cout << mas[i] << endl;
	}
	/*string s;
	in >> s;
	cout << int(s[0])-48 << endl;
	in >> s;
	cout << s << endl;*/
#endif 
	return 0;
}