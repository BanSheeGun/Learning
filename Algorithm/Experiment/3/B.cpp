#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int n, c, i, j, tot;
int w[1000], v[1000];
int f[10000];

int find(int c, int n) {
    if (c == 0)
        return 0;
    for (int i = n; i >= 1; --i) {
        if (f[c] - v[i] == f[c - w[i]]) {
            find(c - w[i], i - 1);
            printf("%d %d %d\n", i, w[i], v[i]);
            tot += w[i];
            return 0;
        }
    }
    return 0;
}

int main() {
    scanf("%d%d", &n, &c);
    memset(f, 0, sizeof(f));
    for (i = 1; i <= n; ++i) {
        scanf("%d%d", &w[i], &v[i]);
        for (j = c; j >= w[i]; --j)
            f[j] = max(f[j], f[j - w[i]] + v[i]);
    }
    find(c, n);
    printf("%d %d\n", tot, f[c]);
    return 0;
}