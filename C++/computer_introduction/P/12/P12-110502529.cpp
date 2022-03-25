/*
*Pratice 12
*Name: 陳柏燊
*Student Number: 110502529
*Course 2021-CE1003-A
*/
#include    <iostream>

using namespace std;

void add(float ax, float ay, float bx, float by, float *cx, float *cy) {
    // implement here !!!
    *cx = ax + bx;
    *cy = ay + by;
}

void scale(float ax, float ay, double s, float *cx, float *cy) {
    // implement here !!!
    *cx = ax * s;
    *cy = ay * s;
}

int main() {
    float ax, ay, bx, by, cx, cy, s;

    cout << "A: ";
    cin >> ax >> ay;
    cout << "B: ";
    cin >> bx >> by;
    cout << "s: ";
    cin >> s;

    add(ax, ay, bx, by, &cx, &cy);
    cout << "A + B = " << "(" << cx << ", " << cy << ")" << endl;

    scale(ax, ay, s, &cx, &cy);
    cout << "A * s = " << "(" << cx << ", " << cy << ")" << endl;

    return 0;
}
