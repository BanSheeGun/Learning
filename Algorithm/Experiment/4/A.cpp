#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

struct X {
    double w, v;
};

inline bool cmp(const X & a, const X & b) {
    return a.v * b.w >= b.v * a.w;
}

X a[100];
double ans;
int n, i;
double v;   

int main() {
    scanf("%d%lf", &n, &v);
    for (i = 1; i <= n; ++i) {
        scanf("%lf%lf", &a[i].w, &a[i].v);
    }    
    sort(a+1, a+1+n, cmp);
    ans = 0;
    for (i = 1; i <= n; ++i) {
        if (v == 0)
            break;
        ans += 1.0 * min(v, a[i].w) * a[i].v / a[i].w; 
        v -= min(v, a[i].w);
    }
    printf("%lf\n", ans);
    return 0;
}