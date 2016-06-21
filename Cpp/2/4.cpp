#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

class Car {
private:
    string Band, Color;
    bool Door, Light;
    int Speed;

public:
    Car () {}

    Car (string band,string color,int door,int light,int speed) {
        Band = band;
        Color = color;
        Door = door;
        Light = light;
        Speed = speed;
    }

    void Display() {
        cout << "Band: " << Band << endl;
        cout << "Color: " << Color << endl;
        cout << "Door: " << ((Door == 1)? "on" : "off") << endl;
        cout << "Light: " << ((Light == 1)? "on" : "off") << endl;
        cout << "Speed: " << Speed << endl;
    }

    void SpeedUp() {
        cout << "Now the speed is " << Speed << endl;
        cout << "Speed up!\n";
        Speed = Speed + 10;
        cout << "Now the speed is " << Speed << endl;
    }

    void SpeedDown() {
        cout << "Now the speed is " << Speed << endl;
        cout << "Speed down!\n";
        Speed = Speed - 10;
        cout << "Now the speed is " << Speed << endl;
    }

    void TurnLight() {
        cout << "Light is " << ((Light == 1)? "on" : "off") << " now\n";
        cout << "change light!\n";
        Light = 1 - Light;
        cout << "Light is " << ((Light == 1)? "on" : "off") << " now\n";
    }

    void TurnDoor() {
        cout << "Door is " << ((Door == 1)? "on" : "off") << " now\n";
        cout << "change Door!\n";
        Door = 1 - Door;
        cout << "Door is " << ((Door == 1)? "on" : "off") << " now\n";
    }
};

int main() {
    Car test("Benz","Black",0,0,100);
    test.Display();
    putchar('\n');
    test.SpeedUp();
    putchar('\n');
    test.SpeedDown();
    putchar('\n');
    test.TurnDoor();
    putchar('\n');
    test.TurnDoor();
    putchar('\n');
    test.TurnLight();
    putchar('\n');
    test.TurnLight();
    putchar('\n');
    return 0;
}
