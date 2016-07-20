#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

struct L {
    int St;
    int To;
    int Time;
    double Ct, Cm;
    L * Next;
};

struct City {
    int Num;
    string Name;
    L *  TH;
    L *  PH;
};

int OP, NumCity;
City C[20];
double l[20][20];


void List() {
    cout << endl;
    cout << endl;
    for (int i = 1; i <= NumCity; ++i) {
        cout << i << " " << C[i].Name << "   ";
        if (i % 4 == 0)
            cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;
    return;
}

void InCity() {
    ++NumCity;
    int &n = NumCity;
    City a;
    cout << "Please Name\n";
    cin >> a.Name;
    a.Num = n;
    a.TH = NULL;
    a.PH = NULL;
    C[n] = a;
    cout << "Please input distance between other city\n";
    for (int i = 1; i < n; ++i) {
        cin >> l[i][n];
        l[n][i] = l[i][n];
    }
    l[n][n] = 0;
    return;
}

void InTL() {
    int x, y, t;
    List();
    cout << "Please input start, to, and time\n";
    cin >> x >> y >> t;
    L * p = new L;
    p->To = y;
    p->St = x;
    p->Time = t;
    p->Ct = l[x][y] / 80;
    p->Cm = l[x][y] / 5;
    p->Next = C[x].TH;
    C[x].TH = p;
    return;
}

void InPL() {
    int x, y, t;
    List();
    cout << "Please input start, to, and time\n";
    cin >> x >> y >> t;
    L * p = new L;
    p->To = y;
    p->St = x;
    p->Time = t;
    p->Ct = l[x][y] / 800;
    p->Cm = l[x][y] / 1.2;
    p->Next = C[x].PH;
    C[x].PH = p;
    return;
}

int d[2000];
bool t[20];
double ct[20];
double cm[20];
L* ans[20];

void dfs(L * a) {
    if (a == NULL) return;
        dfs(ans[a->St]);
    cout << "From "+ C[a->St].Name + " To " + C[a->To].Name
         << " Time " << a->Time << " cost " << a->Cm << endl;
    return;
}

void Q0() {
    int x, y, i, now, f, p, time;
    double costtime;
    L * w = NULL;
    List();
    cout << "Please input start, to, and time\n";
    cin >> x >> y >> time;
    int &n = NumCity;
    for (i = 1; i <= n; ++i) {
        ct[i] = 100000000;
    }
    ct[x] = time - 1; ans[x] = NULL; cm[x] = 0;
    memset(t, 0 ,sizeof(t));
    f = 1; p = 1; t[x] = 1;
    for (d[1] = x; f <= p; ++f) {
        now = d[f];
        for (w = C[now].TH; w != NULL; w = w->Next) {
            costtime = w->Time;
            while (costtime < ct[now]+1) costtime += 24;
            if (ct[w->To] > costtime) {
                ct[w->To] = costtime;
                cm[w->To] = cm[now] + w->Cm;
                ans[w->To] = w;
                if (t[w->To] == 0) {
                    ++p; d[p] = w->To; t[w->To] = 1;
                }
            }
        }
        t[now] = 0;
    }
    cout << "Time:" << ct[y] - time << " money:" << cm[y] << endl;
    dfs(ans[y]);
    getchar();
    getchar();
    return;
}

void Q1() {
    int x, y, i, now, f, p, time;
    double costtime;
    L * w = NULL;
    List();
    cout << "Please input start, to, and time\n";
    cin >> x >> y >> time;
    int &n = NumCity;
    for (i = 1; i <= n; ++i) {
        ct[i] = 100000000;
    }
    for (i = 1; i <= n; ++i) {
        cm[i] = 100000000;
    }
    ct[x] = time - 1; ans[x] = NULL; cm[x] = 0;
    memset(t, 0 ,sizeof(t));
    f = 1; p = 1; t[x] = 1;
    for (d[1] = x; f <= p; ++f) {
        now = d[f];
        for (w = C[now].TH; w != NULL; w = w->Next) {
            costtime = w->Time;
            while (costtime < ct[now]+1) costtime += 24;
            if (cm[w->To] > cm[now] + w->Cm) {
                ct[w->To] = costtime;
                cm[w->To] = cm[now] + w->Cm;
                ans[w->To] = w;
                if (t[w->To] == 0) {
                    ++p; d[p] = w->To; t[w->To] = 1;
                }
            }
        }
        t[now] = 0;
    }
    cout << "Time:" << ct[y] - time << " money:" << cm[y] << endl;
    dfs(ans[y]);
    getchar();
    getchar();
    return;
}

void Q2() {
    int x, y, i, now, f, p, time;
    double costtime;
    L * w = NULL;
    List();
    cout << "Please input start, to, and time\n";
    cin >> x >> y >> time;
    int &n = NumCity;
    for (i = 1; i <= n; ++i) {
        ct[i] = 100000000;
    }
    ct[x] = time - 2; ans[x] = NULL; cm[x] = 0;
    memset(t, 0 ,sizeof(t));
    f = 1; p = 1; t[x] = 1;
    for (d[1] = x; f <= p; ++f) {
        now = d[f];
        for (w = C[now].PH; w != NULL; w = w->Next) {
            costtime = w->Time;
            while (costtime < ct[now]+2) costtime += 24;
            if (ct[w->To] > costtime) {
                ct[w->To] = costtime;
                cm[w->To] = cm[now] + w->Cm;
                ans[w->To] = w;
                if (t[w->To] == 0) {
                    ++p; d[p] = w->To; t[w->To] = 1;
                }
            }
        }
        t[now] = 0;
    }
    cout << "Time:" << ct[y] - time << " money:" << cm[y] << endl;
    dfs(ans[y]);
    getchar();
    getchar();
    return;
    return;
}

void Q3() {    int x, y, i, now, f, p, time;
    double costtime;
    L * w = NULL;
    List();
    cout << "Please input start, to, and time\n";
    cin >> x >> y >> time;
    int &n = NumCity;
    for (i = 1; i <= n; ++i) {
        ct[i] = 100000000;
    }
    for (i = 1; i <= n; ++i) {
        cm[i] = 100000000;
    }
    ct[x] = time - 2; ans[x] = NULL; cm[x] = 0;
    memset(t, 0 ,sizeof(t));
    f = 1; p = 1; t[x] = 1;
    for (d[1] = x; f <= p; ++f) {
        now = d[f];
        for (w = C[now].PH; w != NULL; w = w->Next) {
            costtime = w->Time;
            while (costtime < ct[now]+2) costtime += 24;
            if (cm[w->To] > cm[now] + w->Cm) {
                ct[w->To] = costtime;
                cm[w->To] = cm[now] + w->Cm;
                ans[w->To] = w;
                if (t[w->To] == 0) {
                    ++p; d[p] = w->To; t[w->To] = 1;
                }
            }
        }
        t[now] = 0;
    }
    cout << "Time:" << ct[y] - time << " money:" << cm[y] << endl;
    dfs(ans[y]);
    getchar();
    getchar();
    return;
}

void Q() {
    int op1, op2;
    cout << "Tarin input 0, Plane input 1 :";
    cin >> op1;
    cout << "Time input 0, money input 1 :";
    cin >> op2;
    op1 = op1 * 2 + op2;
    switch (op1) {
        case 0 : Q0(); break;
        case 1 : Q1(); break;
        case 2 : Q2(); break;
        case 3 : Q3(); break;
        default : break;
    }
    return;
}


void Welcome() {
    cout << endl;cout << endl;cout << endl;
    cout << endl;cout << endl;cout << endl;
    cout << endl;cout << endl;
    cout << "                   Welcome!\n";
    cout << "                Loading File now!\n";
    freopen("a.txt", "r", stdin);
    freopen("tmp", "w", stdout);
    cin >> NumCity;
    int &n = NumCity;
    for (int i = 1; i <= NumCity; ++i) {
        cin >> C[i].Name;
        C[i].Num = i;
        C[i].TH = NULL;
        C[i].PH = NULL;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> l[i][j];

    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        InTL();
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        InPL();
    }
    freopen("/dev/tty", "r+", stdin);
    freopen("/dev/tty", "w+", stdout);
    cout << "                Loading Finish\n";
    return;
}

void Init() {
    cout << endl;
    cout << "     Input 1 to add a city\n";
    cout << "     Input 2 to add a airline\n";
    cout << "     Input 3 to add a tarin line\n";
    cout << "     Input 4 to query\n";
    cout << "     Input 0 to save and quit\n";
    return;
}


void Finish() {
    freopen("a.txt", "w", stdout);
    cout << NumCity << endl;
    int &n  = NumCity, m;
    for (int i = 1; i <= n; ++i)
        cout << C[i].Name << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << (int)l[i][j] << ' ';
        cout << endl;
    }
    m = 0;
    for (int i = 1; i <= n; ++i) {
        L * p = C[i].TH;
        while (p != NULL) {
            ++m;
            p = p->Next;
        }
    }
    cout << m << endl;
    for (int i = 1; i <= n; ++i) {
        L * p = C[i].TH;
        while (p != NULL) {
            cout << p->St << ' ';
            cout << p->To << ' ';
            cout << p->Time << endl;
            p = p->Next;
        }
    }
    m = 0;
    for (int i = 1; i <= n; ++i) {
        L * p = C[i].PH;
        while (p != NULL) {
            ++m;
            p = p->Next;
        }
    }
    cout << m << endl;
    for (int i = 1; i <= n; ++i) {
        L * p = C[i].PH;
        while (p != NULL) {
            cout << p->St << ' ';
            cout << p->To << ' ';
            cout << p->Time << endl;
            p = p->Next;
        }
    }
    return;
}

int main() {
    Welcome();
    while (1) {
        Init();
        scanf("%d", &OP);
        switch (OP) {
            case 1 : InCity(); break;
            case 2 : InPL(); break;
            case 3 : InTL(); break;
            case 4 : Q(); break;
            case 0 : break;
            default : break;
        }
        if (OP == 0) break;
    }
    Finish();
    return 0;
}