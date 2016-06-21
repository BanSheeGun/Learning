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

class Graduate : public Student {
private:
	string ResearchD;
public:
	Graduate() {}
	
	Graduate(int _Nu,string _Na,char _Ma,string _Re): Student(_Nu, _Na, _Ma), ResearchD(_Re) {}
	
	void ResearchWork() {
        cout << Number << ' ';
        cout << ResearchD << endl << endl;
	}
};

int main() {
	Student A(1, "A", 'M');
	A.OutputData();
	Graduate B(2, "B", 'M', "Computer Science");
	B.ResearchWork();
	Student C;
	C.ReadDate();
	C.OutputData();
    return 0;
}
