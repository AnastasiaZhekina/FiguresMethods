#include <iostream>
#include <string>
using namespace std;

class Figure {
protected:
	int side = 0;
	string s = "Правильная";
public: 
	Figure (int n, string a): side(n), s(a) {}
	Figure(){}
	
	 virtual void show3() {
		cout << s << endl << "Количество сторон: " << side << endl;
	}

};
class Triangle : public Figure {
	int a = 10, b = 20, c = 30;
	int A = 50, B = 60, C = 70;
public:
	Triangle() : Figure( 3, "Правильная") {}
	Triangle(int p_a, int p_b, int p_c, int p_A, int p_B, int p_C) {
		a = p_a; b = p_b; c = p_c;
		A = p_A; B = p_B; C = p_C;
	}
	

	void show() {
		cout << "Стороны: " << "a = " << a << " b = " << b << " c = " << c << endl;
		cout << "Углы: " << "A = " << A << " B = " << B << " C = " << C << endl << endl;
	}
};
class Rectangular : public Triangle {
public:
	Rectangular() :Triangle(10, 20, 30, 50, 60, 90) {
		side = 3;
		s = "Неправильный";
	}
};
class Rectangular2 : public Triangle {
public:
	Rectangular2() :Triangle(10, 20, 30, 50, 40, 90) {
		side = 3;
		s = "Правильная";
	}
};
class Isosceles : public Triangle {
public:
	Isosceles() :Triangle(10, 20, 10, 50, 60, 50) {
		side = 3;
			s = "Неправильная";
	}
};
class Equilateral : public Triangle {
public:
	Equilateral() :Triangle(30, 30, 30, 60, 60, 60) {
		side = 3;
		s = "Правильная";
	}
};

class Quadrilateral : public Figure {
	int a = 10, b = 20, c = 30, d = 40;
	int A = 50, B = 60, C = 70, D = 80;
public:
	Quadrilateral(): Figure (4, "Неправильная") {}
	Quadrilateral(int p_a, int p_b, int p_c, int p_d, int p_A, int p_B, int p_C, int p_D) {
		a = p_a; b = p_b; c = p_c; d = p_d;
		A = p_A; B = p_B; C = p_C; D = p_D;
	}
	

	void show2() {
		
		cout << "Стороны: " << "a = " << a << " b = " << b << " c = " << c << " d = " << d << endl;
		cout << "Углы: " << "A = " << A << " B = " << B << " C = " << C << " D = " << D << endl << endl;
		;
	}
};
class Rectangle :  public  Quadrilateral {
public:
	
	Rectangle() : Quadrilateral(10, 20, 10, 20, 90, 90, 90, 90) {
		side = 4;
		s = "Правильная";
	}
};
class Square : public  Quadrilateral {
public:
	Square() : Quadrilateral(20, 20, 20, 20, 90, 90, 90, 90) {
		side = 4;
		s = "Правильная";
	}
};
class Parallelogram : public  Quadrilateral {
public:
	Parallelogram() : Quadrilateral(20, 30, 20, 30, 30, 40, 30, 40) {
		side = 4;
		s = "Неправильная";
	}
};
class Rhombus : public  Quadrilateral {
public:
	Rhombus() : Quadrilateral(30, 30, 30, 30, 30, 40, 30, 40) {
		side = 4;
		s = "Неправильная";
	}
};
int main() {

	setlocale(LC_ALL, "Russian");
	
	Figure fig;
	cout << "Фигура: " << endl;
	fig.show3();

	cout << endl;

	Triangle tri;
	cout << "Треугольник: " << endl;
	tri.show3();
	tri.show();

	Rectangular rec;
	cout << "Прямоугольный треугольник: " << endl;
	rec.show3();
	rec.show();

	Rectangular rec2;
	cout << "Прямоугольный треугольник: " << endl;
	rec2.show3();
	rec2.show();

	Isosceles iso;
	cout << "Равнобедренный треугольник: " << endl;
	iso.show3();
	iso.show();

	Equilateral equ;
	cout << "Равносторонний треугольник: " << endl;
	equ.show3();
	equ.show();

	Quadrilateral qua;
	cout << "Четырёхугольник: " << endl;
	qua.show3();
	qua.show2();

	Rectangle rect;
	cout << "Прямоугольник: " << endl;
	rect.show3();
	rect.show2();

	Square squ;
	cout << "Квадрат: " << endl;
	squ.show3();
	squ.show2();

	Parallelogram par;
	cout << "Параллелограмм: " << endl;
	par.show3();
	par.show2();

	Rhombus rho;
	cout << "Ромб: " << endl;
	rho.show3();
	rho.show2();
};