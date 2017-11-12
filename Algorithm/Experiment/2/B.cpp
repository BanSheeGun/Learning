#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int isp[70000000];
int pri[70000000];
const int N = 69900000;
int i, j, top, m;

int main() {
    top = 0;
    memset(isp, 0, sizeof(isp));
    isp[1] = 0;
    for (i = 2; i <= N; ++i) {
        if (!isp[i])
            pri[++top] = i;
        for (j = 1; j <= top; ++j) {
            if (i * pri[j] > N)
                break;
            isp[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
    scanf("%d", &m);
    i = 1;
    while (pri[i+1] - pri[i] <= m)
        ++i;
    printf("%d %d\n", pri[i]+1, pri[i]+m);
    return 0;
}