#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int a, b, tmp, t, d, n;

int main() {
    scanf("%d", &n);
    t = 0;
    for (a = n/2; a < n; ++a) {
        tmp = 1;
        b = n - a;
        while (tmp <= a) {
            d = (a / tmp / 10 * tmp) + (a % tmp);
            if (d == b) {
                ++t;
                printf("%d %d\n", a, b);
            }
            tmp *= 10;
        }
    }
    printf("%d\n", t);
    return 0;
}