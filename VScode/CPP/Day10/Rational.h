#ifndef Rational_h
#define Rational_h

#include <iostream>
using namespace std;

class Rational
{
    int a;
    int b;

public:
    Rational(int a = 0, int b = 1)
    {
        this->a = a;
        this->b = b;
    }

    // 최대공약수 알고리즘 적용
    int gcd(int x, int y)
    {
        while (y != 0)
        {
            int tmp = x % y;
            x = y;
            y = tmp;
        }
        return x;
    }

    // 서로소인 분모 분자로 간단화
    void simplify()
    {
        int g = gcd(a, b);
        a /= g;
        b /= g;
    }

    void show();
    Rational operator+(Rational op2); // r3 = r1 + r2
    Rational operator-(Rational op2); // r4 = r1 - r2
    Rational operator*(Rational op2); // r5 = r1 * r2
    Rational operator/(Rational op2); // r6 = r1 / r2
    Rational &operator++();           // r7 = ++r1
    Rational &operator--();           // r8 = --r1
    Rational operator++(int);         // r9 = r1++
    Rational operator--(int);         // r10 = r1--
    friend Rational operator+(int num, Rational op2);
};

#endif