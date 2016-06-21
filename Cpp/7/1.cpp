#include<cstdio>
#include<iostream>
#include<algorithm>
#include<list>
#include<string>

using namespace std;

class Student {
public:
    Student() {}
    ~Student() {}

    string Num;
    string Name;
    char Sex;

    Student(const Student& ref) {
        Num = ref.Num;
        Name = ref.Name;
        Sex = ref.Sex;
    }


    Student(string _Num, string _Name, char _Sex) :
        Name(_Name),
        Num(_Num),
        Sex(_Sex) {

    }

    bool operator == (const Student &A) const {
        return A.Num == Num;
    }

    bool operator != (const Student &A) const {
        return !(A == *this);
    }

    void Display() {
        cout << Num << ' ';
        cout << Name << ' ';
        cout << Sex << endl;
    }

};

int main() {
    list<Student> aaa;
    Student* A;
    string num = "000";
    string name = "Name0";
    for (int i = 1; i <= 9; ++i) {
        num[2] = 48 + i;
        name[4] = 48 + i;
        A = new Student(num, name, (i%2==1)?'F':'M');
        aaa.push_back(*A);
    }
    A = new Student("010", "Gunpowder", 'M');
    aaa.push_back(*A);

    list<Student>::iterator ii;
    for (ii = aaa.begin(); ii != aaa.end(); ii++) {
        ii->Display();
    }
    A = new Student;
    cin >> A->Num;
    ii = find(aaa.begin(), aaa.end(), *A);
    if (ii == aaa.end()) {
        cout << "NO Find!\n";
    } else {
        ii->Display();
    }
    return 0;
}
