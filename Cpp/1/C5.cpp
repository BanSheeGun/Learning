#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<iostream>
#include<cstring>

using namespace std;

struct Student {
    int num;
    char name[10];
    int sex;
    Student * next;
    Student() {}
    Student(int a,char* b, int c) {
        num = a;
        strcpy(name, b);
        sex = c;
        next = NULL;
    }
    int P() {
        printf("num: %d  ", num);
        printf("name: %s  ", name);
        printf("sex: ");
        if (sex == 0)
            printf("Girl\n");
        else
            printf("Boy\n");
    }
};

int main() {
    char a[10];
    strcpy(a, "CW1");
    Student *head = new Student(1, a, 1);
    strcpy(a, "CW2");
    Student *p = new Student(2, a, 0);
    head->next = p;
    strcpy(a, "CW3");
    p = new Student(3, a, 1);
    head->next->next = p;

    p = head;
    while (p != NULL) {
        p->P();
        p = p->next;
    }

    p = head->next;
    head->next = p->next;
    delete p;
    
    cout << "erease!\n";

    p = head;
    while (p != NULL) {
        p->P();
        p = p->next;
    }
    return 0;
}
