#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

char a[17] = "0123456789ABCDEF";

int i, j, t, n;

int main() {
    scanf("%d", &n);
    for (i = 1; i < n; ++i) {
        for (j = 1; j <= i; ++j) {
            t = i * j;
            if (t < n)
                printf("%c  ", a[t]);
            else
                printf("%c%c ", a[t/n], a[t%n]);
        }
        puts("");
    }
    return 0;
}