#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int n, m, d;

int main() {
    scanf("%d%d%d", &d, &n, &m);
    for (int i = n; i > 1; --i)
        d = (d + m) * 2;
    printf("%d\n", d);
    return 0;
}