#include "Rational.h"
#include <iostream>

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