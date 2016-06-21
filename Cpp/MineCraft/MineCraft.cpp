#include "Base.h"
#include "Mapp.h"
#include "Life.h"

struct RabbitLine {
    Rabbit *a;
    RabbitLine * nxt;
};

struct WolfLine {
    Wolf *a;
    WolfLine * nxt;
};


RabbitLine *RHead = NULL, *Rp;
WolfLine *WHead = NULL, *Wp;

void DieRabbit(int x, int y) {
    ++DR;
    Rp = RHead;
    if (Rp == NULL) return;
    if (Rp->a->x == x && Rp->a->y == y) {
        RHead = RHead->nxt;
        A[x][y]->now = Rp->a->now;
        A[x][y]->tag = Rp->a->taga;
        if (A[x][y]->now == NULL) A[x][y]->tag = TSoil;
        delete Rp->a;
        delete Rp;
        return;
    }
    while (Rp->nxt != NULL) {
        RabbitLine *tmp = Rp->nxt;
        if (tmp->a->x == x && tmp->a->y == y) {
            Rp->nxt = tmp->nxt;
            A[x][y]->now = tmp->a->now;
            A[x][y]->tag = tmp->a->taga;
            if (A[x][y]->now == NULL) A[x][y]->tag = TSoil;
            delete tmp->a;
            delete tmp;
            return;
        }
        Rp = Rp->nxt;
    }
    return;
}

void DieWolf(int x, int y) {
    ++DW;
    Wp = WHead;
    if (Wp == NULL) return;
    if (Wp->a->x == x && Wp->a->y == y) {
        WHead = WHead->nxt;
        A[x][y]->now = Wp->a->now;
        A[x][y]->tag = Wp->a->taga;
        if (A[x][y]->now == NULL) A[x][y]->tag = TSoil;
        delete Wp->a;
        delete Wp;
        return;
    }
    while (Wp->nxt != NULL) {
        WolfLine *tmp = Wp->nxt;
        if (tmp->a->x == x && tmp->a->y == y) {
            Wp->nxt = tmp->nxt;
            A[x][y]->now = tmp->a->now;
            A[x][y]->tag = tmp->a->taga;
            if (A[x][y]->now == NULL) A[x][y]->tag = TSoil;
            delete tmp->a;
            delete tmp;
            return;
        }
        Wp = Wp->nxt;
    }
    return;
}

void Rabbit::Move() {
    int &x = this->x;
    int &y = this->y;
    int fx[4] = {0, 0, 1, -1};
    int fy[4] = {1, -1, 0, 0};
    int tmp = rand() % 4;
    for (int i = 0; i < 4; ++i) {
        tmp = (tmp + 1) % 4;
        int xx = x + fx[tmp];
        int yy = y + fy[tmp];
        if (A[xx][yy]->tag == TSoil || A[xx][yy]->tag == TGlass || A[xx][yy]->tag == TDes) {
            A[x][y]->now = now;
            if (A[x][y]->now == NULL) taga = TSoil;
            A[x][y]->tag = taga;
            x = xx;
            y = yy;
            taga = A[x][y]->tag;
            now = A[x][y]->now;
            A[x][y]->now = NULL;
            A[x][y]->tag = TRabbit;
            return ;
        }
    }
}

void Wolf::Move() {
    int &x = this->x;
    int &y = this->y;
    int fx[4] = {0, 0, 1, -1};
    int fy[4] = {1, -1, 0, 0};
    int tmp = rand() % 4;
    for (int i = 0; i < 4; ++i) {
        tmp = (tmp + 1) % 4;
        int xx = x + fx[tmp];
        int yy = y + fy[tmp];
        if (A[xx][yy]->tag == TSoil || A[xx][yy]->tag == TGlass || A[xx][yy]->tag == TDes) {
            A[x][y]->now = now;
            if (A[x][y]->now == NULL) taga = TSoil;
            A[x][y]->tag = taga;
            x = xx;
            y = yy;
            taga = A[x][y]->tag;
            now = A[x][y]->now;
            A[x][y]->now = NULL;
            A[x][y]->tag = TWolf;
            return ;
        }
    }
}

bool Wolf::Eat() {int &x = this->x;
    int &y = this->y;
    int fx[4] = {0, 0, 1, -1};
    int fy[4] = {1, -1, 0, 0};
    int tmp = rand() % 4;
    for (int i = 0; i < 4; ++i) {
        tmp = (tmp + 1) % 4;
        int xx = x + fx[tmp];
        int yy = y + fy[tmp];
        if (A[xx][yy]->tag == TRabbit) {
            DieRabbit(xx, yy);
            Hungry += 4;
            ++WeR;
            return 1;
        }
    }
    return 0;
}


void Init() {
    int i, j;
    for (i = 0; i <= 31; ++i) {
        A[0][i] = new Mapp(-2);
        A[21][i] = new Mapp(-2);
    }

    for (i = 0; i <= 21; ++i) {
        A[i][0] = new Mapp(-2);
        A[i][31] = new Mapp(-2);
    }

    for (i = 1; i <= 20; ++i) 
        for (j = 1; j <= 30; ++j) {
            int tmp = rand();
            tmp %= 50;
            if (tmp <= 42)
                A[i][j] = new Mapp(TSoil);
            else
                if (tmp == 43)
                    A[i][j] = new Mapp(THill);
                else
                    A[i][j] = new Mapp(TWater);
        }
}

void PrintMap() {
    int i, j;
    for (i = 1; i <= 20; ++i) {
        for (j = 1; j <= 30; ++j)
            switch (A[i][j]->tag) {
                case TSoil:   printf("%c", CSoil);   break;
                case TWater:  printf("%c", CWater);  break;
                case TRabbit: printf("%c", CRabbit); break;
                case TWolf:   printf("%c", CWolf);   break;
                case THill:   printf("%c", CHill);   break;
                case TDes:    printf("%c", CDes);    break;
                case TGlass:  printf("%c", CGlass);  break;
                default : break;
            };
        printf("\n");
    }
}

void InitRabbit() {
    RHead = NULL;
    cout << "Please enter the number of Rabbits: ";
    cin >> TotalRabbit;
    for (int i = 1;i <= TotalRabbit; ++i) {
        int x, y;
        cout << "Please enter the x and y of Rabbits: ";
        cin >> x >> y;
        if (A[x][y]->tag == TSoil) {
            A[x][y]->tag = TRabbit;
            Rp = new RabbitLine;
            Rp->a = new Rabbit;
            Rp->a->x = x;
            Rp->a->y = y;
            Rp->a->taga = TSoil;
            Rp->nxt = RHead;
            RHead = Rp;
        } else {
            cout << "Wrong.";
            i--;
        }
    }
    return;
}

void InitWolf() { 
    WHead = NULL;
    cout << "Please enter the number of Wolfs: ";
    cin >> TotalWolf;
    for (int i = 1;i <= TotalWolf; ++i) {
        int x, y;
        cout << "Please enter the x and y of Wolfs: ";
        cin >> x >> y;
        if (A[x][y]->tag == TSoil) {
            A[x][y]->tag = TWolf;
            Wp = new WolfLine;
            Wp->a = new Wolf;
            Wp->a->x = x;
            Wp->a->y = y;
            Wp->a->taga = TSoil;
            Wp->nxt = WHead;
            WHead = Wp;
        } else {
            cout << "Wrong.";
            i--;
        }
    }
    return;
}

void tongji() {
    if (StD != 0)
        cout << StD << " Soil change into Desert\n";
    if (WeR != 0)
        cout << "Wolf eat " << WeR << " Rabbits\n";
    if (ReG != 0) 
        cout << "Rabbits eat " << ReG << "Glass \n";
    if (DW != 0)
        cout << DW <<" Wolf(s) Die\n";
    if (DR != 0)
        cout << DR <<" Rabbits(s) Die\n";
    return;
}

void Fresh() {
    StD = 0; WeR = 0; ReG = 0; 
    DW = 0; DR = 0;
    clear;
    ++TotalDay;
    cout << "Day" << TotalDay << ":\n";
    for (int i = 1; i <= 20; ++i)
        for (int j = 1; j <= 30; ++j)
            A[i][j]->Fresh();
    int top = 0;
    int x[100],y[100];
    for (Wp = WHead;Wp != NULL; Wp = Wp->nxt) {
        if (Wp->a->Hungry == 0) {
            ++top;
            x[top] = Wp->a->x;
            y[top] = Wp->a->y;
        } else
            Wp->a->Fresh();
    }
    for (int i = 1; i <= top; ++i)
        DieWolf(x[i], y[i]);
    top = 0;
    for (Rp = RHead;Rp != NULL; Rp = Rp->nxt) {
        if (Rp->a->Hungry == 0) {
            ++top;
            x[top] = Rp->a->x;
            y[top] = Rp->a->y;
        } else
            Rp->a->Fresh();
    }
    for (int i = 1; i <= top; ++i)
        DieRabbit(x[i], y[i]);
    PrintMap();
    tongji();
    getchar();
    return;
}

void Ending() {
    clear;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "          The world has been " << TotalDay << " days.\n";
    cout << "          Now, everything is ending!";
    getchar();
    getchar();
    return;
}

int main() {
    TotalDay = 0;
    Init();
    cout << "This is the map:\n";
    PrintMap();
    InitRabbit();
    clear;
    cout << "Now, this is the map:\n";
    PrintMap();
    InitWolf();
    clear;
    cout << "Now, this is the map:\n";
    PrintMap();
    cout << endl;
    PrintMap();
    clear;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "      Now, the world will begin\n";
    getchar();
    getchar();
    while (1) {
        Fresh();
        if (WHead == NULL && RHead == NULL) {
            Ending();
            return 0;
        }
    }
    return 0;
}
