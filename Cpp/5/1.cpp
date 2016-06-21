#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Shape {
public:
	~Shape() {}
	virtual double Area() = 0;
};

class Circle : public Shape {
public:
	double r;
	
	virtual ~Circle() {
		cout << "This is Cicle Destruction.\n";
	}	
	
	double Area() {
		return r * r * 3.1415926;
	}
	
	void PrintArea() {
		cout << Area() << endl;
	}
};

class Rectangle : public Shape {
public:
	double w, h;
	
	double Area() {
		return w * h;
	}
	
	void PrintArea() {
		cout << Area() << endl;
	}
};

class Triangle : public Shape {
public:
	double x, y, z;
	
	double Area() {
		double p;
		p = (x + y + z) / 2;
		p = p * (p - x) * (p - y) * (p - z);
		return sqrt(p);
	}
	
	void PrintArea() {
		cout << Area() << endl;
	}
};

class Cylinder : public Circle {
public:
	double h;
	
	~Cylinder() {
		cout << "This is Cylinder Destruction.\n";
	}
	
	double Area() {
		return r * r * h * 3.1415926;
	}
	
};

int main() {
	Circle* A;
	A = new Circle;
	Rectangle D;
	Triangle E;
	A->r = 1;
	A->PrintArea();
	delete A;
	Cylinder* B;
	B = new Cylinder;
	B->h = 10;
	B->r = 1;
	A = B;
	A->PrintArea();
	delete A;
	cout << '\n';
	
	D.w = 1;
	D.h = 2;
	D.PrintArea();
	E.x = 3;
	E.y = 4;
	E.z = 5;
	E.PrintArea();
    return 0;
}
