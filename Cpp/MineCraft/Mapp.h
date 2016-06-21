#ifndef MAPP_H
#define MAPP_H

#include "Base.h"
#include "Life.h"

class Mapp {
public:
    int tag;
    Glass* now;

    Mapp() {
        tag = 0;
        day = 0;
        now = NULL;
    }

    Mapp(int x)
        : tag(x) {
        day = 0;
        now = NULL;
        if (x == TSoil) {
            int tmp = rand();
            if (tmp % 4 == 0) {
                now = new Glass(1);
                tag = TGlass;
            }
        }
    }


    ~Mapp();

    void Fresh() {
        if (tag == TSoil && now == NULL) {
            ++day;
        }

        if (day == 12) {
            tag = TDes;
            ++StD;
            day = 0;
            now = NULL;
        }

        if (now != NULL) {
            now->Fresh();
        }
    }

private:
    int day;
};


Mapp* A[21][31];

#endif
