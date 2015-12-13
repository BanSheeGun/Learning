`/*
    Author : Gunpowder
    Verison : 2.0
    Date : 2015.12.11

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
    int Number, Sum;
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
int Order, TotalAct = 0;

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
    char a[10];
    int n;
    Stu *p;
    printf("Please input name : ");
    scanf("%s",a);
    printf("Please input number : ");
    scanf("%d",&n);
    p = (Stu *) malloc (StuSize);
    p->Number = n;
    p->Sum = 0;
    strcpy(p->Name,a);
    p->Head = NULL;
    p->Next = StuHead->Next;
    StuHead->Next = p;
    printf("Finish\n");
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
    while (StuHead->Next != NULL) {
        Stu *p = StuHead->Next;
        StuHead->Next = p->Next;
        free(p);
    }
    free(StuHead);
    while (ActHead->Next != NULL) {
        Act *p = ActHead->Next;
        ActHead->Next = p->Next;
        free(p);
    }
    free(ActHead);
    while (RecHead->Next != NULL) {
        Rec *p = RecHead->Next;
        RecHead->Next = p->Next;
        free(p);
    }
    free(RecHead);
    return 0;
}

int main() {
    Init();
    Order = -1;

    //work
    while (Order != 0) {
        ReadInit();
        switch (Order) {
            case 1 : addstu(); break;
            case 2 : addact(); break;
            case 3 : qstu(); break;
            case 4 : qact(); break;
            case 5 : qc(); break;
            case 0 : break;
            default : printf("Unknown Order\n");
        }
    }

    // free the memory
    EndFree();
    return 0;
}
