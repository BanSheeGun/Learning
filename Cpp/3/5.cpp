#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

class Student {
private:
    int Score;
public:
    string Name;
    char Male;
    int Number;
    static int Total;
    static int Sum;
    
    Student() {
        Name = "Zhang San";
        Number = 1001;
        Male = 'M';
        ++Total;
    }
    
    Student(string _Na,char _Ma,int _Nu) : Name(_Na), Male(_Ma), Number(_Nu) {
        ++Total;
    }
    
    ~Student() {
        cout << Number << " RM!\n";
    }
    
    void Display() {
        cout << Name << endl;
        cout << Male << endl;
        cout << Number << endl;
    }
    
    void Readdata() {
        cin >> Number >> Score;
        Sum += Score;
    }
    
    int Getscore() {
        return Score;
    }
};

int Student::Sum = 0;
int Student::Total = 0;

int main() {
    Student *A;
    for (int i = 0; i < 10; ++i) {
        int a;
        A = new Student;
        A->Readdata();
        delete A;
    }
    
    cout << Student::Sum / Student::Total << endl;
    return 0;
}
