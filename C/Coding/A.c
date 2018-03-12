/*
    Author : Gunpowder
    Verison : 1.0
    Date : 2015.12.6

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// define record
struct Record
{
    struct Student *S;
    struct Activity *A;
    char PS[100];
    struct Record *Next;
};

//define activity
struct Activity
{
    int Number;
    char Name[100];
    char PS[100];
    struct Record *Head;
    struct Activity *Next;
};

//define student
struct Student
{
    char Name[10];
    int Number;
    struct Record *Head;
    struct Student *Next;
};

typedef struct Record Rec;
typedef struct Student Stu;
typedef struct Activity Act;


// the size of Structs;
int StuSize = sizeof(struct Student);
int ActSize = sizeof(struct Activity);
int RecSize = sizeof(struct Record);
// head will be meaningless and never changed and link the whole line;
Stu *StuHead;
Rec *RecHead;
Act *ActHead;
int Order;

int Iassign(char a[100]) {
    freopen(a,"r",stdin);
    return 0;
}

int Oassign(char a[100]) {
    freopen(a,"w",stdout);
    return 0;
}

int Faddrec() {
    return 0;
}

int Faddstu() {
    return 0;
}

int Faddact() {
    return 0;
}

int addrec() {
    return 0;
}

int addstu() {
    return 0;
}

int addact() {
    return 0;
}

int qstu() {
    return 0;
}

int qact() {
    return 0;
}

int qc() {
    return 0;
}

int Init() {
    printf("Welcome to use this program\n");
    StuHead = (Stu *) malloc (StuSize);
    StuHead->Next = NULL;
    ActHead = (Act *) malloc (ActSize);
    ActHead->Next = NULL;
    RecHead = (Rec *) malloc (RecSize);
    RecHead->Next = NULL;
    return 0;
}

int ReadInit() {
    // some tips
    printf("If you want to exit,please input 0\n");
    printf("If you want to add a student,please input 1\n");
    printf("If you want to add a activity,please input 2\n");
    printf("If you want to find a student,please input 3\n");
    printf("If you want to find a activity,please input 4\n");
    printf("If you want to find all students,please input 5\n");
    printf("Please input the operate number and press the Enter\n");
    scanf("%d",&Order);
    return 0;
}

int EndFree() {
    return 0;
}

int main() {
    Init();
    Order = -1;

    //work
    while (Order != 0) {
        ReadInit();
        switch (Order) {
            case 1 : addstu();
            case 2 : addact();
            case 3 : qstu();
            case 4 : qact();
            case 5 : qc();
            case 0 : break;
            default : printf("Noknown Order\n");
        }
    }

    // free the memory
    EndFree();
    return 0;
}
