#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int k, n, num, t;

int main() {
    scanf("%d", &n);
    printf("%d", n);
    k = 2;
    t = 0;
    while (n != 1) {
        num = 0;
        if (n % k == 0) {
            if (t == 0)
                putchar('=');
            else
                putchar('*');
            while (n % k == 0) {
                n /= k;
                ++num;
            }
            if (num == 1)
                printf("%d", k);
            else
                printf("%d^%d", k, num);
            t = 1;
        }
        ++k;
    }    
    puts("");
    return 0;
}