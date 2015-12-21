/*
    Gunpowder
    2015 12.20
    v 1.0
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
#include<memory.h>

int clrscr() {
    system("CLS");
    return 0;
}

int a[5][5];
int sorce, un;
char op;
HANDLE hout;
COORD coord;

int GotoXY(int x,int y){
    coord.X=y;
    coord.Y=x;
    hout=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hout,coord);
    return 0;
}

int DrawF() {
    printf("---------------------\n");
    printf("|    |    |    |    |  sorce:%d\n",sorce);
    printf("|    |    |    |    |  Undo(%d)\n",un);
    printf("---------------------\n");
    printf("|    |    |    |    |\n");
    printf("|    |    |    |    |\n");
    printf("---------------------\n");
    printf("|    |    |    |    |\n");
    printf("|    |    |    |    |  Press wasd to move\n");
    printf("---------------------  Press u to Undo\n");
    printf("|    |    |    |    |  Press r to Exit\n");
    printf("|    |    |    |    |  Press q to Save as\n");
    printf("---------------------\n");
    return 0;
}

int Init() { 
    printf("                     \n");
    printf("                     \n");
    printf("   Welcome to 2048!  \n");
    printf("                     \n");
    printf("                     \n");
    printf("                     \n");
    printf("        v 1.0        \n");
    printf("                     \n");
    printf("    The beginning    \n");
    printf("         Tiamo       \n");
    printf("                     \n");
    printf("                     \n");
    printf("Please press any key.\n");
    getch();
    clrscr();
    un = 5;
    sorce = 0;
    DrawF();
    memset(a,0,sizeof(a));
    return 0;
}

int Undo() {
    return 0;
}

int Die() {
    GotoXY(4,3);
    printf("             ");
    GotoXY(5,3);
    printf("  HAHA U DIE ");
    GotoXY(6,3);
    printf("   Sorce :   ");   
    GotoXY(7,3); 
    printf("             ");
    GotoXY(7,3); 
    printf("  %d  ",sorce);
    GotoXY(8,3); 
    printf(" It will exit  ");
    GotoXY(9,3);
    printf("             ");
    GotoXY(13,0);
    return 0;
}

int main() {
    Init();
    while (1) {
        op = getch();
        switch (op) {
            case 'w' : break;
            case 'a' : break;
            case 's' : break;
            case 'd' : break;
            case 'r' : break;
            case 'u' : break;
            case 'q' : break;
            default : break;
        }
        if (op == 'r') break;
    }
    Die();
    return 0;
}
