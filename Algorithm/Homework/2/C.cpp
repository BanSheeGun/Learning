#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

bool f[1000000];
int c, d, i, j, ans, now;

int main() {
    scanf("%d%d", &c, &d);
    memset(f, 0, sizeof(f));
    f[1] = 1;
    for (i = 2; i <= d; ++i)
        if (f[i] == 0)
            for (j = i + i; j <= d; j += i)
                f[j] = 1;
    ans = 0;
    now = 0;
    for (i = c; i <= d; ++i)
        if (!f[i])
            now = 0;
        else {
            now++;
            ans = max(ans, now);
        }
    printf("%d\n", ans);
    return 0;
}