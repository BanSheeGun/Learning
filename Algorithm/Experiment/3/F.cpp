#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int k, i, j, z, n;
ll num[100][100];
char a[100];
ll f[100][100], ans;

int find(int n, int k) {
    if (k == 0) {
        printf("%lld", num[1][n]);
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        if (f[i][k-1] * num[i+1][n] == f[n][k]) {
            find(i, k-1);
            printf(" * %lld", num[i+1][n]);
            return 0;
        }
    }
    return 0;
}

int main() {
    scanf("%s", a);
    memset(num, 0, sizeof(num));
    n = strlen(a);
    scanf("%d", &k);
    for (i = 1; i <= n; ++i)
        for (j = i; j <= n; ++j)      
            num[i][j] = num[i][j-1] * 10 + a[j-1] - '0';

    memset(f, 0, sizeof(f));
    for (i = 1; i <= n; ++i)
        f[i][0] = num[1][i];
    for (j = 1; j <= k; ++j) {
        for (i = 1; i <= n; ++i)
            for (z = 1; z < i; ++z)
                f[i][j] = max(f[i][j], num[z+1][i] * f[z][j-1]);
    }
    ans = 0;
    for (i = 1; i <= n; ++i)
        ans = max(f[i][k], ans);
    find(n, k);
    printf(" = %lld\n", ans);
    return 0;
}