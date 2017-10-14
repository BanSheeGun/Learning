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
int x, i, n, ans;

int main() {
    memset(a, 0, sizeof(a));
    string aa = "1234005678904321";
    a[0] = aa.length();
    for (i = 0; i < a[0]; ++i)
        a[i+1] = aa[a[0] - i - 1] - '0';
    x = 123;
    int now = 0;
    ans = 0;
    for (i = a[0]; i >= 1; --i) {
        now = now * 10 + a[i];
        if (ans != 0 || (now/x)!=0) {
            printf("%d", now / x);
            ans = 1;
        }
        now %= x;
    }
    puts("");
    for (i = 1; i <= a[0]; ++i)
        a[i] *= x;
    for (i = 1; i <= a[0]; ++i) {
        a[i+1] += a[i] / 10;
        a[i] %= 10;
    }
    while (a[a[0]+1] != 0) {
        ++a[0];
        a[a[0]+1] = a[a[0]] / 10;
        a[a[0]] %= 10;
    }
    for (i = a[0]; i >= 1; --i)
        printf("%d", a[i]);
    puts("");
    return 0;
}