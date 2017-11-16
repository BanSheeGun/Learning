#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

bool f[100000];
bool t[100000];
int l[100000];
int a[10000];
int n, i, j, s, ans;

int find(int v) {
    if (v == 0)
        return 0;
    t[l[v]] = 1;
    find(v - a[l[v]]);
    return 0;
}

int main() {
    scanf("%d", &n);
    s = 0;
    for (i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    s /= 2;
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (i = 1; i <= n; ++i) 
        for (j = s; j >= a[i]; --j)
            if (f[j - a[i]] && !f[j]) {
                f[j] = 1;
                l[j] = i;
            }
        
    ans = 0;
    for (i = 0; i <= s; ++i)
        if (f[i])
            ans = i;
    memset(t, 0, sizeof(t));
    printf("%d\n", ans);
    find(ans);
    for (i = 1; i <= n; ++i)
        if (t[i])
            printf("%d ", a[i]);
    puts("");
    for (i = 1; i <= n; ++i)
        if (!t[i])
            printf("%d ", a[i]);
    puts("");
    return 0;
}