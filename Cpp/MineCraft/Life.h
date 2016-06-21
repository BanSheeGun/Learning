#ifndef LIFE_H
#define LIFE_H

#include "Base.h"

class Glass {
public:
    Glass() {}

    ~Glass() {}

    Glass(int x) {
        height = x;
    }

    int height;

    void Fresh() {
        if (height < 3)
            ++height;
    }
};

class Rabbit {
public:
    Rabbit() {
        now = NULL;
        Hungry = 5;
    }

    ~Rabbit() {}
    
    int x, y, Hungry, taga;
    Glass* now;

    void Fresh() {
        --Hungry;
        if (now != NULL) {
            if (now->height > 1)
                Eat();
            else  {
                int tmp = rand();
                if (tmp % 2 == 1)
                    Move();
                else
                   Eat();
            }
        } else {
            Move();
        }
    }

    void Move();
    
    void Eat() {
        --now->height;
        if (now->height == 0) {
            delete now;
            now = NULL;
            ++ReG;
        }
        Hungry += 2;
    }

};

class Wolf {
public:
    Wolf() {
        now = NULL;
        Hungry = 10;
    }
    ~Wolf() {}
    int x, y, Hungry, taga;
    Glass* now;

    void Move();

    bool Eat();

    void Fresh() {
        --Hungry;
        if (!Eat())
            Move(); 
    }
};
#endif