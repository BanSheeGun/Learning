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
    
    void Readdata() {
        cin >> Number >> Score;
    }
    
    int Getscore() {
        return Score;
    }
};

int main() {
    Student A[10];
    for (int i = 0; i < 10; ++i) {
        A[i].Readdata();
    }
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += A[i].Getscore();
    }
    
    cout << sum / 10 << endl;
    return 0;
}
