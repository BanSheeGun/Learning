/*
    Author : Gunpowder
    Verison : 1.0
    Date : 2015.12.6

*/

#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>

using namespace std;

char a[100][100000];
int Total, i;

int TimeDelay() {
    int TimeLimit = 40000000;
    int i, t = 1;
    for (i = 0;i < TimeLimit; ++i)
        t = -t;
    return 0;
}

int PrintString(int n) {
    int i, l = strlen(a[n]);
    for (i = 0; i < l; ++i) {
        TimeDelay();
        printf("%c",a[n][i]);
    }
    TimeDelay();
    printf("\n");
    return 0;
}

int Init() {
    Total = 2;
    strcpy(a[0], "Hello LuLu");
    strcpy(a[1], "I love you!");
    return 0;
}

int main() {
    Init();
    for (i = 0; i < Total; ++i)
        PrintString(i);
    getchar();
    return 0;
}
