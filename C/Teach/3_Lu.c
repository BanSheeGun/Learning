#include<stdio.h>

struct tt
{
    int a,b;
};

int main() {
    int a,b,t;
    double aaaaaa;
    struct tt d;
    d.a = 0;
    scanf("%d%d",&a,&b);
    t=a;
    a=b;
    b=t;
    printf("%d %d\n",a,b);
    return 0;
}
