#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int n, ans;

int main() {
    ans = 0;
    scanf("%d", &n);
    if (n == 0)
        ans = 1;
    else
        while (n != 0) {
            n /= 5;
            ans += n;
        }
    printf("%d\n", ans);
    return 0;
}