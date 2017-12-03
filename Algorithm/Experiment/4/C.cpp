#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int a, b, c, k, j, t, u, f[20];

int main() {
    scanf("%d%d", &a, &b);
    if (b % a == 0) {
        b /= a;
        a = 1;
        printf("%d/%d = %d/%d\n", a, b, a, b);
        return 0;
    }
    k = 0;
    t = 0;
    j = b;
    while (1) {
        c = b / a + 1;
        if (c > 100000000 || c < 0) {
            t = 1;
            break;
        }
        if (c == j)
            c++;
        k++;
        f[k] = c;
        a = a * c - b;
        b *= c;
        for (u = 2; u <= a; ++u)
            while (a % u == 0 && b % u == 0) {
                a /= u;
                b /= u;
            }
        if (a == 1 && b != j) {
            k++;
            f[k] = b;
            break;
        }
    }
    if (t == 0) {
        printf("1/%d", f[1]);
        for (j = 2; j <= k; ++j)
            printf(" + %d/%d", 1, f[j]);
        printf("\n");
    } else {
        printf("No\n");
    }
    return 0;
}