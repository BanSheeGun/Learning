#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int n, i, j, t, top;
int a[1000];
int b[1000];

int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    top = 0;
    for (i = 1; i <= n; ++i) {
        t = 1;
        for (j = 1; j < i; ++j)
            if (a[i] == a[j])
                t = 0;
        if (t)
            b[++top] = a[i]; 
    }
    for (i = 1; i <= top; ++i)
        printf("%d ", b[i]);
    printf("\n");
    return 0;
}