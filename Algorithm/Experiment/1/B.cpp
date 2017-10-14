#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int a[10000000];
int b[10000000];
int c[10000000];
int x, i, n, ans;

int main() {
    memset(a, 0, sizeof(a));
    string aa = "1234005678904321";
    a[0] = aa.length();
    for (i = 0; i < a[0]; ++i)
        a[i+1] = aa[a[0] - i - 1] - '0';
    aa = "321876509877653";
    memset(b, 0, sizeof(b));
    b[0] = aa.length();
    for (i = 0; i < b[0]; ++i)
        b[i+1] = aa[b[0] - i - 1] - '0';
    
    memset(c, 0, sizeof(c));
    for (i = 1; i <= max(a[0], b[0]); ++i)
        c[i] = b[i] + a[i];
    c[0] = max(a[0], b[0]);
    for (i = 1; i <= c[0]; ++i) {
        c[i+1] += c[i] / 10;
        c[i] %= 10;
    }
    while (c[c[0]+1] != 0) {
        ++c[0];
        c[c[0]+1] = c[c[0]] % 10;
        c[c[0]] /= 10;
    }
    for (i = c[0]; i >= 1; --i)
        printf("%d", c[i]);
    puts("");

    memset(c, 0, sizeof(c));
    for (i = 1; i <= max(a[0], b[0]); ++i)
        c[i] = a[i] - b[i];
    c[0] = max(a[0], b[0]);
    for (i = 1; i <= c[0]; ++i)
        if (c[i] < 0) {
            c[i] += 10;
            --c[i+1];
        }
    while (c[c[0]] == 0) {
        --c[0];
    }
    for (i = c[0]; i >= 1; --i)
        printf("%d", c[i]);
    puts("");
    return 0;
}