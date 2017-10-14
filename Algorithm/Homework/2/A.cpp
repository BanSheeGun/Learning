#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int a, b, c, i, t, ans;

int main() {
    scanf("%d%d%d", &a, &b, &c);
    ans = 0;
    for (i = a; i <= b; ++i) {
        t = i;
        while (t != 0) {
            if (t % 10 == c)
                ++ans;
            t /= 10;
        }
    }
    printf("%d\n", ans);
    return 0;
}