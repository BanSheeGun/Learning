#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d",&n);
    for(;n%10!=1;) {
        n=n/10;
        if (n == 0) break;
    }
    if (n==0) printf("No\n"); 
       else printf("Yes\n");
    return 0;
}