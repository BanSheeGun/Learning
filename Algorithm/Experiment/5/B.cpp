#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int ans, n;
int t[20];

int dfs(int x) {
    if (x == n + 1) {
        ++ans;
        return 0;
    }
    for (t[x] = 1; t[x] <= n; ++t[x]) {
        bool flag = 1;
        for (int i = 1; i < x; ++i)
            if (t[i] == t[x] || abs(t[i] - t[x]) == x - i)
                flag = 0;
        if (flag)
            dfs(x + 1);
    }
    return 0;
}

int main() {
    ans = 0;
    scanf("%d", &n);
    dfs(1);
    printf("%d\n", ans);    
    return 0;
}