#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<iostream>

using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int max(int a, int b, int c) {
    int ans = max(a, b);
    ans = max(ans, c);
    return ans;
}

int main() {
    cout << max(1, 2) << endl;
    cout << max(0, 0, 4) << endl;
    return 0;
}
