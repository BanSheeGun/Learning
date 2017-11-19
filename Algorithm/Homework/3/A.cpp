#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int b[21];
int i, s;

int main() {
    b[1] = 1;
    b[2] = 2;
    for (i = 3; i <= 20; ++i)
        b[i] = 3 * b[i - 1] - b[i - 2];
    s = 0;
    for (i = 1; i <= 20; ++i) {
        s += b[i];
        printf("%d ", b[i]);
    }
    printf("\n%d\n", s);
    return 0;
}