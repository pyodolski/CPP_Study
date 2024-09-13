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

// 분수 출력 함수
void Rational::show()
{
    cout << a << "/" << b << endl;
}

// 덧셈 연산자 오버로딩
Rational Rational::operator+(Rational op2)
{
    Rational tmp;
    tmp.a = a * op2.b + b * op2.a;
    tmp.b = b * op2.b;
    tmp.simplify();
    return tmp;
}

// 뺄셈 연산자 오버로딩
Rational Rational::operator-(Rational op2)
{
    Rational tmp;
    tmp.a = a * op2.b - b * op2.a;
    tmp.b = b * op2.b;
    tmp.simplify();
    return tmp;
}

// 곱셈 연산자 오버로딩
Rational Rational::operator*(Rational op2)
{
    Rational tmp;
    tmp.a = a * op2.a;
    tmp.b = b * op2.b;
    tmp.simplify();
    return tmp;
}

// 나눗셈 연산자 오버로딩
Rational Rational::operator/(Rational op2)
{
    Rational tmp;
    tmp.a = a * op2.b;
    tmp.b = b * op2.a;
    tmp.simplify();
    return tmp;
}

// 전위 증가 연산자
Rational &Rational::operator++()
{
    a += b;
    simplify();
    return *this;
}

// 전위 감소 연산자
Rational &Rational::operator--()
{
    a -= b;
    simplify();
    return *this;
}

// 후위 증가 연산자
Rational Rational::operator++(int)
{
    Rational tmp = *this;
    ++(*this);
    return tmp;
}

// 후위 감소 연산자
Rational Rational::operator--(int)
{
    Rational tmp = *this;
    --(*this);
    return tmp;
}

Rational operator+(int num, Rational op2)
{
    Rational result(num * op2.b + op2.a, op2.b);
    result.simplify();
    return result;
}

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
