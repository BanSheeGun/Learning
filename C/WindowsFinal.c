/*
    Author : Gunpowder
    Verison : 3.0
    Date : 2015.12.21

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
    int Number, s, n;
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
    printf("请输入姓名 : ");
    scanf("%s",a);
    printf("请输入学号 : ");
    scanf("%d",&n);
    p = (Stu *) malloc (StuSize);
    p->Number = n;
    p->Sum = 0;
    strcpy(p->Name,a);
    p->Head = NULL;
    p->Next = StuHead->Next;
    StuHead->Next = p;
    printf("录入完成\n");
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
    printf("请输入活动名 : ");
    scanf("%s",a);
    strcpy(p->Name,a);
    printf("请输入活动备注 : ");
    scanf("%s",a);
    strcpy(p->PS,a);
    printf("请输入活动素拓分 : ");
    scanf("%d",&t);
    p->s = t;
    p->Head = NULL;
    p->Next = ActHead->Next;
    p->Number = TotalAct;
    ActHead->Next = p;

    printf("完成，请输入学生数 : ");
    scanf("%d",&t);
    p->n = t;
    while (t--) {
        printf("请输入学号 : ");
        scanf("%d",&n);
        printf("请输入该学生活动备注 : ");
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
    printf("录入完成\n");
    getchar();
    getchar();
    return 0;
}

int qstu() {
    putchar('\n');
    Stu *k;
    Rec *q;
    Act *p;
    printf("请输入学号 : ");
    int n;
    scanf("%d",&n);
    k = StuHead->Next;
    while (k != NULL) {
        if (k->Number == n) break;
        k = k->Next;
    }
    putchar('\n');
    if (k == NULL) {
        printf("未找到！\n");
        putchar('\n');
        return 0;
    }
    printf("姓名 : %s   学号 : %d  素拓分 : %d\n",k->Name,k->Number,k->Sum);
    printf("TA所参加的活动:\n");
    q = k->Head;
    while (q != NULL) {
        p = q->A;
        printf("%s 素拓分:%d  备注:%s",p->Name,p->s,q->PS);
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
        printf("活动号:%d  %s\n",p->Number,p->Name);
        p = p->Next;
    }
    printf("请输入活动号 : ");
    int n;
    scanf("%d",&n);
    p = ActHead->Next;
    while (p != NULL) {
        if (p->Number == n) break;
        p = p->Next;
    }
    putchar('\n');
    if (p == NULL) {
        printf("未找到！\n");
        putchar('\n');
        return 0;
    }
    printf("%d 名称:%s 素拓分:%d 备注:%s\n",p->Number,p->Name,p->s,p->PS);
    printf("参与人员：\n");
    q = p->Head;
    while (q != NULL) {
        k = q->S;
        printf("%s  备注:%s",k->Name,q->PS);
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
        printf("姓名 : %s   学号 : %d  素拓分 : %d\n",k->Name,k->Number,k->Sum);
        k = k->Next;
    }
    getchar();
    getchar();
    return 0;
}

int Init() {
    printf("欢迎使用该程序\n");
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
    printf("如果你想退出请输入 0\n");
    printf("如果你想添加学生请输入 1\n");
    printf("如果你想添加活动请输入 2\n");
    printf("如果你想查询学生请输入 3\n");
    printf("如果你想查询活动请输入 4\n");
    printf("如果你想查询所有学生请输入 5\n");
    printf("请输入对应数字并按下回车\n");
    scanf("%d",&Order);
    return 0;
}

int EndFree() {
    freopen("Data.txt","w",stdout);
    while (StuHead->Next != NULL) {
        Stu *p = StuHead->Next;
        StuHead->Next = p->Next;
        printf("1\n");
        printf("%s\n",p->Name);
        printf("%d\n",p->Number);
        putchar('\n');
        putchar('\n');
        free(p);
    }
    free(StuHead);
    Rec *q;
    Stu *k;
    while (ActHead->Next != NULL) {
        Act *p = ActHead->Next;
        ActHead->Next = p->Next;
        printf("2\n");
        printf("%s\n",p->Name);
        printf("%s\n",p->PS);
        printf("%d\n",p->s);
        printf("%d\n",p->n);
        q = p->Head;
        while (q != NULL) {
            k = q->S;
            printf("%d\n",k->Number);
            printf("%s\n",q->PS);
            q = q->ANext;
        }
        putchar('\n');
        putchar('\n');
        free(p);
    }
    free(ActHead);
    while (RecHead->Next != NULL) {
        Rec *p = RecHead->Next;
        RecHead->Next = p->Next;
        free(p);
    }
    free(RecHead);
    freopen("CON","w",stdout);
    printf("释放结束\n");
    getchar();
    getchar();
    return 0;
}

int FileInit() {
    printf("从文件读入\n");
    freopen("Data.txt","r",stdin);
    freopen("Temp.txt","w",stdout);
    while (~scanf("%d",&Order)) {
        switch (Order) {
            case 1 : addstu(); break;
            case 2 : addact(); break;
            case 3 : qstu(); break;
            case 4 : qact(); break;
            case 5 : qc(); break;
            case 0 : break;
            default : break;
        }
    }
    freopen("CON","r",stdin);
    freopen("CON","w",stdout);
    printf("读入结束\n");
}

int main() {
    Init();
    FileInit();
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
            default : printf("错误的输入号\n");break;
        }
    }

    // free the memory
    EndFree();
    return 0;
}
