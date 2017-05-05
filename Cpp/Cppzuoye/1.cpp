#include<cstdio>
using namespace std;

class Retangle {
private:
    double x1, x2, y1, y2;

public:
    static int Total;

    Retangle() {
        ++Total;
        x1 = 0;
        y1 = 1;
        x2 = 1;
        y2 = 0;
    }

    Retangle(double xx1, double xx2, double yy1, double yy2) {
        ++Total;
        x1 = xx1;
        x2 = xx2;
        y1 = yy1;
        y2 = yy2;
    }
    
    double Perimeter() {
        return (x2 + y1 - x1 - y2) * 2;
    }

    friend double Area(Retangle & a);

};

double Area(Retangle & a) {
    double x = a.x2 - a.x1;
    double y = a.y1 - a.y2;
    return x * y;
}

int Retangle::Total = 0;
int i, n;
double x1, x2, y1, y2;

int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%lf%lf%lf%lf", &x1, &x2, &y1, &y2);
        Retangle a(x1, x2, y1, y2);
        printf("%lf\n", Area(a));
        printf("%lf\n", a.Perimeter());
    }
    printf("%d\n", Retangle::Total);
    return 0;
}