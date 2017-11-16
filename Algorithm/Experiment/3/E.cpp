#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int i, j, n, ans;
int a[10000];
int f[10000];
int t[10000];

int find(int i) {
    if (t[i] != 0)
        find(t[i]);
    printf("%d ", a[i]);
    return 0;
}

int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }    
    memset(t, 0, sizeof(t));
    for (i = 1; i <= n; ++i) {
        f[i] = 0;
        for (j = 1; j < i; ++j)
            if (a[j] <= a[i])
                if (f[j] > f[i]) {
                    t[i] = j;
                    f[i] = f[j];
                }
        ++f[i];
    }
    ans = 1;
    for (i = 1; i <= n; ++i)
        if (f[i] > f[ans])
            ans = i;
    printf("%d\n", f[ans]);
    find(ans);
    puts("");
    return 0;
}