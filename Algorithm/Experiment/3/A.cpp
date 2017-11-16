#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int f[1000][1000];
int l[1000], r[1000];
int le, i, j, k, n;

int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
        scanf("%d%d", &l[i], &r[i]);
    memset(f, 0, sizeof(f));
    for (le = 1; le <= n-1; ++le) {
        for (i = 1; i <= n - le; ++i) {
            j = i + le;
            f[i][j] = 1000000000;
            for (k = i; k < j; ++k)
                f[i][j] = min(f[i][j], f[i][k] + f[k+1][j] + l[i] * r[k] * r[j]);
        }
    }
    printf("%d\n", f[1][n]);
    return 0;
}