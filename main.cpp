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
	cout << "Исходные данные: " << endl;
	cout << "(1) Ввод вручную" << endl;
	cout << "(2) Чтение данных из файла" << endl;
	cout << "(3) Ссылки на абстрактный класс" << endl;
	cout << "(4) Выход из программы" << "(Результат работы программы находится в файле result.txt)" << endl;
	cin >> input;
	if (input > 4 || input < 1) {
		cout << "Неизвестное действие!";
		system("pause");
		system("cls");
		menu();
	}
}

void Menu() {
	cout << "Выберите геометрическое тело: " << endl;
	cout << "(1) Параллелепипед" << endl;
	cout << "(2) Тетраэдр" << endl;
	cout << "(3) Сфера" << endl;
	cout << "(4) Назад" << endl;
	cin >> stateMenu;
	if (stateMenu > 4 || stateMenu < 1) {
		cout << "Неизвестное действие!";
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
		//Ввод вручную
		case 1: {
			Menu(); system("cls");
			while (stateMenu != 4) {
				switch (stateMenu)
				{
				case 1: {
					float x, y, z;
					cout << "Введите длину: "; cin >> x;
					cout << "Введите ширину: "; cin >> y;
					cout << "Введите высоту: "; cin >> z;
					p = new parallelepiped(x, y, z);
					mas[num] = p;
					p->getSquare();
					out << p->getSquare() << endl;
					break;
				}
				case 2: {
					float a;
					cout << "Введите длину ребра тетраэдра: "; cin >> a;
					t = new tetrahedron(a);
					mas[num] = t;
					t->getSquare();
					out << t->getSquare() << endl;
					break;
				}
				case 3: {
					float r;
					cout << "Введите радиус сферы: "; cin >> r;
					s = new sphere(r);
					mas[num] = s;
					s->getSquare();
					out << s->getSquare() << endl;
					break;
				}
				default: {
					cout << "Неизвестное действие." << endl;
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
		//Чтение из файла
		case 2: {
			loop1:
				string filename;
				cout << "Введите название файла: (Пример: data.txt)" << endl;
				cin >> filename;
				system("cls");
				ifstream in(filename);
				if (!in.is_open()) {
					cout << "Файл не найден";
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
		cout << "Данные считаны успешно!" << endl;
		break;
		}
		//Массив ссылок
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