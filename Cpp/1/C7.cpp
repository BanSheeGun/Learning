#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<cstring>
#include<iostream>

using namespace std;

struct BigInt {
    int m[100000];
    BigInt() {
        memset(m, 0, sizeof(m));
    }

    void Print() {
        int i = m[0];
        cout << m[i];
        for (i = m[0]-1; i > 0; --i) {
            printf("%d", m[i] / 10000 % 10);
            printf("%d", m[i] / 1000 % 10);
            printf("%d", m[i] / 100 % 10);
            printf("%d", m[i] / 10 % 10);
            printf("%d", m[i] % 10);
        }
        printf("\n");
        return;
    }

    BigInt operator + (BigInt &b) {
        BigInt c;
        int i, l = max(m[0], b.m[0]);
        c.m[0] = l;
        for (i = 1;i <= l; ++i) {
            c.m[i] = m[i] + b.m[i] + c.m[i];
            c.m[i+1] += c.m[i] / 100000;
            c.m[i] = c.m[i] % 100000;
        }
        while (c.m[c.m[0] + 1] != 0)
            ++c.m[0];
        return c;
    }

    BigInt operator * (int &b) {
        BigInt c;
        int i, l = m[0];
        c.m[0] = l;
        for (i = 1;i <= l; ++i) {
            c.m[i] += m[i] * b;
            c.m[i+1] += c.m[i] / 100000;
            c.m[i] = c.m[i] % 100000;
        }
        while (c.m[c.m[0] + 1] != 0)
            ++c.m[0];
        return c;
    }

    void Init() {
        m[0] = 1;
        m[1] = 1;
    }
};

void Frac(int n, BigInt &a) {
    for (int i = 2;i <= n; ++i) {
        a = a * i;
    }
    return;
}

int a, b, c;
BigInt aa, bb, cc, ans;

int main() {
    cin >> a >> b >> c;
    aa.Init();
    bb.Init();
    cc.Init();
    Frac(a, aa);
    Frac(b, bb);
    Frac(c, cc);
    ans = aa + bb;
    ans = ans + cc;
    ans.Print();
    return 0;
}
