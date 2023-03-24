#include <iostream>
using namespace std;


class Figure {
protected:
	string name = "Фигура";
	int side = 0;
public:
	virtual string gets() { return name; }
	virtual	int getxside() { return side; }
	virtual void print_info() {
		cout  << gets() << endl;
		if(check(side))
			cout <<  "Правильная";
		else cout << "Неправильная";
		cout << endl << "Количество сторон: " << getxside() << endl << endl;
	}
	virtual bool check(int a) { if (a == 0)return true; else return false; }
};

class Triangle : public Figure {
protected:
	int a = 10, b = 20, c = 30;
	int A = 50, B = 60, C = 70;
	string name = "Треугольник";
	int side = 3;
public:

	Triangle(string p_name, int p_a, int p_b, int p_c, int p_A, int p_B, int p_C) : a(p_a), b(p_b), c(p_c), A(p_A), B(p_B), C(p_C), name(p_name) {
		a = p_a; b = p_b; c = p_c;
		A = p_A; B = p_B; C = p_C;
		name = p_name;
	}
	string gets() override { return name; }
	int getxa() { return a; }
	int getxb() { return b; }
	int getxc() { return c; }
	int getxA() { return A; }
	int getxB() { return B; }
	int getxC() { return C; }
	int getxside() override { return side; }
	Triangle() {}

	void print_info() override {
		cout << gets() << endl;
		if (check(a, b , c, A, B, C))
			cout << "Правильная";
		else cout << "Неправильная";
		cout << endl  << "Количество сторон: " << getxside() << endl;
		cout << "Стороны: " << "a = " << getxa() << " b = " << getxb() << " c = " << getxc() << endl;
		cout << "Углы: " << "A = " << getxA() << " B = " << getxB() << " C = " << getxC() << endl << endl;
	}
	virtual bool check(int p_a, int p_b, int p_c, int p_A, int p_B, int p_C)  { if (180 == p_A+p_B+p_C)return true; else return false; }
};
class Rectangular : public Triangle {

public:
	Rectangular(string p_name, int p_a, int p_b, int p_c, int p_A, int p_B, int p_C) :Triangle(p_name, p_a, p_b, p_c, p_A, p_B, p_C) {}

	virtual bool check(int p_a, int p_b, int p_c, int p_A, int p_B, int p_C) { if (180 == p_A + p_B + p_C && p_C == 90)return true; else return false; }

};
class Isosceles : public Triangle {
public:
	Isosceles(string p_name, int p_a, int p_b, int p_c, int p_A, int p_B, int p_C) :Triangle(p_name, p_a, p_b, p_c, p_A, p_B, p_C) {}
		
virtual bool check(int p_a, int p_b, int p_c, int p_A, int p_B, int p_C) { if (180 == p_A + p_B + p_C && p_a == p_c && p_A == p_C)return true; else return false; }
};
class Equilateral : public Triangle {

public:
	Equilateral(string p_name, int p_a, int p_b, int p_c, int p_A, int p_B, int p_C) :Triangle(p_name, p_a, p_b, p_c, p_A, p_B, p_C) {}
	
		virtual bool check(int p_a, int p_b, int p_c, int p_A, int p_B, int p_C) { if (180 == p_A + p_B + p_C && p_a == p_b && p_b == p_c && p_A == 60 && p_B == 60 && p_C == 60) return true; else return false; }
};

class Quadrilateral :public Figure {
protected:
	int a = 10, b = 20, c = 30, d = 40;
	int A = 50, B = 60, C = 70, D = 80;
	string name = "Четырёхугольник: ";
	int side = 4;
public:
	Quadrilateral(string p_name, int p_a, int p_b, int p_c, int p_d, int p_A, int p_B, int p_C, int p_D) {
		a = p_a; b = p_b; c = p_c; d = p_d;
		A = p_A; B = p_B; C = p_C; D = p_D;
		name = p_name;
	}
	Quadrilateral() {}

	string gets() override { return name; }
	int getxa() { return a; }
	int getxb() { return b; }
	int getxc() { return c; }
	int getxd() { return d; }
	int getxA() { return A; }
	int getxB() { return B; }
	int getxC() { return C; }
	int getxD() { return D; }
	int getxside() override { return side; }
	void print_info() override {
		cout << gets() << endl;
		if (check(a, b, c, d, A, B, C, D))
			cout << "Правильная";
		else cout << "Неправильная";
		cout << endl << "Количество сторон: " << getxside() << endl;
		cout << "Стороны: " << "a = " << getxa() << " b = " << getxb() << " c = " << getxc() << " d = " << getxd() << endl;
		cout << "Углы: " << "A = " << getxA() << " B = " << getxB() << " C = " << getxC() << " D = " << getxD() << endl << endl;
	}
	virtual bool check(int p_a, int p_b, int p_c, int p_d, int p_A, int p_B, int p_C, int p_D) 
	{ if (360 == p_A + p_B + p_C + p_D)return true; else return false; }
};

class Rectangle : public  Quadrilateral {
public:
	Rectangle(string p_name, int p_a, int p_b, int p_c, int p_d, int p_A, int p_B, int p_C, int p_D) : Quadrilateral(p_name, p_a, p_b, p_c, p_d, p_A, p_B, p_C, p_D) {}
virtual bool check(int p_a, int p_b, int p_c, int p_d, int p_A, int p_B, int p_C, int p_D)
	{ if (360 == p_A + p_B + p_C + p_D && p_a == p_c && p_b == p_d && p_A == 90 && p_B == 90 && p_C == 90 && p_D == 90) return true; else return false; }
};

class Square : public  Quadrilateral {
public:
	Square(string p_name, int p_a, int p_b, int p_c, int p_d, int p_A, int p_B, int p_C, int p_D) : Quadrilateral(p_name, p_a, p_b, p_c, p_d, p_A, p_B, p_C, p_D) {}
virtual	bool check(int p_a, int p_b, int p_c, int p_d, int p_A, int p_B, int p_C, int p_D) 
	{ if (360 == p_A + p_B + p_C + p_D && p_a == p_c && p_c == p_b && p_b == p_d && p_d == p_a && p_A == 90 && p_B == 90 && p_C == 90 && p_D == 90)return true; else return false; }
};

class Parallelogram : public  Quadrilateral {
public:
	Parallelogram(string p_name, int p_a, int p_b, int p_c, int p_d, int p_A, int p_B, int p_C, int p_D) : Quadrilateral(p_name, p_a, p_b, p_c, p_d, p_A, p_B, p_C, p_D) {}
	virtual bool check(int p_a, int p_b, int p_c, int p_d, int p_A, int p_B, int p_C, int p_D) 
	{ if (360 == p_A + p_B + p_C + p_D && p_a == p_c && p_b == p_d && p_A == p_C && p_B == p_D)return true; else return false; }
};

class Rhombus : public  Quadrilateral {
public:
	Rhombus(string p_name, int p_a, int p_b, int p_c, int p_d, int p_A, int p_B, int p_C, int p_D) : Quadrilateral(p_name, p_a, p_b, p_c, p_d, p_A, p_B, p_C, p_D) {}
	virtual bool check(int p_a, int p_b, int p_c, int p_d, int p_A, int p_B, int p_C, int p_D)
	{if (360 == p_A + p_B + p_C + p_D && p_a == p_c && p_c == p_b && p_b == p_d && p_d == p_a && p_A == p_C && p_B == p_D)return true; else return false;}
};

int main() {

	setlocale(LC_ALL, "Russian");

	Figure* gi = new Figure;
	gi->print_info();

	Figure* tri = new Triangle("Треугольник", 10, 20, 30, 50, 60, 70);
	tri->print_info();

	Figure* rec = new Rectangular("Прямоугольный треугольник:", 10, 20, 10, 50, 60, 90);
	rec->print_info();

	Figure* iso = new Isosceles("Равнобедренный треугольник: ", 10, 20, 10, 50, 60, 50);
	iso->print_info();

	Figure* equ = new Equilateral("Равносторонний треугольник: ", 30, 30, 30, 60, 60, 60);
	equ->print_info();

	Figure* qua = new Quadrilateral("Четырёхугольник: ", 10, 20, 30, 40, 50, 60, 70, 80);
	qua->print_info();

	Figure* rect = new Rectangle("Прямоугольник: ", 10, 20, 10, 20, 90, 90, 90, 90);
	rect->print_info();

	Figure* squ = new Square("Квадрат: ", 20, 20, 20, 20, 90, 90, 90, 90);
	squ->print_info();

	Figure* par = new Parallelogram("Параллелограмм: ", 20, 30, 20, 30, 30, 40, 30, 40);
	par->print_info();

	Figure* rho = new Rhombus("Ромб: ", 30, 30, 30, 30, 30, 40, 30, 40);
	rho->print_info();

	delete rec;
	delete iso;
	delete equ;
	delete qua;
	delete rect;
	delete par;
	delete rho;
};