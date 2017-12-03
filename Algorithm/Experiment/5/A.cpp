#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int n, v, an, i;
int x[100];
int y[100];
int ans[100];
int now[100];

int dfs(int num, int cv, int c) {
    if (num == n + 1) {
        if (c > an) {
            an = c;
            for (int i = 1; i <= n; ++i)
                ans[i] = now[i];
        }
        return 0;
    }
    now[num] = 0;
    dfs(num+1, cv, c);
    if (x[num] + cv <= v) {
        now[num] = 1;
        dfs(num+1, cv + x[num], c + y[num]);
        now[num] = 0;
    }
    return 0;
}

int main() {
    scanf("%d%d", &n, &v);
    an = 0;
    for (i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &y[i]);
    dfs(1, 0, 0);
    printf("%d\n", an);
    for (i = 1; i <= n; ++i)
        if (ans[i])
            printf("%d %d\n", x[i], y[i]);
    return 0;
}