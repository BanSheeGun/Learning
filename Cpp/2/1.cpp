#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

class Student {
public:
    string Class;
    string Name;
    int Num;

    Student() {
    }

    Student(string _name, string _class, int _num) {
        Name = _name;
        Class = _class;
        Num = _num;
    }

    void Scan() {
        cout << "Name: ";
        cin >> Name;
        cout << "Class: ";
        cin >> Class;
        cout << "num: ";
        cin >> Num;
    }

    void Print() {
        cout << "Name: " << Name << endl;
        cout << "Class: " << Class << endl;
        cout << "num: " << Num << endl;
    }
};

int main() {
    Student Me;
    Me.Scan();
    Me.Print();
    return 0;
}
