#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

class Student {
public:
    string Name;
    char Male;
    int Number;
    
    Student() {
        Name = "Zhang San";
        Number = 1001;
        Male = 'M';
    }
    
    Student(string _Na,char _Ma,int _Nu) : Name(_Na), Male(_Ma), Number(_Nu) {
    }
    
    ~Student() {
        cout << Number << " RM!\n";
    }
    
    void Display() {
        cout << Name << endl;
        cout << Male << endl;
        cout << Number << endl;
    }
};

int main() {
    Student *A = new Student;
    delete A;
    A = new Student("Cao Wei",'M',1002);
    delete A;
    return 0;
}
