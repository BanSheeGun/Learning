#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int a[1000];
char s[1000];
int n, m, i, top;

int main() {
    scanf("%s", s);
    scanf("%d", &m);
    for (i = 1; i <= strlen(s); ++i)
        a[i] = s[i-1] - '0';

    a[0] = 10;
    top = 1;
    n = strlen(s) - m;
    a[n+1] = 10;
    while (m != 0) {
        while (a[top] <= a[top-1])
            ++top;
        if (a[top - 1] != -1)
            --m;
        a[top - 1] = a[top];
        a[top] = -1;
        --top; 
    }
    top = 1;
    while (m != n) {
        if (a[top] != -1) {
            ++m;
            printf("%d", a[top]);
        }
        ++top;
    }
    printf("\n");
    return 0;
}