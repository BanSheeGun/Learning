#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Matrix {
public:
    Matrix() {}
    ~Matrix() {}

    int a[2][3];

    Matrix(int x) {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                cin >> a[i][j];
    }

    Matrix operator + (const Matrix &B) const {
        Matrix C;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                C.a[i][j] = a[i][j] + B.a[i][j];
        return C;
    }

    void Display() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j)
                cout << a[i][j] << ' ';
            cout << a[i][2] << endl;
        }
    }
};

int main() {
    Matrix A(0), B(0);
    Matrix C = A + B;
    C.Display();
    return 0;
}
