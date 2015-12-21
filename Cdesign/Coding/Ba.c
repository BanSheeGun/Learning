/*
    Author : Gunpowder
    Verison : 2.1
    Date : 2015.12.18

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
    struct Record *ANext;
    struct Record *SNext;
    struct Record *Next;
};

//define activity
struct Activity
{
    int Number, s;
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
    getchar();
    getchar();
    return 0;
}

int addact() {
    putchar('\n');
    ++TotalAct;
    char a[100];
    Act *p;
    Rec *q;
    Stu *k;
    int t,n;
    p = (Act *) malloc (ActSize);
    printf("Please input name : ");
    scanf("%s",a);
    strcpy(p->Name,a);
    printf("Please input ps : ");
    scanf("%s",a);
    strcpy(p->PS,a);
    printf("Please input s : ");
    scanf("%d",&t);
    p->s = t;
    p->Head = NULL;
    p->Next = ActHead->Next;
    p->Number = TotalAct;
    ActHead->Next = p;

    printf("complete Please input number : ");
    scanf("%d",&t);
    while (t--) {
        printf("Please input number : ");
        scanf("%d",&n);
        printf("Please input ps : ");
        scanf("%s",a);
        q = (Rec *) malloc (RecSize);
        strcpy(q->PS,a);
        q->A = p;
        q->ANext = p->Head;
        p->Head = q;
        k = StuHead->Next;
        while (k != NULL) {
            if (k->Number == n) break;
            k = k->Next;
        }
        k->Sum += p->s;
        q->S = k;
        q->SNext = k->Head;
        k->Head = q;
        q->Next = RecHead->Next;
        RecHead->Next = q;
    }
    printf("Finish\n");
    getchar();
    getchar();
    return 0;
}

int qstu() {
    putchar('\n');
    Stu *k;
    Rec *q;
    Act *p;
    printf("Please input number : ");
    int n;
    scanf("%d",&n);
    k = StuHead->Next;
    while (k != NULL) {
        if (k->Number == n) break;
        k = k->Next;
    }
    putchar('\n');
    printf("Name : %s   Number : %d  Sum : %d\n",k->Name,k->Number,k->Sum);
    printf("Following:\n");
    q = k->Head;
    while (q != NULL) {
        p = q->A;
        printf("%s s:%d  ps:%s",p->Name,p->s,q->PS);
        putchar('\n');
        q = q->SNext;
    }
    getchar();
    getchar();
    return 0;
}

int qact() {
    putchar('\n');
    Stu *k;
    Rec *q;
    Act *p;
    p = ActHead->Next;
    while (p != NULL) {
        printf("Number:%d  %s\n",p->Number,p->Name);
        p = p->Next;
    }
    printf("Please input number : ");
    int n;
    scanf("%d",&n);
    p = ActHead->Next;
    while (p != NULL) {
        if (p->Number == n) break;
        p = p->Next;
    }
    putchar('\n');
    printf("%d Name:%s s:%d ps:%s\n",p->Number,p->Name,p->s,p->PS);
    printf("Following:\n");
    q = p->Head;
    while (q != NULL) {
        k = q->S;
        printf("%s  ps:%s",k->Name,q->PS);
        putchar('\n');
        q = q->ANext;
    }
    getchar();
    getchar();
    return 0;
}

int qc() {
    putchar('\n');
    Stu *k;
    int n;
    k = StuHead->Next;
    while (k != NULL) { 
        printf("Name : %s   Number : %d  Sum : %d\n",k->Name,k->Number,k->Sum);
        k = k->Next;
    }
    getchar();
    getchar();
    return 0;
}

int Init() {
    printf("Welcome to use this program\n");
    putchar('\n');
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
    printf("Free Finish\n");
    getchar();
    getchar();
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
