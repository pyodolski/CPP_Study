#include "Rational.h"
#include "Rational.cpp"
#include <iostream>
using namespace std;

int main()
{
    Rational r1(3, 6), r2(2, 3), r3, r4, r5, r6, r7, r8, r9, r10, r11;
    r1.show();
    r2.show();

    r3 = r1 + r2;
    r4 = r1 - r2;
    r5 = r1 * r2;
    r6 = r1 / r2;
    r7 = ++r1;
    r8 = --r1;
    r9 = r1++;
    r10 = r1--;
    r11 = 2 + r1;

    r3.show();
    r4.show();
    r5.show();
    r6.show();
    r8.show();
    r9.show();
    r10.show();
    r11.show();
}