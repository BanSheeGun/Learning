#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Matrix {
public:
    Matrix() {}
    ~Matrix() {}

    void Init() {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                cin >> a[i][j];
    }

    friend void GetH(Matrix &, int i);

    friend void GetL(Matrix &, int j);

private:
    int a[4][4];
};

void GetH(Matrix &A, int i) {
    for (int j = 0; j < 4; ++j)
        cout << A.a[i-1][j] << ' ';
    cout << endl;
}

void GetL(Matrix &A, int j) {
    for (int i = 0; i < 4; ++i)
        cout << A.a[i][j-1] << ' ';
    cout << endl;
}

int main() {
    Matrix A;
    int n;
    A.Init();
    cin >> n;
    GetL(A, n);
    cin >> n;
    GetH(A, n);
    return 0;
}
