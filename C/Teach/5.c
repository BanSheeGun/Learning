#include<stdio.h>
int main()
{
    int ans,n;
    scanf("%d",&n);
    ans=0;
/*    while (n != 0) {
        ans += n % 10;
        n = n / 10;
    } */
    for (ans = 0;n != 0;n=n/10){
        ans += n % 10;
    }
    printf("%d\n",ans);
    return 0;
}