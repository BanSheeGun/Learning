#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int a;

void work(int n) {
    if (n >= 8)
        work(n / 8);
    printf("%d", n % 8);
}

int main() {
    scanf("%d", &a);
    if (a < 0) {
        putchar('-');
        a = -a;
    }
    work(a);
    puts("");
    return 0;
}