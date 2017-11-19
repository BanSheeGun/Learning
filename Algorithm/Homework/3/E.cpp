#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int i;

int work(int n, int i) {
    if (n == 0) {
        return i % 5 == 1;
    }
    if (i % 5 != 1)
        return 0;
    return work(n - 1, (i - 1) / 5 * 4);
}

int main() {
    for (i = 1;; ++i)
        if (work(5, i)) {
            printf("%d\n", i);
            return 0;
        }
    return 0;
}