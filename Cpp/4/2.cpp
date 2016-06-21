#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

class Student {
public:
    string Name;
    char Sex;
    int Number;
    
    Student() {}
    
    Student(int _Nu,string _Na,char _Ma) : Number(_Nu), Name(_Na), Sex(_Ma)  {
    }
    
    void ReadDate() {
    	cin >> Number >> Name >> Sex;
	}

    void OutputData() {
        cout << Number << ' ';
        cout << Name << ' ';
        cout << Sex << endl << endl;
    }
};

class Teacher {
protected:
    string Name;
    char Sex;
    string Title;
    int Wages;
 public:   
    Teacher() {}
};

class Student_Teacher : public Student, public Teacher {
public:
	void ReadF1() {
		ReadDate();
		cin >> Title >> Wages;
	}
	
	void Show() {
		OutputData();
		cout << Title << ' ' << Wages << endl;
	}
};

int main() {
	Student_Teacher A;
	A.ReadF1();
	A.Show();
    return 0;
}
