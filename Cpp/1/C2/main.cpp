#include <QCoreApplication>
#include <iostream>
#include <a.cpp>
using namespace std;

int A, B, C, ans;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cin >> A >> B >> C;
    ans = f(A) + f(B) + f(C);
    cout << ans << endl;
    return a.exec();
}
