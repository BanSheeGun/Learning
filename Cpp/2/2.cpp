#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

class Student {
private:
    string Class;
    string Name;
    int num;

public:
    Student() {
    }

    Student(string _name, string _class, int _num) {
        Name = _name;
        Class = _class;
        num = _num;
    }

    void Print() {
        cout << "Name: " << Name << endl;
        cout << "Class: " << Class << endl;
        cout << "num: " << num << endl;
    }
};

int main() {
    Student Me("CaoWei", "JSJ1502", 21);
    Me.Print();
    return 0;
}
