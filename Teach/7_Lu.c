#include<stdio.h>
int main()
{
    double m,n,i,j;
    for (j=2000000;j<=2000000;++j){
        n=1;
        for(i=1;i<=j;i++)
        {
            m=1+1.0/j;
            n=m*n;
        }
        printf("%lf\n",n );
    }
    return 0;
}
