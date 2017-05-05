#include<iostream>
#include<string>
using namespace std;

class Person {
public:
    string Name;
    string Num;
};

class Student : public Person {
public:
    string banji;
    int fenshu;
};

class Teacher : public Person {
public:
    string zhicheng;
    string bumeng;

    Teacher() {
        
    }

    Teacher(Student a) {
        Name = a.Name;
        Num = a.Num;
    }
};

int main() {
    Student a;
    Teacher b;
    Teacher c(a);
    return 0;
}