#include <iostream>
#include "line.h"
#include "point.h"

using namespace std;

int main() {
    Line l;
    Point p;

    while (cin >> l.a >> l.b >> l.c >> p.x >> p.y) {
        double hasil_rumus = gradient(&l, &p);
        string hasil_posisi = CheckPointPosition(hasil_rumus);
        cout << hasil_posisi << endl;
    }

    return 0;
}