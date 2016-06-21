#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<iostream>

using namespace std;

int a[3][4];
int x, y;

int main() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j)
            cin >> a[i][j];
    }

    x = 0;
    y = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j)
            if (a[i][j] > a[x][y]) {
                x = i;
                y = j;
            }
    }

    cout << x+1 << ' ' << y+1 << ' ' << a[x][y] << endl;
    return 0;
}
