#include<stdio.h>
int main()
{
    int m,n,i;
    scanf("%d",&n);
    i=1;
    m = 1;
    for(;i<=n;i++)
        m=m*i;
    printf("%d\n",m );
    return 0;

}
