#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int a[10000000];
int x, i, n, ans;

int main() {
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    a[0] = 1;
    a[1] = 1;
    for (x = 2; x <= n; ++x) {
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
    }

    ans = 0;
    for (i = 1; i <= a[0]; ++i)
        ans += (a[i] == 0);
    printf("%d\n", ans);
    ans = 0;
    while (n != 0) {
        n /= 5;
        ans += n;
    }
    printf("%d\n", ans);
    return 0;
}