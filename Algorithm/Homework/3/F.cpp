#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int i, n, m;

int work(int k, int i) {
    if (k == 0) {
        return i % n == 1;
    }
    if (i % n != 1)
        return 0;
    return work(k - 1, (i - 1) / n * (n - 1));
}

int main() {
    scanf("%d%d", &n, &m);
    for (i = 1;; ++i)
        if (work(n, i)) {
            printf("%d\n", i);
            return 0;
        }
    return 0;
}