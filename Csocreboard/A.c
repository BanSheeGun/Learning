/*
    Author : Gunpowder
    Verison : 1.0
    Date : 2015.12.6

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//define student
struct Student
{
    char Name[10];
    int Number;
    struct Student *Next;
};

// the size of Student;
int size = sizeof(struct Student);
// head will be meaningless and never changed and link the whole line;
struct Student *head;
int Order;

int Init() {
    printf("Welcome to use this program\n");
    head = (struct Student *) malloc (size);
    head->Next = NULL;
    head->Number = 0;
    return 0;
}

int ReadInit() {
    printf("If you want to exit,please input 0\n");
    printf("If you want to add a student,please input 1\n");
    printf("Please input the operate number and press the Enter\n");
    scanf("%d",&Order);
    return 0;
}

int add() {
    return 0;
}

int main() {
    Init();
    ReadInit();
    while (Order != 0) {
        ReadInit();
        switch (Order) {
            case 1 : add();
            default : break;
        }
    }

    // free the memory
    free(head);
    return 0;
}
