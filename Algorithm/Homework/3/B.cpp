#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int a[30], b[30];
int i, t;

int main() {
    a[0] = 1;
    b[0] = 0;
    scanf("%d", &t);
    for (i = 1; i <= t; ++i) {
        a[i] = b[i-1] + a[i-1];
        b[i] = b[i-1] * 2+ 3 * a[i-1] + b[i-1];
    }
    printf("%d %d\n", a[t], b[t]);
    return 0;
}