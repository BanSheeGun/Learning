#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

class Rectangle {
private:
    int Length, Width;

public:
    void Set(int _Length, int _Width) {
        Length = _Length;
        Width = _Width;
    }

    void Get() {
        cout << "Length: " << Length << "    Width: " << Width << endl;
    }

    int Area() {
        return Length * Width;
    }
};

int main() {
    Rectangle test;
    test.Set(4, 5);
    test.Get();
    cout << "Area: " << test.Area() << endl;
    return 0;
}
