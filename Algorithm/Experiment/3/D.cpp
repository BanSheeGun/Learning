#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int f[100][100];
int a[100];
int l, r, n, i, j, ans, k;

int find(int l, int r) {
    if (l + 2 >= r)
        return 0;
    for (int k = l + 1; k <= r - 1; ++k) {
        if (f[l][r] == f[l][k] + f[k][r] + a[l] * a[r] * a[k]) {
            if (l + 1 != k)
                printf("%d -- %d\n", l, k);
            if (k + 1 != r)
                printf("%d -- %d\n", k, r);
            find(l, k);
            find(k, r);
            return 0;
        } 
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (l = 1; l <= n; ++l)
        for (r = l; r <= n; ++r)
            f[l][r] = 1000000000;
    for (i = 1; i <= n - 1; ++i)
        f[i][i+1] = 0;
    for (i = 1; i < n-1; ++i)
        f[i][i+2] = a[i] * a[i + 1] * a[i + 2];
    for (l = 3; l <= n; ++l) {
        for (i = 1; i <= n - l; ++i) {
            j = i + l;
            for (k = i + 1; k <= j - 1; ++k)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j] + a[i] * a[k] * a[j]);
        }
    }
    printf("%d\n", f[1][n]);
    find(1, n);
    return 0;
}