#include <iostream>
using namespace std;

class Rational {
    int a;
    int b;
public:
    Rational(int a = 0, int b = 1) {
        this->a = a;
        this->b = b;
    }

    // 최대공약수 알고리즘 적용 
    int gcd(int x, int y) {
        while (y != 0) {
            int tmp = x % y;
            x = y;
            y = tmp;
        }
        return x;
    }

    // 서로소인 분모 분자로 간단화
    void simplify() {
        int g = gcd(a, b);
        a /= g;
        b /= g;
    }

    void show();
    Rational operator+(Rational op2); // r3 = r1 + r2
    Rational operator-(Rational op2); // r4 = r1 - r2
    Rational operator*(Rational op2); // r5 = r1 * r2
    Rational operator/(Rational op2); // r6 = r1 / r2
    Rational& operator++(); // r7 = ++r1
};

void Rational::show() {
    cout << a << "/" << b << endl;
}

Rational Rational::operator+(Rational op2) {
    Rational tmp;
    tmp.a = a * op2.b + b * op2.a;
    tmp.b = b * op2.b;
    tmp.simplify();
    return tmp;
}

Rational Rational::operator-(Rational op2) {
    Rational tmp;
    tmp.a = a * op2.b - b * op2.a;
    tmp.b = b * op2.b;
    tmp.simplify();
    return tmp;
}

Rational Rational::operator*(Rational op2) {
    Rational tmp;
    tmp.a = a * op2.a;
    tmp.b = b * op2.b;
    tmp.simplify();
    return tmp;
}

Rational Rational::operator/(Rational op2) {
    Rational tmp;
    tmp.a = a * op2.b;
    tmp.b = b * op2.a;
    tmp.simplify();
    return tmp;
}

Rational& Rational::operator++() {
    a += b;
    simplify();
    return *this;
}

int main() {
    Rational r1(3, 6), r2(2, 3), r3, r4, r5, r6, r7;
    r1.show();
    r2.show();

    r3 = r1 + r2;
    r4 = r1 - r2;
    r5 = r1 * r2;
    r6 = r1 / r2;
    r7 = ++r1;
    
    r3.show();
    r4.show();
    r5.show();
    r6.show();
}
    
