#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Teacher {
public:
	Teacher() {}
	~Teacher() {}
	string Num, Name;
	char Sex;
};

class Student {
public:
	Student() {}
	~Student() {}
	string Num, Name;
	char Sex;

	operator Teacher() {
		Teacher A;
		A.Num = Num;
		A.Name = Name;
		A.Sex = Sex;
		return A;
	}
};


int main() {
	Student A;
	A.Num = "15408100111";
	A.Name = "CW";
	A.Sex = 'M';
	Teacher B = A;
	cout <<  A.Num + " " + A.Name + " " << A.Sex << endl;
    return 0;
}
