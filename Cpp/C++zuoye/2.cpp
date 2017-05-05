#include<cstdio>
using namespace std;

class Complex {
public:
    int a, b;

    Complex() {
        a = 0;
        b = 0;
    }

    Complex(int aa, int bb) {
        a = aa;
        b = bb;
    }
    
    Complex operator + (const Complex & B) const {
        Complex c;
        c.a = a + B.a;
        c.b = b + B.b;
        return c;
    }

    operator int () const {
        return a;
    } 

};

int main() {
    Complex a(1, 2);
    Complex b(2, 3);
    Complex c = a + b;
    printf("%d + %di\n", c.a, c.b);
    printf("%d\n", (int)c);
    return 0;
}