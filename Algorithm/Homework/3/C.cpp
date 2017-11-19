#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int main() {
    int n = 1;
    for (int i = 10; i > 1; --i)
        n = (n + 1) * 2;
    printf("%d\n", n);
    return 0;
}