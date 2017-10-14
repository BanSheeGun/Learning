#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int x, y, a, b, c;

int main() {
    scanf("%d%d", &x, &y);
    for (a = x; a <= y; ++a)
        for (b = x; b <= y; ++b)
            for (c = b+1; c <= y; ++c)
                if ((b * c - a) * (b + c) == a * a)
                    printf("%d %d %d\n", a, b, c);    
    return 0;
}